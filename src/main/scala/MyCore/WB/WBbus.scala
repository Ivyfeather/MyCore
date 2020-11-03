package MyCore

import chisel3._

class WBbus extends MyCoreBundle {
    val rf_we   = Output(Bool())
    val wr_addr = Output(UInt(5.W))
    val wr_data = Output(UInt(xlen.W))
}

class Forwardbus extends WBbus{
    val wb_sel = Output(UInt(WBsel_bits))
}