#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem9{
	
	Fun fun;
	siint32  output;
	siint32  input;
	

} Problem9;


void Problem9Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
