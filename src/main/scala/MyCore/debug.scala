package MyCore

import chisel3._
import chisel3.util._
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
    val rf      = Output(Vec(32, UInt(xlen.W)))
    val PC      = Output(UInt(xlen.W))
    val valid   = Output(Bool())
    val trap    = Output(Bool())

    //[TEST]
    val test    = Output(UInt(xlen.W))
}

object MyCoreTrap{
    def TRAP = BitPat("b????????????_?????_000_?????_1101011")
}