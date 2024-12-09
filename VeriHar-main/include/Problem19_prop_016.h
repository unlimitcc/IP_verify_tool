#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_016{
	
	Fun fun;
	siint32  input;
	siint32  output;
	

} Problem19_prop_016;


void Problem19_prop_016Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
