package MyCore

class Top extends core

object MyCoreGen extends App{
    chisel3.Driver.execute(args, () => new Top)
}