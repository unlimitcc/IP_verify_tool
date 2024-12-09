#if !defined(__THREEAXISCONTROLLER_H__)
#define __THREEAXISCONTROLLER_H__

#include "IP.h"

/* IP句柄函数类型 */
typedef void (*Fun)(void *);

/* 三轴控制器 */
typedef struct __ThreeAxisController
{
    /* 接口函数 */
    Fun     fun;
    /* 输入端口 */
    unint08     workMode;
	float32 	*pAngle;			 	/* 三轴姿态角数组指针 */
	float32 	*pRate; 			 	/* 三轴角速度数组指针 */
    /* 输出端口 */
    float32     u[3];
    /* 输入输出端口 */
    /* 状态变量 */
    float32     destRate[3];                            /* 角速度偏置 */
    float32 mController[3][3];
    /* 参数变量 */
    float32 CTRL_PARAM_SAM[3][2];             /* 喷气参数 */

} ThreeAxisController;

void ThreeAxisControllerFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))

#endif // __THREEAXISCONTROLLER_H__
