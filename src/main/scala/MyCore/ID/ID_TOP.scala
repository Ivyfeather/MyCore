package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import Const.CSR_CTRL

class ID_TOP_IO extends MyCoreBundle{
    val fs      = Flipped(DecoupledIO(new IF_to_ID_IO))
    val es      = DecoupledIO(new ID_TO_EXE_IO)
    val wb      = Flipped(new Forwardbus)
}

class ID_TOP extends MyCoreModule{
    val io = IO(new ID_TOP_IO)
    io := DontCare

    val rf = Module(new ForwardUnit)

    val from_fs_r = RegEnable(io.fs.bits, 0.U.asTypeOf(new IF_to_ID_IO), io.fs.valid && io.fs.ready)

    //[TODO] consider write_read related later
    val ds_ready_go = !rf.io.wr_stall
    val ds_valid    = RegEnable(io.fs.valid, false.B, io.fs.ready)

    io.fs.ready := !ds_valid || ds_ready_go && io.es.ready
    io.es.valid := ds_valid && ds_ready_go

// ===== Inst Decode ===========================================================
    val inst = from_fs_r.inst
    val idu = Module(new IDU)
    idu.io.inst := inst

// ==== RegFile ============================================================
    rf.io.ctrl        := idu.io.ctrl
    rf.io.ws_res      := io.wb
    rf.io.rs1_addr    := inst(RS1_MSB, RS1_LSB)
    rf.io.rs2_addr    := inst(RS2_MSB, RS2_LSB)

// ==== To es ============================================================
    io.es.bits.PC       := from_fs_r.PC
    io.es.bits.inst     := from_fs_r.inst
    io.es.bits.decode   := idu.io.ctrl
    io.es.bits.rs1_data := rf.io.rs1_data
    io.es.bits.rs2_data := rf.io.rs2_data

// ==== Branch ============================================================
    val imm_i = inst(31, 20)
    val imm_b = Cat(inst(31), inst(7), inst(30,25), inst(11,8))
    val imm_j = Cat(inst(31), inst(19,12), inst(20), inst(30,21))
    val imm_i_sext = Cat(Fill(xlen-12,imm_i(11)), imm_i)
    val imm_b_sext = Cat(Fill(xlen-11,imm_b(11)), imm_b, 0.U)
    val imm_j_sext = Cat(Fill(xlen-11,imm_j(19)), imm_j, 0.U)

    val branch_target  = from_fs_r.PC + imm_b_sext
    val jmp_target = from_fs_r.PC + imm_j_sext
    val jr_target  = rf.io.rs1_data + imm_i_sext

    val rf_eq  = (rf.io.rs1_data === rf.io.rs2_data)
    val rf_lt  = (rf.io.rs1_data.asSInt() < rf.io.rs2_data.asSInt())
    val rf_ltu = (rf.io.rs1_data.asUInt() < rf.io.rs2_data.asUInt())
    val ctrl   = idu.io.ctrl

    val br_taken = Wire(Bool())
    val br_target = Wire(UInt(xlen.W))
    val mepc    = WireInit(0.U(64.W))
    BoringUtils.addSink(mepc, "mepc")

    br_taken := MuxCase(false.B, Array(
        (ctrl.br_type === BR_EQ  &&  rf_eq)       -> true.B,
        (ctrl.br_type === BR_NE  && !rf_eq)       -> true.B,
        (ctrl.br_type === BR_GE  && !rf_lt)       -> true.B,
        (ctrl.br_type === BR_GEU && !rf_ltu)      -> true.B,
        (ctrl.br_type === BR_LT  &&  rf_lt)       -> true.B,
        (ctrl.br_type === BR_LTU &&  rf_ltu)      -> true.B,
        (ctrl.br_type === BR_J)                   -> true.B,
        (ctrl.br_type === BR_JR)                  -> true.B,
        (ctrl.csr_cmd === CSR_CTRL.MRET)          -> true.B
    ))
    br_target:= MuxCase(branch_target, Array(
        (ctrl.br_type === BR_J)                   -> jmp_target,
        (ctrl.br_type === BR_JR)                  -> jr_target
    ))

    val br_taken_final = Mux(rf.io.wr_stall, false.B, br_taken && ds_valid)

    BoringUtils.addSource(br_taken_final, "br_taken")
    BoringUtils.addSource(br_target, "br_target")
    BoringUtils.addSource(from_fs_r.PC, "br_old_PC")

    val insts_sent_after_br = WireInit(0.U)
    BoringUtils.addSink(insts_sent_after_br, "insts_sent_after_br")

    // if br_taken, then we need to flush #"insts_sent_after_br" following insts
    val flush_set = RegInit(false.B)
    val flush_reg = RegInit(0.U(2.W))
    when(br_taken && io.fs.valid && io.fs.ready && !flush_set){
        flush_reg := insts_sent_after_br - 1.U
        flush_set := true.B
    }.elsewhen(br_taken && !flush_set) {
        flush_reg := insts_sent_after_br
        flush_set := true.B
    }.elsewhen(io.fs.valid && io.fs.ready && flush_reg > 0.U){
        flush_reg := flush_reg - 1.U
        flush_set := Mux(flush_reg === 0.U, false.B, flush_set)
    }.elsewhen(io.fs.valid && io.fs.ready && flush_reg === 0.U){
        flush_set := false.B
    }

    //[TODO] as it appears in waveform, dont need to flush the reg
    // maybe it will have problem with random delay ram
    when(flush_reg =/= 0.U){ // this "if" has higher prior when generating .v
        from_fs_r := 0.U.asTypeOf(new IF_to_ID_IO)
    }

}
