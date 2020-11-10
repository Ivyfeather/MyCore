package MyCore

import Memory.MemPortIO
import Utils.{SignExt, ZeroExt}
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

    val from_es_r = RegEnable(io.es.bits, 0.U.asTypeOf(new EXE_TO_MEM_IO), io.es.valid && io.es.ready)
    val ms_ready_go = Wire(Bool())
    val ms_valid = RegEnable(io.es.valid, false.B, io.es.ready)

    io.es.ready := !ms_valid || ms_ready_go && io.ws.ready;
    io.ws.valid := ms_valid && ms_ready_go
    // ================================================================
    val decode = from_es_r.decode
    val res_from_mem = (decode.wb_sel === WB_MEM).asBool()
    // ==== Dmem ============================================================
    //[TODO] logic from myCPU:MEM_stage.v: 133
    // if we see in waveform that unfinished_store is always 0, then can simply this logic
    val unfinished_store = RegInit(0.U(4.W))
    when(decode.mem_wr && ms_valid && io.dmem.resp.valid){

    }.elsewhen(decode.mem_wr && ms_valid) {
        unfinished_store := unfinished_store + 1.U
        decode.mem_wr    := false.B
    }.elsewhen(io.dmem.resp.valid && unfinished_store > 0.U){
        unfinished_store := unfinished_store - 1.U
    }
    ms_ready_go := Mux(unfinished_store =/= 0.U,                                        false.B,
                   Mux(res_from_mem && unfinished_store === 0.U && !io.dmem.resp.valid, false.B,
                                                                                        true.B))


// ==== To ws ============================================================
    val data = (io.dmem.resp.bits.data >> (from_es_r.load_offset << 3.U).asUInt()).asUInt()
    val byte = Wire(UInt(8.W))
    byte := data & "h_ff".U
    val half = Wire(UInt(16.W))
    half := data & "h_ffff".U
    val word = Wire(UInt(32.W))
    word := data & "h_ffff_ffff".U

    val load_final = MuxCase(io.dmem.resp.bits.data, Array(
        (decode.mem_msk === MT_B)    -> SignExt(byte, xlen),
        (decode.mem_msk === MT_BU)   -> ZeroExt(byte, xlen),
        (decode.mem_msk === MT_H)    -> SignExt(half, xlen),
        (decode.mem_msk === MT_HU)   -> ZeroExt(half, xlen),
        (decode.mem_msk === MT_W)    -> SignExt(word, xlen),
        (decode.mem_msk === MT_WU)   -> ZeroExt(word, xlen)
    ))
    val load_final_reg = RegEnable(load_final, 0.U, io.dmem.resp.valid)

    io.ws.bits.PC           := from_es_r.PC
    io.ws.bits.decode       := decode
    io.ws.bits.final_result := Mux(res_from_mem, load_final, from_es_r.alu_result)
    io.ws.bits.rd_addr      := from_es_r.rd_addr

// ==== Forward ============================================================
    val ms_res = Wire(new Forwardbus)
    ms_res.wb_sel   := from_es_r.decode.wb_sel
    ms_res.rf_we    := from_es_r.decode.rf_wen
    ms_res.wr_addr  := io.ws.bits.rd_addr
    ms_res.wr_data  := io.ws.bits.final_result
    BoringUtils.addSource(ms_res, "ms_res")
    BoringUtils.addSource(io.dmem.resp.valid, "load_data_returned")
}
