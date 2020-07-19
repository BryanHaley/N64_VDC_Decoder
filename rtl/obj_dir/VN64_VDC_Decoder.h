// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VN64_VDC_DECODER_H_
#define _VN64_VDC_DECODER_H_  // guard

#include "verilated.h"

//==========

class VN64_VDC_Decoder__Syms;

//----------

VL_MODULE(VN64_VDC_Decoder) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(vdc_clk,0,0);
    VL_IN8(vdc_dsync,0,0);
    VL_IN8(vdc_bus,6,0);
    VL_OUT8(pix_r,7,0);
    VL_OUT8(pix_g,7,0);
    VL_OUT8(pix_b,7,0);
    VL_OUT8(hsync,0,0);
    VL_OUT8(vsync,0,0);
    VL_OUT16(pix_x,9,0);
    VL_OUT16(pix_y,9,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ N64_VDC_Decoder__DOT__dsync_count;
    IData/*23:0*/ N64_VDC_Decoder__DOT__pix_rgb_buff;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__vdc_clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VN64_VDC_Decoder__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VN64_VDC_Decoder);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VN64_VDC_Decoder(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VN64_VDC_Decoder();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VN64_VDC_Decoder__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VN64_VDC_Decoder__Syms* symsp, bool first);
  private:
    static QData _change_request(VN64_VDC_Decoder__Syms* __restrict vlSymsp);
    static QData _change_request_1(VN64_VDC_Decoder__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VN64_VDC_Decoder__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VN64_VDC_Decoder__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VN64_VDC_Decoder__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(VN64_VDC_Decoder__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
