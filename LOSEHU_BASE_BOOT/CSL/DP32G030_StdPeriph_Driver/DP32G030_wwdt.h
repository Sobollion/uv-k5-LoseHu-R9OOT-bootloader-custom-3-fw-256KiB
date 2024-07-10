#ifndef __DP32G030_WWDT_H__
#define __DP32G030_WWDT_H__

#include "DP32G030.h"

typedef enum
{ 
	WWDT_CLKDIV_1 =  0x00,       //ʱ��1��Ƶ
	WWDT_CLKDIV_2 =  0x01,       //ʱ��2��Ƶ
	WWDT_CLKDIV_4 =  0x02,       //ʱ��4��Ƶ
	WWDT_CLKDIV_8 =  0x03        //ʱ��8��Ƶ
} WWDT_ClkDiv_TypeDef;


typedef struct
{                                               
	WWDT_ClkDiv_TypeDef    ClkDiv;            //ʱ��Ԥ��Ƶ
	uint8_t                Int_Load;          //�жϱȽ�ֵ
	uint8_t                Rst_Load;          //��λ�Ƚ�ֵ
	FunctionalState        IntEn;             //�ж�ʹ��ѡ��
	FunctionalState        PresetIntEn;       //Ԥ��λ�ж�ʹ��ѡ��
} WWDT_InitTypeDef;


//����  WWDTʱ��Ԥ��Ƶ
#define IS_WWDT_CLKDIV(WWDT_CLKDIV)  (((WWDT_CLKDIV) == WWDT_CLKDIV_1) || ((WWDT_CLKDIV) == WWDT_CLKDIV_2)  \
                                      ((WWDT_CLKDIV) == WWDT_CLKDIV_4) || ((WWDT_CLKDIV) == WWDT_CLKDIV_8)) 

//����  WWDT�жϱȽ�ֵ
#define IS_WWDT_INTLOAD(WWDT_INTLOAD) ((WWDT_INTLOAD) > 0x00 && (WWDT_INTLOAD) <= 0x7F)

//����  WWDT��λ�Ƚ�ֵ
#define IS_WWDT_RSTLOAD(WWDT_RSTLOAD) ((WWDT_RSTLOAD) > 0x00 && (WWDT_RSTLOAD) <= 0x3F)

//����  WWDT�ж�ʹ��
#define IS_INT_EN(INT_EN)             (((INT_EN) == ENABLE) || ((INT_EN) == DISABLE))

//����  WWDTԤ��λ�ж�ʹ��
#define IS_PREINT_EN(PREINT_EN)       (((PREINT_EN) == ENABLE) || ((PREINT_EN) == DISABLE))



void WWDT_Init(WWDT_InitTypeDef * WWDT_InitStruct);  //WWDT��ʼ��

void WWDT_Start(void);                               //����WWDT

void WWDT_Stop(void);                                //ֹͣWWDT

void WWDT_Feed(void);                                //WWDTι�� 

uint8_t WWDT_Read(void);                             //��WWDT�ĵ�ǰ����ֵ

void WWDT_INT_Enable(void);                          //WWDT�����ж�ʹ��

void WWDT_INT_Disable(void);                         //WWDT�����жϽ���

uint8_t WWDT_INTStat(void);                          //WWDT�����ж�״̬��ѯ

void WWDT_INTClr(void);                              //WWDT�����жϱ�־���

void WWDT_PRESETINT_Enable(void);                    //WWDTԤ��λ�ж�ʹ��

void WWDT_PRESETINT_Disable(void);                   //WWDTԤ��λ�жϽ���

uint8_t WWDT_PRESETINTStat(void);                    //WWDTԤ��λ�ж�״̬��ѯ

void WWDT_PRESETINTClr(void);                        //WWDTԤ��λ�жϱ�־���


#endif //__DP32G030_WWDT_H__
