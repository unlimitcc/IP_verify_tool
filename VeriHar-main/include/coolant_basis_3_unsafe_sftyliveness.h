#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __coolant_basis_3_unsafe_sftyliveness{
	
	Fun fun;
	siint32  time1;
	siint32  otime;
	siint32  init;

} coolant_basis_3_unsafe_sftyliveness;


void coolant_basis_3_unsafe_sftylivenessFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
