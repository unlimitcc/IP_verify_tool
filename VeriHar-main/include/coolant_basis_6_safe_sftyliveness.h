#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __coolant_basis_6_safe_sftyliveness{
	
	Fun fun;
	siint32  tempIn;
	siint32  limit;
	siint32  warnLED;

} coolant_basis_6_safe_sftyliveness;


void coolant_basis_6_safe_sftylivenessFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
