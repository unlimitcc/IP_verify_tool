#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_024{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_024;


void Problem19_prop_024Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
