#include "VeriHar-main/include/CalculateGyroDg.h"
#include <string.h>

//void MatrixMulti(float32 *a, float32 *b, float32 *c, int d, int f, int g) {}

void CalculateGyroDgFun(void *pIp)
{
    CalculateGyroDg *p = (CalculateGyroDg*)pIp;
 	unint08 j;									
	unint08 k;									
	float32 tmpwa[5];	
	
	for (j = 0 ; j < 5 ; j++ )							/* 给临时数组赋值 */
	{
	     tmpwa[j] = 0;									/* 赋值为0，使用时修改 */
    }
	for (j=0; j<p->JoinTotal; j++)
	{
		k = p->SignFlag[j];							/* 所有参加诊断陀螺的序号 */								
		tmpwa[j] = p->wa[k];						/* 取对应序号的模拟量测量值 */				
	}                                                   	
	                                                    	
	if (p->JoinTotal >= 3)							/* 若大于三个陀螺工作可定姿 */
	{                                                                               		
														/* 算角速度 */	                        		
		MatrixMulti(&p->W[0], p->Rtemp, &tmpwa[0], 3, 5, 1);
		MatrixMulti(&p->TEMP_W[0], p->Rtemp, &tmpwa[0], 3, 5, 1);										
                                                                                    		
	}                                                                               		
	else                                                                            		
	{                                                                               		
		p->W[0] = 0.0f;								/* 参加定姿的陀螺太少 */						
		p->W[1] = 0.0f;									
		p->W[2] = 0.0f;									
	}
	memcpy(p->TEMP_tmpwa,tmpwa,sizeof(tmpwa));
    return;
}
