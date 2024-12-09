#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __Problem19_prop_032{
	
	Fun fun;
	siint32  output;
	siint32  input;

} Problem19_prop_032;


void Problem19_prop_032Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
