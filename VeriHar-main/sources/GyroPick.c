#include "VeriHar-main/include/GyroPick.h"

void GyroPickFun(void *pIp)
{
    GyroPick *p = (GyroPick*)pIp;
    unint08 iy ;									
    float32 tmpgi ;									

    for ( iy=0 ; iy<9 ; iy++ )
    {
        
        tmpgi = ABS(p->wa[iy] - p->wal[iy]) ;	/* 角度增量剔野处理 */				
                                                            
        if (tmpgi > p->waThr)     				/* 剔野限0.08° */
        {                                                   
            p->countPick[iy]++ ;					/* 野值计数器 */

            if (p->countPick[iy] < p->pickThr)  /* 没有6次连续野值 */
            {
                p->wa_out[iy] = p->wal[iy] ;	/* 用上周期的值代替本周期的值 */
                
            }
            else                                	/* 连续6周期野值 */         
            {
                p->wal[iy] = p->wa[iy] ;		/* 用本周期的值代替上周期的值 */
                p->wa_out[iy] = p->wa[iy];
                p->countPick[iy] = 0 ;			/* 替代后，野值计数器清零 */
                
            }
        }
        else                     					/* 没有超出剔野限 */
        {
            p->wal[iy] = p->wa[iy] ;			/* 用新值 */
            p->wa_out[iy] = p->wa[iy];
            p->countPick[iy] = 0 ;				/* 野值计数器清零 */
        }
    }
    return;
}
