package MyCore

import chisel3._
import chisel3.util._
import Memory._

class Soc extends MyCoreModule {
    val io = IO(new Debug_IO)
    val core = Module(new core)
    val ram  = Module(new AXI_ram)
    val bridge = Module(new AXI_Bridge)

    io := core.io.debug

    bridge.io.clock     := clock
    bridge.io.reset     := reset
    bridge.io.inst_req  := core.io.imem.req.valid

    bridge.io.inst_wr   := core.io.imem.req.bits.wr
    bridge.io.inst_size := core.io.imem.req.bits.msk

}
