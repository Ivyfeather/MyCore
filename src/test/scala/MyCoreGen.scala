package MyCore

class Top extends RegFile

object MyCoreGen extends App{
    chisel3.Driver.execute(args, () => new Top)
}