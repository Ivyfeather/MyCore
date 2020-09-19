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