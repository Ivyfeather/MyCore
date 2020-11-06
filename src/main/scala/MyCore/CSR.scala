package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import Const.CSR_CTRL

class CSRIO extends MyCoreBundle{
    val addr = Input(UInt(12.W))
    val ctrl = Input(UInt(CSR_CTRL.SZ))
    val gr_data  = Input(UInt(xlen.W))
    val csr_data = Output(UInt(xlen.W))

}


class mstatus extends Bundle{

}

class CSR extends MyCoreModule{
    val io = IO(new CSRIO)
    io := DontCare

    val misa = new Bundle{
        val MXL  = 2.U(2.W)
        val WLRL = 0.U(36.W)
        val Ext  = "h100".U(26.W) // RV64I alone
    }


    //[TEST][TODO]
//    BoringUtils.addSource(misa, "misa")
}
