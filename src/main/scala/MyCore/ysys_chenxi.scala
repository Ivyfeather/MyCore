package MyCore

import Memory.{AXI_Bridge, AXI_Interface, AXI_lite_interface}
import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class ysys_chenxi_IO extends MyCoreBundle {
    val mem  = Flipped(new AXI_Interface)
    val mmio = Flipped(new AXI_lite_interface)
    val mtip = Input(Bool())
    val meip = Input(Bool())
}

class ysys_chenxi extends MyCoreModule {
    val io = IO(new ysys_chenxi_IO)

    val core = Module(new core)
    val bridge = Module(new AXI_Bridge)
    core.io.mtip := io.mtip
    core.io.meip := io.meip

    // Connecting core to AXI bridge
    bridge.io.clock     := clock
    bridge.io.reset     := reset

    val ireq  = core.io.imem.req
    bridge.io.inst_req  := ireq.valid
    bridge.io.inst_wr   := ireq.bits.wr
    bridge.io.inst_size := ireq.bits.msk
    bridge.io.inst_addr := ireq.bits.addr
    bridge.io.inst_wdata:= ireq.bits.data
    ireq.ready := bridge.io.inst_addr_ok
    val iresp = core.io.imem.resp
    iresp.valid     := bridge.io.inst_data_ok
    iresp.bits.data := bridge.io.inst_rdata

    val dreq  = core.io.dmem.req
    bridge.io.data_req  := dreq.valid
    bridge.io.data_wr   := dreq.bits.wr
    bridge.io.data_size := dreq.bits.msk
    bridge.io.data_addr := dreq.bits.addr
    bridge.io.data_wdata:= dreq.bits.data
    dreq.ready := bridge.io.data_addr_ok
    val dresp = core.io.dmem.resp
    dresp.valid     := bridge.io.data_data_ok
    dresp.bits.data := bridge.io.data_rdata


// Connecting AXI bridge to MMIO and RAM
    // to mem
    val is_mem_raddr = (bridge.io.araddr >= "h8000_0000".U)
    val is_mem_waddr = (bridge.io.awaddr >= "h8000_0000".U)

    io.mem.awid := bridge.io.awid
    io.mem.awaddr := bridge.io.awaddr
    io.mem.awlen := bridge.io.awlen
    io.mem.awsize := bridge.io.awsize
    io.mem.awburst := bridge.io.awburst
    io.mem.awlock := bridge.io.awlock
    io.mem.awcache := bridge.io.awcache
    io.mem.awprot := bridge.io.awprot
    io.mem.awvalid := Mux(is_mem_waddr, bridge.io.awvalid, false.B)

    io.mem.wid := bridge.io.wid
    io.mem.wdata := bridge.io.wdata
    io.mem.wstrb := bridge.io.wstrb
    io.mem.wlast := bridge.io.wlast
    io.mem.wvalid := Mux(is_mem_waddr, bridge.io.wvalid, false.B)

    io.mem.bready := bridge.io.bready
    io.mem.arid := bridge.io.arid
    io.mem.araddr := bridge.io.araddr
    io.mem.arlen := bridge.io.arlen
    io.mem.arsize := bridge.io.arsize
    io.mem.arburst := bridge.io.arburst
    io.mem.arlock := bridge.io.arlock
    io.mem.arcache := bridge.io.arcache
    io.mem.arprot := bridge.io.arprot
    io.mem.arvalid := Mux(is_mem_raddr, bridge.io.arvalid, false.B)
    io.mem.rready := bridge.io.rready

    // to mmio
    io.mmio.awaddr  := bridge.io.awaddr
    io.mmio.awprot  := bridge.io.awprot
    io.mmio.awvalid := Mux(is_mem_waddr, false.B, bridge.io.awvalid)
    io.mmio.wdata   := bridge.io.wdata
    io.mmio.wstrb   := bridge.io.wstrb
    io.mmio.wvalid  := Mux(is_mem_waddr, false.B, bridge.io.wvalid)
    io.mmio.bready  := bridge.io.bready
    io.mmio.araddr  := bridge.io.araddr
    io.mmio.arprot  := bridge.io.arprot
    io.mmio.arvalid := Mux(is_mem_raddr, false.B, bridge.io.arvalid)
    io.mmio.rready  := bridge.io.rready

    // from mem and mmio
    bridge.io.bid := io.mem.bid
    bridge.io.rid := io.mem.rid
    bridge.io.rlast := io.mem.rlast

    bridge.io.awready := io.mem.awready | io.mmio.awready
    bridge.io.wready := io.mem.wready   | io.mmio.wready
    bridge.io.bresp := io.mem.bresp     | io.mmio.bresp
    bridge.io.bvalid := io.mem.bvalid   | io.mmio.bvalid
    bridge.io.arready := io.mem.arready | io.mmio.arready
    bridge.io.rdata := Mux(io.mem.rvalid, io.mem.rdata, io.mmio.rdata)
    bridge.io.rresp := io.mem.rresp     | io.mmio.rresp
    bridge.io.rvalid := io.mem.rvalid   | io.mmio.rvalid

}