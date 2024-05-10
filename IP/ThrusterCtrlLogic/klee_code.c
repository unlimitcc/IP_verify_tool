#include "klee/klee.h"
#include <string.h>
#include "/home/rotatecc/desktop/VeriHar-main/include/ThrusterCtrlLogic.h"

void ThrusterCtrlLogicFun(void *p)
{
    ThrusterCtrlLogic *pIp = (ThrusterCtrlLogic*)p;
	pIp->wPulse = 0;
	if ( pIp->Yp[0] != 0)									/* 伪速率状态量 */
	{                                                           
		pIp->wPulse = pIp->wPulse | 0x04 ;	/* 软件喷气变量 */								
	}                                                           
                                                                
	if ( pIp->Yn[0] != 0)									/* 伪速率状态量 */
	{                                                           
		pIp->wPulse = pIp->wPulse | 0x08 ;	/* 软件喷气变量 */								
	}	                                                        
                                                                
	if ( pIp->Yp[1] != 0)									/* 伪速率状态量 */
	{                                                           
		pIp->wPulse = pIp->wPulse | 0x10 ;	/* 软件喷气变量 */								
	}                                                           
                                                                
	if ( pIp->Yn[1] != 0)									/* 伪速率状态量 */
	{                                                           
		pIp->wPulse = pIp->wPulse | 0x20 ;	/* 软件喷气变量 */								
	}			                                                
                                                                
	if ( pIp->Yp[2] != 0)									/* 伪速率状态量 */
	{                                                           
		pIp->wPulse = pIp->wPulse | 0x40 ;	/* 软件喷气变量 */								
	}                                                           
                                                                
	if ( pIp->Yn[2] != 0)									/* 伪速率状态量 */
	{                                                           
		pIp->wPulse = pIp->wPulse | 0x80 ;	/* 软件喷气变量 */								
	}
    return;
}

int main(){
	ThrusterCtrlLogic ThrusterCtrlLogic1;
	unint08 Yn[3];
	ThrusterCtrlLogic1.Yn=&Yn[0];
	klee_make_symbolic(&Yn[0], sizeof(Yn), "*Yn[3]");
	unint08 Yp[3];
	ThrusterCtrlLogic1.Yp=&Yp[0];
	klee_make_symbolic(&Yp[0], sizeof(Yp), "*Yp[3]");
	unint08* p0;
	unint08 p1;
	p0= &ThrusterCtrlLogic1.wPulse;
	klee_make_symbolic(&p1, sizeof(p1), "wPulse");
	memcpy(p0, &p1, sizeof(ThrusterCtrlLogic1.wPulse));
	ThrusterCtrlLogicFun(&ThrusterCtrlLogic1);
}
