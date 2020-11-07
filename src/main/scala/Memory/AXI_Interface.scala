package Memory

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class AXI_Interface extends Bundle {
    private val data_width = 64
    private val addr_width = 64
    private val wstrb_width = data_width/8
    private val id_width = 8

    val awid    = Input(UInt(id_width.W))
    val awaddr  = Input(UInt(addr_width.W))
    val awlen   = Input(UInt(8.W))
    val awsize  = Input(UInt(3.W))
    val awburst = Input(UInt(2.W))
    val awlock  = Input(Bool())
    val awcache = Input(UInt(4.W))
    val awprot  = Input(UInt(3.W))
    val awvalid = Input(Bool())
    val awready = Output(Bool())
    val wid    = Input(UInt(id_width.W))
    val wdata   = Input(UInt(data_width.W))
    val wstrb   = Input(UInt(wstrb_width.W))
    val wlast   = Input(Bool())
    val wvalid  = Input(Bool())
    val wready  = Output(Bool())
    val bid     = Output(UInt(id_width.W))
    val bresp   = Output(UInt(2.W))
    val bvalid  = Output(Bool())
    val bready  = Input(Bool())
    val arid    = Input(UInt(id_width.W))
    val araddr  = Input(UInt(addr_width.W))
    val arlen   = Input(UInt(8.W))
    val arsize  = Input(UInt(3.W))
    val arburst = Input(UInt(2.W))
    val arlock  = Input(Bool())
    val arcache = Input(UInt(4.W))
    val arprot  = Input(UInt(3.W))
    val arvalid = Input(Bool())
    val arready = Output(Bool())
    val rid     = Output(UInt(id_width.W))
    val rdata   = Output(UInt(data_width.W))
    val rresp   = Output(UInt(2.W))
    val rlast   = Output(Bool())
    val rvalid  = Output(Bool())
    val rready  = Input(Bool())
}

class AXI_lite_interface extends Bundle {
    private val data_width = 64
    private val addr_width = 64 // 1 Megabyte should be enough for us
    private val wstrb_width = data_width / 8

    val awaddr  = Input(UInt(addr_width.W))
    val awprot  = Input(UInt(3.W))
    val awvalid = Input(Bool())
    val awready = Output(Bool())
    val wdata   = Input(UInt(data_width.W))
    val wstrb   = Input(UInt(wstrb_width.W))
    val wvalid  = Input(Bool())
    val wready  = Output(Bool())
    val bresp   = Output(UInt(2.W))
    val bvalid  = Output(Bool())
    val bready  = Input(Bool())
    val araddr  = Input(UInt(addr_width.W))
    val arprot  = Input(UInt(3.W))
    val arvalid = Input(Bool())
    val arready = Output(Bool())
    val rdata   = Output(UInt(data_width.W))
    val rresp   = Output(UInt(2.W))
    val rvalid  = Output(Bool())
    val rready  = Input(Bool())
}



