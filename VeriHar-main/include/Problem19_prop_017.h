#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_017{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_017;


void Problem19_prop_017Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
