#include "IP.h"

typedef void (*Fun)(void *);

typedef struct __coolant_basis_2_unsafe_liveness{
	
	Fun fun;
	siint32  limit;
	siint32  tempIn;
	siint32  temp; 
	siint32  limit1;
	siint32  time;
	siint32  otime;
	

} coolant_basis_2_unsafe_liveness;


void coolant_basis_2_unsafe_livenessFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))
