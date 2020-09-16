package MyCore

import chisel3._
import chisel3.util._

trait CoreConfig
{
    val xlen = 64
}

abstract class MyCoreModule extends Module with CoreConfig
abstract class MyCoreBundle extends Bundle with CoreConfig




