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
    val csr_cmd = UInt(CSR.SZ)
}

class IDUIO extends MyCoreBundle with ALUop {
    val inst = Input(UInt(32.W))
    val ctrl = Output(new ctrlops)
}

class IDU extends MyCoreModule with ALUop {
    val io = IO(new IDUIO)

    val csignals =
        ListLookup(io.inst,
            List(N, BR_N  , OP1_X  ,  OP2_X  , ALU_X   , WB_X   , REN_0, MEN_0, MRD  , MT_X,  CSR.N),
            Array(       /* val  |  BR  |  op1   |   op2     |  ALU    |  wb  | rf   | mem  | mem  | mask |  csr  */
                         /* inst | type |   sel  |    sel    |   fcn   |  sel | wen  |  en  |  wr  | type |  cmd  */
                LW      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_W,  CSR.N),
                LB      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_B,  CSR.N),
                LBU     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_BU, CSR.N),
                LHU     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_HU, CSR.N),
                SW      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, MWR,  MT_W,  CSR.N),
                SB      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, MWR,  MT_B,  CSR.N),
                SH      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, MWR,  MT_H,  CSR.N),

                AUIPC   -> List(Y, BR_N  , OP1_IMU, OP2_PC  , ALU_ADD ,  WB_ALU, REN_1, MEN_0, MRD,  MT_X,  CSR.N),
                LUI     -> List(Y, BR_N  , OP1_IMU, OP2_X   , ALU_COPY1, WB_ALU, REN_1, MEN_0, MRD,  MT_X,  CSR.N),

                ADDI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                ANDI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_AND ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                ORI     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_OR  ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                XORI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_XOR ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SLTI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLT ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SLTIU   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLTU,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SLLI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLL ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SRAI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRA ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SRLI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRL ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),

                SLL     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLL ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                ADD     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_ADD ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SUB     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SUB ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SLT     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLT ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SLTU    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLTU,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                AND     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_AND ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                OR      -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_OR  ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                XOR     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_XOR ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SRA     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRA ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SRL     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRL ,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),

                JAL     -> List(Y, BR_J  , OP1_X  , OP2_X   , ALU_X   ,  WB_PC4, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                JALR    -> List(Y, BR_JR , OP1_RS1, OP2_IMI , ALU_X   ,  WB_PC4, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                BEQ     -> List(Y, BR_EQ , OP1_RS1, OP2_RS2 , ALU_SUB ,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.N),
                BNE     -> List(Y, BR_NE , OP1_RS1, OP2_RS2 , ALU_SUB ,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.N),
                BGE     -> List(Y, BR_GE , OP1_RS1, OP2_RS2 , ALU_SLT ,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.N),
                BGEU    -> List(Y, BR_GEU, OP1_RS1, OP2_RS2 , ALU_SLTU,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.N),
                BLT     -> List(Y, BR_LT , OP1_RS1, OP2_RS2 , ALU_SLT ,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.N),
                BLTU    -> List(Y, BR_LTU, OP1_RS1, OP2_RS2 , ALU_SLTU,  WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.N),
            // RV64I
                LWU     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_WU, CSR.N),
                LD      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, MRD,  MT_D,  CSR.N),
                SD      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, MWR,  MT_D,  CSR.N),
                ADDIW   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADDW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SLLIW   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLLW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SRLIW   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRLW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SRAIW   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRAW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),

                ADDW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_ADDW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SUBW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SUBW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SLLW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLLW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SRLW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRLW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),
                SRAW    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRAW,  WB_ALU, REN_1, MEN_0, MRD , MT_X,  CSR.N),

                CSRRWI  -> List(Y, BR_N  , OP1_IMZ, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR.W),
                CSRRSI  -> List(Y, BR_N  , OP1_IMZ, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR.S),
                CSRRCI  -> List(Y, BR_N  , OP1_IMZ, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR.C),
                CSRRW   -> List(Y, BR_N  , OP1_RS1, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR.W),
                CSRRS   -> List(Y, BR_N  , OP1_RS1, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR.S),
                CSRRC   -> List(Y, BR_N  , OP1_RS1, OP2_X   , ALU_COPY1, WB_CSR, REN_1, MEN_0, MRD,  MT_X,  CSR.C),

                ECALL   -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.I),
                MRET    -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.I),
                DRET    -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.I),
                EBREAK  -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.I),
                WFI     -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.N), // implemented as a NOP

                FENCE_I -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, MRD , MT_X,  CSR.N),
                FENCE   -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_1, MRD , MT_X,  CSR.N)
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


