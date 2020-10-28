package MyCore

import chisel3._

class ID_TO_EXE_IO extends MyCoreBundle {
    val PC = Output(UInt(xlen.W))
    val inst = Output(UInt(32.W))
    val decode = Output(new ctrlops)
    val rs1_data = Output(UInt(xlen.W))
    val rs2_data = Output(UInt(xlen.W))
}
