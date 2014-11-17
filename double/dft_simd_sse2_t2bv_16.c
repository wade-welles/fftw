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
/* Generated on Tue Mar  4 13:47:40 EST 2014 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 16 -name t2bv_16 -include t2b.h -sign 1 */

/*
 * This function contains 87 FP additions, 64 FP multiplications,
 * (or, 53 additions, 30 multiplications, 34 fused multiply/add),
 * 61 stack variables, 3 constants, and 32 memory accesses
 */
#include "t2b.h"

static void t2bv_16(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP414213562, +0.414213562373095048801688724209698078569671875);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 30)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 30), MAKE_VOLATILE_STRIDE(16, rs)) {
	       V TO, Ta, TJ, TP, T14, Tq, T1i, T10, T1b, T1l, T13, T1c, TR, Tl, T15;
	       V Tv;
	       {
		    V Tc, TW, T4, T19, T9, TD, TI, Tj, TZ, T1a, Te, Th, Tn, Tr, Tu;
		    V Tp;
		    {
			 V T1, T2, T5, T7;
			 T1 = LD(&(x[0]), ms, &(x[0]));
			 T2 = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 T5 = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 T7 = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
			 {
			      V Tz, TG, TB, TE;
			      Tz = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			      TG = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			      TB = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
			      TE = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			      {
				   V Ti, TX, TY, Td, Tg, Tm, Tt, To;
				   {
					V T3, T6, T8, TA, TH, TC, TF, Tb;
					Tb = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
					T3 = BYTW(&(W[TWVL * 14]), T2);
					T6 = BYTW(&(W[TWVL * 6]), T5);
					T8 = BYTW(&(W[TWVL * 22]), T7);
					TA = BYTW(&(W[TWVL * 2]), Tz);
					TH = BYTW(&(W[TWVL * 10]), TG);
					TC = BYTW(&(W[TWVL * 18]), TB);
					TF = BYTW(&(W[TWVL * 26]), TE);
					Tc = BYTW(&(W[0]), Tb);
					TW = VSUB(T1, T3);
					T4 = VADD(T1, T3);
					T19 = VSUB(T6, T8);
					T9 = VADD(T6, T8);
					Ti = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
					TD = VADD(TA, TC);
					TX = VSUB(TA, TC);
					TI = VADD(TF, TH);
					TY = VSUB(TF, TH);
				   }
				   Td = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
				   Tg = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
				   Tm = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
				   Tj = BYTW(&(W[TWVL * 24]), Ti);
				   Tt = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
				   To = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
				   TZ = VADD(TX, TY);
				   T1a = VSUB(TX, TY);
				   Te = BYTW(&(W[TWVL * 16]), Td);
				   Th = BYTW(&(W[TWVL * 8]), Tg);
				   Tn = BYTW(&(W[TWVL * 28]), Tm);
				   Tr = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
				   Tu = BYTW(&(W[TWVL * 20]), Tt);
				   Tp = BYTW(&(W[TWVL * 12]), To);
			      }
			 }
		    }
		    {
			 V Tf, T11, Tk, T12, Ts;
			 TO = VADD(T4, T9);
			 Ta = VSUB(T4, T9);
			 TJ = VSUB(TD, TI);
			 TP = VADD(TD, TI);
			 Tf = VADD(Tc, Te);
			 T11 = VSUB(Tc, Te);
			 Tk = VADD(Th, Tj);
			 T12 = VSUB(Th, Tj);
			 Ts = BYTW(&(W[TWVL * 4]), Tr);
			 T14 = VSUB(Tn, Tp);
			 Tq = VADD(Tn, Tp);
			 T1i = VFNMS(LDK(KP707106781), TZ, TW);
			 T10 = VFMA(LDK(KP707106781), TZ, TW);
			 T1b = VFMA(LDK(KP707106781), T1a, T19);
			 T1l = VFNMS(LDK(KP707106781), T1a, T19);
			 T13 = VFNMS(LDK(KP414213562), T12, T11);
			 T1c = VFMA(LDK(KP414213562), T11, T12);
			 TR = VADD(Tf, Tk);
			 Tl = VSUB(Tf, Tk);
			 T15 = VSUB(Tu, Ts);
			 Tv = VADD(Ts, Tu);
		    }
	       }
	       {
		    V T1d, T16, TS, Tw, TU, TQ;
		    T1d = VFMA(LDK(KP414213562), T14, T15);
		    T16 = VFNMS(LDK(KP414213562), T15, T14);
		    TS = VADD(Tq, Tv);
		    Tw = VSUB(Tq, Tv);
		    TU = VADD(TO, TP);
		    TQ = VSUB(TO, TP);
		    {
			 V T1e, T1j, T17, T1m;
			 T1e = VSUB(T1c, T1d);
			 T1j = VADD(T1c, T1d);
			 T17 = VADD(T13, T16);
			 T1m = VSUB(T13, T16);
			 {
			      V TV, TT, TK, Tx;
			      TV = VADD(TR, TS);
			      TT = VSUB(TR, TS);
			      TK = VSUB(Tl, Tw);
			      Tx = VADD(Tl, Tw);
			      {
				   V T1h, T1f, T1o, T1k;
				   T1h = VFMA(LDK(KP923879532), T1e, T1b);
				   T1f = VFNMS(LDK(KP923879532), T1e, T1b);
				   T1o = VFMA(LDK(KP923879532), T1j, T1i);
				   T1k = VFNMS(LDK(KP923879532), T1j, T1i);
				   {
					V T1g, T18, T1p, T1n;
					T1g = VFMA(LDK(KP923879532), T17, T10);
					T18 = VFNMS(LDK(KP923879532), T17, T10);
					T1p = VFNMS(LDK(KP923879532), T1m, T1l);
					T1n = VFMA(LDK(KP923879532), T1m, T1l);
					ST(&(x[WS(rs, 8)]), VSUB(TU, TV), ms, &(x[0]));
					ST(&(x[0]), VADD(TU, TV), ms, &(x[0]));
					ST(&(x[WS(rs, 4)]), VFMAI(TT, TQ), ms, &(x[0]));
					ST(&(x[WS(rs, 12)]), VFNMSI(TT, TQ), ms, &(x[0]));
					{
					     V TN, TL, TM, Ty;
					     TN = VFMA(LDK(KP707106781), TK, TJ);
					     TL = VFNMS(LDK(KP707106781), TK, TJ);
					     TM = VFMA(LDK(KP707106781), Tx, Ta);
					     Ty = VFNMS(LDK(KP707106781), Tx, Ta);
					     ST(&(x[WS(rs, 15)]), VFNMSI(T1h, T1g), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 1)]), VFMAI(T1h, T1g), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 9)]), VFMAI(T1f, T18), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 7)]), VFNMSI(T1f, T18), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 3)]), VFNMSI(T1p, T1o), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 13)]), VFMAI(T1p, T1o), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 11)]), VFNMSI(T1n, T1k), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 5)]), VFMAI(T1n, T1k), ms, &(x[WS(rs, 1)]));
					     ST(&(x[WS(rs, 2)]), VFMAI(TN, TM), ms, &(x[0]));
					     ST(&(x[WS(rs, 14)]), VFNMSI(TN, TM), ms, &(x[0]));
					     ST(&(x[WS(rs, 10)]), VFMAI(TL, Ty), ms, &(x[0]));
					     ST(&(x[WS(rs, 6)]), VFNMSI(TL, Ty), ms, &(x[0]));
					}
				   }
			      }
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     VTW(0, 15),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 16, XSIMD_STRING("t2bv_16"), twinstr, &GENUS, {53, 30, 34, 0}, 0, 0, 0 };

void XSIMD(codelet_t2bv_16) (planner *p) {
     X(kdft_dit_register) (p, t2bv_16, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 16 -name t2bv_16 -include t2b.h -sign 1 */

/*
 * This function contains 87 FP additions, 42 FP multiplications,
 * (or, 83 additions, 38 multiplications, 4 fused multiply/add),
 * 36 stack variables, 3 constants, and 32 memory accesses
 */
#include "t2b.h"

static void t2bv_16(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  INT m;
	  R *x;
	  x = ii;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 30)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 30), MAKE_VOLATILE_STRIDE(16, rs)) {
	       V TJ, T1b, TD, T1c, T17, T18, Ty, TK, T10, T11, T12, Tb, TM, T13, T14;
	       V T15, Tm, TN, TG, TI, TH;
	       TG = LD(&(x[0]), ms, &(x[0]));
	       TH = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
	       TI = BYTW(&(W[TWVL * 14]), TH);
	       TJ = VSUB(TG, TI);
	       T1b = VADD(TG, TI);
	       {
		    V TA, TC, Tz, TB;
		    Tz = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
		    TA = BYTW(&(W[TWVL * 6]), Tz);
		    TB = LD(&(x[WS(rs, 12)]), ms, &(x[0]));
		    TC = BYTW(&(W[TWVL * 22]), TB);
		    TD = VSUB(TA, TC);
		    T1c = VADD(TA, TC);
	       }
	       {
		    V Tp, Tw, Tr, Tu, Ts, Tx;
		    {
			 V To, Tv, Tq, Tt;
			 To = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 Tp = BYTW(&(W[TWVL * 2]), To);
			 Tv = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Tw = BYTW(&(W[TWVL * 10]), Tv);
			 Tq = LD(&(x[WS(rs, 10)]), ms, &(x[0]));
			 Tr = BYTW(&(W[TWVL * 18]), Tq);
			 Tt = LD(&(x[WS(rs, 14)]), ms, &(x[0]));
			 Tu = BYTW(&(W[TWVL * 26]), Tt);
		    }
		    T17 = VADD(Tp, Tr);
		    T18 = VADD(Tu, Tw);
		    Ts = VSUB(Tp, Tr);
		    Tx = VSUB(Tu, Tw);
		    Ty = VMUL(LDK(KP707106781), VSUB(Ts, Tx));
		    TK = VMUL(LDK(KP707106781), VADD(Ts, Tx));
	       }
	       {
		    V T2, T9, T4, T7, T5, Ta;
		    {
			 V T1, T8, T3, T6;
			 T1 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 T2 = BYTW(&(W[0]), T1);
			 T8 = LD(&(x[WS(rs, 13)]), ms, &(x[WS(rs, 1)]));
			 T9 = BYTW(&(W[TWVL * 24]), T8);
			 T3 = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 T4 = BYTW(&(W[TWVL * 16]), T3);
			 T6 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
			 T7 = BYTW(&(W[TWVL * 8]), T6);
		    }
		    T10 = VADD(T2, T4);
		    T11 = VADD(T7, T9);
		    T12 = VSUB(T10, T11);
		    T5 = VSUB(T2, T4);
		    Ta = VSUB(T7, T9);
		    Tb = VFNMS(LDK(KP382683432), Ta, VMUL(LDK(KP923879532), T5));
		    TM = VFMA(LDK(KP382683432), T5, VMUL(LDK(KP923879532), Ta));
	       }
	       {
		    V Td, Tk, Tf, Ti, Tg, Tl;
		    {
			 V Tc, Tj, Te, Th;
			 Tc = LD(&(x[WS(rs, 15)]), ms, &(x[WS(rs, 1)]));
			 Td = BYTW(&(W[TWVL * 28]), Tc);
			 Tj = LD(&(x[WS(rs, 11)]), ms, &(x[WS(rs, 1)]));
			 Tk = BYTW(&(W[TWVL * 20]), Tj);
			 Te = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 Tf = BYTW(&(W[TWVL * 12]), Te);
			 Th = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 Ti = BYTW(&(W[TWVL * 4]), Th);
		    }
		    T13 = VADD(Td, Tf);
		    T14 = VADD(Ti, Tk);
		    T15 = VSUB(T13, T14);
		    Tg = VSUB(Td, Tf);
		    Tl = VSUB(Ti, Tk);
		    Tm = VFMA(LDK(KP923879532), Tg, VMUL(LDK(KP382683432), Tl));
		    TN = VFNMS(LDK(KP382683432), Tg, VMUL(LDK(KP923879532), Tl));
	       }
	       {
		    V T1a, T1g, T1f, T1h;
		    {
			 V T16, T19, T1d, T1e;
			 T16 = VMUL(LDK(KP707106781), VSUB(T12, T15));
			 T19 = VSUB(T17, T18);
			 T1a = VBYI(VSUB(T16, T19));
			 T1g = VBYI(VADD(T19, T16));
			 T1d = VSUB(T1b, T1c);
			 T1e = VMUL(LDK(KP707106781), VADD(T12, T15));
			 T1f = VSUB(T1d, T1e);
			 T1h = VADD(T1d, T1e);
		    }
		    ST(&(x[WS(rs, 6)]), VADD(T1a, T1f), ms, &(x[0]));
		    ST(&(x[WS(rs, 14)]), VSUB(T1h, T1g), ms, &(x[0]));
		    ST(&(x[WS(rs, 10)]), VSUB(T1f, T1a), ms, &(x[0]));
		    ST(&(x[WS(rs, 2)]), VADD(T1g, T1h), ms, &(x[0]));
	       }
	       {
		    V T1k, T1o, T1n, T1p;
		    {
			 V T1i, T1j, T1l, T1m;
			 T1i = VADD(T1b, T1c);
			 T1j = VADD(T17, T18);
			 T1k = VSUB(T1i, T1j);
			 T1o = VADD(T1i, T1j);
			 T1l = VADD(T10, T11);
			 T1m = VADD(T13, T14);
			 T1n = VBYI(VSUB(T1l, T1m));
			 T1p = VADD(T1l, T1m);
		    }
		    ST(&(x[WS(rs, 12)]), VSUB(T1k, T1n), ms, &(x[0]));
		    ST(&(x[0]), VADD(T1o, T1p), ms, &(x[0]));
		    ST(&(x[WS(rs, 4)]), VADD(T1k, T1n), ms, &(x[0]));
		    ST(&(x[WS(rs, 8)]), VSUB(T1o, T1p), ms, &(x[0]));
	       }
	       {
		    V TF, TQ, TP, TR;
		    {
			 V Tn, TE, TL, TO;
			 Tn = VSUB(Tb, Tm);
			 TE = VSUB(Ty, TD);
			 TF = VBYI(VSUB(Tn, TE));
			 TQ = VBYI(VADD(TE, Tn));
			 TL = VSUB(TJ, TK);
			 TO = VSUB(TM, TN);
			 TP = VSUB(TL, TO);
			 TR = VADD(TL, TO);
		    }
		    ST(&(x[WS(rs, 5)]), VADD(TF, TP), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 13)]), VSUB(TR, TQ), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 11)]), VSUB(TP, TF), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 3)]), VADD(TQ, TR), ms, &(x[WS(rs, 1)]));
	       }
	       {
		    V TU, TY, TX, TZ;
		    {
			 V TS, TT, TV, TW;
			 TS = VADD(TJ, TK);
			 TT = VADD(Tb, Tm);
			 TU = VADD(TS, TT);
			 TY = VSUB(TS, TT);
			 TV = VADD(TD, Ty);
			 TW = VADD(TM, TN);
			 TX = VBYI(VADD(TV, TW));
			 TZ = VBYI(VSUB(TW, TV));
		    }
		    ST(&(x[WS(rs, 15)]), VSUB(TU, TX), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 7)]), VADD(TY, TZ), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 1)]), VADD(TU, TX), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 9)]), VSUB(TY, TZ), ms, &(x[WS(rs, 1)]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     VTW(0, 10),
     VTW(0, 11),
     VTW(0, 12),
     VTW(0, 13),
     VTW(0, 14),
     VTW(0, 15),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 16, XSIMD_STRING("t2bv_16"), twinstr, &GENUS, {83, 38, 4, 0}, 0, 0, 0 };

void XSIMD(codelet_t2bv_16) (planner *p) {
     X(kdft_dit_register) (p, t2bv_16, &desc);
}
#endif				/* HAVE_FMA */
