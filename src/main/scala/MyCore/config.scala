package MyCore

import chisel3._
import Const._

trait config {
  val xlen = 32
}

abstract class MyCoreModule extends Module with config with Ctrlopsel with RISCVconst
abstract class MyCoreBundle extends Bundle with config with SelWidth
