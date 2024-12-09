#include "VeriHar-main/include/ThreeAxisController.h"

void LimitControllerInput(ThreeAxisController *this);

float32 LimitFloat32(float32 value, float32 limit)
{
    if (value > limit)
    {
        value = limit;
    }
    else if (value < -limit)
    {
        value = -limit;
    }
    return value;
}

void ThreeAxisControllerFun(void *p)
{
    ThreeAxisController *pIp = (ThreeAxisController*)p;

    switch (pIp->workMode)
    {
    case SAM_DAMP:
        /* 速率阻尼 */   
        pIp->destRate[0] = 0.0f;   /* 滚动角目标角速度0 */
        pIp->destRate[1] = 0.0f;   /* 俯仰角目标角速度0 */
        break;
    case SAM_PITCH:
        /* 俯仰搜索 */   
        pIp->destRate[0] =  0.0f;   /* 滚动角目标角速度0 */
        pIp->destRate[1] = -0.5f;   /* 俯仰角目标角速度-0.5 */
        break;
    case SAM_ROLL:
        /* 滚动搜索 */   
        pIp->destRate[0] = 0.5f;   /* 滚动角目标角速度0.5 */
        pIp->destRate[1] = 0.0f;   /* 俯仰角目标角速度0 */
        break;
    case SAM_CRUISE:
        /* 巡航模式 */
        pIp->destRate[0] = 0.0f;   /* 滚动角目标角速度0 */
        pIp->destRate[1] = 0.0f;   /* 俯仰角目标角速度0 */
    default:
        break;
    }

    LimitControllerInput(p);

    /* 三轴控制器计算 */
    pIp->mController[0][2] = pIp->mController[0][0] * pIp->CTRL_PARAM_SAM[0][0] + pIp->mController[0][1] * pIp->CTRL_PARAM_SAM[0][1];
    pIp->mController[1][2] = pIp->mController[1][0] * pIp->CTRL_PARAM_SAM[1][0] + pIp->mController[1][1] * pIp->CTRL_PARAM_SAM[1][1];
    pIp->mController[2][2] = pIp->mController[2][1] * pIp->CTRL_PARAM_SAM[2][1];

    /* 控制器输出限幅,伪速率调制器输入,即控制器输出 */
    pIp->u[0] = LimitFloat32(pIp->mController[0][2], 1.3f); /* 伪速率状态量 */
    pIp->u[1] = LimitFloat32(pIp->mController[1][2], 1.3f); /* 伪速率状态量 */
    pIp->u[2] = LimitFloat32(pIp->mController[2][2], 1.3f); /* 伪速率状态量 */

    return;
}

void LimitControllerInput(ThreeAxisController *this)
{
    /* 在进行控制器计算前,对输入信号进行限幅 */
    this->mController[0][0] = this->pAngle[0]; /* 角度减偏置量，偏置量为0  */
    this->mController[1][0] = this->pAngle[1]; /* 角度减偏置量，偏置量为0  */
    this->mController[2][0] = 0.0f;                 /* Z轴角度清零 */

    this->mController[0][1] = this->pRate[0] - this->destRate[0];   /* 角速度减偏置量 */
    this->mController[1][1] = this->pRate[1] - this->destRate[1];   /* 角速度减偏置量 */
    this->mController[2][1] = this->pRate[2];                       /* Z轴角速度无偏置 */

    this->mController[0][0] = LimitFloat32(this->mController[0][0], 8.0f); /* 角度限幅8° */
    this->mController[1][0] = LimitFloat32(this->mController[1][0], 8.0f);

    this->mController[0][1] = LimitFloat32(this->mController[0][1], 1.2f); /* 角速度限幅1.2° */
    this->mController[1][1] = LimitFloat32(this->mController[1][1], 1.2f);
    this->mController[2][1] = LimitFloat32(this->mController[2][1], 1.2f);
    return;
}

