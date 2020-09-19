package MyCore

import chisel3._
import chisel3.util._
import utils._

trait ALUop{
    val ALUop_bits = 6
    def ALU_X   = BitPat("b000000")
    def ADD     = BitPat("b000000")
    def SLT     = BitPat("b010001")
    def SLTU    = BitPat("b010010")
    def XOR     = BitPat("b000001")
    def OR      = BitPat("b000010")
    def AND     = BitPat("b000011")
    def SLL     = BitPat("b000100")
    def SRL     = BitPat("b000101")
    def SRA     = BitPat("b000110")
    def SUB     = BitPat("b010000")

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
                    SLT         -> ZeroExt(sltu_result, xlen),
                    SLT         -> ZeroExt(slt_result, xlen),
                    XOR         -> xor_result,
                    OR          -> or_result,
                    AND         -> and_result
                    
                    ))

    printf("in1:%d in2:%d opcode:%x out:%d\n", io.in1, io.in2, io.opcode, io.out)
}
