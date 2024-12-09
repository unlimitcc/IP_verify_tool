#if !defined(__GYROSTATESET_H__)
#define __GYROSTATESET_H__

#include "IP.h"

/* IP句柄函数类型 */
typedef void (*Fun)(void *);

/* 陀螺状态收集 */
typedef struct __GyroStateSet
{
    /* 接口函数 */
    Fun     fun;
    /* 输入端口 */
    unint32 powerState;     /* 陀螺加电状态 */
    unint32 healthState;    /* 陀螺健康状态 */
    /* 输出端口 */
    unint08 StateFlag[9];   /* 陀螺可用标志 */
    /* 输入输出端口 */
    /* 状态变量 */
    /* 参数变量 */
} GyroStateSet;

extern void GyroStateSetFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))

#endif // __GYROSTATESET_H__
