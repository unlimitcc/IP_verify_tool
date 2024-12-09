#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_023{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_023;


void Problem19_prop_023Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
