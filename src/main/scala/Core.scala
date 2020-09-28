package MyCore

import chisel3._
import chisel3.util._
import utils._

import ISA._
import ISA.Instructions._
import ISA.OpSelConst._
import ISA.RISCVconst._

import Memory._

class CoreIO extends MyCoreBundle{
    val imem = new MemPortIO(32)
    val dmem = new MemPortIO(xlen)
}

class Core extends MyCoreModule{
    val io = IO(new CoreIO)
    val inst = 0.U

    ////// TODO
    val pc_reg  = RegInit(0.U)//START_ADDR)
    val pc_next = Wire(UInt(32.W))
    val pc_4    = Wire(UInt(32.W))
    val pc_sel  = Wire()
    pc_4    := pc_reg + 4.U

    pc_next := MuxCase(pc_4, Array(
        (id.io.pc_se)
    ))


    val alu = new ALU
    val id  = new Decoder
    val rf  = new RegFile
    
    // inst decode
    id.io.inst := inst
    

    // immediates
    val imm_i = inst(31, 20)
    val imm_s = Cat(inst(31, 25), inst(11,7))
    val imm_b = Cat(inst(31), inst(7), inst(30,25), inst(11,8))
    val imm_u = inst(31, 12)
    val imm_j = Cat(inst(31), inst(19,12), inst(20), inst(30,21))
    val imm_z = Cat(Fill(27,0.U), inst(19,15))

    // sign-extend immediates
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
        (id.io.wb_sel === WB_ALU) -> alu.io.out,
        (id.io.wb_sel === WB_MEM) -> io.dmem.data,//////
        (id.io.wb_sel === WB_PC4) -> (pc_reg + 4.U)
    ))
    rf.io.wen      := id.io.rf_wen // && !exception


    // ALU
    alu.io.opcode  := id.io.alu_op
    alu.io.in1     := MuxCase(0.U, Array(
        (id.io.op1_sel === OP1_RS1) -> rf.io.rs1_data,
        (id.io.op1_sel === OP1_IMU) -> imm_u_sext,
        (id.io.op1_sel === OP1_IMZ) -> imm_z
    )).asUInt()

    alu.io.in2     := MuxCase(0.U, Array(
        (id.io.op2_sel === OP2_RS2) -> rf.io.rs2_data,
        (id.io.op2_sel === OP2_IMI) -> imm_i_sext,
        (id.io.op2_sel === OP2_IMS) -> imm_s_sext,
        (id.io.op2_sel === OP2_PC ) -> pc_reg
    )).asUInt()


    // 




}