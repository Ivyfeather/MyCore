package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class WB_TOP_IO extends MyCoreBundle {
    val ms  = Flipped(DecoupledIO(new MEM_TO_WB_IO))
    val rf  = new WBbus
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
    io.rf.wr_addr := from_ms_r.rd_addr
    io.rf.wr_data := from_ms_r.final_result
    io.rf.rf_we   := decode.rf_wen

    val is_commit = RegInit(false.B)
//    when(io.ms.valid && io.ms.ready){
//        is_commit := RegNext(from_ms_r.PC =/= 0.U)
//    }.elsewhen(is_commit){ // last for one cycle
//        is_commit := false.B
//    }
    when(io.ms.valid && io.ms.ready){
        is_commit := true.B
    }.elsewhen(is_commit){ // last for one cycle
        is_commit := false.B
    }

    BoringUtils.addSource( RegNext(Mux(is_commit, from_ms_r.PC =/= 0.U, false.B)), "is_valid")
    BoringUtils.addSource( RegNext(from_ms_r.PC), "debug_pc")
// ================================================================
    val csrs = Module(new CSR)
    csrs.io := DontCare

}
