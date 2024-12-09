#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_037{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_037;


void Problem19_prop_037Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
