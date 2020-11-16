package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import Const.CSR_CTRL

class CSRIO extends MyCoreBundle{
    val pc   = Input(UInt(12.W))
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

    // custom defined
    val ADDR_MTIME = 0x7c0.U
    val ADDR_MTIMECMP = 0x7c2.U
}

class Mtvec extends Bundle{
    val base = UInt(62.W)
    val mode = UInt(2.W)
}
class Mstatus extends Bundle{
    val notused_0 = UInt(56.W)
    val mpie = UInt(1.W)
    val notused_1 = UInt(3.W)
    val mie = UInt(1.W)
    val notused_2 = UInt(3.W)
}
class Mcause extends Bundle{
    val interrupt = UInt(1.W)
    val exc_code  = UInt(63.W)
}

class CSR extends MyCoreModule with ADDR_CSRS {
    val io = IO(new CSRIO)
    io := DontCare

    val write_csr_data = WireInit(0.U(xlen.W))
    val read_csr_data = WireInit(0.U(xlen.W))

    // [TODO] consider how to assign bundle with UInt(64.W)
    // [TODO] some bits should be hardwired to 0! maybe we should assign the writeable bits
    val mie     = RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MIE)
    val mtvec   = RegEnable(write_csr_data.asTypeOf(new Mtvec),  0.U.asTypeOf(new Mtvec),    io.addr === ADDR_MTVEC)
    val mscratch= RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MSCRATCH)
    val mepc    = RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MEPC)
    val mcause  = RegEnable(write_csr_data.asTypeOf(new Mcause), 0.U.asTypeOf(new Mcause),   io.addr === ADDR_MCAUSE)
    val mtval   = RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MTVAL)
    val mip     = RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MIP)
    val mstatus = RegEnable(write_csr_data.asTypeOf(new Mstatus),0.U.asTypeOf(new Mstatus),  io.addr === ADDR_MSTATUS)
    val mtime   = RegInit(0.U(xlen.W))
        mtime := mtime + 1.U
    val mtimecmp= RegEnable(write_csr_data, 0.U(xlen.W),                io.addr === ADDR_MTIMECMP)

    read_csr_data := MuxCase(0.U(xlen.W), Array(
        (io.addr === ADDR_MSTATUS) -> mstatus.asUInt(),
        (io.addr === ADDR_MIE)     -> mie,
        (io.addr === ADDR_MTVEC)   -> mtvec.asUInt(),
        (io.addr === ADDR_MSCRATCH)-> mscratch,
        (io.addr === ADDR_MEPC)    -> mepc,
        (io.addr === ADDR_MCAUSE)  -> mcause.asUInt(),
        (io.addr === ADDR_MTVAL)   -> mtval,
        (io.addr === ADDR_MIP)     -> mip,
        (io.addr === ADDR_MTIME)   -> mtime,
        (io.addr === ADDR_MTIMECMP)-> mtimecmp
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
    val exception = WireInit(false.B)
    val exc_addr  = WireInit(0.U(64.W))

    val is_ecall  = io.ctrl === CSR_CTRL.ECALL
    val is_ebreak = io.ctrl === CSR_CTRL.EBREAK
    val is_mret   = io.ctrl === CSR_CTRL.MRET
    val time_int  = mtime   === mtimecmp

    when(exception){
        mepc := io.pc
        mstatus.mpie := mstatus.mie
        mstatus.mie  := 0.U
    }
    when(is_mret){
        mstatus.mie := mstatus.mpie
    }

    when(time_int)          {
        mcause.interrupt := 1.U
        mcause.exc_code  := 7.U
    }
    .elsewhen(is_ecall)     { mcause.exc_code := 11.U }
    .elsewhen(is_ebreak)    { mcause.exc_code :=  3.U }


    exception   := mstatus.mie.asBool() & (is_ecall || is_ebreak || time_int)
    exc_addr    := Mux(mtvec.mode === 0.U, Cat(mtvec.base, Fill(2, 0.U)), Cat(mtvec.base, Fill(2, 0.U)) + mcause.asUInt() << 2.U)

    BoringUtils.addSource(exception, "exception")
    BoringUtils.addSource(exc_addr, "exc_addr")

}
