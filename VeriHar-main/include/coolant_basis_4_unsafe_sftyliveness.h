#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __coolant_basis_4_unsafe_sftyliveness{
	
	Fun fun;
	siint32  temp;
	siint32  init;
	siint32  limit;
	siint32  chainBroken;

} coolant_basis_4_unsafe_sftyliveness;


void coolant_basis_4_unsafe_sftylivenessFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
