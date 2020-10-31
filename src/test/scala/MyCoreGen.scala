package MyCore

//class Top extends core
//class Top extends RegFile

import chisel3._
class Top extends MyCoreModule{
    val io = IO(new RFIO)
    val rf = Module(new RegFile)

    val rs1_addr = RegNext(io.rs1_addr)
    val rs2_addr = RegNext(io.rs2_addr)
    val waddr   = RegNext(io.waddr)
    val wdata   = RegNext(io.wdata)
    val wen     = RegNext(io.wen)

    io.rs1_data := rf.io.rs1_data
    io.rs2_data := rf.io.rs2_data
    rf.io.rs1_addr := rs1_addr
    rf.io.rs2_addr := rs2_addr
    rf.io.waddr := waddr
    rf.io.wdata := wdata
    rf.io.wen   := wen
}

object MyCoreGen extends App{
    chisel3.Driver.execute(args, () => new Top)
}