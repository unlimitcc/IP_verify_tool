#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_043{
	
	Fun fun;
	siint32  output;
	siint32  input;
	

} Problem19_prop_043;


void Problem19_prop_043Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
