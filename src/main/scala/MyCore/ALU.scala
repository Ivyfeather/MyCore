package MyCore

import chisel3._
import chisel3.util._
import Utils._
import Const._

class ALUIO extends MyCoreBundle with ALUop{
    val opcode  = Input(UInt(ALUop_bits))
    val in1     = Input(UInt(xlen.W))
    val in2     = Input(UInt(xlen.W))
    val out     = Output(UInt(xlen.W))
    val zero    = Output(Bool())
}

class ALU extends MyCoreModule with ALUop{
    val io = IO(new ALUIO)

    val add_result = io.in1 +& Mux(isSub(io.opcode), ~io.in2 + 1.U, io.in2)
    val xor_result = io.in1 ^ io.in2
    val or_result  = io.in1 | io.in2
    val and_result = io.in1 & io.in2

    val sltu_result : Bool = ~add_result(xlen)
    val slt_result  : Bool = xor_result(xlen - 1) ^ sltu_result

    // SHIFT
    val shamt = io.in2(4,0).asUInt() //[TODO] consider 64bit
    val sll_result = (io.in1 << shamt)(xlen-1, 0)
    val sra_result = (io.in1.asSInt() >> shamt).asUInt()
    val srl_result = io.in1 >> shamt

    io.out := MuxCase(add_result(xlen-1, 0), Array(
        (io.opcode === ALU_SLTU)    -> ZeroExt(sltu_result, xlen),
        (io.opcode === ALU_SLT)     -> ZeroExt(slt_result,  xlen),
        (io.opcode === ALU_XOR)     -> xor_result,
        (io.opcode === ALU_OR)      -> or_result,
        (io.opcode === ALU_AND)     -> and_result,
        (io.opcode === ALU_SLL)     -> sll_result,
        (io.opcode === ALU_SRA)     -> sra_result,
        (io.opcode === ALU_SRL)     -> srl_result,
        (io.opcode === ALU_COPY1)   -> io.in1
    ))

    io.zero := Mux(io.out === 0.asUInt(xlen.W), true.B, false.B)
}
