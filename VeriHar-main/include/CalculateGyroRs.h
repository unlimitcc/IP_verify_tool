#if !defined(__CALCULATEGYRORS_H__)
#define __CALCULATEGYRORS_H__

#include "IP.h"
#include "/home/planet/Desktop/VeriHar-main/sources/std.c"

/* IP句柄函数类型 */
typedef void (*Fun)(void *);

/* 计算陀螺相关矩阵 */
typedef struct __CalculateGyroRs
{
	/* 接口函数 */
	Fun fun;
	/* 输入端口 */
	unint08 JoinTotal;         /* 参加定姿的陀螺个数 */
	unint16 gyroStatus0;       /* 陀螺状态旧 */
	unint08 *SignFlag;         /* 参加定姿的陀螺序号数组指针 */
	/* 输出端口 */
	unint08 flgGryoCalc;       /* 陀螺计算标志 */
	float32 Rtemp[3][5];       /* 矩阵计算结果 */
	/* 输入输出端口 */
	/* 状态变量 */
	unint16 gyroStatus1;       /* 陀螺状态新 */
	/* 参数变量 */
	float32 VG[9][3];
	/*验证辅助变量*/
	unint08 TEMP_rank;		
	float32 TEMP_Rtemp[5][3];
	float32 TEMP_Rgtemp[5][3];		
	
} CalculateGyroRs;

extern void CalculateGyroRsFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))

#endif // __CALCULATEGYRORS_H__
