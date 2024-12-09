#if !defined(__GYROCHOOSE_H__)
#define __GYROCHOOSE_H__

#include "IP.h"

/* IP句柄函数类型 */
typedef void (*Fun)(void *);

/* 选择参加定姿的陀螺 */
typedef struct __GyroChoose
{
    /* 接口函数 */
    Fun         fun;
    /* 输入端口 */
    unint08     *StateFlag;                 /* 陀螺可用标志数组指针 */

    /* 输出端口 */
    unint08		JoinTotal;           	/* 参加定姿的陀螺个数 */
    unint16 	gyroStatus0;		 	/* 陀螺状态旧 */
    unint08		SignFlag[9] ; 		 	/* 参加定姿的陀螺序号 */
    /* 输入输出端口 */
    /* 状态变量 */
    /* 参数变量 */
    unint08		tempFlag[9];
} GyroChoose;

extern void GyroChooseFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))

#endif // __GYROCHOOSE_H__
