#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_042{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_042;


void Problem19_prop_042Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
