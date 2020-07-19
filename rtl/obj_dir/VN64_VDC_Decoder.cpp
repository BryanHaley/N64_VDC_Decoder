// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VN64_VDC_Decoder.h for the primary calling header

#include "VN64_VDC_Decoder.h"
#include "VN64_VDC_Decoder__Syms.h"

//==========

void VN64_VDC_Decoder::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VN64_VDC_Decoder::eval\n"); );
    VN64_VDC_Decoder__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VN64_VDC_Decoder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("N64_VDC_Decoder.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VN64_VDC_Decoder::_eval_initial_loop(VN64_VDC_Decoder__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("N64_VDC_Decoder.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VN64_VDC_Decoder::_sequent__TOP__1(VN64_VDC_Decoder__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VN64_VDC_Decoder::_sequent__TOP__1\n"); );
    VN64_VDC_Decoder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    IData/*23:0*/ __Vdly__N64_VDC_Decoder__DOT__pix_rgb_buff;
    // Body
    __Vdly__N64_VDC_Decoder__DOT__pix_rgb_buff = vlTOPp->N64_VDC_Decoder__DOT__pix_rgb_buff;
    if (vlTOPp->vdc_dsync) {
        vlTOPp->vsync = 0U;
    } else {
        if ((1U & (~ ((IData)(vlTOPp->vdc_bus) >> 3U)))) {
            vlTOPp->vsync = 1U;
        }
    }
    if (vlTOPp->vdc_dsync) {
        vlTOPp->hsync = 0U;
    } else {
        if ((1U & (~ ((IData)(vlTOPp->vdc_bus) >> 1U)))) {
            vlTOPp->hsync = 1U;
        }
    }
    if ((1U & (~ (IData)(vlTOPp->vdc_dsync)))) {
        if ((1U & (~ ((IData)(vlTOPp->vdc_bus) >> 1U)))) {
            vlTOPp->pix_y = (0x3ffU & ((IData)(1U) 
                                       + (IData)(vlTOPp->pix_y)));
        }
        if ((1U & (~ ((IData)(vlTOPp->vdc_bus) >> 3U)))) {
            vlTOPp->pix_y = 0U;
        }
    }
    if ((1U & (~ (IData)(vlTOPp->vdc_dsync)))) {
        vlTOPp->pix_x = (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->pix_x)));
        if ((1U & (~ ((IData)(vlTOPp->vdc_bus) >> 1U)))) {
            vlTOPp->pix_x = 0U;
        }
        if ((1U & (~ ((IData)(vlTOPp->vdc_bus) >> 3U)))) {
            vlTOPp->pix_x = 0U;
        }
    }
    if (vlTOPp->vdc_dsync) {
        if ((0U == (IData)(vlTOPp->N64_VDC_Decoder__DOT__dsync_count))) {
            __Vdly__N64_VDC_Decoder__DOT__pix_rgb_buff 
                = (0x10000U | ((IData)(vlTOPp->vdc_bus) 
                               << 0x11U));
        } else {
            if ((1U == (IData)(vlTOPp->N64_VDC_Decoder__DOT__dsync_count))) {
                __Vdly__N64_VDC_Decoder__DOT__pix_rgb_buff 
                    = (vlTOPp->N64_VDC_Decoder__DOT__pix_rgb_buff 
                       & (0x100U | ((IData)(vlTOPp->vdc_bus) 
                                    << 9U)));
            } else {
                if ((2U == (IData)(vlTOPp->N64_VDC_Decoder__DOT__dsync_count))) {
                    __Vdly__N64_VDC_Decoder__DOT__pix_rgb_buff 
                        = (vlTOPp->N64_VDC_Decoder__DOT__pix_rgb_buff 
                           & (1U | ((IData)(vlTOPp->vdc_bus) 
                                    << 1U)));
                }
            }
        }
        vlTOPp->N64_VDC_Decoder__DOT__dsync_count = 
            (3U & ((IData)(1U) + (IData)(vlTOPp->N64_VDC_Decoder__DOT__dsync_count)));
    } else {
        vlTOPp->pix_r = (0xffU & (vlTOPp->N64_VDC_Decoder__DOT__pix_rgb_buff 
                                  >> 0x10U));
        vlTOPp->N64_VDC_Decoder__DOT__dsync_count = 0U;
        vlTOPp->pix_g = (0xffU & (vlTOPp->N64_VDC_Decoder__DOT__pix_rgb_buff 
                                  >> 8U));
        vlTOPp->pix_b = (0xffU & vlTOPp->N64_VDC_Decoder__DOT__pix_rgb_buff);
    }
    vlTOPp->N64_VDC_Decoder__DOT__pix_rgb_buff = __Vdly__N64_VDC_Decoder__DOT__pix_rgb_buff;
}

void VN64_VDC_Decoder::_eval(VN64_VDC_Decoder__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VN64_VDC_Decoder::_eval\n"); );
    VN64_VDC_Decoder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->vdc_clk)) & (IData)(vlTOPp->__Vclklast__TOP__vdc_clk))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__vdc_clk = vlTOPp->vdc_clk;
}

VL_INLINE_OPT QData VN64_VDC_Decoder::_change_request(VN64_VDC_Decoder__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VN64_VDC_Decoder::_change_request\n"); );
    VN64_VDC_Decoder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VN64_VDC_Decoder::_change_request_1(VN64_VDC_Decoder__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VN64_VDC_Decoder::_change_request_1\n"); );
    VN64_VDC_Decoder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VN64_VDC_Decoder::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VN64_VDC_Decoder::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vdc_clk & 0xfeU))) {
        Verilated::overWidthError("vdc_clk");}
    if (VL_UNLIKELY((vdc_dsync & 0xfeU))) {
        Verilated::overWidthError("vdc_dsync");}
    if (VL_UNLIKELY((vdc_bus & 0x80U))) {
        Verilated::overWidthError("vdc_bus");}
}
#endif  // VL_DEBUG
