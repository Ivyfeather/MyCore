package MyCore

import chisel3._

class EXE_TO_MEM_IO extends MyCoreBundle {
    val PC          = Output(UInt(xlen.W))
    val decode      = Output(new ctrlops)
    val alu_result  = Output(UInt(xlen.W))
    val rd_addr     = Output(UInt(5.W))
    val load_offset = Output(UInt(3.W))
}
