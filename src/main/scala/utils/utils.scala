package utils

import chisel3._
import chisel3.util._

object SignExt{
    def apply(a: UInt, len: Int) = {
        val a_len = a.getWidth
        val a_sign = a(a_len-1)
        if(a_len >= len) a(len-1, 0) 
        else Cat(Fill(len - a_len, a_sign), a)
    }
}

object ZeroExt{
    def apply(a: UInt, len: Int) = {
        val a_len = a.getWidth
        if(a_len >= len) a(len-1, 0)
        else Cat(0.U((len - a_len).W), a)
    }
}

object LookupTree {
  def apply[T <: Data](key: UInt, mapping: Iterable[(UInt, T)]): T =
    Mux1H(mapping.map(p => (p._1 === key, p._2)))
}

object LookupTreeDefault {
  def apply[T <: Data](key: UInt, default: T, mapping: Iterable[(UInt, T)]): T =
    MuxLookup(key, default, mapping.toSeq)
}
