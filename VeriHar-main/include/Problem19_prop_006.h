#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_006{
	
	Fun fun;
	siint32  output;
	siint32  input;
	

} Problem19_prop_006;


void Problem19_prop_006Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
