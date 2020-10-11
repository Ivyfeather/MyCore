package MyCore

import chisel3._
import chisel3.util._
import Memory._

class coreIO extends MyCoreBundle {
    val imem = new MemPortIO(32)
    val dmem = new MemPortIO(xlen)
    val debug_io = new Debug_IO
}

class core extends MyCoreModule {
    val io = IO(new coreIO)

    // PC
    val pc_reg  = RegInit(START_ADDR)//START_ADDR)
    val pc_next = Wire(UInt(32.W))
    val pc_4    = Wire(UInt(32.W))
    pc_4    := pc_reg + 4.U

    // INST
    io.imem.req.bits.data   := 0.U // this data is for writing mem
    io.imem.req.bits.addr   := pc_reg
    io.imem.req.bits.fcn    := MRD
    io.imem.req.bits.msk    := MT_WU
    io.imem.req.valid       := true.B
    val inst = Wire(UInt(32.W))
    inst:= Mux(io.imem.resp.valid, io.imem.resp.bits.data, BUBBLE)
    //[TODO] ready? logic correct?
    io.imem.resp.ready := true.B

    val alu = Module(new ALU)
    val idu = Module(new IDU)
    val rf  = Module(new RegFile)
    idu.io.inst := inst

    // stall when inst/required data not returned
    val stall = !io.imem.resp.valid || !( (idu.io.mem_en && io.dmem.resp.valid) || !idu.io.mem_en )

    // immediates, riscv-spec P16
    val imm_i = inst(31, 20)
    val imm_s = Cat(inst(31, 25), inst(11,7))
    val imm_b = Cat(inst(31), inst(7), inst(30,25), inst(11,8))
    val imm_u = inst(31, 12)
    val imm_j = Cat(inst(31), inst(19,12), inst(20), inst(30,21))
    val imm_z = Cat(Fill(27,0.U), inst(19,15))

    // sign-extend immediates, riscv-spec P17
    val imm_i_sext = Cat(Fill(20,imm_i(11)), imm_i)
    val imm_s_sext = Cat(Fill(20,imm_s(11)), imm_s)
    val imm_b_sext = Cat(Fill(19,imm_b(11)), imm_b, 0.U)
    val imm_u_sext = Cat(imm_u, Fill(12,0.U))
    val imm_j_sext = Cat(Fill(11,imm_j(19)), imm_j, 0.U)

    // RegFile
    rf.io.rs1_addr := inst(RS1_MSB, RS1_LSB)
    rf.io.rs2_addr := inst(RS2_MSB, RS2_LSB)
    rf.io.waddr    := inst(RD_MSB,  RD_LSB)
    rf.io.wdata    := MuxCase(alu.io.out, Array(
        (idu.io.wb_sel === WB_ALU) -> alu.io.out,
        (idu.io.wb_sel === WB_MEM) -> io.dmem.resp.bits.data,
        (idu.io.wb_sel === WB_PC4) -> pc_4
    ))
    rf.io.wen      := idu.io.rf_wen // && !exception

    // ALU
    alu.io.opcode  := idu.io.alu_op
    alu.io.in1     := MuxCase(rf.io.rs1_data, Array(
        (idu.io.op1_sel === OP1_RS1) -> rf.io.rs1_data,
        (idu.io.op1_sel === OP1_IMU) -> imm_u_sext,
        (idu.io.op1_sel === OP1_IMZ) -> imm_z
    )).asUInt()

    alu.io.in2     := MuxCase(rf.io.rs2_data, Array(
        (idu.io.op2_sel === OP2_RS2) -> rf.io.rs2_data,
        (idu.io.op2_sel === OP2_IMI) -> imm_i_sext,
        (idu.io.op2_sel === OP2_IMS) -> imm_s_sext,
        (idu.io.op2_sel === OP2_PC ) -> pc_reg
    )).asUInt()

    // Dmem
    io.dmem.req.bits.addr := alu.io.out
    io.dmem.req.bits.data := rf.io.rs2_data
    io.dmem.req.valid     := idu.io.mem_en
    io.dmem.req.bits.fcn  := idu.io.mem_fcn
    io.dmem.req.bits.msk  := idu.io.mem_msk

    io.dmem.resp.ready := true.B

    // Branch/Jump
    val br_target  = pc_reg + imm_b_sext
    val jmp_target = pc_reg + imm_j_sext
    val jr_target  = rf.io.rs1_data + imm_i_sext

    val br_taken = MuxCase(false.B, Array(
        (idu.io.br_type === BR_EQ  &&  alu.io.zero)   -> true.B,
        (idu.io.br_type === BR_NE  && !alu.io.zero)   -> true.B,
        (idu.io.br_type === BR_GE  && !alu.io.out(0)) -> true.B,
        (idu.io.br_type === BR_GEU && !alu.io.out(0)) -> true.B,
        (idu.io.br_type === BR_LT  &&  alu.io.out(0)) -> true.B,
        (idu.io.br_type === BR_LTU &&  alu.io.out(0)) -> true.B
    ))

    // PC_NEXT
    pc_next := MuxCase(pc_4, Array(
        (br_taken === true.B)       -> br_target,
        (idu.io.br_type === BR_J)   -> jmp_target,
        (idu.io.br_type === BR_JR)  -> jr_target
    ))
    when(!stall){
        pc_reg := pc_next
    }

    // DEBUG
    io.debug_io.wen     := rf.io.wen
    io.debug_io.waddr   := rf.io.waddr
    io.debug_io.wdata   := rf.io.wdata
    io.debug_io.PC      := pc_reg
    io.debug_io.stall   := stall
}


