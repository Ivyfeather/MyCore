;buildInfoPackage: chisel3, version: 3.3.1, scalaVersion: 2.12.11, sbtVersion: 1.3.10
circuit Top : 
  module Top : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip rs1_addr : UInt<5>, rs1_data : UInt<64>, flip rs2_addr : UInt<5>, rs2_data : UInt<64>, flip waddr : UInt<5>, flip wdata : UInt<64>, flip wen : UInt<1>}
    
    cmem rf : UInt<64>[32] @[regs.scala 19:17]
    when io.wen : @[regs.scala 21:17]
      infer mport _T = rf[io.waddr], clock @[regs.scala 21:23]
      _T <= io.wdata @[regs.scala 21:33]
      skip @[regs.scala 21:17]
    node _T_1 = neq(io.rs1_addr, UInt<1>("h00")) @[regs.scala 22:37]
    infer mport _T_2 = rf[io.rs1_addr], clock @[regs.scala 22:49]
    node _T_3 = mux(_T_1, _T_2, UInt<1>("h00")) @[regs.scala 22:23]
    io.rs1_data <= _T_3 @[regs.scala 22:17]
    node _T_4 = neq(io.rs2_addr, UInt<1>("h00")) @[regs.scala 23:37]
    infer mport _T_5 = rf[io.rs2_addr], clock @[regs.scala 23:49]
    node _T_6 = mux(_T_4, _T_5, UInt<1>("h00")) @[regs.scala 23:23]
    io.rs2_data <= _T_6 @[regs.scala 23:17]
    
