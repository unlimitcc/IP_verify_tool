#include "VeriHar-main/include/GetSSData.h"
//#include "ma.h"

unsigned char volatile XBYTE[0xFFFF];
unsigned char volatile P1;

void Delay(int time) {}

void GetSSDataFun(void *pIp)
{
    GetSSData *p = (GetSSData*)pIp;
	unint08 si;
	unint08 tmp_ad_start;
	unint16 wd;
	unint16 tmp_hi8;
	unint16 tmp_lo4;

	/* 读EC模拟量 */
	for ( si=0 ; si<2 ; si++ )
	{

		P1 = (P1 & 0xF0) | p->chnl[si];					/* 选择通道 */								   

		Delay(45) ;									        /*500us*/

		/* 启动AD转换 */                                    
		tmp_ad_start = XBYTE[p->ADDR_AD_START] ;			/* 读地址0xA000启动AD转换 */

		Delay(3) ;									        /*40us*/

		tmp_lo4 = XBYTE[p->AD_SS_LO4] ;					/* 0xA003 低4位;8位数据宽度,高4位有效*/

		tmp_hi8 = XBYTE[p->AD_SS_HI8] ;					/* 0xA001 高8位 */

	    /* 拼12位AD转换数据 */
		wd = ((tmp_hi8 << 4) & 0x0FF0 ) | ((tmp_lo4 >> 4) & 0xF) ;									  

        if (si == 0)
        {
            p->royaw = DIVIATION_TO_FLOAT_DSS(wd);  /* SS 当量:  2.44140625e-3f */
        }
        else
        {
            p->piyaw = DIVIATION_TO_FLOAT_DSS(wd);  /* SS 当量:  2.44140625e-3f */
        }
	}

    p->flgSp = ( XBYTE[p->SP_ADDR] >> p->SP_BIT ) & 0x01 ;	/* SP标志 */
    return;
}
