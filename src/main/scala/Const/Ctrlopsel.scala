package Const

import chisel3._

trait SelWidth {
    val PCsel_bits = 3.W
    val Brsel_bits = 4.W
    val OP1sel_bits = 2.W
    val OP2sel_bits = 2.W
    val WBsel_bits = 2.W
    val MTT_bits = 3.W
}

trait Ctrlopsel extends SelWidth{
    val Y       = true.B
    val N       = false.B

    // PC Sel
    val PC_4   = 0.asUInt(PCsel_bits)  // PC + 4
    val PC_BR  = 1.asUInt(PCsel_bits)  // branch_target
    val PC_J   = 2.asUInt(PCsel_bits)  // jump_target
    val PC_JR  = 3.asUInt(PCsel_bits)  // jump_reg_target
    val PC_EXC = 4.asUInt(PCsel_bits)  // exception

    // Branch Sel
    val BR_N   = 0.asUInt(Brsel_bits)  // Next
    val BR_NE  = 1.asUInt(Brsel_bits)  // Branch on NotEqual
    val BR_EQ  = 2.asUInt(Brsel_bits)  // Branch on Equal
    val BR_GE  = 3.asUInt(Brsel_bits)  // Branch on Greater/Equal
    val BR_GEU = 4.asUInt(Brsel_bits)  // Branch on Greater/Equal Unsigned
    val BR_LT  = 5.asUInt(Brsel_bits)  // Branch on Less Than
    val BR_LTU = 6.asUInt(Brsel_bits)  // Branch on Less Than Unsigned
    val BR_J   = 7.asUInt(Brsel_bits)  // Jump
    val BR_JR  = 8.asUInt(Brsel_bits)  // Jump Register

    // RS1 Operand Sel
    val OP1_RS1 = 0.asUInt(OP1sel_bits) // Register Source #1
    val OP1_IMU = 1.asUInt(OP1sel_bits) // immediate, U-type
    val OP1_IMZ = 2.asUInt(OP1sel_bits) // Zero-extended rs1 field of inst, for CSRI instructions
    val OP1_X   = 0.asUInt(OP1sel_bits)

    // RS2 Operand Sel
    val OP2_RS2 = 0.asUInt(OP2sel_bits) // Register Source #2
    val OP2_IMI = 1.asUInt(OP2sel_bits) // immediate, I-type
    val OP2_IMS = 2.asUInt(OP2sel_bits) // immediate, S-type
    val OP2_PC  = 3.asUInt(OP2sel_bits) // PC
    val OP2_X   = 0.asUInt(OP2sel_bits)

    // Register File Write Enable Signal
    val REN_0   = false.B
    val REN_1   = true.B
    val REN_X   = false.B

    // Writeback Sel
    val WB_ALU  = 0.asUInt(WBsel_bits)
    val WB_MEM  = 1.asUInt(WBsel_bits)
    val WB_PC4  = 2.asUInt(WBsel_bits)
    val WB_CSR  = 3.asUInt(WBsel_bits)
    val WB_X    = 0.asUInt(WBsel_bits)

    // Memory Enable Signal
    val MEN_0   = false.B
    val MEN_1   = true.B

    // Memory Write Enable Signal
    val MRD   = false.B
    val MWR   = true.B

    // Memory Mask Type Signal
    val MT_X    = 0.asUInt(MTT_bits)
    val MT_B    = 1.asUInt(MTT_bits)
    val MT_H    = 2.asUInt(MTT_bits)
    val MT_W    = 3.asUInt(MTT_bits)
    val MT_D    = 4.asUInt(MTT_bits)
    val MT_BU   = 5.asUInt(MTT_bits)
    val MT_HU   = 6.asUInt(MTT_bits)
    val MT_WU   = 7.asUInt(MTT_bits)
}
