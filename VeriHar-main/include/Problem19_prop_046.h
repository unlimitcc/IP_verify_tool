#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_046{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_046;


void Problem19_prop_046Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
