#include "VeriHar-main/include/windows_os_frag3.h"
//超时计时器 timer
int timer = 0;

//源码
//int Stored;
//void init() { Stored = 0; }
void callback() {}
void IoQueueWorkItem() {}
void windows_os_frag3Fun(void *pIp) {
	
	windows_os_frag3 *p = (windows_os_frag3*)pIp;	
	
    while(p->input1) {
           if (p->input2) {
               //
               // We are safely at PASSIVE_LEVEL, call callback directly
               // to perform
               // this operation immediately.
               //
               callback ();
           } else {
	       IoQueueWorkItem ();
               p->Stored = 1;
               break;
           }
           if(timer>10000) break;
           timer++;
    }
    // Lower Irql and process
    if (p->Stored==1) {
        callback ();
        p->Stored = 0;
    }
}
