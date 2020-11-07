package MyCore

//class Top extends core
//class Top extends RegFile
import Memory.MemPortIO
import chisel3._

//实际的模块不包含这个
// 似乎利用verilator仿真，然后用gtkwave查看波形，
// 输入信号会晚一拍， 导致效果是看起来 当拍的输入就会立刻驱动reg更新
//为解决上述问题，加了如下一个缓冲 （等于看波形时将所有输入左移一拍
/*
class Top extends MyCoreModule{
    val io = IO(new coreIO)
    val core = Module(new core)

    val imem_req_ready  = RegNext(io.imem.req.ready)
    val imem_resp_valid = RegNext(io.imem.resp.valid)
    val imem_resp_bits_data = RegNext(io.imem.resp.bits.data)

    val dmem_req_ready  = RegNext(io.dmem.req.ready)
    val dmem_resp_valid = RegNext(io.dmem.resp.valid)
    val dmem_resp_bits_data = RegNext(io.dmem.resp.bits.data)

    io <> core.io

    core.io.imem.req.ready := imem_req_ready
    core.io.imem.resp.valid := imem_resp_valid
    core.io.imem.resp.bits.data := imem_resp_bits_data

    core.io.dmem.req.ready := dmem_req_ready
    core.io.dmem.resp.valid := dmem_resp_valid
    core.io.dmem.resp.bits.data := dmem_resp_bits_data

}
*/
class Top extends Soc
object MyCoreGen extends App{
    chisel3.Driver.execute(args, () => new Top)
}