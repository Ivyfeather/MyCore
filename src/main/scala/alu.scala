package MyCore

import chisel3._
import chisel3.util._
import utils._

trait ALUop{
    val ALUop_bits = 6
    def ALU_X       = "b000000".U
    def ALU_ADD     = "b000000".U
    def ALU_SLT     = "b010001".U
    def ALU_SLTU    = "b010010".U
    def ALU_XOR     = "b000001".U
    def ALU_OR      = "b000010".U
    def ALU_AND     = "b000011".U
    def ALU_SLL     = "b000100".U
    def ALU_SRL     = "b000101".U
    def ALU_SRA     = "b000110".U
    def ALU_SUB     = "b010000".U
    def ALU_COPY1   = "b001000".U

    def isSub(op: UInt) = op(4)
}

class ALUIO extends MyCoreBundle with ALUop{
    val opcode = Input(UInt(ALUop_bits.W))
    val in1 = Input(UInt(xlen.W))
    val in2 = Input(UInt(xlen.W))
    val out = Output(UInt(xlen.W))
}

class ALU extends MyCoreModule with ALUop{
    val io = IO(new ALUIO)

    val add_result = io.in1 +& Mux(isSub(io.opcode), ~io.in2 + 1.U, io.in2) 
    val xor_result = io.in1 ^ io.in2
    val or_result  = io.in1 | io.in2 
    val and_result = io.in1 & io.in2

    val sltu_result= ~add_result(xlen)
    val slt_result = xor_result(xlen - 1) ^ sltu_result

    // SHIFT
    val shamt = io.in2(4,0).asUInt()


    io.out := Lookup(io.opcode,    add_result(xlen-1, 0),//test
            Array(  
                    BitPat.apply(ALU_SLTU)   -> ZeroExt(sltu_result, xlen),
                    BitPat.apply(ALU_SLT)    -> ZeroExt(slt_result, xlen),
                    BitPat.apply(ALU_XOR)    -> xor_result,
                    BitPat.apply(ALU_OR)     -> or_result,
                    BitPat.apply(ALU_AND)    -> and_result,
                    BitPat.apply(ALU_COPY1)  -> io.in1
                    ))

    printf("in1:%d in2:%d opcode:%x out:%d\n", io.in1, io.in2, io.opcode, io.out)
}
