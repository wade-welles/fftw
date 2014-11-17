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
/* Generated on Tue Mar  4 13:46:59 EST 2014 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 14 -name n2bv_14 -with-ostride 2 -include n2b.h -store-multiple 2 */

/*
 * This function contains 74 FP additions, 48 FP multiplications,
 * (or, 32 additions, 6 multiplications, 42 fused multiply/add),
 * 65 stack variables, 6 constants, and 35 memory accesses
 */
#include "n2b.h"

static void n2bv_14(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP801937735, +0.801937735804838252472204639014890102331838324);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DVK(KP692021471, +0.692021471630095869627814897002069140197260599);
     DVK(KP554958132, +0.554958132087371191422194871006410481067288862);
     DVK(KP356895867, +0.356895867892209443894399510021300583399127187);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(28, is), MAKE_VOLATILE_STRIDE(28, os)) {
	       V TH, T3, TP, Tn, Ta, Tu, TU, TK, TO, Tk, TM, Tg, TL, Td, T1;
	       V T2;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
	       {
		    V Ti, TI, T6, TJ, T9, Tj, Te, Tf, Tb, Tc;
		    {
			 V T4, T5, T7, T8, Tl, Tm;
			 T4 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 T7 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			 T8 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			 Tl = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 Tm = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Ti = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 TH = VADD(T1, T2);
			 T3 = VSUB(T1, T2);
			 TI = VADD(T4, T5);
			 T6 = VSUB(T4, T5);
			 TJ = VADD(T7, T8);
			 T9 = VSUB(T7, T8);
			 TP = VADD(Tl, Tm);
			 Tn = VSUB(Tl, Tm);
			 Tj = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
			 Te = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
			 Tf = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 Tb = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
		    }
		    Ta = VADD(T6, T9);
		    Tu = VSUB(T6, T9);
		    TU = VSUB(TI, TJ);
		    TK = VADD(TI, TJ);
		    TO = VADD(Ti, Tj);
		    Tk = VSUB(Ti, Tj);
		    TM = VADD(Te, Tf);
		    Tg = VSUB(Te, Tf);
		    TL = VADD(Tb, Tc);
		    Td = VSUB(Tb, Tc);
	       }
	       {
		    V T19, T1a, T13, TG, TY, T18, TB, Tw, TT, Tz, T11, T16, TE, Tr, TV;
		    V TQ;
		    TV = VSUB(TP, TO);
		    TQ = VADD(TO, TP);
		    {
			 V Ts, To, TW, TN;
			 Ts = VSUB(Tk, Tn);
			 To = VADD(Tk, Tn);
			 TW = VSUB(TM, TL);
			 TN = VADD(TL, TM);
			 {
			      V Tt, Th, TR, T12;
			      Tt = VSUB(Td, Tg);
			      Th = VADD(Td, Tg);
			      TR = VFNMS(LDK(KP356895867), TK, TQ);
			      T12 = VFNMS(LDK(KP554958132), TV, TU);
			      {
				   V Tx, TF, TZ, T14;
				   Tx = VFNMS(LDK(KP356895867), Ta, To);
				   TF = VFMA(LDK(KP554958132), Ts, Tu);
				   T19 = VADD(TH, VADD(TK, VADD(TN, TQ)));
				   STM2(&(xo[0]), T19, ovs, &(xo[0]));
				   TZ = VFNMS(LDK(KP356895867), TN, TK);
				   T14 = VFNMS(LDK(KP356895867), TQ, TN);
				   {
					V TX, T17, TC, Tp;
					TX = VFMA(LDK(KP554958132), TW, TV);
					T17 = VFMA(LDK(KP554958132), TU, TW);
					T1a = VADD(T3, VADD(Ta, VADD(Th, To)));
					STM2(&(xo[14]), T1a, ovs, &(xo[2]));
					TC = VFNMS(LDK(KP356895867), Th, Ta);
					Tp = VFNMS(LDK(KP356895867), To, Th);
					{
					     V TA, Tv, TS, Ty;
					     TA = VFMA(LDK(KP554958132), Tt, Ts);
					     Tv = VFNMS(LDK(KP554958132), Tu, Tt);
					     TS = VFNMS(LDK(KP692021471), TR, TN);
					     T13 = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), T12, TW));
					     Ty = VFNMS(LDK(KP692021471), Tx, Th);
					     TG = VMUL(LDK(KP974927912), VFMA(LDK(KP801937735), TF, Tt));
					     {
						  V T10, T15, TD, Tq;
						  T10 = VFNMS(LDK(KP692021471), TZ, TQ);
						  T15 = VFNMS(LDK(KP692021471), T14, TK);
						  TY = VMUL(LDK(KP974927912), VFMA(LDK(KP801937735), TX, TU));
						  T18 = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), T17, TV));
						  TD = VFNMS(LDK(KP692021471), TC, To);
						  Tq = VFNMS(LDK(KP692021471), Tp, Ta);
						  TB = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), TA, Tu));
						  Tw = VMUL(LDK(KP974927912), VFNMS(LDK(KP801937735), Tv, Ts));
						  TT = VFNMS(LDK(KP900968867), TS, TH);
						  Tz = VFNMS(LDK(KP900968867), Ty, T3);
						  T11 = VFNMS(LDK(KP900968867), T10, TH);
						  T16 = VFNMS(LDK(KP900968867), T15, TH);
						  TE = VFNMS(LDK(KP900968867), TD, T3);
						  Tr = VFNMS(LDK(KP900968867), Tq, T3);
					     }
					}
				   }
			      }
			 }
		    }
		    {
			 V T1b, T1c, T1d, T1e;
			 T1b = VFMAI(TY, TT);
			 STM2(&(xo[4]), T1b, ovs, &(xo[0]));
			 T1c = VFNMSI(TY, TT);
			 STM2(&(xo[24]), T1c, ovs, &(xo[0]));
			 T1d = VFMAI(TB, Tz);
			 STM2(&(xo[18]), T1d, ovs, &(xo[2]));
			 T1e = VFNMSI(TB, Tz);
			 STM2(&(xo[10]), T1e, ovs, &(xo[2]));
			 {
			      V T1f, T1g, T1h, T1i;
			      T1f = VFMAI(T13, T11);
			      STM2(&(xo[12]), T1f, ovs, &(xo[0]));
			      STN2(&(xo[12]), T1f, T1a, ovs);
			      T1g = VFNMSI(T13, T11);
			      STM2(&(xo[16]), T1g, ovs, &(xo[0]));
			      STN2(&(xo[16]), T1g, T1d, ovs);
			      T1h = VFMAI(T18, T16);
			      STM2(&(xo[8]), T1h, ovs, &(xo[0]));
			      STN2(&(xo[8]), T1h, T1e, ovs);
			      T1i = VFNMSI(T18, T16);
			      STM2(&(xo[20]), T1i, ovs, &(xo[0]));
			      {
				   V T1j, T1k, T1l, T1m;
				   T1j = VFNMSI(TG, TE);
				   STM2(&(xo[26]), T1j, ovs, &(xo[2]));
				   STN2(&(xo[24]), T1c, T1j, ovs);
				   T1k = VFMAI(TG, TE);
				   STM2(&(xo[2]), T1k, ovs, &(xo[2]));
				   STN2(&(xo[0]), T19, T1k, ovs);
				   T1l = VFNMSI(Tw, Tr);
				   STM2(&(xo[22]), T1l, ovs, &(xo[2]));
				   STN2(&(xo[20]), T1i, T1l, ovs);
				   T1m = VFMAI(Tw, Tr);
				   STM2(&(xo[6]), T1m, ovs, &(xo[2]));
				   STN2(&(xo[4]), T1b, T1m, ovs);
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 14, XSIMD_STRING("n2bv_14"), {32, 6, 42, 0}, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2bv_14) (planner *p) {
     X(kdft_register) (p, n2bv_14, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 14 -name n2bv_14 -with-ostride 2 -include n2b.h -store-multiple 2 */

/*
 * This function contains 74 FP additions, 36 FP multiplications,
 * (or, 50 additions, 12 multiplications, 24 fused multiply/add),
 * 41 stack variables, 6 constants, and 35 memory accesses
 */
#include "n2b.h"

static void n2bv_14(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP900968867, +0.900968867902419126236102319507445051165919162);
     DVK(KP222520933, +0.222520933956314404288902564496794759466355569);
     DVK(KP623489801, +0.623489801858733530525004884004239810632274731);
     DVK(KP781831482, +0.781831482468029808708444526674057750232334519);
     DVK(KP974927912, +0.974927912181823607018131682993931217232785801);
     DVK(KP433883739, +0.433883739117558120475768332848358754609990728);
     {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(28, is), MAKE_VOLATILE_STRIDE(28, os)) {
	       V Tp, Ty, Tl, TL, Tq, TE, T7, TJ, Ts, TB, Te, TK, Tr, TH, Tn;
	       V To;
	       Tn = LD(&(xi[0]), ivs, &(xi[0]));
	       To = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
	       Tp = VSUB(Tn, To);
	       Ty = VADD(Tn, To);
	       {
		    V Th, TC, Tk, TD;
		    {
			 V Tf, Tg, Ti, Tj;
			 Tf = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
			 Tg = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 Th = VSUB(Tf, Tg);
			 TC = VADD(Tf, Tg);
			 Ti = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
			 Tj = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 Tk = VSUB(Ti, Tj);
			 TD = VADD(Ti, Tj);
		    }
		    Tl = VSUB(Th, Tk);
		    TL = VSUB(TD, TC);
		    Tq = VADD(Th, Tk);
		    TE = VADD(TC, TD);
	       }
	       {
		    V T3, Tz, T6, TA;
		    {
			 V T1, T2, T4, T5;
			 T1 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 T2 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			 T3 = VSUB(T1, T2);
			 Tz = VADD(T1, T2);
			 T4 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			 T5 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			 T6 = VSUB(T4, T5);
			 TA = VADD(T4, T5);
		    }
		    T7 = VSUB(T3, T6);
		    TJ = VSUB(Tz, TA);
		    Ts = VADD(T3, T6);
		    TB = VADD(Tz, TA);
	       }
	       {
		    V Ta, TF, Td, TG;
		    {
			 V T8, T9, Tb, Tc;
			 T8 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 T9 = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
			 Ta = VSUB(T8, T9);
			 TF = VADD(T8, T9);
			 Tb = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			 Tc = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			 Td = VSUB(Tb, Tc);
			 TG = VADD(Tb, Tc);
		    }
		    Te = VSUB(Ta, Td);
		    TK = VSUB(TG, TF);
		    Tr = VADD(Ta, Td);
		    TH = VADD(TF, TG);
	       }
	       {
		    V TR, TS, TU, TV;
		    TR = VADD(Tp, VADD(Ts, VADD(Tq, Tr)));
		    STM2(&(xo[14]), TR, ovs, &(xo[2]));
		    TS = VADD(Ty, VADD(TB, VADD(TE, TH)));
		    STM2(&(xo[0]), TS, ovs, &(xo[0]));
		    {
			 V TT, Tm, Tt, TQ, TP, TW;
			 Tm = VBYI(VFMA(LDK(KP433883739), T7, VFNMS(LDK(KP781831482), Tl, VMUL(LDK(KP974927912), Te))));
			 Tt = VFMA(LDK(KP623489801), Tq, VFNMS(LDK(KP222520933), Tr, VFNMS(LDK(KP900968867), Ts, Tp)));
			 TT = VADD(Tm, Tt);
			 STM2(&(xo[6]), TT, ovs, &(xo[2]));
			 TU = VSUB(Tt, Tm);
			 STM2(&(xo[22]), TU, ovs, &(xo[2]));
			 TQ = VBYI(VFMA(LDK(KP974927912), TJ, VFMA(LDK(KP433883739), TL, VMUL(LDK(KP781831482), TK))));
			 TP = VFMA(LDK(KP623489801), TH, VFNMS(LDK(KP900968867), TE, VFNMS(LDK(KP222520933), TB, Ty)));
			 TV = VSUB(TP, TQ);
			 STM2(&(xo[24]), TV, ovs, &(xo[0]));
			 TW = VADD(TP, TQ);
			 STM2(&(xo[4]), TW, ovs, &(xo[0]));
			 STN2(&(xo[4]), TW, TT, ovs);
		    }
		    {
			 V T10, TM, TI, TZ;
			 {
			      V Tu, Tv, TX, TY;
			      Tu = VBYI(VFMA(LDK(KP781831482), T7, VFMA(LDK(KP974927912), Tl, VMUL(LDK(KP433883739), Te))));
			      Tv = VFMA(LDK(KP623489801), Ts, VFNMS(LDK(KP900968867), Tr, VFNMS(LDK(KP222520933), Tq, Tp)));
			      TX = VADD(Tu, Tv);
			      STM2(&(xo[2]), TX, ovs, &(xo[2]));
			      STN2(&(xo[0]), TS, TX, ovs);
			      TY = VSUB(Tv, Tu);
			      STM2(&(xo[26]), TY, ovs, &(xo[2]));
			      STN2(&(xo[24]), TV, TY, ovs);
			 }
			 TM = VBYI(VFNMS(LDK(KP433883739), TK, VFNMS(LDK(KP974927912), TL, VMUL(LDK(KP781831482), TJ))));
			 TI = VFMA(LDK(KP623489801), TB, VFNMS(LDK(KP900968867), TH, VFNMS(LDK(KP222520933), TE, Ty)));
			 TZ = VSUB(TI, TM);
			 STM2(&(xo[12]), TZ, ovs, &(xo[0]));
			 STN2(&(xo[12]), TZ, TR, ovs);
			 T10 = VADD(TI, TM);
			 STM2(&(xo[16]), T10, ovs, &(xo[0]));
			 {
			      V T11, TO, TN, T12;
			      TO = VBYI(VFMA(LDK(KP433883739), TJ, VFNMS(LDK(KP974927912), TK, VMUL(LDK(KP781831482), TL))));
			      TN = VFMA(LDK(KP623489801), TE, VFNMS(LDK(KP222520933), TH, VFNMS(LDK(KP900968867), TB, Ty)));
			      T11 = VSUB(TN, TO);
			      STM2(&(xo[8]), T11, ovs, &(xo[0]));
			      T12 = VADD(TN, TO);
			      STM2(&(xo[20]), T12, ovs, &(xo[0]));
			      STN2(&(xo[20]), T12, TU, ovs);
			      {
				   V Tx, Tw, T13, T14;
				   Tx = VBYI(VFNMS(LDK(KP781831482), Te, VFNMS(LDK(KP433883739), Tl, VMUL(LDK(KP974927912), T7))));
				   Tw = VFMA(LDK(KP623489801), Tr, VFNMS(LDK(KP900968867), Tq, VFNMS(LDK(KP222520933), Ts, Tp)));
				   T13 = VSUB(Tw, Tx);
				   STM2(&(xo[10]), T13, ovs, &(xo[2]));
				   STN2(&(xo[8]), T11, T13, ovs);
				   T14 = VADD(Tx, Tw);
				   STM2(&(xo[18]), T14, ovs, &(xo[2]));
				   STN2(&(xo[16]), T10, T14, ovs);
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 14, XSIMD_STRING("n2bv_14"), {50, 12, 24, 0}, &GENUS, 0, 2, 0, 0 };

void XSIMD(codelet_n2bv_14) (planner *p) {
     X(kdft_register) (p, n2bv_14, &desc);
}

#endif				/* HAVE_FMA */
