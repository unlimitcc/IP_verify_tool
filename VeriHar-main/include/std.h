#if !defined(__STD_H__)
#define __STD_H__

#include "std/std_basal.h"
#include "IP.h"

float32 ModPNHP(float32 x, float32 halfperiod);
void MatrixTran(float32 *tran, const float32 *mat, unint08 nrow, unint08 ncol);
void MatrixMulti(float32 *product,const float32 *faciend,const float32 *multiplier,unint08 nrow,unint08 nrc,unint08 ncol);
unint08 MatrixInv33F(float32 *inv, const float32 *src);
float32 TripleFabsMax(float32 fx1, float32 fy2, float32 fz3);
float32 LimitFloat32(float32 fin, float32 fbound);
#endif // __STD_H__

