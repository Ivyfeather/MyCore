;buildInfoPackage: chisel3, version: 3.1.2, scalaVersion: 2.12.4, sbtVersion: 1.1.1, builtAtString: 2018-07-25 16:51:33.220, builtAtMillis: 1532537493220
circuit Top : 
  module Top : 
    input clock : Clock
    input reset : UInt<1>
    output io : {flip rs1_addr : UInt<5>, rs1_data : UInt<32>, flip rs2_addr : UInt<5>, rs2_data : UInt<32>, flip waddr : UInt<5>, flip wdata : UInt<32>, flip wen : UInt<1>}
    
    cmem rf : UInt<32>[32] @[RegFile.scala 19:17]
    when io.wen : @[RegFile.scala 21:17]
      infer mport _T_21 = rf[io.waddr], clock @[RegFile.scala 21:23]
      _T_21 <= io.wdata @[RegFile.scala 21:33]
      skip @[RegFile.scala 21:17]
    node _T_23 = neq(io.rs1_addr, UInt<1>("h00")) @[RegFile.scala 22:37]
    infer mport _T_24 = rf[io.rs1_addr], clock @[RegFile.scala 22:49]
    node _T_26 = mux(_T_23, _T_24, UInt<1>("h00")) @[RegFile.scala 22:23]
    io.rs1_data <= _T_26 @[RegFile.scala 22:17]
    node _T_28 = neq(io.rs2_addr, UInt<1>("h00")) @[RegFile.scala 23:37]
    infer mport _T_29 = rf[io.rs2_addr], clock @[RegFile.scala 23:49]
    node _T_31 = mux(_T_28, _T_29, UInt<1>("h00")) @[RegFile.scala 23:23]
    io.rs2_data <= _T_31 @[RegFile.scala 23:17]
    
