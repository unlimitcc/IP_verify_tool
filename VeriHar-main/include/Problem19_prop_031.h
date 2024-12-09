#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_031{
	
	Fun fun;
	siint32  output;
	

} Problem19_prop_031;


void Problem19_prop_031Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
