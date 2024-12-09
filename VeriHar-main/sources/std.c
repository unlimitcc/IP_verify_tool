#include "VeriHar-main/include/IP.h"

/* 功能： 矩阵/向量的转置,注意源和目标矩阵/向量不能是同一个 */
void MatrixTran(float32 *tran, 
          const float32 *mat, 
                unint08 nrow, 
                unint08 ncol)
{
	/* 注意源和目标矩阵/向量不能是同一个 */     
    unint08 i ;		/* 矩阵行循环变量 */   							
    unint08 j ;		/* 矩阵列循环变量 */   							

   /* tran:目标矩阵 */    
   /* mat: 源矩阵 */      
   /* nrow:矩阵行数 */    
   /* ncol:矩阵列数 */    

    for ( i=0 ; i<nrow ; i++ )                              /* 行循环 */     
    {                                                                        
        for ( j=0 ; j<ncol ; j++ )                          /* 列循环 */     
        {
            *(tran + j * nrow + i) = *(mat + i * ncol + j) ;									
        }
    }

    return ;									
}

/* 功能：两个矩阵/向量相乘 */
void MatrixMulti(float32 *product,
                 const float32 *faciend,
                 const float32 *multiplier,
                 unint08 nrow,
                 unint08 nrc,
                 unint08 ncol)
{
    unint08 ir ;			                                /* 行循环变量 */              						
    unint08 jc ;			                                /* 列循环变量 */              						
    unint08 nk ;			                                /* 求积后做加个数 */          						
    unint08 index ;			                                /* 矩阵计算结果位置 */        	
                                                            
    /* product:求和结果矩阵指针 */                          
    /* faciend:求和矩阵 */                                  
    /* multiplier:被求和矩阵 */                             
    /* nrow:矩阵行数 */                                     
    /* nrc:求积后做加个数 */                                
    /* ncol:矩阵列数 */					                    
                                                            
    for (ir=0 ; ir<nrow ; ir++)                             /* 行循环 */                   
    {                                                                                      
        for (jc=0 ; jc<ncol ; jc++)                         /* 列循环 */                   
        {                                                                                  
            index = ir * ncol + jc ;		                /* 矩阵计算结果位置 */         							
                                                                                           
            product[index] = 0.0f ;			                /* 乘积结果默认取0 */          						
                                                                                           
            for (nk=0 ; nk<nrc ; nk++)                      /* 求积后做加个数循环 */       
            {
                product[index] = product[index] + faciend[ir * nrc + nk] * multiplier[nk * ncol + jc] ;									
            }
        }
    }
    
    return ;									
}

/***********************************************************************************************
功能：单精度3×3矩阵求逆
***********************************************************************************************/
unint08 MatrixInv33F(float32 *inv, const float32 *src)
{
    siint08 i;
    float32 rank;
    unint08 bAbleInv;   /* TRUE32:矩阵可逆 */
    
    /* inv:输出结果矩阵指针 */
    /* src:输如计算矩阵指针 */

    /* 默认不可逆 */
    bAbleInv = FALSE;

    inv[0] = src[4] * src[8] - src[5] * src[7];             /* 第1行第1列 */
    inv[1] = src[2] * src[7] - src[1] * src[8];             /* 第1行第2列 */
    inv[2] = src[1] * src[5] - src[2] * src[4];             /* 第1行第3列 */
    inv[3] = src[5] * src[6] - src[3] * src[8];             /* 第2行第1列 */
    inv[4] = src[0] * src[8] - src[2] * src[6];             /* 第2行第2列 */
    inv[5] = src[2] * src[3] - src[0] * src[5];             /* 第2行第3列 */
    inv[6] = src[3] * src[7] - src[4] * src[6];             /* 第3行第1列 */
    inv[7] = src[1] * src[6] - src[0] * src[7];             /* 第3行第2列 */
    inv[8] = src[0] * src[4] - src[1] * src[3];             /* 第3行第3列 */

    /* 求矩阵的行列式值 */
    rank = src[0] * inv[0] + src[1] * inv[3] + src[2] * inv[6];

   
    if ((FLT32_ZERO < rank) || (rank < -FLT32_ZERO))         /* 不等于浮点数0 */
    {
        
        bAbleInv = TRUE;                                     /* 矩阵可逆 */

        for (i=0; i<9; i++)                                  /* 行列式 */
        {
            inv[i] = inv[i] / rank;
        }
    }
    else
    {
        /* 矩阵不可逆时与原矩阵一致 */
        for (i=0; i<9; i++)
        {
            inv[i] = src[i];
        }
    }

    return bAbleInv;
}

/***********************************
编写：, 日期：
输入：限幅前的值x，限幅范围halfperiod
输出：限幅后的值
功能：限在(-divisor, divisor)之间
***********************************/
