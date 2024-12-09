#include "VeriHar-main/include/CalculateGyroRs.h"

#ifndef __VERIHAR_CPACHECKER__
/*void MatrixTran(float32 *a, float32 *b, int c, int d) {}
void MatrixMulti(float32 *a, float32 *b, float32 *c, int d, int e, int f) {}
unint08 MatrixInv33F(float32 *a, float32 *b) {}*/
#endif

void CalculateGyroRsFun(void *pIp)
{
    CalculateGyroRs *p = (CalculateGyroRs*)pIp;
	unint08 i;
 	unint08 j;
	unint08 k;
 	float32 Rgtrans[3][5];
 	float32 Rs[3][3];
	float32 RsInv[3][3];
 	float32 Rgtemp[5][3];

 	p->JoinTotal = MIN(p->JoinTotal, 5);												
  	
	if (p->gyroStatus0 != p->gyroStatus1)		/* 有陀螺切换 */
	{		                                                
		p->flgGryoCalc = TRUE;					/* 置陀螺计算标志 */
		
		for (j=0; j<p->JoinTotal; j++)			/* 参加定姿的陀螺个数 */
		{                                                               				
			k = p->SignFlag[j];					/* 按从小到大排列依次选5个，不足5个选余下的 */								
		    
			for (i=0; i<3; i++)                        
			{                                               
				Rgtemp[j][i] = p->VG[k][i];		/* n*3的安装阵R */						
			}                                               
		}                                                   
                                                            
		for (i = p->JoinTotal; i<5; i++)			/* 不用的（5-JoinTotal）维，清零 */
		{
			for (j=0; j<3; j++)
			{
				Rgtemp[i][j] = 0.0f;										
			}
		}
		
		if (p->JoinTotal >= 3)					/* 若大于三个陀螺工作可以计算角速度 */
		{                                                                       
			MatrixTran(&Rgtrans[0][0], &Rgtemp[0][0], 5, 3);						/* Rg->Rgtrans    		*/								
			MatrixMulti(&Rs[0][0], &Rgtrans[0][0], &Rgtemp[0][0], 3, 5, 3);			/* R*RT->RS       		*/	
			/*验证点*/							
			p->TEMP_rank = MatrixInv33F(&RsInv[0][0], &Rs[0][0]);					/* INV(RS)->RsInv 		*/
			/*验证点*/	
			p->TEMP_rank = p->TEMP_rank==TRUE?3:0;	
			MatrixMulti(&p->Rtemp[0][0], &RsInv[0][0], &Rgtrans[0][0], 3, 3, 5);	/* RsInv*Rgtrans->Rtemp */
			/*验证点*/
			MatrixMulti(&p->TEMP_Rtemp[0][0], &RsInv[0][0], &Rgtrans[0][0], 3, 3, 5);	
		}
		memcpy(p->TEMP_Rgtemp,Rgtemp,sizeof(Rgtemp));		
		p->gyroStatus1 = p->gyroStatus0;
		
	}
    return;
}
