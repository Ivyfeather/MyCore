package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

class ID_TOP_IO extends MyCoreBundle{
    val fs      = Flipped(DecoupledIO(new IF_to_ID_IO))
    val es      = DecoupledIO(new ID_TO_EXE_IO)
}

class ID_TOP extends MyCoreModule{
    val io = IO(new ID_TOP_IO)
    io := DontCare

    val from_fs_r = RegEnable(io.fs.bits, 0.U.asTypeOf(new IF_to_ID_IO),
        io.fs.valid && io.fs.ready)

    //[TODO] consider write_read related later
    val ds_ready_go = WireInit(true.B)
    val ds_valid    = RegEnable(io.fs.valid, false.B, io.fs.ready)

    io.fs.ready := !ds_valid || ds_ready_go && io.es.ready
    io.es.valid := ds_valid && ds_ready_go

// ================================================================
    val inst = from_fs_r.inst

    val idu = Module(new IDU)
    idu.io.inst := inst
    io.es.bits.decode := idu.io.ctrl


// ==== RegFile ============================================================

    val rf = Module(new RegFile)
    //[TODO]
    rf.io := DontCare
    rf.io.rs1_addr := inst(RS1_MSB, RS1_LSB)
    rf.io.rs2_addr := inst(RS2_MSB, RS2_LSB)



    //[TEST]
    BoringUtils.addSource(from_fs_r.PC,"debug_pc")
    BoringUtils.addSource(from_fs_r.inst, "debug_inst")

// ==== Branch ============================================================

    val br_taken = Wire(Bool())
    val br_target = Wire(UInt(xlen.W))

    br_taken := false.B
    br_target:= 0.U

    BoringUtils.addSource(br_taken, "br_taken")
    BoringUtils.addSource(br_target, "br_target")
}
