package Memory

import MyCore.{MyCoreBundle, MyCoreModule}
import chisel3._
import chisel3.util._
import Utils._

class MemMaskIO(val data_width: Int) extends MyCoreBundle{
    val from_core = Flipped(new MemPortIO(data_width))
    val to_ram = new MemPortIO(data_width)
}

class MemMask(val data_width: Int) extends MyCoreModule{
    val io = IO(new MemMaskIO(data_width))
    io.to_ram <> io.from_core

    val offset = ((io.to_ram.req.bits.addr % 8.U) << 3.U).asUInt()
    val data = (io.to_ram.resp.bits.data >> offset).asUInt()

    val byte = Wire(UInt(8.W))
    byte := data & "h_ff".U
    val half = Wire(UInt(16.W))
    half := data & "h_ffff".U
    val word = Wire(UInt(32.W))
    word := data & "h_ffff_ffff".U

    if(xlen == 64) { //scala if
        io.to_ram.req.bits.addr := Cat(io.from_core.req.bits.addr(xlen-1, 3), Fill(3, 0.U))
        io.from_core.resp.bits.data := MuxCase(io.to_ram.resp.bits.data, Array(
            (io.from_core.req.bits.msk === MT_B)    -> SignExt(byte, xlen),
            (io.from_core.req.bits.msk === MT_BU)   -> ZeroExt(byte, xlen),
            (io.from_core.req.bits.msk === MT_H)    -> SignExt(half, xlen),
            (io.from_core.req.bits.msk === MT_HU)   -> ZeroExt(half, xlen),
            (io.from_core.req.bits.msk === MT_W)    -> SignExt(word, xlen),
            (io.from_core.req.bits.msk === MT_WU)   -> ZeroExt(word, xlen)
        ))
    }else{ // RV32

    }
}
