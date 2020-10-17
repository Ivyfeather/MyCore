package MyCore

import chisel3._
import Const._

class Debug_IO extends MyCoreBundle {
    /*
    val wen     = Output(Bool())
    val waddr   = Output(UInt(5.W))
    val wdata   = Output(UInt(xlen.W))
    val PC      = Output(UInt(xlen.W))

    val stall   = Output(Bool())
     */

    //[TEST] GPRs only for now
    val difftest_r  = Output(Vec(32, UInt(xlen.W)))
    val PC          = Output(UInt(xlen.W))
    val stall       = Output(Bool())
}
