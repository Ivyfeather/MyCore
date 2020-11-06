package Const

import chisel3._

object CSR_CTRL {
    val SZ = 3.W
    val X = 0.asUInt(SZ)
    val N = 0.asUInt(SZ)
    val W = 1.asUInt(SZ)
    val S = 2.asUInt(SZ)
    val C = 3.asUInt(SZ)
    val I = 4.asUInt(SZ)
    val R = 5.asUInt(SZ)
}

trait CSR_addr {
    val MSTATUS = 0x300.U
    val MISA    = 0x301.U
    val MIE     = 0x304.U
    val MTVEC   = 0x305.U
    val MSCRATCH  = 0x340.U
    val MEPC    = 0x341.U
    val MCAUSE  = 0x342.U
    val MTVAL   = 0x343.U
    val MIP     = 0x344.U
    val MVENDORID = 0xf11.U
    val MARCHID = 0xf12.U
    val MIMPID  = 0xf13.U
    val MHARTID = 0xf14.U


}