#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_012{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_012;


void Problem19_prop_012Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
