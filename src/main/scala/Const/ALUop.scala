package Const

import chisel3._

trait ALUop {
    val ALUop_bits = 6.W
    def ALU_X       = "b000000".U
    def ALU_ADD     = "b000000".U
    def ALU_SLT     = "b010001".U
    def ALU_SLTU    = "b010010".U
    def ALU_SUB     = "b010000".U
    def ALU_XOR     = "b000001".U
    def ALU_OR      = "b000010".U
    def ALU_AND     = "b000011".U
    def ALU_SLL     = "b000100".U
    def ALU_SRL     = "b000101".U
    def ALU_SRA     = "b000110".U
    def ALU_COPY1   = "b001000".U

    def ALU_ADDW    = "b100000".U
    def ALU_SUBW    = "b110000".U
    def ALU_SLLW    = "b100100".U
    def ALU_SRLW    = "b100101".U
    def ALU_SRAW    = "b100110".U

    def ALU_DIVUW   = "b111111".U

    def isSub(op: UInt) = op(4)
}
