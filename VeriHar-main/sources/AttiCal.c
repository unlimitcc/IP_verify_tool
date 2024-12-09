//#include "VeriHar-main/include/AttiCal.h"
#include "../include/AttiCal.h"

void AttiCalFun(void *pIp)
{
    AttiCal *p = (AttiCal*)pIp;

	if ( (p->workmode) == SAM_CRUISE )     	/* 巡航方式 */
	{                                                       
		if (p->flgSP == TRUE )   			/* 太阳可见 */
		{                                                   
        	p->angle[0] = p->royaw;	/* 滚动角用太敏 */
        	p->angle[1] = p->piyaw;	/* 俯仰角用太敏 */
        	                                                
        	 												/* 将太敏读数替换当前积分值 */
       		p->Gi[0] = p->royaw;	/* 滚动角陀螺积分  */
       		p->Gi[1] = p->piyaw;	/* 俯仰角陀螺积分  */
		}                                                   
		else												/* 太阳不可见 */
		{                                                   
		    p->angle[0] = p->Gi[0];	/* 滚动角用陀螺积分 */
        	p->angle[1] = p->Gi[1];	/* 俯仰角用陀螺积分 */
		}
	}
	
	else    /* 其他模式 */
	{
		p->angle[0] = 0.0f ;					/* 滚动角清零 */
    	p->angle[1] = 0.0f ;					/* 俯仰角清零 */	
	}                                                       
	                                                        
	p->rate[0] = p->W[0];			/* 滚动角速度用陀螺算出的滚动角速度 */
    p->rate[1] = p->W[1];			/* 俯仰角速度用陀螺算出的俯仰角速度 */
	p->rate[2] = p->W[2];			/* 偏航角速度用陀螺算出的偏航角速度 */
    return;
}
