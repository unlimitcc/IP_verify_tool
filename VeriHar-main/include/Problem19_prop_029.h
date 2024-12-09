#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_029{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_029;


void Problem19_prop_029Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
