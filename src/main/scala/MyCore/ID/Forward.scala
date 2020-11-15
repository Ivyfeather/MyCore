package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class ForwardUnitIO extends MyCoreBundle {
    val ctrl     = Input(new ctrlops)
    val rs1_addr = Input(UInt(5.W))
    val rs2_addr = Input(UInt(5.W))
    val ws_res   = Input(new Forwardbus)
    val rs1_data = Output(UInt(xlen.W))
    val rs2_data = Output(UInt(xlen.W))
    val wr_stall = Output(Bool()) // stall caused by write-read related
}

class ForwardUnit extends MyCoreModule {
    val io = IO(new ForwardUnitIO)
    val es_res = WireInit(0.U.asTypeOf(new Forwardbus))
    val ms_res = WireInit(0.U.asTypeOf(new Forwardbus))
    val ws_res = io.ws_res
    BoringUtils.addSink(es_res, "es_res")
    BoringUtils.addSink(ms_res, "ms_res")





// rf
    val rf = Module(new RegFile)
    rf.io.rs1_addr  := io.rs1_addr
    rf.io.rs2_addr  := io.rs2_addr
    rf.io.wen       := io.ws_res.rf_we
    rf.io.waddr     := io.ws_res.wr_addr
    rf.io.wdata     := io.ws_res.wr_data


// Output
    val es_addr1 = es_res.wr_addr === io.rs1_addr
    val es_addr2 = es_res.wr_addr === io.rs2_addr
    val ms_addr1 = ms_res.wr_addr === io.rs1_addr
    val ms_addr2 = ms_res.wr_addr === io.rs2_addr
    val ws_addr1 = ws_res.wr_addr === io.rs1_addr
    val ws_addr2 = ws_res.wr_addr === io.rs2_addr

    io.rs1_data := MuxCase(rf.io.rs1_data, Array(
        (es_res.rf_we && es_addr1 && !is_load) -> es_res.wr_data,
        (ms_res.rf_we && ms_addr1) -> ms_res.wr_data,
        (ws_res.rf_we && ws_addr1) -> ws_res.wr_data
    ))
    io.rs2_data := MuxCase(rf.io.rs2_data, Array(
        (es_res.rf_we && es_addr2 && !is_load) -> es_res.wr_data,
        (ms_res.rf_we && ms_addr2) -> ms_res.wr_data,
        (ws_res.rf_we && ws_addr2) -> ws_res.wr_data
    ))

    val is_load = es_res.wb_sel === WB_MEM
    val load_data_ok = WireInit(false.B)
    BoringUtils.addSink(load_data_ok, "load_data_returned")
    val load_data_not_returned = (es_addr1 || es_addr2) && is_load && !load_data_ok

    val csrr_at_ws = ws_res.wb_sel === WB_CSR
    val is_csrr_es = (es_addr1 || es_addr2) && es_res.wb_sel === WB_CSR && !csrr_at_ws
    val is_csrr_ms = (ms_addr1 || ms_addr2) && ms_res.wb_sel === WB_CSR && !csrr_at_ws

    /* forget about this paragraph
    // in the first case, csrr inst is at es-stage, and ds-stage needs its forwarding data
    //   then we stall until it flows to ws-stage when we can get the data, at this time both es and ms has wbsel===WB_CSR (the same inst in es and ms)
    //   now we expect ds inst to flow to es
    //   []: we dont write as "is_csrr_es || is_csrr_ms", because in this case csrr at es-stage will always be stalled since
    // in the second case, csrr is at ms-stage
     */
    val csrr_stall = is_csrr_es || is_csrr_ms

    //[TODO] assume mem-op always take longer time so that flowline always will stall for load
    io.wr_stall := load_data_not_returned || csrr_stall

}
