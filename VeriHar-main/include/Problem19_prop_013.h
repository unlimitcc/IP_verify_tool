#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_013{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_013;


void Problem19_prop_013Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
