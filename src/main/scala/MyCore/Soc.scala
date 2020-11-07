package MyCore

import chisel3._
import chisel3.util._
import Memory._

class SocIO extends MyCoreBundle{
    val debug = new Debug_IO
}

class Soc extends MyCoreModule {
    val io = IO(new SocIO)
    val core = Module(new core)
    val ram  = Module(new AXI_ram)
    val bridge = Module(new AXI_Bridge)

    io.debug := core.io.debug

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

// Connecting AXI bridge to ram
    ram.io.clock    := clock
    ram.io.reset    := reset

    ram.io.awid    := bridge.io.awid   
    ram.io.awaddr  := bridge.io.awaddr 
    ram.io.awlen   := bridge.io.awlen  
    ram.io.awsize  := bridge.io.awsize 
    ram.io.awburst := bridge.io.awburst
    ram.io.awlock  := bridge.io.awlock 
    ram.io.awcache := bridge.io.awcache
    ram.io.awprot  := bridge.io.awprot 
    ram.io.awvalid := bridge.io.awvalid
    bridge.io.awready := ram.io.awready
    ram.io.wid     := bridge.io.wid
    ram.io.wdata   := bridge.io.wdata  
    ram.io.wstrb   := bridge.io.wstrb  
    ram.io.wlast   := bridge.io.wlast  
    ram.io.wvalid  := bridge.io.wvalid 
    bridge.io.wready  := ram.io.wready
    bridge.io.bid     := ram.io.bid
    bridge.io.bresp   := ram.io.bresp
    bridge.io.bvalid  := ram.io.bvalid
    ram.io.bready  := bridge.io.bready 
    ram.io.arid    := bridge.io.arid   
    ram.io.araddr  := bridge.io.araddr 
    ram.io.arlen   := bridge.io.arlen  
    ram.io.arsize  := bridge.io.arsize 
    ram.io.arburst := bridge.io.arburst
    ram.io.arlock  := bridge.io.arlock 
    ram.io.arcache := bridge.io.arcache
    ram.io.arprot  := bridge.io.arprot 
    ram.io.arvalid := bridge.io.arvalid
    bridge.io.arready := ram.io.arready
    bridge.io.rid     := ram.io.rid
    bridge.io.rdata   := ram.io.rdata
    bridge.io.rresp   := ram.io.rresp
    bridge.io.rlast   := ram.io.rlast
    bridge.io.rvalid  := ram.io.rvalid
    ram.io.rready  := bridge.io.rready 

}
