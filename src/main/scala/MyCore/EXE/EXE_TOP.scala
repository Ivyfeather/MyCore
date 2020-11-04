package MyCore

import Memory.MemPortIO
import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class EXE_TOP_IO extends MyCoreBundle{
    val ds      = Flipped(DecoupledIO(new ID_TO_EXE_IO))
    val ms      = DecoupledIO(new EXE_TO_MEM_IO)
    val dmem    = new MemPortIO(xlen)
}

class EXE_TOP extends MyCoreModule {
    val io = IO(new EXE_TOP_IO)
    io := DontCare

    val from_ds_r   = RegEnable(io.ds.bits, 0.U.asTypeOf(new ID_TO_EXE_IO), io.ds.valid && io.ds.ready)
    val es_ready_go = Mux(io.dmem.req.valid && !io.dmem.req.ready, false.B, true.B)
    val es_valid    = RegEnable(io.ds.valid, false.B, io.ds.ready)

    io.ds.ready    := !es_valid || es_ready_go && io.ms.ready;
    io.ms.valid    := es_valid && es_ready_go

// ==== ALU ============================================================
    val decode = from_ds_r.decode
    val inst = from_ds_r.inst

// immediates, riscv-spec P16
    val imm_i = inst(31, 20)
    val imm_s = Cat(inst(31, 25), inst(11, 7))
    val imm_b = Cat(inst(31), inst(7), inst(30, 25), inst(11, 8))
    val imm_u = inst(31, 12)
    val imm_j = Cat(inst(31), inst(19, 12), inst(20), inst(30, 21))
    val imm_z = Cat(Fill(27, 0.U), inst(19, 15))

    // sign-extend immediates, riscv-spec P17
    // [TODO] imm for 64bit?
    val imm_i_sext = Cat(Fill(xlen - 12, imm_i(11)), imm_i)
    val imm_s_sext = Cat(Fill(xlen - 12, imm_s(11)), imm_s)
    val imm_b_sext = Cat(Fill(xlen - 11, imm_b(11)), imm_b, 0.U)
    val imm_u_sext = Cat(Fill(xlen - 32, imm_u(11)), imm_u, Fill(12, 0.U))
    val imm_j_sext = Cat(Fill(xlen - 11, imm_j(19)), imm_j, 0.U)

    val alu = Module(new ALU)
    alu.io.opcode := decode.alu_op
    alu.io.in1 := MuxCase(from_ds_r.rs1_data, Array(
        (decode.op1_sel === OP1_RS1) -> from_ds_r.rs1_data,
        (decode.op1_sel === OP1_IMU) -> imm_u_sext,
        (decode.op1_sel === OP1_IMZ) -> imm_z
    )).asUInt()

    alu.io.in2 := MuxCase(from_ds_r.rs2_data, Array(
        (decode.op2_sel === OP2_RS2) -> from_ds_r.rs2_data,
        (decode.op2_sel === OP2_IMI) -> imm_i_sext,
        (decode.op2_sel === OP2_IMS) -> imm_s_sext,
        (decode.op2_sel === OP2_PC) -> from_ds_r.PC //[TODO] check, right?
    )).asUInt()


// ==== dmem ============================================================
    val dmem_req_r = RegInit(false.B)
    when(io.ds.valid && io.ds.ready)    { dmem_req_r := true.B}
    .elsewhen(io.dmem.req.ready)        { dmem_req_r := false.B}
    .elsewhen(decode.mem_en && dmem_req_r) { }
    //[TODO]the last line refer to myCPU EXE.v:333 ?   else if ((es_load_op||es_mem_we) && data_sram_req_r==1'b1)begin   end

    io.dmem.req.valid       := Mux(decode.mem_en, dmem_req_r, false.B)
    if(xlen==64){   io.dmem.req.bits.addr   := Cat(alu.io.out(xlen-1, 3), Fill(3, 0.U)) }
    else        {   io.ms.bits.load_offset  := Cat(alu.io.out(xlen-1, 2), Fill(2, 0.U)) }
    io.dmem.req.bits.data   := from_ds_r.rs2_data
    io.dmem.req.bits.wr     := decode.mem_wr
    io.dmem.req.bits.msk    := decode.mem_msk


// ==== To ms ============================================================
    io.ms.bits.PC           := from_ds_r.PC
    io.ms.bits.alu_result   := Mux(decode.wb_sel === WB_PC4, from_ds_r.PC + 4.U, alu.io.out)
    io.ms.bits.rd_addr      := inst(RD_MSB,  RD_LSB)
    io.ms.bits.decode       := decode
    if(xlen==64){   io.ms.bits.load_offset  := alu.io.out % 8.U }
    else        {   io.ms.bits.load_offset  := alu.io.out % 4.U }

    // ==== Forward ============================================================
    val es_res = Wire(new Forwardbus)
    es_res.wb_sel  := from_ds_r.decode.wb_sel
    es_res.rf_we   := from_ds_r.decode.rf_wen
    es_res.wr_addr := io.ms.bits.rd_addr
    es_res.wr_data := io.ms.bits.alu_result
    BoringUtils.addSource(es_res, "es_res")
}
