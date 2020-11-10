package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import Memory.MemPortIO

class Pre_TOP_IO extends MyCoreBundle {
    val fs   = DecoupledIO(new Pre_to_IF_IO)
    val imem    = new MemPortIO(xlen)
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
    val imem_req_r = RegInit(true.B)
    when(io.imem.req.ready) { // addr accepted, send req no more
        imem_req_r := false.B
    }.elsewhen(io.fs.ready){// if ready to accept, so pre send another req
        imem_req_r := true.B
    }

    io.imem.req.valid       := imem_req_r
    io.imem.req.bits.addr   := Mux(nextpc >= "h8000_0000".U, nextpc & "hFFFF_FFFF_FFFF_FFF8".U, nextpc)
    io.imem.req.bits.data   := 0.U
    io.imem.req.bits.wr     := false.B
    io.imem.req.bits.msk    := "hFF".U

    // next pc
    val br_taken  = WireInit(Bool(), false.B)
    val br_target = WireInit(UInt(xlen.W), 0.U)
    val br_old_PC = WireInit(UInt(xlen.W), 0.U)
    BoringUtils.addSink(br_taken, "br_taken")
    BoringUtils.addSink(br_target,"br_target")
    BoringUtils.addSink(br_old_PC, "br_old_PC")

    // #insts that are sent to imem after branch
    val insts_sent_after_br = WireInit(UInt(2.W), 0.U)
    val diff = ((nextpc - br_old_PC)>> 2.U ).asUInt()
    insts_sent_after_br := Mux(io.imem.req.ready, diff, //如果当拍imem接受了
                           Mux(diff>0.U, diff-1.U, 0.U))
    BoringUtils.addSource(insts_sent_after_br, "insts_sent_after_br")


    // use reg to store br_target
    val buf_valid = RegInit(false.B)
    val buf_npc = RegEnable(br_target, 0.U(xlen.W), br_taken)

    when(buf_valid && io.imem.req.ready)    { buf_valid := false.B }
    .elsewhen(buf_npc === br_target)        { }
    .elsewhen(br_taken)                     { buf_valid := true.B}


    nextpc := MuxCase(seq_pc, Array(
        (buf_valid) -> buf_npc
    ))

    //[TODO] check
    io.fs.bits.PC := pre_pc
    io.fs.bits.offset := pre_pc(2)
}
