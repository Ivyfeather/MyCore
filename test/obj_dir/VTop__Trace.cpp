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
            tracep->chgQData(oldp+1,(vlTOPp->Top__DOT__alu_io_in1),64);
            tracep->chgQData(oldp+3,(vlTOPp->Top__DOT__alu_io_in2),64);
            tracep->chgQData(oldp+5,(vlTOPp->Top__DOT__alu_io_out),64);
            tracep->chgBit(oldp+7,((0ULL == vlTOPp->Top__DOT__alu_io_out)));
            tracep->chgIData(oldp+8,(vlTOPp->Top__DOT__idu_io_inst),32);
            tracep->chgCData(oldp+9,(vlTOPp->Top__DOT__idu_io_br_type),4);
            tracep->chgCData(oldp+10,(vlTOPp->Top__DOT__idu_io_op1_sel),2);
            tracep->chgCData(oldp+11,(vlTOPp->Top__DOT__idu_io_op2_sel),2);
            tracep->chgCData(oldp+12,(vlTOPp->Top__DOT__idu_io_wb_sel),2);
            tracep->chgBit(oldp+13,(vlTOPp->Top__DOT__idu_io_rf_wen));
            tracep->chgBit(oldp+14,(vlTOPp->Top__DOT__idu_io_mem_en));
            tracep->chgBit(oldp+15,(vlTOPp->Top__DOT__idu_io_mem_fcn));
            tracep->chgCData(oldp+16,(vlTOPp->Top__DOT__idu_io_mem_msk),3);
            tracep->chgCData(oldp+17,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xfU))),5);
            tracep->chgQData(oldp+18,(vlTOPp->Top__DOT__rf_io_rs1_data),64);
            tracep->chgCData(oldp+20,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0x14U))),5);
            tracep->chgQData(oldp+21,(vlTOPp->Top__DOT__rf_io_rs2_data),64);
            tracep->chgCData(oldp+23,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 7U))),5);
            tracep->chgQData(oldp+24,(vlTOPp->Top__DOT__rf_io_wdata),64);
            tracep->chgBit(oldp+26,(vlTOPp->Top__DOT__stall));
            tracep->chgSData(oldp+27,((0xfffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                 >> 0x14U))),12);
            tracep->chgSData(oldp+28,(vlTOPp->Top__DOT__imm_s),12);
            tracep->chgSData(oldp+29,(vlTOPp->Top__DOT__imm_b),12);
            tracep->chgIData(oldp+30,((0xfffffU & (vlTOPp->Top__DOT__idu_io_inst 
                                                   >> 0xcU))),20);
            tracep->chgIData(oldp+31,(vlTOPp->Top__DOT__imm_j),20);
            tracep->chgIData(oldp+32,((0x1fU & (vlTOPp->Top__DOT__idu_io_inst 
                                                >> 0xfU))),32);
            tracep->chgIData(oldp+33,(vlTOPp->Top__DOT__imm_i_sext),32);
            tracep->chgIData(oldp+34,(vlTOPp->Top__DOT__imm_s_sext),32);
            tracep->chgIData(oldp+35,((vlTOPp->Top__DOT___T_151 
                                       << 1U)),32);
            tracep->chgIData(oldp+36,((0xfffff000U 
                                       & vlTOPp->Top__DOT__idu_io_inst)),32);
            tracep->chgIData(oldp+37,((vlTOPp->Top__DOT___T_163 
                                       << 1U)),32);
            tracep->chgQData(oldp+38,((((QData)((IData)(
                                                        vlTOPp->Top__DOT___T_188[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT___T_188[0U])))),64);
            tracep->chgQData(oldp+40,((((QData)((IData)(
                                                        vlTOPp->Top__DOT___T_189[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT___T_189[0U])))),64);
            tracep->chgQData(oldp+42,((((QData)((IData)(
                                                        vlTOPp->Top__DOT___T_190[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT___T_190[0U])))),64);
            tracep->chgBit(oldp+44,(vlTOPp->Top__DOT__br_taken));
            tracep->chgIData(oldp+45,((IData)(vlTOPp->Top__DOT___T_231)),32);
            tracep->chgWData(oldp+46,(vlTOPp->Top__DOT__alu__DOT__add_result),65);
            tracep->chgQData(oldp+49,(vlTOPp->Top__DOT__alu__DOT__xor_result),64);
            tracep->chgQData(oldp+51,(vlTOPp->Top__DOT__alu__DOT__or_result),64);
            tracep->chgQData(oldp+53,(vlTOPp->Top__DOT__alu__DOT__and_result),64);
            tracep->chgBit(oldp+55,((1U & (~ vlTOPp->Top__DOT__alu__DOT__add_result[2U]))));
            tracep->chgBit(oldp+56,(vlTOPp->Top__DOT__alu__DOT__slt_result));
            tracep->chgCData(oldp+57,((0x1fU & (IData)(vlTOPp->Top__DOT__alu_io_in2))),5);
            tracep->chgQData(oldp+58,((((QData)((IData)(
                                                        vlTOPp->Top__DOT__alu__DOT___T_23[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->Top__DOT__alu__DOT___T_23[0U])))),64);
            tracep->chgQData(oldp+60,(vlTOPp->Top__DOT__alu__DOT___T_25),64);
            tracep->chgQData(oldp+62,(vlTOPp->Top__DOT__alu__DOT__srl_result),64);
            tracep->chgCData(oldp+64,(vlTOPp->Top__DOT__idu__DOT__csignals_4),5);
            tracep->chgQData(oldp+65,(vlTOPp->Top__DOT__rf__DOT__regfile___05FT_24_data),64);
            tracep->chgQData(oldp+67,(vlTOPp->Top__DOT__rf__DOT__regfile___05FT_29_data),64);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+69,(vlTOPp->Top__DOT__pc_reg),64);
            tracep->chgIData(oldp+71,(((IData)(4U) 
                                       + (IData)(vlTOPp->Top__DOT__pc_reg))),32);
            tracep->chgQData(oldp+72,(vlTOPp->Top__DOT__rf__DOT__regfile[0]),64);
            tracep->chgQData(oldp+74,(vlTOPp->Top__DOT__rf__DOT__regfile[1]),64);
            tracep->chgQData(oldp+76,(vlTOPp->Top__DOT__rf__DOT__regfile[2]),64);
            tracep->chgQData(oldp+78,(vlTOPp->Top__DOT__rf__DOT__regfile[3]),64);
            tracep->chgQData(oldp+80,(vlTOPp->Top__DOT__rf__DOT__regfile[4]),64);
            tracep->chgQData(oldp+82,(vlTOPp->Top__DOT__rf__DOT__regfile[5]),64);
            tracep->chgQData(oldp+84,(vlTOPp->Top__DOT__rf__DOT__regfile[6]),64);
            tracep->chgQData(oldp+86,(vlTOPp->Top__DOT__rf__DOT__regfile[7]),64);
            tracep->chgQData(oldp+88,(vlTOPp->Top__DOT__rf__DOT__regfile[8]),64);
            tracep->chgQData(oldp+90,(vlTOPp->Top__DOT__rf__DOT__regfile[9]),64);
            tracep->chgQData(oldp+92,(vlTOPp->Top__DOT__rf__DOT__regfile[10]),64);
            tracep->chgQData(oldp+94,(vlTOPp->Top__DOT__rf__DOT__regfile[11]),64);
            tracep->chgQData(oldp+96,(vlTOPp->Top__DOT__rf__DOT__regfile[12]),64);
            tracep->chgQData(oldp+98,(vlTOPp->Top__DOT__rf__DOT__regfile[13]),64);
            tracep->chgQData(oldp+100,(vlTOPp->Top__DOT__rf__DOT__regfile[14]),64);
            tracep->chgQData(oldp+102,(vlTOPp->Top__DOT__rf__DOT__regfile[15]),64);
            tracep->chgQData(oldp+104,(vlTOPp->Top__DOT__rf__DOT__regfile[16]),64);
            tracep->chgQData(oldp+106,(vlTOPp->Top__DOT__rf__DOT__regfile[17]),64);
            tracep->chgQData(oldp+108,(vlTOPp->Top__DOT__rf__DOT__regfile[18]),64);
            tracep->chgQData(oldp+110,(vlTOPp->Top__DOT__rf__DOT__regfile[19]),64);
            tracep->chgQData(oldp+112,(vlTOPp->Top__DOT__rf__DOT__regfile[20]),64);
            tracep->chgQData(oldp+114,(vlTOPp->Top__DOT__rf__DOT__regfile[21]),64);
            tracep->chgQData(oldp+116,(vlTOPp->Top__DOT__rf__DOT__regfile[22]),64);
            tracep->chgQData(oldp+118,(vlTOPp->Top__DOT__rf__DOT__regfile[23]),64);
            tracep->chgQData(oldp+120,(vlTOPp->Top__DOT__rf__DOT__regfile[24]),64);
            tracep->chgQData(oldp+122,(vlTOPp->Top__DOT__rf__DOT__regfile[25]),64);
            tracep->chgQData(oldp+124,(vlTOPp->Top__DOT__rf__DOT__regfile[26]),64);
            tracep->chgQData(oldp+126,(vlTOPp->Top__DOT__rf__DOT__regfile[27]),64);
            tracep->chgQData(oldp+128,(vlTOPp->Top__DOT__rf__DOT__regfile[28]),64);
            tracep->chgQData(oldp+130,(vlTOPp->Top__DOT__rf__DOT__regfile[29]),64);
            tracep->chgQData(oldp+132,(vlTOPp->Top__DOT__rf__DOT__regfile[30]),64);
            tracep->chgQData(oldp+134,(vlTOPp->Top__DOT__rf__DOT__regfile[31]),64);
        }
        tracep->chgBit(oldp+136,(vlTOPp->clock));
        tracep->chgBit(oldp+137,(vlTOPp->reset));
        tracep->chgBit(oldp+138,(vlTOPp->io_imem_req_ready));
        tracep->chgBit(oldp+139,(vlTOPp->io_imem_req_valid));
        tracep->chgIData(oldp+140,(vlTOPp->io_imem_req_bits_addr),32);
        tracep->chgIData(oldp+141,(vlTOPp->io_imem_req_bits_data),32);
        tracep->chgBit(oldp+142,(vlTOPp->io_imem_req_bits_fcn));
        tracep->chgCData(oldp+143,(vlTOPp->io_imem_req_bits_msk),3);
        tracep->chgBit(oldp+144,(vlTOPp->io_imem_resp_ready));
        tracep->chgBit(oldp+145,(vlTOPp->io_imem_resp_valid));
        tracep->chgIData(oldp+146,(vlTOPp->io_imem_resp_bits_data),32);
        tracep->chgBit(oldp+147,(vlTOPp->io_dmem_req_ready));
        tracep->chgBit(oldp+148,(vlTOPp->io_dmem_req_valid));
        tracep->chgIData(oldp+149,(vlTOPp->io_dmem_req_bits_addr),32);
        tracep->chgQData(oldp+150,(vlTOPp->io_dmem_req_bits_data),64);
        tracep->chgBit(oldp+152,(vlTOPp->io_dmem_req_bits_fcn));
        tracep->chgCData(oldp+153,(vlTOPp->io_dmem_req_bits_msk),3);
        tracep->chgBit(oldp+154,(vlTOPp->io_dmem_resp_ready));
        tracep->chgBit(oldp+155,(vlTOPp->io_dmem_resp_valid));
        tracep->chgQData(oldp+156,(vlTOPp->io_dmem_resp_bits_data),64);
        tracep->chgBit(oldp+158,(vlTOPp->io_debug_io_wen));
        tracep->chgCData(oldp+159,(vlTOPp->io_debug_io_waddr),5);
        tracep->chgQData(oldp+160,(vlTOPp->io_debug_io_wdata),64);
        tracep->chgQData(oldp+162,(vlTOPp->io_debug_io_PC),64);
        tracep->chgBit(oldp+164,(vlTOPp->io_debug_io_stall));
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
