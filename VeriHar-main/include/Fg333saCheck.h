#if !defined(__FG_333_SA_CHECK_H__)
#define __FG_333_SA_CHECK_H__

#include "IP.h"

/* 
fg_3_3_3sa协议校验IP

功能描述：
	校验接收到的数据是否符合Fg333型光纤陀螺通信协议，校验成功返回TRUE32，否则返回FALSE32。
	1.校验数据长度是否正确：若长度不为19，则cntLenRd、totalLenRd +1，返回校验失败；
	2.校验帧计数是否更新：若帧计数不更新，则cntUpdata、totalUpdata +1，返回校验失败；
	3.校验帧头是否正确：若帧头非0xEB90，则cntHead、totalHead +1，返回校验失败；
	4.校验累加和是否正确：若累加和正确则返回校验成功，否则返回校验失败。
*/

/* IP句柄函数类型 */
typedef void (*Fun)(void *);

typedef struct __Fg333saCheck
{
	/* 入口函数句柄 */
	Fun fun;

	/* 输入端口 */
	const unint08 *pbuff;	/* 陀螺原始数据缓冲区指针 */
	unint32 rdLen;			/* 由pbuff指向的数据缓冲区的长度 */

	/* 输出端口 */
	unint32 bComSuc;		/* 通信成功标志，协议校验正确为TRUE32；不正确为FALSE32 */
	siint32 cntLenRdO;		/* 输出的连续读取长度错误计数 */
	siint32 cntHeadO;		/* 输出的连续帧头错误计数 */
	siint32 cntCheckO;		/* 输出的连续校验错误计数 */
	siint32 cntUpdataO;		/* 输出的连续数据更新错误计数 */
	siint32 totalLenRdO;	/* 输出的累计读取长度错误计数 */ 
	siint32 totalHeadO;		/* 输出的累计帧头错误计数 */	
	siint32 totalCheckO;	/* 输出的累计校验错误计数 */	
	siint32 totalUpdataO;	/* 输出的累计数据更新错误计数 */

	/* 输入输出端口 */
	/* 无 */

	/* 状态变量 */
	unint32 frm;			/* 帧计数 */
	siint32 cntLenRdS;		/* 连续读取长度错误计数 */
	siint32 cntHeadS;		/* 连续帧头错误计数 */
	siint32 cntCheckS;		/* 连续校验错误计数 */
	siint32 cntUpdataS;		/* 连续数据更新错误计数 */
	siint32 totalLenRdS;	/* 累计读取长度错误计数 */ 
	siint32 totalHeadS;		/* 累计帧头错误计数 */	
	siint32 totalCheckS;	/* 累计校验错误计数 */	
	siint32 totalUpdataS;	/* 累计数据更新错误计数 */
	/* 参数变量 */
	/* 无 */

}Fg333saCheck;

extern void Fg333saCheckFun(void *pIp);
#define IPCALL(IP)		(IP.fun(&IP))

#endif // __FG_333_SA_CHECK_H__
