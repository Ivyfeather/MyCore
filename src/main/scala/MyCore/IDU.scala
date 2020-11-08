package MyCore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

import ISA._
import Utils._
import Const._

class ctrlops extends MyCoreBundle with ALUop{
    val is_Inst = Bool()
    val br_type = UInt(Brsel_bits)
    val op1_sel = UInt(OP1sel_bits)
    val op2_sel = UInt(OP2sel_bits)
    val alu_op  = UInt(ALUop_bits)
    val wb_sel  = UInt(WBsel_bits)
    val rf_wen  = Bool()
    val mem_en  = Bool()
    val mem_wr  = Bool()
    val mem_msk = UInt(MTT_bits)
    val csr_cmd = UInt(CSR_CTRL.SZ)
}

class IDUIO extends MyCoreBundle with ALUop {
    val inst = Input(UInt(32.W))
    val ctrl = Output(new ctrlops)
}

class IDU extends MyCoreModule with ALUop {
    val io = IO(new IDUIO)

    val csignals =
        ListLookup(io.inst,
            List(N, BR_N  , OP1_X  ,  OP2_X  , ALU_X   , WB_X   , REN_0, MEN_0, MRD  , MT_X,  CSR_CTRL.N),
            Array(       /* val  |  BR  |  op1   |   op2     |  ALU    |  wb  | rf   | mem  | mem  | mask |  csr  */
                         /* inst | type |   sel  |    sel    |   fcn   |  sel | wen  |  en  |  wr  | type |  cmd  */
                LW      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_W,  CSR_CTRL.N),
                LB      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_B,  CSR_CTRL.N),
                LBU     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_BU, CSR_CTRL.N),
                LH      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_H,  CSR_CTRL.N),
                LHU     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_HU, CSR_CTRL.N),
                SW      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, MWR,  MT_W,  CSR_CTRL.N),
                SB      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, MWR,  MT_B,  CSR_CTRL.N),
                SH      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, MWR,  MT_H,  CSR_CTRL.N),

                AUIPC   -> List(Y, BR_N  , OP1_IMU, OP2_PC  , ALU_ADD ,  WB_ALU, REN_1, MEN_0, MRD,  MT_X,  CSR_CTRL.N),
                LUI     -> List(Y, BR_N  , OP1_IMU, OP2_X   , ALU_COPY1, WB_ALU, REN_1, MEN_0, MRD,  MT_X,  CSR_CTRL.N),

                ADDI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                ANDI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_AND ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                ORI     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_OR  ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                XORI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_XOR ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SLTI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLT ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SLTIU   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLTU,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SLLI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLL ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SRAI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRA ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SRLI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRL ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),

                SLL     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLL ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                ADD     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_ADD ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SUB     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SUB ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SLT     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLT ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SLTU    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLTU,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                AND     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_AND ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                OR      -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_OR  ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                XOR     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_XOR ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SRA     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRA ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SRL     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRL ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),

                JAL     -> List(Y, BR_J  , OP1_X  , OP2_X   , ALU_X   ,  WB_PC4, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                JALR    -> List(Y, BR_JR , OP1_RS1, OP2_IMI , ALU_X   ,  WB_PC4, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                BEQ     -> List(Y, BR_EQ , OP1_RS1, OP2_RS2 , ALU_SUB ,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                BNE     -> List(Y, BR_NE , OP1_RS1, OP2_RS2 , ALU_SUB ,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                BGE     -> List(Y, BR_GE , OP1_RS1, OP2_RS2 , ALU_SLT ,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                BGEU    -> List(Y, BR_GEU, OP1_RS1, OP2_RS2 , ALU_SLTU,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                BLT     -> List(Y, BR_LT , OP1_RS1, OP2_RS2 , ALU_SLT ,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                BLTU    -> List(Y, BR_LTU, OP1_RS1, OP2_RS2 , ALU_SLTU,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.N),
            // RV64I
                LWU     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_WU, CSR_CTRL.N),
                LD      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_D,  CSR_CTRL.N),
                SD      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, MWR,  MT_D,  CSR_CTRL.N),
                ADDIW   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADDW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SLLIW   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLLW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SRLIW   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRLW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SRAIW   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRAW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),

                ADDW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_ADDW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SUBW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SUBW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SLLW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLLW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SRLW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRLW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                SRAW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRAW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N),

                CSRRWI  -> List(Y, BR_N  , OP1_IMZ, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR_CTRL.W),
                CSRRSI  -> List(Y, BR_N  , OP1_IMZ, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR_CTRL.S),
                CSRRCI  -> List(Y, BR_N  , OP1_IMZ, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR_CTRL.C),
                CSRRW   -> List(Y, BR_N  , OP1_RS1, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR_CTRL.W),
                CSRRS   -> List(Y, BR_N  , OP1_RS1, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR_CTRL.S),
                CSRRC   -> List(Y, BR_N  , OP1_RS1, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR_CTRL.C),

                ECALL   -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.I),
                MRET    -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.I),
                EBREAK  -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.I),
                WFI     -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.N), // implemented as a NOP

                FENCE_I -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR_CTRL.N),
                FENCE   -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_1, MRD , MT_X,  CSR_CTRL.N),

                DIVUW   -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_DIVUW, WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR_CTRL.N)
            ))

    io.ctrl.is_Inst      := csignals(0)
    io.ctrl.br_type      := csignals(1)
    io.ctrl.op1_sel      := csignals(2)
    io.ctrl.op2_sel      := csignals(3)
    io.ctrl.alu_op       := csignals(4)
    io.ctrl.wb_sel       := csignals(5)
    io.ctrl.rf_wen       := csignals(6)
    io.ctrl.mem_en       := csignals(7)
    io.ctrl.mem_wr       := csignals(8)
    io.ctrl.mem_msk      := csignals(9)
    io.ctrl.csr_cmd      := csignals(10)

    val is_trap = io.inst === MyCoreTrap.TRAP
    BoringUtils.addSource(is_trap, "is_trap")
}


