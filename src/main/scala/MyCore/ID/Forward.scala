package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class ForwardUnitIO extends MyCoreBundle {
    val ctrl     = Input(new ctrlops)
    val rs1_addr = Input(UInt(5.W))
    val rs2_addr = Input(UInt(5.W))
    val ws_res   = Input(new WBbus)
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

    val is_load = es_res.wb_sel === WB_MEM
    //[TODO] forward from csr
    io.rs1_data := MuxCase(rf.io.rs1_data, Array(
        (es_res.rf_we && es_res.wr_addr === io.rs1_addr && !is_load) -> es_res.wr_data,
        (ms_res.rf_we && ms_res.wr_addr === io.rs1_addr) -> ms_res.wr_data,
        (ws_res.rf_we && ws_res.wr_addr === io.rs1_addr) -> ws_res.wr_data
    ))
    io.rs2_data := MuxCase(rf.io.rs2_data, Array(
        (es_res.rf_we && es_res.wr_addr === io.rs2_addr && !is_load) -> es_res.wr_data,
        (ms_res.rf_we && ms_res.wr_addr === io.rs2_addr) -> ms_res.wr_data,
        (ws_res.rf_we && ws_res.wr_addr === io.rs2_addr) -> ws_res.wr_data
    ))
    val load_data_ok = WireInit(false.B)
    BoringUtils.addSink(load_data_ok, "load_data_returned")

    //[TODO] ??
    io.wr_stall := (es_res.wr_addr === io.rs1_addr || es_res.wr_addr === io.rs2_addr) && is_load && !load_data_ok


}
