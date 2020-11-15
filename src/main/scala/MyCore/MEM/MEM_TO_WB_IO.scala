package MyCore

import chisel3._

class MEM_TO_WB_IO extends MyCoreBundle {
    val PC          = Output(UInt(xlen.W))
    val decode      = Output(new ctrlops)
    val final_result= Output(UInt(xlen.W))
    val rd_addr     = Output(UInt(5.W))
    val csr_addr    = Output(UInt(12.W))
}

