#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_036{
	
	Fun fun;
	siint32  output;
	siint32  input;
	

} Problem19_prop_036;


void Problem19_prop_036Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
