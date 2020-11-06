package MyCore

import chisel3._

class Pre_to_IF_IO extends MyCoreBundle {
    val PC = Output(UInt(xlen.W))
    val offset = Output(Bool())
}
