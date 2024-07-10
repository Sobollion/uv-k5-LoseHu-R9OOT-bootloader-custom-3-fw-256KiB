#ifndef __DP32G030_TIMERBASE_H__
#define	__DP32G030_TIMERBASE_H__

#include "DP32G030.h"


typedef enum
{
	TIMBASE_LOW  = 0x01,
	TIMBASE_HIGH = 0x02,
	TIMBASE_BOTH = 0x03,
} TIMBASE_TypeTypeDef;


typedef struct
{
	uint16_t                ClkDiv;       //ʱ�ӷ�Ƶ
	
	uint16_t                Period;       //��������ֵ	
	
	FunctionalState         Ovf_IE;       //����ж�ʹ��
	
} TIMBASE_InitTypeDef;


//����  TIMBASE
#define IS_TIMBASE_ALL(TIMBASE)      ((TIMBASE) == TIMBASE0 || (TIMBASE) == TIMBASE1 || (TIMBASE) == TIMBASE2)

//����  TIMBASEģʽ
#define IS_TIMBASE_TYPE(TYPE)        ((TYPE) == TIMBASE_LOW || (TYPE) == TIMBASE_HIGH || (TYPE) == TIMBASE_BOTH)

//����  TIMBASEԤ��Ƶϵ��  
#define IS_TIMBASE_CLKDIV(CLKDIV)    ((CLKDIV) <= 65535)

//����  TIMBASE����
#define IS_TIMBASE_PERIOD(PERIOD)    (((PERIOD) > 0) && ((PERIOD) <= 65535))

//����  TIMBASE����ж�ʹ��
#define IS_TIMBASE_OVF_IE(OVF_IE)      (((OVF_IE) == ENABLE) || ((OVF_IE) == DISABLE))


void TIMBASE_Init(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type,TIMBASE_InitTypeDef * TIMBASE_InitStruct);    //��ʱ����ʼ��

void TIMBASE_Start(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type);                          //������ʱ��

void TIMBASE_Stop(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type);                           //ֹͣ��ʱ��

void TIMBASE_SetClkDiv(TIMBASE_TypeDef * TIMBASEx,uint16_t Clk_Div);                              //���ö�ʱ��Ԥ��Ƶϵ��  

void TIMBASE_SetPeriod(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type,uint16_t Period);      //���ö�ʱ������ֵ   

uint16_t TIMBASE_GetPeriod(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type);                  //��ȡ��ʱ������ֵ            

uint16_t TIMBASE_GetCurValue(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type);                //��ȡ��ʱ����ǰֵ

void TIMBASE_INTEn(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type);                          //��ʱ���ж�ʹ��

void TIMBASE_INTDis(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type);                         //��ʱ���жϽ���

void TIMBASE_INTClr(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type);                         //��ʱ���ж����

uint8_t TIMBASE_INTStat(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type);                     //��ȡ��ʱ���ж�״̬


#endif //__DP32G030_TIMERBASE_H__
