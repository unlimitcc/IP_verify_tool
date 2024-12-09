#include "VeriHar-main/include/coolant_basis_4_unsafe_sftyliveness.h"
#include <stdlib.h>
#include <time.h>

//extern void __VERIFIER_error() __attribute__ ((__noreturn__));
//extern void __VERIFIER_assume() __attribute__ ((__noreturn__));
//extern int __VERIFIER_nondet_int() __attribute__ ((__noreturn__));

int error, tempDisplay, warnLED, tempIn, chainBroken,
warnLight, temp, otime = 0, time1 = 0, limit, init;

void display(int tempdiff, int warning)
{
	tempDisplay = tempdiff;
	warnLED = warning;
}

int vinToCels(int kelvin)
{
	if (temp < 0) 
	{
		error = 1;
		display(kelvin - 273, error);
	}
	return kelvin -273;
}

void coolantControl()
{
	while(1)
	{
		otime = time1;
		time1 = otime +1;
		tempIn = rand() % 10000 - 5000;
		temp = vinToCels(tempIn);
		if(temp > limit) 
		{
			chainBroken = 1;
		}
		// BUG
		//if (otime > time1 || time1 > 100000000)  chainBroken  = 0;
		if (otime > time1 || time1 > 100)  chainBroken  = 0;
	}
}

void coolant_basis_4_unsafe_sftylivenessFun(void* pIp)
{
    init = 0;
    tempDisplay = 0;
    warnLED = 1;
    tempIn = 0;
    error = 0;
    chainBroken = 0;
    warnLight = 0;
    temp = 0;
    limit = 8;
    init = 1;
	
	while(1)
	{
		int limit = tempIn = rand() % 10000 - 5000;
		if(limit < 10 && limit > -273)
		{
			error = 0;
			display(0, error);
			break;
		} else {
			error = 1;
			display(0, error);
		}	
	}
	
	init = 3;
	coolantControl();	
}
