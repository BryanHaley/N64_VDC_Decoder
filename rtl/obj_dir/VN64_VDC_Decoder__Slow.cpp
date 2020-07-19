// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VN64_VDC_Decoder.h for the primary calling header

#include "VN64_VDC_Decoder.h"
#include "VN64_VDC_Decoder__Syms.h"

//==========

VL_CTOR_IMP(VN64_VDC_Decoder) {
    VN64_VDC_Decoder__Syms* __restrict vlSymsp = __VlSymsp = new VN64_VDC_Decoder__Syms(this, name());
    VN64_VDC_Decoder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VN64_VDC_Decoder::__Vconfigure(VN64_VDC_Decoder__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VN64_VDC_Decoder::~VN64_VDC_Decoder() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void VN64_VDC_Decoder::_eval_initial(VN64_VDC_Decoder__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VN64_VDC_Decoder::_eval_initial\n"); );
    VN64_VDC_Decoder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__vdc_clk = vlTOPp->vdc_clk;
}

void VN64_VDC_Decoder::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VN64_VDC_Decoder::final\n"); );
    // Variables
    VN64_VDC_Decoder__Syms* __restrict vlSymsp = this->__VlSymsp;
    VN64_VDC_Decoder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VN64_VDC_Decoder::_eval_settle(VN64_VDC_Decoder__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VN64_VDC_Decoder::_eval_settle\n"); );
    VN64_VDC_Decoder* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VN64_VDC_Decoder::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VN64_VDC_Decoder::_ctor_var_reset\n"); );
    // Body
    vdc_clk = VL_RAND_RESET_I(1);
    vdc_dsync = VL_RAND_RESET_I(1);
    vdc_bus = VL_RAND_RESET_I(7);
    pix_x = VL_RAND_RESET_I(10);
    pix_y = VL_RAND_RESET_I(10);
    pix_r = VL_RAND_RESET_I(8);
    pix_g = VL_RAND_RESET_I(8);
    pix_b = VL_RAND_RESET_I(8);
    hsync = VL_RAND_RESET_I(1);
    vsync = VL_RAND_RESET_I(1);
    N64_VDC_Decoder__DOT__pix_rgb_buff = VL_RAND_RESET_I(24);
    N64_VDC_Decoder__DOT__dsync_count = VL_RAND_RESET_I(2);
}
