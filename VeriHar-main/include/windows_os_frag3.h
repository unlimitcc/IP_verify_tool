#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __windows_os_frag3{
	
	Fun fun;
	siint32  Stored;

} windows_os_frag3;


void windows_os_frag3Fun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
