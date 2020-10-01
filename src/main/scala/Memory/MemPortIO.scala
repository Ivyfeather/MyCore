package Memory

import MyCore.MyCoreBundle
import chisel3._
import chisel3.util._

class MemPortIO(val data_width: Int) extends MyCoreBundle {
    val req     = new DecoupledIO(new MemReq(data_width))
    val resp    = Flipped(new DecoupledIO(new MemResp(data_width)))
}

class MemReq(val data_width: Int) extends MyCoreBundle {
    val addr = Output(UInt(32.W))//[TODO] 32/39 bit addr space
    val data = Output(UInt(data_width.W))
    val fcn  = Output(Bool())
    val msk  = Output(UInt(MTT_bits))
}

class MemResp(val data_width: Int) extends MyCoreBundle {
    val data = Output(UInt(data_width.W))
}
