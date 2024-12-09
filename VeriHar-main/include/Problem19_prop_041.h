#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_041{
	
	Fun fun;
	siint32  output;
	siint32  input;
	

} Problem19_prop_041;


void Problem19_prop_041Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
