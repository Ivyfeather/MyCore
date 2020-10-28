package MyCore

import Memory.MemPortIO
import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class MEM_TOP_IO extends MyCoreBundle{
    val es      = Flipped(DecoupledIO(new EXE_TO_MEM_IO))
    val ws      = DecoupledIO(new MEM_TO_WB_IO)
    val dmem    = new MemPortIO(xlen)
}

class MEM_TOP extends MyCoreModule {
    val io = IO(new MEM_TOP_IO)
    io := DontCare

    val from_es_r   = RegEnable(io.es.bits, 0.U.asTypeOf(new EXE_TO_MEM_IO), io.es.valid && io.es.ready)
    val ms_ready_go = Wire(Bool())
    val ms_valid    = RegEnable(io.es.valid, false.B, io.es.ready)

    io.es.ready     := !ms_valid || ms_ready_go && io.ws.ready;
    io.ws.valid     := ms_valid && ms_ready_go
// ================================================================
    val decode = from_es_r.decode
    val res_from_mem = (decode.wb_sel == WB_MEM).asBool()
// ==== Dmem ============================================================
    //[TODO] logic from myCPU:MEM_stage.v: 133
    // if we see in waveform that unfinished_store is always 0, then can simply this logic
    val unfinished_store = RegInit(0.U(4.W))
    when(decode.mem_wr && ms_valid) {
        unfinished_store := unfinished_store + 1.U
    }.elsewhen(io.dmem.resp.valid && unfinished_store > 0.U){
        unfinished_store := unfinished_store - 1.U
    }
    ms_ready_go := Mux(unfinished_store =/= 0.U,                                        false.B,
                   Mux(res_from_mem && unfinished_store === 0.U && !io.dmem.resp.valid, false.B,
                                                                                        true.B))


// ==== To ws ============================================================
    io.ws.bits.PC           := from_es_r.PC
    io.ws.bits.decode       := decode
    io.ws.bits.final_result := Mux(res_from_mem, io.dmem.resp.bits.data, from_es_r.alu_result)
    io.ws.bits.rd_addr      := from_es_r.rd_addr


}
