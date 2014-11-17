#define SIMD_HEADER "simd-sse2.h"
/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Mar  4 13:51:49 EST 2014 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 6 -dit -name hc2cfdftv_6 -include hc2cfv.h */

/*
 * This function contains 29 FP additions, 30 FP multiplications,
 * (or, 17 additions, 18 multiplications, 12 fused multiply/add),
 * 38 stack variables, 2 constants, and 12 memory accesses
 */
#include "hc2cfv.h"

static void hc2cfdftv_6(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 10)); m < me; m = m + VL, Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms), Im = Im - (VL * ms), W = W + (TWVL * 10), MAKE_VOLATILE_STRIDE(24, rs)) {
	       V T5, T6, T3, Tj, T4, T9, Te, Th, T1, T2, Ti, Tc, Td, Tb, Tg;
	       V T7, Ta, Tt, Tk, Tr, T8, Ts, Tf, Tx, Tu, To, Tl, Tw, Tv, Tn;
	       V Tm, Tz, Ty, Tp, Tq;
	       T1 = LD(&(Rp[0]), ms, &(Rp[0]));
	       T2 = LD(&(Rm[0]), -ms, &(Rm[0]));
	       Ti = LDW(&(W[0]));
	       Tc = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
	       Td = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
	       Tb = LDW(&(W[TWVL * 8]));
	       Tg = LDW(&(W[TWVL * 6]));
	       T5 = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
	       T6 = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
	       T3 = VFMACONJ(T2, T1);
	       Tj = VZMULIJ(Ti, VFNMSCONJ(T2, T1));
	       T4 = LDW(&(W[TWVL * 4]));
	       T9 = LDW(&(W[TWVL * 2]));
	       Te = VZMULIJ(Tb, VFNMSCONJ(Td, Tc));
	       Th = VZMULJ(Tg, VFMACONJ(Td, Tc));
	       T7 = VZMULIJ(T4, VFNMSCONJ(T6, T5));
	       Ta = VZMULJ(T9, VFMACONJ(T6, T5));
	       Tt = VADD(Tj, Th);
	       Tk = VSUB(Th, Tj);
	       Tr = VADD(T3, T7);
	       T8 = VSUB(T3, T7);
	       Ts = VADD(Ta, Te);
	       Tf = VSUB(Ta, Te);
	       Tx = VMUL(LDK(KP866025403), VSUB(Tt, Ts));
	       Tu = VADD(Ts, Tt);
	       To = VMUL(LDK(KP866025403), VSUB(Tk, Tf));
	       Tl = VADD(Tf, Tk);
	       Tw = VFNMS(LDK(KP500000000), Tu, Tr);
	       Tv = VCONJ(VMUL(LDK(KP500000000), VADD(Tr, Tu)));
	       Tn = VFNMS(LDK(KP500000000), Tl, T8);
	       Tm = VMUL(LDK(KP500000000), VADD(T8, Tl));
	       Tz = VMUL(LDK(KP500000000), VFMAI(Tx, Tw));
	       Ty = VCONJ(VMUL(LDK(KP500000000), VFNMSI(Tx, Tw)));
	       ST(&(Rm[WS(rs, 2)]), Tv, -ms, &(Rm[0]));
	       Tp = VMUL(LDK(KP500000000), VFNMSI(To, Tn));
	       Tq = VCONJ(VMUL(LDK(KP500000000), VFMAI(To, Tn)));
	       ST(&(Rp[0]), Tm, ms, &(Rp[0]));
	       ST(&(Rp[WS(rs, 1)]), Tz, ms, &(Rp[WS(rs, 1)]));
	       ST(&(Rm[0]), Ty, -ms, &(Rm[0]));
	       ST(&(Rm[WS(rs, 1)]), Tq, -ms, &(Rm[WS(rs, 1)]));
	       ST(&(Rp[WS(rs, 2)]), Tp, ms, &(Rp[0]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(1, 1),
     VTW(1, 2),
     VTW(1, 3),
     VTW(1, 4),
     VTW(1, 5),
     {TW_NEXT, VL, 0}
};

static const hc2c_desc desc = { 6, XSIMD_STRING("hc2cfdftv_6"), twinstr, &GENUS, {17, 18, 12, 0} };

void XSIMD(codelet_hc2cfdftv_6) (planner *p) {
     X(khc2c_register) (p, hc2cfdftv_6, &desc, HC2C_VIA_DFT);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2cdft_c.native -simd -compact -variables 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 6 -dit -name hc2cfdftv_6 -include hc2cfv.h */

/*
 * This function contains 29 FP additions, 20 FP multiplications,
 * (or, 27 additions, 18 multiplications, 2 fused multiply/add),
 * 42 stack variables, 3 constants, and 12 memory accesses
 */
#include "hc2cfv.h"

static void hc2cfdftv_6(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 10)); m < me; m = m + VL, Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms), Im = Im - (VL * ms), W = W + (TWVL * 10), MAKE_VOLATILE_STRIDE(24, rs)) {
	       V Ta, Tu, Tn, Tw, Ti, Tv, T1, T8, Tg, Tf, T7, T3, Te, T6, T2;
	       V T4, T9, T5, Tk, Tm, Tj, Tl, Tc, Th, Tb, Td, Tr, Tp, Tq, To;
	       V Tt, Ts, TA, Ty, Tz, Tx, TC, TB;
	       T1 = LD(&(Rp[0]), ms, &(Rp[0]));
	       T8 = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
	       Tg = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
	       Te = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
	       Tf = VCONJ(Te);
	       T6 = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
	       T7 = VCONJ(T6);
	       T2 = LD(&(Rm[0]), -ms, &(Rm[0]));
	       T3 = VCONJ(T2);
	       T4 = VADD(T1, T3);
	       T5 = LDW(&(W[TWVL * 4]));
	       T9 = VZMULIJ(T5, VSUB(T7, T8));
	       Ta = VADD(T4, T9);
	       Tu = VSUB(T4, T9);
	       Tj = LDW(&(W[0]));
	       Tk = VZMULIJ(Tj, VSUB(T3, T1));
	       Tl = LDW(&(W[TWVL * 6]));
	       Tm = VZMULJ(Tl, VADD(Tf, Tg));
	       Tn = VADD(Tk, Tm);
	       Tw = VSUB(Tm, Tk);
	       Tb = LDW(&(W[TWVL * 2]));
	       Tc = VZMULJ(Tb, VADD(T7, T8));
	       Td = LDW(&(W[TWVL * 8]));
	       Th = VZMULIJ(Td, VSUB(Tf, Tg));
	       Ti = VADD(Tc, Th);
	       Tv = VSUB(Tc, Th);
	       Tr = VMUL(LDK(KP500000000), VBYI(VMUL(LDK(KP866025403), VSUB(Tn, Ti))));
	       To = VADD(Ti, Tn);
	       Tp = VMUL(LDK(KP500000000), VADD(Ta, To));
	       Tq = VFNMS(LDK(KP250000000), To, VMUL(LDK(KP500000000), Ta));
	       ST(&(Rp[0]), Tp, ms, &(Rp[0]));
	       Tt = VCONJ(VADD(Tq, Tr));
	       ST(&(Rm[WS(rs, 1)]), Tt, -ms, &(Rm[WS(rs, 1)]));
	       Ts = VSUB(Tq, Tr);
	       ST(&(Rp[WS(rs, 2)]), Ts, ms, &(Rp[0]));
	       TA = VMUL(LDK(KP500000000), VBYI(VMUL(LDK(KP866025403), VSUB(Tw, Tv))));
	       Tx = VADD(Tv, Tw);
	       Ty = VCONJ(VMUL(LDK(KP500000000), VADD(Tu, Tx)));
	       Tz = VFNMS(LDK(KP250000000), Tx, VMUL(LDK(KP500000000), Tu));
	       ST(&(Rm[WS(rs, 2)]), Ty, -ms, &(Rm[0]));
	       TC = VADD(Tz, TA);
	       ST(&(Rp[WS(rs, 1)]), TC, ms, &(Rp[WS(rs, 1)]));
	       TB = VCONJ(VSUB(Tz, TA));
	       ST(&(Rm[0]), TB, -ms, &(Rm[0]));
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(1, 1),
     VTW(1, 2),
     VTW(1, 3),
     VTW(1, 4),
     VTW(1, 5),
     {TW_NEXT, VL, 0}
};

static const hc2c_desc desc = { 6, XSIMD_STRING("hc2cfdftv_6"), twinstr, &GENUS, {27, 18, 2, 0} };

void XSIMD(codelet_hc2cfdftv_6) (planner *p) {
     X(khc2c_register) (p, hc2cfdftv_6, &desc, HC2C_VIA_DFT);
}
#endif				/* HAVE_FMA */
