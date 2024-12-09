#if !defined(__GYROPICK_H__)
#define __GYROPICK_H__

#include "IP.h"

/* IP句柄函数类型 */
typedef void (*Fun)(void *);

/* 陀螺剔野处理 */
typedef struct __GyroPick
{
    /* 接口函数 */
    Fun         fun;
    /* 输入端口 */
    float32 	*wa;				    /* 陀螺角速度模拟量数组指针 */
    /* 输出端口 */
    float32     wa_out[9];              /* 剔野后的陀螺角速度模拟量 */
    /* 输入输出端口 */
    /* 状态变量 */
    float32 	wal[9];				 	/* 上周期陀螺角速度模拟量 */
    unint08		countPick[9];		 	/* 陀螺原始数据处理时,剔野计数器 */   
    /* 参数变量 */
    float32     waThr;                  /* 剔野限 */
    unint08     pickThr;                /* 连续阈值 */
} GyroPick;

extern void GyroPickFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))

#endif // __GYROPICK_H__
