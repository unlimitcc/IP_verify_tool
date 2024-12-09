#include "VeriHar-main/include/GyroStateSet.h"

void GyroStateSetFun(void *pIp)
{
    GyroStateSet *p = (GyroStateSet*)pIp;

	unint08 si ;									
	unint16 tmpFOGPS ;									
	unint16 tmpPSBIT ;									
	unint16 tmpHTBIT ;									
	
	for ( si=0 ; si<9 ; si++ )								/* 9个陀螺 */
	{                                                       
		tmpPSBIT = p->powerState & (1 << si) ;			/* 找上电 */
		tmpHTBIT = p->healthState & (1 << si) ;			/* 找健康 */
		                                                    
		if ((tmpPSBIT != 0) && (tmpHTBIT == 0))				/* 上电且健康 */
		{                                                   
			p->StateFlag[si] = TRUE;				/* 陀螺状态标志为正常 */
		}                                                   
		else                                                
		{                                                   
			p->StateFlag[si] = FALSE;				/* 陀螺状态标志为不正常 */		
		}
	}
    return;
}
