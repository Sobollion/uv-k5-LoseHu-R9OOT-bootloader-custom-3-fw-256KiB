#ifndef __DP32G030_CMP_H__
#define __DP32G030_CMP_H__          

#include "DP32G030.h"

typedef enum
{ 
	CMP0 =  0x01,                     //�Ƚ���0
	CMP1 =  0x02,                     //�Ƚ���1
	CMP2 =  0x04,                     //�Ƚ���2
} CMP_TypeDef;

typedef enum
{ 
	CMP_HYS_24MV = 0x00,              //�Ƚ������͵�ѹ24����          
	CMP_HYS_40MV = 0x01,              //�Ƚ������͵�ѹ40����    
	CMP_HYS_60MV = 0x02,              //�Ƚ������͵�ѹ60����    
	CMP_HYS_0MV  = 0x03,              //�Ƚ������͵�ѹ0����    
} CMP_HYS_TypeDef;

typedef enum
{ 
	CMP_FILTER_0CLK = 0x00,           //�Ƚ���������˲� 
	CMP_FILTER_2CLK = 0x01,           //�Ƚ����������2��ϵͳʱ�����ڵ��˲�
	CMP_FILTER_4CLK = 0x02,           //�Ƚ����������4��ϵͳʱ�����ڵ��˲�
	CMP_FILTER_8CLK = 0x03,           //�Ƚ����������8��ϵͳʱ�����ڵ��˲�
} CMP_FILTER_TypeDef;


typedef struct
{
	CMP_TypeDef          CMP;         //�Ƚ���ѡ��       
    CMP_HYS_TypeDef      HYS;         //����                              
    CMP_FILTER_TypeDef   FILTER;      //�˲�����
	FunctionalState      IE;          //�ж�ʹ��
} CMP_InitTypeDef;




//����  CMP
#define IS_CMP_ALL(CMP)        (((CMP) >= 0x01) && ((CMP) <= 0x07))

//����  CMP_TYPE
#define IS_CMP_TYPE(CMP)       (((CMP) == CMP0) || ((CMP) == CMP1) || ((CMP) == CMP2))

//����  CMP_HYS
#define IS_CMP_HYS(HYS)        ((HYS) == CMP_HYS_24MV || (HYS) == CMP_HYS_40MV || (HYS) == CMP_HYS_60MV || (HYS) == CMP_HYS_0MV)

//����  CMP_FILTER
#define IS_CMP_FILTER(FILTER)  ((FILTER) == CMP_FILTER_0CLK || (FILTER) == CMP_FILTER_2CLK || (FILTER) == CMP_FILTER_4CLK || (FILTER) == CMP_FILTER_8CLK)

//����  CMP�ж�
#define IS_CMP_IE(IE)          (((IE) == ENABLE) || ((IE) == DISABLE))


void CMP_Init(CMP_InitTypeDef* CMP_InitStruct);               //�Ƚ�����ʼ��

void CMP_Open(CMP_TypeDef Cmp);                               //�Ƚ�����

void CMP_Close(CMP_TypeDef Cmp);                              //�Ƚ����ر�

void CMP_INTEn(CMP_TypeDef Cmp);                              //�Ƚ����ж�ʹ��
 
void CMP_INTDis(CMP_TypeDef Cmp);                             //�Ƚ����жϽ���

void CMP_SetHys(CMP_TypeDef Cmp,CMP_HYS_TypeDef Cmp_Hys);     //�Ƚ������ó��͵�ѹ

void CMP_SetFilter(CMP_FILTER_TypeDef Cmp_Filter);            //�Ƚ��������˲�

uint8_t CMP_Get_Value_AfterFilter(CMP_TypeDef Cmp);           //�Ƚ�����ȡ�˲���ıȽϽ��

uint8_t CMP_Get_Value_BeforeFilter(CMP_TypeDef Cmp);          //�Ƚ�����ȡ�˲�ǰ�ıȽϽ��

uint8_t CMP_INTRiseStat(CMP_TypeDef Cmp);                     //�Ƚ�������Ƿ�����0��1�ı仯

uint8_t CMP_INTFallStat(CMP_TypeDef Cmp);                     //�Ƚ�������Ƿ�����1��0�ı仯

void CMP_INTRiseClr(CMP_TypeDef Cmp);                         //�Ƚ������������0��1�ı仯�жϱ�־���

void CMP_INTFallClr(CMP_TypeDef Cmp);                         //�Ƚ������������1��0�ı仯�жϱ�־���


#endif //__DP32G030_CMP_H__
