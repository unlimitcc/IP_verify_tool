#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __coolant_basis_5_neg{
	
	Fun fun;
	siint32  init;

} coolant_basis_5_neg;


void coolant_basis_5_negFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
