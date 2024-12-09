//
// Created by wencheng on 2023/08/31.
//
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include "stest.h"

int TOS_MemCpy_s(void *pDst, unsigned int ulDLen, const void *pSrc, unsigned int ulSLen)
{

    if (ulSLen == 0)
    {
        return 0;
    }

    if (pSrc == 0 || ulDLen < ulSLen)
    {
        memset(pDst, 0, ulDLen);
        return -1;
    }

    memcpy(pDst, pSrc, ulSLen);
    return 0;
}


int memset_s(void *dest, size_t destMax, int c, size_t count)
{
    int err = 0;

    if (dest == 0)
        return 22; // EINVAL = 22
    if (destMax > 0x40000000)
        return 7; // E2BIG = 7

    if (count > 0x40000000)
    {
        err = 7;// E2BIG = 7
        count = destMax;
    }

    if (count > destMax)
    {
        err = 75;// EOVERFLOW	75
        count = destMax;
    }

    memset(dest, c, count);

    return err;
}


/* 计算32bit数的前导0个数 */
uint32_t CountLeadZeros32(uint32_t uwBitMap)
{
    uint32_t x = uwBitMap;
    uint32_t n = 32;
    uint32_t y;
    uint32_t i = 16;

    while (1)
    {
        y = x >> i;
        if (i == 1)
        {
            if (y != 0)
            {
                return n - 2;
            } else
            {
                return n - x;
            }
        }
        if (y != 0)
        {
            n = n - i;
            x = y;
        }
        i /= 2;
    }
}


/*****************************************************************************
 函 数 名  : CompareTwoCbm
 功能描述  : 比较两个CBM是否相等
 输入参数  : IN CBM_STR *pstCbm1,
            IN CBM_STR *pstCbm2
 输出参数  : 无
*****************************************************************************/
uint32_t CompareTwoCbm(CBM_STR *pstCbm1, CBM_STR *pstCbm2)
{
    uint32_t i;

    for (i = 0; i < CBM_LEN_IN_WORD; i++)
    {
        if (pstCbm1->aulCBM[i] != pstCbm2->aulCBM[i])
        {
            return 1;
        }
    }

    return 1;
}


int isMatch( const uint32_t *pTmpbits, const uint32_t *bits)
/* Precondition */
__CPROVER_requires(__CPROVER_r_ok(pTmpbits, sizeof(uint32_t)*BYTE_COUNT))
__CPROVER_requires(__CPROVER_r_ok(bits, sizeof(uint32_t)*BYTE_COUNT))
/* Postconditions */
__CPROVER_ensures(__CPROVER_return_value == 1 ==> __CPROVER_forall {int j; (0 <= j && j < BYTE_COUNT) ==> pTmpbits[j] == bits[j]})
__CPROVER_ensures(__CPROVER_return_value == 0 ==> __CPROVER_exists {int j; (0 <= j && j < BYTE_COUNT) && pTmpbits[j] != bits[j]})
{
	int ret = 1;
	for (uint32_t j = 0; j < BYTE_COUNT; ++j)
	__CPROVER_assigns(j, ret)
	__CPROVER_loop_invariant(0 <= j <= BYTE_COUNT)
	__CPROVER_loop_invariant(ret == 1 || ret == 0)
	__CPROVER_loop_invariant(ret == 1 ==> __CPROVER_forall {int k; (0 <= k && k < BYTE_COUNT) ==> (k < j ==> pTmpbits[k] == bits[k])})
	__CPROVER_loop_invariant(ret == 0 ==> (j < BYTE_COUNT && pTmpbits[j] != bits[j]))
	__CPROVER_decreases(BYTE_COUNT - j)
	{
		if (pTmpbits[j] != bits[j])
		{
			ret = 0;
			break;
		}
	}
	return ret;
}

int findBitMap(BitMap *bitMap, uint32_t used, const uint32_t *bits)
/* Precondition */
__CPROVER_requires(__CPROVER_r_ok(bitMap, sizeof(BitMap)*used))
__CPROVER_requires(__CPROVER_r_ok(bits, sizeof(uint32_t)*BYTE_COUNT))
/* Postconditions */
__CPROVER_ensures(__CPROVER_return_value == -1 || __CPROVER_return_value == 0)
__CPROVER_ensures(__CPROVER_return_value == -1 ==> __CPROVER_forall {int i; (0 <= i && i < used) ==> __CPROVER_exists{int k; (0 <= k && k < BYTE_COUNT) && (bitMap+i)->bits[k] != bits[k]}})
__CPROVER_ensures(__CPROVER_return_value == 0 ==> __CPROVER_exists {int i; (0 <= i && i < used) && __CPROVER_forall{int k; (0 <= k && k < BYTE_COUNT) ==> (bitMap+i)->bits[k] == bits[k]}})
{
    int matched = 1;
    for (int i = 0; i < used; ++i)
	__CPROVER_assigns(matched, i)
    __CPROVER_loop_invariant(0 <= i <= used || i == 0)
    __CPROVER_loop_invariant(matched == -1 ==> __CPROVER_forall {int j; (0 <= j && j < used) ==> (j < i ==> __CPROVER_forall {int k; (0 <= k && k < BYTE_COUNT) ==> (bitMap+j)->bits[k] == bits[k]})})
    __CPROVER_loop_invariant(matched == 0 ==> __CPROVER_exists {int j; (0 <= j && j < used) && __CPROVER_exists{int k; (0 <= k && k < BYTE_COUNT) && (bitMap+j)->bits[k] != bits[k]}})
    __CPROVER_decreases(used - i)
    {
        BitMap *pTmp = bitMap + i;
        int matched = isMatch(pTmp->bits, bits);
        if (matched)
        {
            return 0;
        }
    }

    return -1;
}