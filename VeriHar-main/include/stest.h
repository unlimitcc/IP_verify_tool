#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdint.h>

#define CBM_LEN_IN_WORD_32 1 // FIXME 调节规格，原始为RFC_CBM_LEN_IN_WORD_1024
#define CBM_LEN_IN_WORD_512 16
#define CBM_LEN_IN_WORD_1024 32
#define CBM_LEN_IN_WORD CBM_LEN_IN_WORD_32

#define BYTE_COUNT 1
#define ONE_BYTE 16
#define BIT_WIDTH (ONE_BYTE*BYTE_COUNT)
#define PORT_MAX (63+1)

typedef struct {
    int mapId;
    uint32_t bits[BYTE_COUNT];
} BitMap;

/* 等价类的BIT MAP定义 */
typedef struct {
    uint32_t aulCBM[CBM_LEN_IN_WORD]; /* CBM,512Bit for 512 rules,lower bit for higher priority rule */
} CBM_STR;

int TOS_MemCpy_s(void *pDst, unsigned int ulDLen, const void *pSrc, unsigned int ulSLen);
int memset_s(void *dest, size_t destMax, int c, size_t count);
uint32_t CountLeadZeros32(uint32_t uwBitMap);
uint32_t CompareTwoCbm(CBM_STR *pstCbm1, CBM_STR *pstCbm2);
int findBitMap(BitMap *bitMap, uint32_t used, const uint32_t *bits);
int isMatch( const uint32_t *pTmpbits, const uint32_t *bits);