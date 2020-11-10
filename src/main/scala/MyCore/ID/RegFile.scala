package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class RFIO extends MyCoreBundle {
    val rs1_addr = Input(UInt(5.W))
    val rs1_data = Output(UInt(xlen.W))
    val rs2_addr = Input(UInt(5.W))
    val rs2_data = Output(UInt(xlen.W))

    val waddr   = Input(UInt(5.W))
    val wdata   = Input(UInt(xlen.W))
    val wen     = Input(Bool())
}

class RegFile extends MyCoreModule {
    val io = IO(new RFIO)
    val regfile = Mem(32, UInt(xlen.W))

    when(io.wen){   regfile(io.waddr):= io.wdata }
    io.rs1_data := Mux((io.rs1_addr =/= 0.U), regfile(io.rs1_addr), 0.U)
    io.rs2_data := Mux((io.rs2_addr =/= 0.U), regfile(io.rs2_addr), 0.U)

    // !caution! regfile[0] reads 0 from RFIO, but its content is not 0
    BoringUtils.addSource(VecInit((0 to 31).map(i => regfile(i))), "difftest_r")
}