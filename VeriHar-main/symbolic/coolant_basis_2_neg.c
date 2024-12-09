#include "VeriHar-main/include/coolant_basis_2_neg.h"
#include <stdlib.h>
#include <time.h>

//extern void __VERIFIER_error() __attribute__ ((__noreturn__));
//extern void __VERIFIER_assume() __attribute__ ((__noreturn__));
//extern int __VERIFIER_nondet_int() __attribute__ ((__noreturn__));

int error, tempDisplay, warnLED, chainBroken, warnLight, init;
int timer = 0;
int counter = 0;

void display(int tempdiff, int warning, void *pIp)
{
	coolant_basis_2_neg *p = (coolant_basis_2_neg*)pIp;
	tempDisplay = tempdiff;
	warnLED = warning;
}

int vinToCels(int kelvin, void *pIp)
{
	coolant_basis_2_neg *p = (coolant_basis_2_neg*)pIp;
	if (p->temp < 0) 
	{
		error = 1;
		display(kelvin - 273, error, p);
	}
	return kelvin -273;
}

void coolantControl(void *pIp)
{
	coolant_basis_2_neg *p = (coolant_basis_2_neg*)pIp;

	while(1)
	{
		p->otime = p->time;
		p->time = p->otime + 1;
		if(counter != 0){
			p->tempIn = rand() % 10000 - 5000;
		}
		//p->tempIn = __VERIFIER_nondet_int();
		p->temp = vinToCels(p->tempIn, p);
		if(p->temp > p->limit) 
		{
			chainBroken = 1;
		}
		if(timer > 1000) break;
		timer++;
		counter++;
	}
}

void coolant_basis_2_negFun(void *pIp)
{
	coolant_basis_2_neg *p = (coolant_basis_2_neg*)pIp;
 	init = 0;
    tempDisplay = 0;
    warnLED = 1;
    p->tempIn = 0;
    error = 0;
    chainBroken = 0;
    warnLight = 0;
    p->temp = 0;
    p->limit = 8;
    init = 1;
    p->time = 0;
    p->otime = 0;
    int try = 0;
	
	srand((unsigned)time(NULL));
	while(1)
	{
		int limit;
		if(counter == 0){//第一次执行使用符号执行的测试用例
			limit = p->limit1;
			counter++;
		}else{
			limit = rand() % 10000 - 5000;
		}
		if(limit < 10 && limit > -273)
		{
			error = 0;
			display(0, error, p);
			break;
		} else {
			error = 1;
			display(0, error, p);
		}	
		if (try >= 3) {
			limit = 7;
			break;
		}
		try++;
		p->limit1 = limit;
	}
	
	counter = 0;//重新开始
	
	init = 3;
	coolantControl(p);	
}

