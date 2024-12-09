#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_009{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_009;


void Problem19_prop_009Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
