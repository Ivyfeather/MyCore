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

//[TODO] consider write/read protection later
trait ADDR_CSRS{
    val ADDR_MSTATUS = 0x300.U
    val ADDR_MIE     = 0x304.U
    val ADDR_MTVEC   = 0x305.U
    val ADDR_MSCRATCH= 0x340.U
    val ADDR_MEPC    = 0x341.U
    val ADDR_MCAUSE  = 0x342.U
    val ADDR_MTVAL   = 0x343.U
    val ADDR_MIP     = 0x344.U
}

class Mtvec extends Bundle{
    val base = UInt(62.W)
    val mode = UInt(2.W)
}
class Mstatus extends Bundle{
    val notused_0 = UInt(56.W)
    val MPIE = UInt(1.W)
    val notused_1 = UInt(3.W)
    val MIE = UInt(1.W)
    val notused_2 = UInt(3.W)
}
class Mcause extends Bundle{
    val interrupt = UInt(1.W)
    val exc_code  = UInt(63.W)
}

class CSR extends MyCoreModule with ADDR_CSRS {
    val io = IO(new CSRIO)
    io := DontCare

    val write_csr_data = WireInit(UInt(xlen.W))
    val read_csr_data = WireInit(UInt(xlen.W))

    val mstatus = RegEnable(write_csr_data, 0.U.asTypeOf(new Mstatus),  io.addr === ADDR_MSTATUS)
    val mie     = RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MIE)
    val mtvec   = RegEnable(write_csr_data, 0.U.asTypeOf(new Mtvec),    io.addr === ADDR_MTVEC)
    val mscratch= RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MSCRATCH)
    val mepc    = RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MEPC)
    val mcause  = RegEnable(write_csr_data, 0.U.asTypeOf(new Mcause),   io.addr === ADDR_MCAUSE)
    val mtval   = RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MTVAL)
    val mip     = RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MIP)

    read_csr_data := MuxCase(0.U(xlen.W), Array(
        (io.addr === ADDR_MSTATUS) -> mstatus,
        (io.addr === ADDR_MIE)     -> mie,
        (io.addr === ADDR_MTVEC)   -> mtvec,
        (io.addr === ADDR_MSCRATCH)-> mscratch,
        (io.addr === ADDR_MEPC)    -> mepc,
        (io.addr === ADDR_MCAUSE)  -> mcause,
        (io.addr === ADDR_MTVAL)   -> mtval,
        (io.addr === ADDR_MIP)     -> mip
    )).asUInt()
    io.csr_data := read_csr_data

    write_csr_data := MuxCase(io.gr_data, Array( //csrrw
        ((io.ctrl === CSR_CTRL.S || io.ctrl === CSR_CTRL.C) && io.gr_data =/= 0.U) -> read_csr_data, // riscv-spec:P56
        (io.ctrl === CSR_CTRL.S)    -> (read_csr_data | io.gr_data) ,
        (io.ctrl === CSR_CTRL.C)    -> (read_csr_data & ~io.gr_data)
    ))

    BoringUtils.addSource(mepc, "mepc")
    //[TEST][TODO]
//    BoringUtils.addSource(misa, "misa")
}
