package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import Memory.MemPortIO

class IF_TOP_IO extends MyCoreBundle {
    val pres    = Flipped(DecoupledIO(new Pre_to_IF_IO))
    val ds      = DecoupledIO(new IF_to_ID_IO)
    val imem    = new MemPortIO(xlen)
}

class IF_TOP extends MyCoreModule {
    val io = IO(new IF_TOP_IO)
    io := DontCare

    // RegEnable(next, init, enable)
    val from_pre_r = RegEnable(io.pres.bits, 0.U.asTypeOf(new Pre_to_IF_IO), io.pres.valid && io.pres.ready)

    //-- ready_go: whether this module finishes its own task
    val fs_ready_go    = RegInit(false.B)
    when(io.imem.resp.valid)                    { fs_ready_go := true.B }
    .elsewhen(io.ds.ready && io.ds.valid)       { fs_ready_go := false.B }

    //-- valid:    whether it receives valid data from upstream module
    val fs_valid       = RegEnable(io.pres.valid, false.B, io.pres.ready)

    // if has not received valid data from upstream |or| can pass data downstream, then signal upstream ready
    io.pres.ready := !fs_valid || fs_ready_go && io.ds.ready
    // if gets valid data and finishes its task, signal downstream valid
    io.ds.valid    := fs_valid && fs_ready_go

// ==== To ds ===========================================================
    val inst_off = Mux(from_pre_r.offset, io.imem.resp.bits.data(xlen-1, 32), io.imem.resp.bits.data(31, 0))
    io.ds.bits.inst := RegEnable(inst_off, 0.U, io.imem.resp.valid)
    io.ds.bits.PC := from_pre_r.PC
}
