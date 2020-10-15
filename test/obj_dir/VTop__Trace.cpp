// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VTop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgCData(oldp+0,(vlTOPp->Top__DOT__idu__DOT__csignals_4),6);
            tracep->chgIData(oldp+1,(vlTOPp->Top__DOT__alu_io_in1),32);
            tracep->chgIData(oldp+2,(vlTOPp->Top__DOT__alu_io_in2),32);
            tracep->chgIData(oldp+3,(vlTOPp->Top__DOT__alu_io_out),32);
            tracep->chgBit(oldp+4,((0U == vlTOPp->Top__DOT__alu_io_out)));
            tracep->chgIData(oldp+5,(vlTOPp->Top__DOT__idu_io_inst),32);
            tracep->chgCData(oldp+6,(vlTOPp->Top__DOT__idu_io_br_type),4);
            tracep->chgCData(oldp+7,(vlTOPp->Top__DOT__idu_io_op1_sel),2);
            tracep->chgCData(oldp+8,(vlTOPp->Top__DOT__idu_io_op2_sel),2);
            tracep->chgCData(oldp+9,(vlTOPp->Top__DOT__idu_io_wb_sel),2);
            tracep->chgBit(oldp+10,(vlTOPp->Top__DOT__idu_io_rf_wen));
            tracep->chgBit(oldp+11,(vlTOPp->Top__DOT__idu_io_mem_en));
            tracep->chgBit(oldp+12,(vlTOPp->Top__DOT__idu_io_mem_fcn));
            tracep->chgCData(oldp+13,(vlTOPp->Top__DOT__idu_io_mem_msk),3);
            tracep->chgCData(oldp+14,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xfU))),5);
            tracep->chgIData(oldp+15,(vlTOPp->Top__DOT__rf_io_rs1_data),32);
            tracep->chgCData(oldp+16,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0x14U))),5);
            tracep->chgIData(oldp+17,(vlTOPp->Top__DOT__rf_io_rs2_data),32);
            tracep->chgCData(oldp+18,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 7U))),5);
            tracep->chgIData(oldp+19,(vlTOPp->Top__DOT__rf_io_wdata),32);
            tracep->chgBit(oldp+20,(vlTOPp->Top__DOT__stall));
            tracep->chgSData(oldp+21,((0xfffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                 >> 0x14U))),12);
            tracep->chgSData(oldp+22,(vlTOPp->Top__DOT__imm_s),12);
            tracep->chgSData(oldp+23,(vlTOPp->Top__DOT__imm_b),12);
            tracep->chgIData(oldp+24,((0xfffffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                   >> 0xcU))),20);
            tracep->chgIData(oldp+25,(vlTOPp->Top__DOT__imm_j),20);
            tracep->chgIData(oldp+26,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xfU))),32);
            tracep->chgIData(oldp+27,(vlTOPp->Top__DOT__imm_i_sext),32);
            tracep->chgIData(oldp+28,(vlTOPp->Top__DOT__imm_s_sext),32);
            tracep->chgIData(oldp+29,((vlTOPp->Top__DOT___T_150 
                                       << 1U)),32);
            tracep->chgIData(oldp+30,((0xfffff000U 
                                       & vlTOPp->Top__DOT__idu_io_inst)),32);
            tracep->chgIData(oldp+31,((vlTOPp->Top__DOT___T_162 
                                       << 1U)),32);
            tracep->chgIData(oldp+32,((IData)(vlTOPp->Top__DOT___T_187)),32);
            tracep->chgIData(oldp+33,((IData)(vlTOPp->Top__DOT___T_188)),32);
            tracep->chgIData(oldp+34,((IData)(vlTOPp->Top__DOT___T_189)),32);
            tracep->chgBit(oldp+35,(vlTOPp->Top__DOT__br_taken));
            tracep->chgIData(oldp+36,(vlTOPp->Top__DOT__pc_next),32);
            tracep->chgQData(oldp+37,(vlTOPp->Top__DOT__alu__DOT__add_result),33);
            tracep->chgIData(oldp+39,(vlTOPp->Top__DOT__alu__DOT__xor_result),32);
            tracep->chgIData(oldp+40,(vlTOPp->Top__DOT__alu__DOT__or_result),32);
            tracep->chgIData(oldp+41,(vlTOPp->Top__DOT__alu__DOT__and_result),32);
            tracep->chgBit(oldp+42,((1U & (~ (IData)(
                                                     (vlTOPp->Top__DOT__alu__DOT__add_result 
                                                      >> 0x20U))))));
            tracep->chgBit(oldp+43,(vlTOPp->Top__DOT__alu__DOT__slt_result));
            tracep->chgCData(oldp+44,((0x1fU & vlTOPp->Top__DOT__alu_io_in2)),5);
            tracep->chgIData(oldp+45,((IData)(vlTOPp->Top__DOT__alu__DOT___T_23)),32);
            tracep->chgIData(oldp+46,(vlTOPp->Top__DOT__alu__DOT___T_25),32);
            tracep->chgIData(oldp+47,(vlTOPp->Top__DOT__alu__DOT__srl_result),32);
            tracep->chgCData(oldp+48,(vlTOPp->Top__DOT__idu__DOT__csignals_4),5);
            tracep->chgIData(oldp+49,(vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data),32);
            tracep->chgIData(oldp+50,(vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+51,(vlTOPp->Top__DOT__pc_reg),32);
            tracep->chgIData(oldp+52,(((IData)(4U) 
                                       + vlTOPp->Top__DOT__pc_reg)),32);
            tracep->chgIData(oldp+53,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),32);
            tracep->chgIData(oldp+54,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),32);
            tracep->chgIData(oldp+55,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),32);
            tracep->chgIData(oldp+56,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),32);
            tracep->chgIData(oldp+57,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),32);
            tracep->chgIData(oldp+58,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),32);
            tracep->chgIData(oldp+59,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),32);
            tracep->chgIData(oldp+60,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),32);
            tracep->chgIData(oldp+61,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),32);
            tracep->chgIData(oldp+62,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),32);
            tracep->chgIData(oldp+63,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),32);
            tracep->chgIData(oldp+64,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),32);
            tracep->chgIData(oldp+65,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),32);
            tracep->chgIData(oldp+66,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),32);
            tracep->chgIData(oldp+67,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),32);
            tracep->chgIData(oldp+68,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),32);
            tracep->chgIData(oldp+69,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),32);
            tracep->chgIData(oldp+70,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),32);
            tracep->chgIData(oldp+71,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),32);
            tracep->chgIData(oldp+72,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),32);
            tracep->chgIData(oldp+73,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),32);
            tracep->chgIData(oldp+74,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),32);
            tracep->chgIData(oldp+75,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),32);
            tracep->chgIData(oldp+76,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),32);
            tracep->chgIData(oldp+77,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),32);
            tracep->chgIData(oldp+78,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),32);
            tracep->chgIData(oldp+79,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),32);
            tracep->chgIData(oldp+80,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),32);
            tracep->chgIData(oldp+81,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),32);
            tracep->chgIData(oldp+82,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),32);
            tracep->chgIData(oldp+83,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),32);
            tracep->chgIData(oldp+84,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),32);
        }
        tracep->chgBit(oldp+85,(vlTOPp->clock));
        tracep->chgBit(oldp+86,(vlTOPp->reset));
        tracep->chgBit(oldp+87,(vlTOPp->io_imem_req_ready));
        tracep->chgBit(oldp+88,(vlTOPp->io_imem_req_valid));
        tracep->chgIData(oldp+89,(vlTOPp->io_imem_req_bits_addr),32);
        tracep->chgIData(oldp+90,(vlTOPp->io_imem_req_bits_data),32);
        tracep->chgBit(oldp+91,(vlTOPp->io_imem_req_bits_fcn));
        tracep->chgCData(oldp+92,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->chgBit(oldp+93,(vlTOPp->io_imem_resp_ready));
        tracep->chgBit(oldp+94,(vlTOPp->io_imem_resp_valid));
        tracep->chgIData(oldp+95,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->chgBit(oldp+96,(vlTOPp->io_dmem_req_ready));
        tracep->chgBit(oldp+97,(vlTOPp->io_dmem_req_valid));
        tracep->chgIData(oldp+98,(vlTOPp->io_dmem_req_bits_addr),32);
        tracep->chgIData(oldp+99,(vlTOPp->io_dmem_req_bits_data),32);
        tracep->chgBit(oldp+100,(vlTOPp->io_dmem_req_bits_fcn));
        tracep->chgCData(oldp+101,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->chgBit(oldp+102,(vlTOPp->io_dmem_resp_ready));
        tracep->chgBit(oldp+103,(vlTOPp->io_dmem_resp_valid));
        tracep->chgIData(oldp+104,(vlTOPp->io_dmem_resp_bits_data),32);
        tracep->chgBit(oldp+105,(vlTOPp->io_debug_io_wen));
        tracep->chgCData(oldp+106,(vlTOPp->io_debug_io_waddr),5);
        tracep->chgIData(oldp+107,(vlTOPp->io_debug_io_wdata),32);
        tracep->chgIData(oldp+108,(vlTOPp->io_debug_io_PC),32);
        tracep->chgBit(oldp+109,(vlTOPp->io_debug_io_stall));
    }
}

void VTop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VTop__Syms* __restrict vlSymsp = static_cast<VTop__Syms*>(userp);
    VTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
    }
}
