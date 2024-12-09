#include "VeriHar-main/include/GyroChoose.h"


void GyroChooseFun(void *pIp)
{
    GyroChoose *p = (GyroChoose*)pIp;
	unint08 i;										/* 循环用临时变量 */
	/* 确定参加工作陀螺的个数 */                             
	p->JoinTotal = 0;								/* 参加定姿的陀螺个数清零 */
	p->gyroStatus0 = 0;								 
	                                                         
	for (i=0; i<9; i++)								/* 9个陀螺进行判断 */
	{	                                                     
		if (p->StateFlag[i] == (unint08)1)			/* 如果陀螺状态正常 */
		{	                                                 
			p->SignFlag[p->JoinTotal] = i;		/* 统计参加定姿的陀螺螺序号 */
			p->JoinTotal++;						/* 统计参加定姿的陀螺个数 */	
			p->gyroStatus0 = p->gyroStatus0 | (1 << i);
			p->tempFlag[i] = 1;
		}else{
			p->tempFlag[i] = 0;
		}
	}
    return;
}
