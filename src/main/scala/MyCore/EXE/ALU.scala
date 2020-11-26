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

    val add2       = Mux(isSub(io.opcode), (~io.in2).asUInt(), io.in2)
    val cin        = Mux(isSub(io.opcode), 1.U, 0.U)
    val add_result = io.in1 +& add2 +& cin
    val xor_result = io.in1 ^ io.in2
    val or_result  = io.in1 | io.in2
    val and_result = io.in1 & io.in2

    val sltu_result : Bool = ~add_result(xlen)
    val slt_result  : Bool = xor_result(xlen - 1) ^ sltu_result

    // SHIFT
    val shamt = if(xlen==64) io.in2(5,0).asUInt() else io.in2(4,0).asUInt()
    val sll_result = (io.in1 << shamt)(xlen-1, 0)
    val sra_result = (io.in1.asSInt() >> shamt).asUInt()
    val srl_result = io.in1 >> shamt

    val shamt5 = io.in2(4,0).asUInt()
    val sllw_result = (io.in1 << shamt5)(31, 0)
    val sraw_result = (io.in1(31,0).asSInt() >> shamt5).asUInt()
    val srlw_result = io.in1(31,0) >> shamt5

//    val divuw_result = io.in1(31,0).asUInt() / io.in2(31,0).asUInt()
//    val remuw_result = io.in1(31,0).asUInt() % io.in2(31,0).asUInt()

    io.out := MuxCase(add_result(xlen-1, 0), Array(
        (io.opcode === ALU_SLTU)    -> ZeroExt(sltu_result, xlen),
        (io.opcode === ALU_SLT)     -> ZeroExt(slt_result,  xlen),
        (io.opcode === ALU_XOR)     -> xor_result,
        (io.opcode === ALU_OR)      -> or_result,
        (io.opcode === ALU_AND)     -> and_result,
        (io.opcode === ALU_SLL)     -> sll_result,
        (io.opcode === ALU_SRA)     -> sra_result,
        (io.opcode === ALU_SRL)     -> srl_result,
        (io.opcode === ALU_COPY1)   -> io.in1,
        (io.opcode === ALU_ADDW)    -> SignExt(add_result(31,0), xlen),
        (io.opcode === ALU_SUBW)    -> SignExt(add_result(31,0), xlen),
        (io.opcode === ALU_SLLW)    -> SignExt(sllw_result(31,0), xlen),
        (io.opcode === ALU_SRAW)    -> SignExt(sraw_result(31,0), xlen),
        (io.opcode === ALU_SRLW)    -> SignExt(srlw_result(31,0), xlen)//,
//        (io.opcode === ALU_DIVUW)   -> SignExt(divuw_result(31,0), xlen),
//        (io.opcode === ALU_REMUW)   -> SignExt(remuw_result(31,0), xlen)
    ))

    io.zero := Mux(io.out === 0.asUInt(xlen.W), true.B, false.B)
}
