#ifndef __DP32G030_DMA_H__
#define	__DP32G030_DMA_H__

#include "DP32G030.h"


typedef enum
{ 
	DMA_CH0 =  0x00,                //DMAͨ��0
	DMA_CH1 =  0x01,                //DMAͨ��1 
	DMA_CH2 =  0x02,                //DMAͨ��2 
	DMA_CH3 =  0x03,                //DMAͨ��3
} CH_TypeDef;

typedef enum
{ 
	PRI_LOW     =  0x00,            //�����ȼ�
	PRI_MID     =  0x01,            //�����ȼ�
	PRI_HIGH    =  0x02,            //�����ȼ�
	PRI_HIGHEST =  0x03,            //������ȼ� 
} PRI_TypeDef;


typedef enum
{ 
	ADDR_INC_DIS =  0x00,           //DMAͨ����ַ����
	ADDR_INC_EN  =  0x01,           //DMAͨ����ַ����
} ADDR_MODE_TypeDef;


typedef enum
{ 
	SIZE_8BITS   =  0x00,           //DMAͨ�����ߴ�����Ϊ8bits
	SIZE_16BITS  =  0x01,           //DMAͨ�����ߴ�����Ϊ16bits
	SIZE_32BITS  =  0x02,           //DMAͨ�����ߴ�����Ϊ32bits
} ADDR_SIZE_TypeDef;


typedef enum
{ 
	CH0_MS_RAM        =  0x00,      //DMAͨ��0Դ��ַ��  RAM
	CH0_MS_UART0_RX   =  0x01,      //DMAͨ��0Դ��ַ��  ����0�Ľ���
	CH0_MS_UART1_RX   =  0x02,      //DMAͨ��0Դ��ַ��  ����0�Ľ���
	CH0_MS_SARADC     =  0x04,      //DMAͨ��0Դ��ַ��  SARADC�Ľ���
	CH0_MS_TIMPLUS0_L =  0x05,      //DMAͨ��0Դ��ַ��  TIMPLUS0_LOW�����벶��ֵ
	CH0_MS_TIMPLUS1_L =  0x06,      //DMAͨ��0Դ��ַ��  TIMPLUS1_LOW�����벶��ֵ
} CH0_MS_TypeDef;


typedef enum
{ 
	CH0_MD_RAM        =  0x00,      //DMAͨ��0Ŀ�ĵ�ַ��  RAM
} CH0_MD_TypeDef;


typedef enum
{ 
	CH1_MS_RAM        =  0x00,      //DMAͨ��1Դ��ַ��  RAM
	CH1_MS_UART1_RX   =  0x01,      //DMAͨ��1Դ��ַ��  ����1�Ľ���
	CH1_MS_UART2_RX   =  0x02,      //DMAͨ��1Դ��ַ��  ����2�Ľ���
	CH1_MS_SARADC     =  0x04,      //DMAͨ��1Դ��ַ��  SARADC�Ľ���
	CH1_MS_TIMPLUS0_H =  0x05,      //DMAͨ��1Դ��ַ��  TIMPLUS0_HIGH�����벶��ֵ
	CH1_MS_TIMPLUS1_H =  0x06,      //DMAͨ��1Դ��ַ��  TIMPLUS1_HIGH�����벶��ֵ
} CH1_MS_TypeDef;

typedef enum
{ 
	CH1_MD_RAM        =  0x00,      //DMAͨ��1Ŀ�ĵ�ַ��  RAM
} CH1_MD_TypeDef;


typedef enum
{ 
	CH2_MS_RAM        =  0x00,      //DMAͨ��2Դ��ַ��  RAM
	CH2_MS_UART2_RX   =  0x01,      //DMAͨ��2Դ��ַ��  ����2�Ľ���
	CH2_MS_UART0_RX   =  0x02,      //DMAͨ��0Դ��ַ��  ����0�Ľ���
	CH2_MS_SARADC     =  0x04,      //DMAͨ��2Դ��ַ��  SARADC�Ľ���
	CH2_MS_TIMPLUS1_L =  0x05,      //DMAͨ��2Դ��ַ��  TIMPLUS1_LOW�����벶��ֵ
	CH2_MS_TIMPLUS0_L =  0x06,      //DMAͨ��2Դ��ַ��  TIMPLUS0_LOW�����벶��ֵ
} CH2_MS_TypeDef;

typedef enum
{ 
	CH2_MD_RAM        =  0x00,      //DMAͨ��2Ŀ�ĵ�ַ��  RAM
} CH2_MD_TypeDef;


typedef enum
{ 
	CH3_MS_RAM        =  0x00,      //DMAͨ��0Դ��ַ��  RAM
	CH3_MS_UART0_RX   =  0x01,      //DMAͨ��0Դ��ַ��  ����0�Ľ���
	CH3_MS_UART1_RX   =  0x02,      //DMAͨ��0Դ��ַ��  ����0�Ľ���
	CH3_MS_SARADC     =  0x04,      //DMAͨ��0Դ��ַ��  SARADC�Ľ���
	CH3_MS_TIMPLUS1_H =  0x05,      //DMAͨ��0Դ��ַ��  TIMPLUS1_HIGH�����벶��ֵ
	CH3_MS_TIMPLUS0_H =  0x06,      //DMAͨ��0Դ��ַ��  TIMPLUS0_HIGH�����벶��ֵ
} CH3_MS_TypeDef;


typedef enum
{ 
	CH3_MD_RAM        =  0x00,      //DMAͨ��3Ŀ�ĵ�ַ��  RAM
} CH3_MD_TypeDef;



typedef struct {
	uint16_t          Lenth;             //��������ݳ���  ��λ��SIZE����
	
	FunctionalState   Loop;              //ѭ����ʽ   0  ����  1  ѭ��
	
	PRI_TypeDef       Priority;          //ͨ�����ȼ�   00 ��  01  ��  10 ��  11 ��� 
	
	uint32_t          MS_Addr;           //MS��ĵ�ַ
	
	ADDR_MODE_TypeDef MS_AddrMode;       //MS��ĵ�ַ�仯ѡ��  0  ��ַ����  1  ��ַ����
	
	ADDR_SIZE_TypeDef MS_AddrSize;       //MS������ߴ�����  00  8bits  01 16bits   10 32bits
	
	uint8_t           MS_Sel;            //MS�������ѡ��
	
	uint32_t          MD_Addr;           //MD��ĵ�ַ
	
	ADDR_MODE_TypeDef MD_AddrMode;       //MD��ĵ�ַ�仯ѡ��  0  ��ַ����  1  ��ַ����
	
	ADDR_SIZE_TypeDef MD_AddrSize;       //MD������ߴ�����  00  8bits  01 16bits   10 32bits
	
	uint8_t           MD_Sel;            //MD�������ѡ��
	
	FunctionalState   Complete_IE;       //��������ж�ʹ��
	
	FunctionalState   HalfComplete_IE;   //����һ������ж�ʹ��	
} DMA_ChannelInitTypeDef;


//����DMAͨ��
#define IS_DMA_CH(DMA_CH)    (((DMA_CH) == DMA_CH0) || ((DMA_CH) == DMA_CH1) || ((DMA_CH) == DMA_CH2) || ((DMA_CH) == DMA_CH3))  

//����DMAͨ�����ȼ� 
#define IS_DMA_PRI(DMA_PRI)  (((DMA_PRI) == PRI_LOW) || ((DMA_PRI) == PRI_MID) || ((DMA_PRI) == PRI_HIGH) || ((DMA_PRI) == PRI_HIGHEST))  

//����DMA��ַ�仯ѡ��
#define IS_DMA_ADDRMODE(DMA_ADDRMODE)    (((DMA_ADDRMODE) == ADDR_INC_DIS) || ((DMA_ADDRMODE) == ADDR_INC_EN))  

//����DMA���ߴ�����
#define IS_DMA_ADDRSIZE(DMA_ADDRSIZE)    (((DMA_ADDRSIZE) == SIZE_8BITS) || ((DMA_ADDRSIZE) == SIZE_16BITS) || ((DMA_ADDRSIZE) == SIZE_32BITS)) 




void DMA_Channel_Init(CH_TypeDef  CHx,DMA_ChannelInitTypeDef  * DMA_ChannelInitStruct);   //DMA��ʼ��

void DMA_Open(void);                                                   //DMA�� 

void DMA_Close(void);                                                  //DMA�ر�

void DMA_CH_En(CH_TypeDef  CHx);                                       //DMAͨ��ʹ��

void DMA_CH_Dis(CH_TypeDef  CHx);                                      //DMAͨ������

void DMA_CH_Set_Lenth(CH_TypeDef  CHx,uint16_t Lenth);                 //DMAͨ������������������

void DMA_CH_Loop_En(CH_TypeDef  CHx);                                  //DMAͨ��ѭ����ʽʹ��

void DMA_CH_Loop_Dis(CH_TypeDef  CHx);                                 //DMAͨ��ѭ����ʽ����

void DMA_CH_Set_Priority(CH_TypeDef  CHx,PRI_TypeDef Priority);        //DMAͨ�����ȼ�����

void DMA_CH_SwReq_En(CH_TypeDef  CHx);                                 //DMAͨ�������ʽ������ 

void DMA_CH_MS_AddrMode(CH_TypeDef  CHx,ADDR_MODE_TypeDef AddrMode);   //DMAͨ��MS���ַ�仯��ʽѡ��

void DMA_CH_MS_Size(CH_TypeDef  CHx,ADDR_SIZE_TypeDef Size);           //DMAͨ��MS�����ߴ�����

void DMA_CH0_MS_Sel(CH0_MS_TypeDef  Sel);                              //DMAͨ��0��MS������ѡ��

void DMA_CH1_MS_Sel(CH1_MS_TypeDef  Sel);                              //DMAͨ��1��MS������ѡ��

void DMA_CH2_MS_Sel(CH2_MS_TypeDef  Sel);                              //DMAͨ��2��MS������ѡ��

void DMA_CH3_MS_Sel(CH3_MS_TypeDef  Sel);                              //DMAͨ��3��MS������ѡ��

void DMA_CH_MD_AddrMode(CH_TypeDef  CHx,ADDR_MODE_TypeDef AddrMode);   //DMAͨ��MD���ַ�仯��ʽѡ��

void DMA_CH_MD_Size(CH_TypeDef  CHx,ADDR_SIZE_TypeDef Size);           //DMAͨ��MD�����ߴ�����

void DMA_CH0_MD_Sel(CH0_MD_TypeDef  Sel);                              //DMAͨ��0��MD������ѡ��

void DMA_CH1_MD_Sel(CH1_MD_TypeDef  Sel);                              //DMAͨ��1��MD������ѡ��

void DMA_CH2_MD_Sel(CH2_MD_TypeDef  Sel);                              //DMAͨ��2��MD������ѡ��

void DMA_CH3_MD_Sel(CH3_MD_TypeDef  Sel);                              //DMAͨ��3��MD������ѡ��

void DMA_CH0_Int_Complete_En(void);                                    //DMAͨ��0�Ĵ�������ж�ʹ��

void DMA_CH0_Int_Complete_Dis(void);                                   //DMAͨ��0�Ĵ�������жϽ���

void DMA_CH0_Int_Complete_Clr(void);                                   //DMAͨ��0�Ĵ�������ж�״̬���

uint8_t DMA_CH0_Int_Complete_State(void);                              //��ȡDMAͨ��0�Ĵ�������ж�״̬

void DMA_CH1_Int_Complete_En(void);                                    //DMAͨ��1�Ĵ�������ж�ʹ��

void DMA_CH1_Int_Complete_Dis(void);                                   //DMAͨ��1�Ĵ�������жϽ���

void DMA_CH1_Int_Complete_Clr(void);                                   //DMAͨ��1�Ĵ�������ж�״̬���

uint8_t DMA_CH1_Int_Complete_State(void);                              //��ȡDMAͨ��1�Ĵ�������ж�״̬

void DMA_CH2_Int_Complete_En(void);                                    //DMAͨ��2�Ĵ�������ж�ʹ��

void DMA_CH2_Int_Complete_Dis(void);                                   //DMAͨ��2�Ĵ�������жϽ���

void DMA_CH2_Int_Complete_Clr(void);                                   //DMAͨ��2�Ĵ�������ж�״̬���

uint8_t DMA_CH2_Int_Complete_State(void);                              //��ȡDMAͨ��2�Ĵ�������ж�״̬

void DMA_CH3_Int_Complete_En(void);                                    //DMAͨ��3�Ĵ�������ж�ʹ��

void DMA_CH3_Int_Complete_Dis(void);                                   //DMAͨ��3�Ĵ�������жϽ���

void DMA_CH3_Int_Complete_Clr(void);                                   //DMAͨ��3�Ĵ�������ж�״̬���

uint8_t DMA_CH3_Int_Complete_State(void);                              //��ȡDMAͨ��3�Ĵ�������ж�״̬

void DMA_CH0_Int_HalfComplete_En(void);                                //DMAͨ��0�Ĵ���һ������ж�ʹ��

void DMA_CH0_Int_HalfComplete_Dis(void);                               //DMAͨ��0�Ĵ���һ������жϽ���

void DMA_CH0_Int_HalfComplete_Clr(void);                               //DMAͨ��0�Ĵ���һ������ж�״̬���

uint8_t DMA_CH0_Int_HalfComplete_State(void);                          //��ȡDMAͨ��0�Ĵ���һ������ж�״̬

void DMA_CH1_Int_HalfComplete_En(void);                                //DMAͨ��1�Ĵ���һ������ж�ʹ��

void DMA_CH1_Int_HalfComplete_Dis(void);                               //DMAͨ��1�Ĵ���һ������жϽ���

void DMA_CH1_Int_HalfComplete_Clr(void);                               //DMAͨ��1�Ĵ���һ������ж�״̬���

uint8_t DMA_CH1_Int_HalfComplete_State(void);                          //��ȡDMAͨ��1�Ĵ���һ������ж�״̬

void DMA_CH2_Int_HalfComplete_En(void);                                //DMAͨ��2�Ĵ���һ������ж�ʹ��

void DMA_CH2_Int_HalfComplete_Dis(void);                               //DMAͨ��2�Ĵ���һ������жϽ���

void DMA_CH2_Int_HalfComplete_Clr(void);                               //DMAͨ��2�Ĵ���һ������ж�״̬���

uint8_t DMA_CH2_Int_HalfComplete_State(void);                          //��ȡDMAͨ��2�Ĵ���һ������ж�״̬

void DMA_CH3_Int_HalfComplete_En(void);                                //DMAͨ��3�Ĵ���һ������ж�ʹ��

void DMA_CH3_Int_HalfComplete_Dis(void);                               //DMAͨ��3�Ĵ���һ������жϽ���

void DMA_CH3_Int_HalfComplete_Clr(void);                               //DMAͨ��3�Ĵ���һ������ж�״̬���

uint8_t DMA_CH3_Int_HalfComplete_State(void);                          //��ȡDMAͨ��3�Ĵ���һ������ж�״̬

uint16_t DMA_CH_Get_CurLenth(CH_TypeDef  CHx);                         //��ȡͨ����ǰ�������



#endif //__DP32G030_DMA_H__


