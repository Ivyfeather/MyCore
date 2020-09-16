package MyCore

object MyCoreGen extends App{
    chisel3.Driver.execute(args, () => new RegFile)
}