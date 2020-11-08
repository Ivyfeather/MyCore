package Const

import chisel3._

trait RISCVconst {
    val RD_MSB  = 11
    val RD_LSB  = 7
    val RS1_MSB = 19
    val RS1_LSB = 15
    val RS2_MSB = 24
    val RS2_LSB = 20

    // Machine generated NOP, XOR x0, x0, x0
    val BUBBLE  = 0x4033.U(32.W)

    val START_ADDR = 0x40000000L
}
   