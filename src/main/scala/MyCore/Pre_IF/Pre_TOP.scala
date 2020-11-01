package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import Memory.MemPortIO

class Pre_TOP_IO extends MyCoreBundle {
    val fs   = DecoupledIO(new Pre_to_IF_IO)
    val imem    = new MemPortIO(32)
}

class Pre_TOP extends MyCoreModule {
    val io = IO(new Pre_TOP_IO)
    //[TODO] Dontcare
    io := DontCare

    //-- ready_go: whether this module finishes its own task
    val pre_ready_go    = RegInit(false.B)
    when(io.imem.req.ready)                    { pre_ready_go := true.B  }
    .elsewhen(io.fs.ready && io.fs.valid)      { pre_ready_go := false.B }

    //-- valid:    whether it receives valid data from upstream module
    val pre_valid       = RegInit(true.B)

    io.fs.valid := pre_valid && pre_ready_go

// ================================================================
    // trick: to make nextpc be START_ADDR during reset
    val nextpc  = Wire(UInt(xlen.W))
    val pre_pc  = RegEnable(nextpc, (START_ADDR - 4).asUInt(xlen.W), io.imem.req.ready) //[TODO]
    val seq_pc  = pre_pc + 4.U

    // require inst
    val imem_req_r = RegInit(false.B)
    when(io.imem.req.ready) { // addr accepted, send req no more
        imem_req_r := false.B
    }.elsewhen(io.fs.ready){// if ready to accept, so pre send another req
        imem_req_r := true.B
    }

    io.imem.req.valid       := imem_req_r
    io.imem.req.bits.addr   := nextpc
    io.imem.req.bits.data   := 0.U
    io.imem.req.bits.wr     := false.B
    io.imem.req.bits.msk    := MT_WU

    // next pc
    val br_taken  = WireInit(Bool(), false.B)
    val br_target = WireInit(UInt(xlen.W), 0.U)

    BoringUtils.addSink(br_taken, "br_taken")
    BoringUtils.addSink(br_target,"br_target")

    // use reg to store br_target
    val buf_valid = RegInit(false.B)
    when(buf_valid && io.imem.req.ready)    { buf_valid := false.B }
    .elsewhen(br_taken)                     { buf_valid := true.B}

    val buf_npc = RegEnable(br_target, 0.U(xlen.W), br_taken)

    nextpc := MuxCase(seq_pc, Array(
        (buf_valid) -> buf_npc
    ))

    //[TODO] check
    io.fs.bits.PC := pre_pc
}
