#if !defined(__CALCULATEGYRODG_H__)
#define __CALCULATEGYRODG_H__

#include "IP.h"
#include "/home/planet/Desktop/VeriHar-main/sources/std.c"

/* IP句柄函数类型 */
typedef void (*Fun)(void *);

/* 计算陀螺三轴角度输出 */
typedef struct __CalculateGyroDg
{
    /* 接口函数 */
    Fun     fun;
    /* 输入端口 */
 	unint08		JoinTotal;           	/* 参加定姿的陀螺个数 */
    unint08		*SignFlag; 		 	    /* 参加定姿的陀螺序号数组指针 */
    float32 	*wa;				    /* 陀螺角速度模拟量数组指针 */
    float32 	*Rtemp;		 	        /* 矩阵计算结果指针 */
    /* 输出端口 */
    float32 	W[3];				 	/* 陀螺算出的角速度 */
    /* 输入输出端口 */
    /* 状态变量 */
    /* 参数变量 */
    /* 验证临时变量 */
    float32 TEMP_tmpwa[5];
    float32 TEMP_W[3];
    
} CalculateGyroDg;

extern void CalculateGyroDgFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))

#endif // __CALCULATEGYRODG_H__
