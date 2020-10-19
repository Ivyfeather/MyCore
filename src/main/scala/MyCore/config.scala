package MyCore

import chisel3._
import Const._

trait config {
  val xlen = 64
  val RV32 = false
}

abstract class MyCoreModule extends Module with config with Ctrlopsel with RISCVconst
abstract class MyCoreBundle extends Bundle with config with SelWidth
