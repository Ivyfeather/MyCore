package MyCore

import chisel3._

class WBbus extends MyCoreBundle {
    val rf_we   = Output(Bool())
    val rf_addr = Output(UInt(5.W))
    val rf_data = Output(UInt(xlen.W))
}
