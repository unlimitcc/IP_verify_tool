#include "VeriHar-main/include/coolant_basis_1_neg.h"
#include <stdlib.h>
#include <time.h>

//extern void __VERIFIER_error() __attribute__ ((__noreturn__));
//extern void __VERIFIER_assume() __attribute__ ((__noreturn__));
//extern int __VERIFIER_nondet_int() __attribute__ ((__noreturn__));

int error, tempDisplay, warnLED, tempIn, chainBroken,
warnLight, temp, limit, init;

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
	
	
	int otime = 0, time = 0;
	while(1)
	{
		otime = time;
		time = otime + 1;
		tempIn = tempIn = rand() % 10000 - 5000;
		temp = vinToCels(tempIn);
		if(temp > limit) 
		{
			chainBroken = 1;
		}
	}
}

void coolant_basis_1_negFun(void *pIp)
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
    int try = 0;
	
	srand((unsigned)time(NULL));
	while(1)
	{
		int limit;

		limit = rand() % 10000 - 5000;
		
		if(limit < 10 && limit > -273)
		{
			error = 0;
			display(0, error);
			break;
		} else {
			error = 1;
			display(0, error);
		}	
		if (try >= 3) {
			limit = 7;
			break;
		}
		try++;
	}
	
	
	init = 3;
	coolantControl();	
}

