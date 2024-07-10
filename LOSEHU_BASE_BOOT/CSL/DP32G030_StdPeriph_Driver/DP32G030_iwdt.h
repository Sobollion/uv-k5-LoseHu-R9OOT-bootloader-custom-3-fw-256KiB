#ifndef __DP32G030_IWDT_H__
#define __DP32G030_IWDT_H__

#include "DP32G030.h"


typedef struct
{                                               
	FunctionalState   IntEn;       //�ж�ʹ��ѡ��
	uint32_t          Load;        //װ��ֵ
} IWDT_InitTypeDef;


//����IWDT�ж�ʹ��ѡ��
#define IS_IWDT_INT(IWDT_INT)        (((IWDT_INT) == DISABLE) || ((IWDT_INT) == ENABLE))

//����WDTװ��ֵ
#define IS_IWDT_LOAD(IWDT_LOAD)      ((IWDT_LOAD) != 0 && (IWDT_LOAD) <= 0xFFFFF)


void IWDT_Init(IWDT_InitTypeDef * IWDT_InitStruct);  //IWDT��ʼ��

void IWDT_Start(void);                               //����IWDT

void IWDT_Stop(void);                                //ֹͣIWDT

void IWDT_FEED(void);                                //IWDTι��

void IWDT_INT_Enable(void);                          //IWDT�ж�ʹ��

void IWDT_INT_Disable(void);                         //IWDT�жϽ���

uint8_t IWDT_INTStat(void);                          //��ѯIWDT�ж�״̬

void IWDT_INTClr(void);                              //���IWDT�ж�״̬


#endif //__DP32G030_IWDT_H__
