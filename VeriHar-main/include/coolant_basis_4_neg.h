#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __coolant_basis_4_neg{
	
	Fun fun;
	siint32  temp;
	siint32  init;
	siint32  limit;
	siint32  chainBroken;

} coolant_basis_4_neg;


void coolant_basis_4_negFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
