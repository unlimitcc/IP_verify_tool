#include "VeriHar-main/include/windows_os_frag3.h"
#include <stdlib.h>
#include <time.h>

//超时计时器 timer
int timer = 0;

//源码
int Stored;
//void init() { Stored = 0; }
void callback() {}
void IoQueueWorkItem() {}
void windows_os_frag3Fun(void *pIp) {
	
	srand((unsigned)time(NULL));
    while(rand()%10000 - 5000) {
           if (rand()%10000 - 5000) {
               //
               // We are safely at PASSIVE_LEVEL, call callback directly
               // to perform
               // this operation immediately.
               //
               callback ();
           } else {
	       IoQueueWorkItem ();
               Stored = 1;
               break;
           }
           if(timer>1000) break;
           timer++;
    }
    // Lower Irql and process
    if (Stored==1) {
        callback ();
        Stored = 0;
    }
}
