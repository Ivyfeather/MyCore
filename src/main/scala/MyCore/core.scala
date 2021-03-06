package MyCore

import chisel3._
import chisel3.util._
import Memory._
import chisel3.util.experimental.BoringUtils

class coreIO extends MyCoreBundle {
    val imem = new MemPortIO(xlen)
    val dmem = new MemPortIO(xlen)
    val mtip = Input(Bool())
    val meip = Input(Bool())
}

class core extends MyCoreModule {
    val io = IO(new coreIO)
    io := DontCare

    val pre_top = Module(new Pre_TOP)
    val fs_top  = Module(new IF_TOP)
    val ds_top  = Module(new ID_TOP)
    val es_top  = Module(new EXE_TOP)
    val ms_top  = Module(new MEM_TOP)
    val ws_top  = Module(new WB_TOP)

    pre_top.io.fs <> fs_top.io.pres
    fs_top.io.ds <> ds_top.io.fs
    ds_top.io.es <> es_top.io.ds
    es_top.io.ms <> ms_top.io.es
    ms_top.io.ws <> ws_top.io.ms
    ws_top.io.rf <> ds_top.io.wb

    pre_top.io.imem := DontCare
    fs_top.io.imem  := DontCare
    io.imem.req  <> pre_top.io.imem.req
    io.imem.resp <> fs_top.io.imem.resp

    es_top.io.dmem := DontCare
    ms_top.io.dmem := DontCare
    io.dmem.req  <> es_top.io.dmem.req
    io.dmem.resp <> ms_top.io.dmem.resp
    ws_top.io.mtip := io.mtip
    ws_top.io.meip := io.meip

    ms_top.io.exception := ws_top.io.exception
    es_top.io.exception := ws_top.io.exception

    pre_top.io.br_taken := ds_top.io.br_taken
    pre_top.io.br_target := ds_top.io.br_target
    pre_top.io.br_old_PC := ds_top.io.br_old_PC

    ds_top.io.insts_sent_after_br := pre_top.io.insts_sent_after_br

    ds_top.io.es_res := es_top.io.es_res
    ds_top.io.ms_res := ms_top.io.ms_res
    ds_top.io.ldrt := ms_top.io.ldrt

    ds_top.io.exception := ws_top.io.exception
    ds_top.io.exc_addr := ws_top.io.exc_addr
    ds_top.io.mepc := ws_top.io.mepc

}
/*
class single_core extends MyCoreModule {
    val io = IO(new coreIO)
    io := DontCare

    val alu = Module(new ALU)
    val idu = Module(new IDU)
    val rf  = Module(new RegFile)

    // PC
    val pc_reg  = RegInit(START_ADDR.asUInt(xlen.W))
    val pc_next = Wire(UInt(32.W))
    val pc_4    = Wire(UInt(32.W))
    pc_4    := pc_reg + 4.U

    // stall when inst/required data not returned
    val stall = WireInit(false.B)
    val imem_req_r = RegInit(true.B)
    val dmem_req_r = RegInit(false.B)

    // INST
    //[TODO] should have another reg for whether inst returned
    when(io.imem.req.ready) { imem_req_r := false.B }
    .elsewhen(!stall)       { imem_req_r := true.B  }

    when(io.dmem.req.ready) { dmem_req_r := false.B }
    .elsewhen(idu.io.ctrl.mem_en){ dmem_req_r := true.B  }

    //stall :=  !imem_req_r || !( (idu.io.ctrl.mem_en && io.dmem.resp.valid) || !idu.io.ctrl.mem_en )
    stall := imem_req_r || dmem_req_r

    io.imem.req.valid       := imem_req_r
    io.imem.req.bits.data   := 0.U // this data is for writing mem
    io.imem.req.bits.addr   := pc_reg
    io.imem.req.bits.wr     := MRD
    io.imem.req.bits.msk    := MT_WU
    //[TODO] req_addr should be PC_NEXT


    val inst = RegInit(BUBBLE)
    when(io.imem.resp.valid) { inst := io.imem.resp.bits.data }

    idu.io.inst := inst

    // immediates, riscv-spec P16
    val imm_i = inst(31, 20)
    val imm_s = Cat(inst(31, 25), inst(11,7))
    val imm_b = Cat(inst(31), inst(7), inst(30,25), inst(11,8))
    val imm_u = inst(31, 12)
    val imm_j = Cat(inst(31), inst(19,12), inst(20), inst(30,21))
    val imm_z = Cat(Fill(27,0.U), inst(19,15))

    // sign-extend immediates, riscv-spec P17
    // [TODO] imm for 64bit?
    val imm_i_sext = Cat(Fill(xlen-12,imm_i(11)), imm_i)
    val imm_s_sext = Cat(Fill(xlen-12,imm_s(11)), imm_s)
    val imm_b_sext = Cat(Fill(xlen-11,imm_b(11)), imm_b, 0.U)
    val imm_u_sext = Cat(Fill(xlen-32,imm_u(11)), imm_u, Fill(12,0.U))
    val imm_j_sext = Cat(Fill(xlen-11,imm_j(19)), imm_j, 0.U)

    // RegFile
    rf.io.rs1_addr := inst(RS1_MSB, RS1_LSB)
    rf.io.rs2_addr := inst(RS2_MSB, RS2_LSB)
    rf.io.waddr    := inst(RD_MSB,  RD_LSB)
    rf.io.wdata    := MuxCase(alu.io.out, Array(
        (idu.io.ctrl.wb_sel === WB_ALU) -> alu.io.out,
        (idu.io.ctrl.wb_sel === WB_MEM) -> io.dmem.resp.bits.data,
        (idu.io.ctrl.wb_sel === WB_PC4) -> pc_4
    ))
    rf.io.wen      := idu.io.ctrl.rf_wen // && !exception

    // ALU
    alu.io.opcode  := idu.io.ctrl.alu_op
    alu.io.in1     := MuxCase(rf.io.rs1_data, Array(
        (idu.io.ctrl.op1_sel === OP1_RS1) -> rf.io.rs1_data,
        (idu.io.ctrl.op1_sel === OP1_IMU) -> imm_u_sext,
        (idu.io.ctrl.op1_sel === OP1_IMZ) -> imm_z
    )).asUInt()

    alu.io.in2     := MuxCase(rf.io.rs2_data, Array(
        (idu.io.ctrl.op2_sel === OP2_RS2) -> rf.io.rs2_data,
        (idu.io.ctrl.op2_sel === OP2_IMI) -> imm_i_sext,
        (idu.io.ctrl.op2_sel === OP2_IMS) -> imm_s_sext,
        (idu.io.ctrl.op2_sel === OP2_PC ) -> pc_reg
    )).asUInt()

    // Dmem
    io.dmem.req.valid     := dmem_req_r
    io.dmem.req.bits.addr := alu.io.out
    io.dmem.req.bits.data := rf.io.rs2_data
    io.dmem.req.bits.wr   := idu.io.ctrl.mem_wr
    io.dmem.req.bits.msk  := idu.io.ctrl.mem_msk

    // Branch/Jump
    val br_target  = pc_reg + imm_b_sext
    val jmp_target = pc_reg + imm_j_sext
    val jr_target  = rf.io.rs1_data + imm_i_sext

    val br_taken = MuxCase(false.B, Array(
        (idu.io.ctrl.br_type === BR_EQ  &&  alu.io.zero)   -> true.B,
        (idu.io.ctrl.br_type === BR_NE  && !alu.io.zero)   -> true.B,
        (idu.io.ctrl.br_type === BR_GE  && !alu.io.out(0)) -> true.B,
        (idu.io.ctrl.br_type === BR_GEU && !alu.io.out(0)) -> true.B,
        (idu.io.ctrl.br_type === BR_LT  &&  alu.io.out(0)) -> true.B,
        (idu.io.ctrl.br_type === BR_LTU &&  alu.io.out(0)) -> true.B
    ))

    // PC_NEXT
    pc_next := MuxCase(pc_4, Array(
        (br_taken === true.B)       -> br_target,
        (idu.io.ctrl.br_type === BR_J)   -> jmp_target,
        (idu.io.ctrl.br_type === BR_JR)  -> jr_target
    ))
    when(!stall){
        pc_reg := pc_next
    }


    // DEBUG
    io.debug.PC      := pc_reg
    io.debug.valid   := !stall

    val difftest_regs = WireInit(0.U.asTypeOf( Vec(32, UInt(xlen.W)) ))
    val difftest_is_trap = WireInit(false.B)
    BoringUtils.addSink(difftest_regs, "difftest_r")
    BoringUtils.addSink(difftest_is_trap, "is_trap")
    io.debug.rf     := difftest_regs
    io.debug.trap   := difftest_is_trap
}
*/

