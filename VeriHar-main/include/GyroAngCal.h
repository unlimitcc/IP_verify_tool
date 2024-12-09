#if !defined(__GYROANGCAL_H__)
#define __GYROANGCAL_H__

#include "IP.h"

/* IP句柄函数类型 */
typedef void (*Fun)(void *);

/* 陀螺角度积分 */
typedef struct __GyroAngCal
{
    /* 接口函数 */
    Fun     fun;
    /* 输入端口 */
    float32     *W;
    /* 输出端口 */
    float32 	Gi[3];				 	/* 陀螺角度积分 */
    /* 输入输出端口 */
    /* 状态变量 */
    /* 参数变量 */
    float32     ctlPeriod;      /* 控制周期（s） */

} GyroAngCal;

void GyroAngCalFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))

#endif // __GYROANGCAL_H__
