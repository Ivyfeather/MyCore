package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class WB_TOP_IO extends MyCoreBundle {
    val ms  = Flipped(DecoupledIO(new MEM_TO_WB_IO))
    val rf  = new Forwardbus
    val mtip = Input(Bool())
    val meip = Input(Bool())

    val exception = Output(Bool())

    val mepc = Output(UInt(64.W))
    val exc_addr = Output(UInt(64.W))
}

class WB_TOP extends MyCoreModule{
    val io = IO(new WB_TOP_IO)
    io := DontCare

    val from_ms_r   = RegEnable(io.ms.bits, 0.U.asTypeOf(new MEM_TO_WB_IO), io.ms.valid && io.ms.ready)
    val ws_ready_go = WireInit(true.B)
    val ws_valid    = RegEnable(io.ms.valid, false.B, io.ms.ready)

    io.ms.ready := !ws_valid || ws_ready_go
// ================================================================
    val decode = from_ms_r.decode





// ================================================================
    val csrs = Module(new CSR)
    csrs.io.addr    := from_ms_r.csr_addr
    csrs.io.ctrl    := from_ms_r.decode.csr_cmd
    csrs.io.gr_data := from_ms_r.final_result
    csrs.io.pc      := from_ms_r.PC

    val csr_data = csrs.io.csr_data
    // WBstage takes only 1 cycle always(ready_go === true)
    // write into RF will not be affected when IDstage is stalled

    io.rf.wr_addr := from_ms_r.rd_addr
    io.rf.wr_data := Mux(decode.wb_sel === WB_CSR, csr_data, from_ms_r.final_result)
    io.rf.rf_we   := decode.rf_wen
    io.rf.wb_sel  := decode.wb_sel

// ==== for debug ============================================================
    val is_commit = RegInit(false.B)
    when(io.ms.valid && io.ms.ready){
        is_commit := true.B
    }.elsewhen(is_commit){ // last for one cycle
        is_commit := false.B
    }
    io.exception := csrs.io.exception
    io.mepc := csrs.io.mepc
    io.exc_addr := csrs.io.exc_addr
}
