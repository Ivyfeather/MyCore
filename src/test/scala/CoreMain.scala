package MyCore

class Top extends ALU

object MyCoreGen extends App{
    chisel3.Driver.execute(args, () => new Top)
}