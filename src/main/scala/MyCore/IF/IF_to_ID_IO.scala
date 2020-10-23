package MyCore

import chisel3._

class IF_to_ID_IO extends MyCoreBundle{
    val PC      = Output(UInt(xlen.W))
    val inst    = Output(UInt(32.W))
}
