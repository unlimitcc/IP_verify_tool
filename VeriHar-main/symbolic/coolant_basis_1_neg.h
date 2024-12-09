#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __coolant_basis_1_neg{
	
	Fun fun;
	siint32  limit;
	siint32  tempIn;
	siint32  chainBroken;
	siint32  temp; 
	siint32  limit1;
	

} coolant_basis_1_neg;


void coolant_basis_1_negFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
