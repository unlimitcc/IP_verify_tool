#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __coolant_basis_2_neg{
	
	Fun fun;
	siint32  time1;
	siint32  otime;
	

} coolant_basis_2_neg;


void coolant_basis_2_negFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
