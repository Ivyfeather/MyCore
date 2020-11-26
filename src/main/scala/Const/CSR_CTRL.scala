package Const

import chisel3._

object CSR_CTRL {
    val SZ = 3.W
    val X = 0.asUInt(SZ)
    val N = 0.asUInt(SZ)
    val W = 1.asUInt(SZ)
    val S = 2.asUInt(SZ)
    val C = 3.asUInt(SZ)
    val MRET  = 4.asUInt(SZ)
    val ECALL = 5.asUInt(SZ)
    val EBREAK= 6.asUInt(SZ)
    val R = 7.asUInt(SZ)
}

trait CSR_mem_addr {
    val mem_mtime       = 0x41400000.U(64.W)
    val mem_mtimecmp    = 0x41400008.U(64.W)

}