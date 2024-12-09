#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_027{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_027;


void Problem19_prop_027Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
