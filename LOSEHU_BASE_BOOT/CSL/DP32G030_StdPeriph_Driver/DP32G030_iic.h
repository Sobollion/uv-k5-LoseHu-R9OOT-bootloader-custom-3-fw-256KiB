#ifndef __DP32G030_IIC_H__
#define __DP32G030_IIC_H__

#include "DP32G030.h"


typedef enum
{ 
	SLAVE_MODE  = 0x00,      //�ӻ�ģʽ
	MASTER_MODE = 0x01,      //����ģʽ
} IIC_Master_TypeDef;

typedef enum
{ 
	SLAVE_ADDR_7BIT  = 0x00,    //7λ��ַģʽ
	SLAVE_ADDR_10BIT = 0x01,    //10λ��ַģʽ
} Slave_Addr_Mode_TypeDef;


typedef struct {
	
	IIC_Master_TypeDef  Master;		           //1 ����ģʽ    0 �ӻ�ģʽ
	
	uint16_t            BaudRate;              //��������
	
	Slave_Addr_Mode_TypeDef  Slave_Addr_Mode;  //�ӻ���ַģʽ   
	
	uint16_t            Slave_Addr;            //�ӻ���ַ
	
	uint16_t            Slave_Addr_Mask;       //�ӻ���ַ����
	
	FunctionalState     Clock_Stretch;         //ʱ����չʹ��
	
	FunctionalState     Clock_Stretch_Adaptive;   //ʱ����չ�����ݽ���ʱ������Ӧʹ��
	
	FunctionalState     RX_Ovf_IE;             //�������ݼĴ�������ж�ʹ��
	
	FunctionalState     TX_End_IE;             //�������ݽ����ж�ʹ��
	
	FunctionalState     RX_End_IE;             //�������ݽ����ж�ʹ��
	
	FunctionalState     Start_IE;              //SLAVEģʽ�¼�⵽��ʼ�ź��ж�ʹ��
	
	FunctionalState     Stop_IE;               //SLAVEģʽ�¼�⵽ֹͣ�ź��ж�ʹ�� 
	
	FunctionalState     SCL_LOW_TimeOut_IE;    //����ģʽ��SCL�͵�ƽ��ʱ�ж�ʹ��
	
} IIC_InitTypeDef;


//����  IICģʽ
#define IS_IIC_MODE(IIC_MODE) (((IIC_MODE) == SLAVE_MODE) || ((IIC_MODE) == MASTER_MODE))

//����  IIC�ӻ���ַģʽ   
#define IS_IIC_SLAVE_ADDRMODE(IIC_SLAVE_ADDRMODE) (((IIC_SLAVE_ADDRMODE) == SLAVE_ADDR_7BIT) || ((IIC_SLAVE_ADDRMODE) == SLAVE_ADDR_10BIT))


void IIC_Init(IIC_TypeDef *IICx,IIC_InitTypeDef * IIC_InitStruct);   //IIC��ʼ��

void IIC_Open(IIC_TypeDef *IICx);                                  //��IIC

void IIC_Close(IIC_TypeDef *IICx);                                 //�ر�IIC

uint8_t IIC_Start(IIC_TypeDef *IICx,uint8_t addr);                 //������ʼ�źŲ������豸��ַ

uint8_t IIC_Start_10bit(IIC_TypeDef *IICx,uint16_t addr,uint8_t readwrite);    //������ʼ�źŲ������豸��ַ  10λ��ַ

void IIC_Stop(IIC_TypeDef *IICx);                                  //����ֹͣ�ź�

uint8_t IIC_Write(IIC_TypeDef *IICx,uint8_t data);                 //д��һ������

uint8_t IIC_Read(IIC_TypeDef *IICx,uint8_t ack);                   //��ȡһ������   

void IIC_Start_NoWait(IIC_TypeDef *IICx,uint8_t addr);                                               //������ʼ�źŲ������豸��ַ

void IIC_Start_10bit_First_NoWait(IIC_TypeDef *IICx,uint16_t addr,uint8_t readwrite);                //������ʼ�źŲ������豸��ַ  10λ��ַ   bit9 8

void IIC_Start_10bit_Second_NoWait(IIC_TypeDef *IICx,uint16_t addr);                                 //������ʼ�źŲ������豸��ַ  10λ��ַ   bit7-0

uint8_t IIC_Wait_ACK(IIC_TypeDef *IICx);                                                             //��ȡӦ���ź�

void IIC_Write_NoWait(IIC_TypeDef *IICx,uint8_t data);                                               //д��һ������

void IIC_Read_NoWait(IIC_TypeDef *IICx,uint8_t ack);                                                 //��ȡһ������  

void IIC_IntRxOvfEn(IIC_TypeDef *IICx);                                                              //IIC������������ж�ʹ��

void IIC_IntRxOvfDis(IIC_TypeDef *IICx);                                                             //IIC������������жϽ���

void IIC_IntRxOvfClr(IIC_TypeDef *IICx);                                                             //IIC������������ж�״̬���

uint8_t IIC_IntRxOvfStat(IIC_TypeDef *IICx);                                                         //��ȡIIC������������ж�״̬

void IIC_IntTxFinishEn(IIC_TypeDef *IICx);                                                           //IIC�������ݽ����ж�ʹ��

void IIC_IntTxFinishDis(IIC_TypeDef *IICx);                                                          //IIC�������ݽ����жϽ���

void IIC_IntTxFinishClr(IIC_TypeDef *IICx);                                                          //IIC�������ݽ����ж�״̬���

uint8_t IIC_IntTxFinishStat(IIC_TypeDef *IICx);                                                      //��ȡIIC�������ݽ����ж�״̬

void IIC_IntRxFinishEn(IIC_TypeDef *IICx);                                                           //IIC�������ݽ����ж�ʹ��

void IIC_IntRxFinishDis(IIC_TypeDef *IICx);                                                          //IIC�������ݽ����жϽ���

void IIC_IntRxFinishClr(IIC_TypeDef *IICx);                                                          //IIC�������ݽ����ж�״̬���

uint8_t IIC_IntRxFinishStat(IIC_TypeDef *IICx);                                                      //��ȡIIC�������ݽ����ж�״̬

void IIC_IntSlaveStartEn(IIC_TypeDef *IICx);                                                         //IIC�ӻ���⵽START�ź��ж�ʹ��

void IIC_IntSlaveStartDis(IIC_TypeDef *IICx);                                                        //IIC�ӻ���⵽START�ź��жϽ���

void IIC_IntSlaveStartClr(IIC_TypeDef *IICx);                                                        //IIC�ӻ���⵽START�ź��ж�״̬���

uint8_t IIC_IntSlaveStartStat(IIC_TypeDef *IICx);                                                    //��ȡIIC�ӻ���⵽START�ź��ж�״̬

void IIC_IntSlaveStopEn(IIC_TypeDef *IICx);                                                          //IIC�ӻ���⵽STOP�ź��ж�ʹ��

void IIC_IntSlaveStopDis(IIC_TypeDef *IICx);                                                         //IIC�ӻ���⵽STOP�ź��жϽ���

void IIC_IntSlaveStopClr(IIC_TypeDef *IICx);                                                         //IIC�ӻ���⵽STOP�ź��ж�״̬���

uint8_t IIC_IntSlaveStopStat(IIC_TypeDef *IICx);                                                     //��ȡIIC�ӻ���⵽STOP�ź��ж�״̬

void IIC_IntSclLowTimeOutEn(IIC_TypeDef *IICx);                                                      //IIC����ģʽ��SCL�͵�ƽ��ʱ�ж�ʹ��

void IIC_IntSclLowTimeOutDis(IIC_TypeDef *IICx);                                                     //IIC����ģʽ��SCL�͵�ƽ��ʱ�жϽ���

void IIC_IntSclLowTimeOutClr(IIC_TypeDef *IICx);                                                     //IIC����ģʽ��SCL�͵�ƽ��ʱ�ж�״̬���

uint8_t IIC_IntSclLowTimeOutStat(IIC_TypeDef *IICx);                                                 //��ȡIIC����ģʽ��SCL�͵�ƽ��ʱ�ж�״̬

uint8_t IIC_Busy_State(IIC_TypeDef *IICx);                                                           //��ȡIIC����æ״̬

uint8_t IIC_SCL_State(IIC_TypeDef *IICx);                                                            //��ȡIIC����SCL��ƽ״̬

uint8_t IIC_SDA_State(IIC_TypeDef *IICx);                                                            //��ȡIIC����SDA��ƽ״̬

uint8_t IIC_Slave_Read_State(IIC_TypeDef *IICx);                                                     //��ȡIIC�ӻ���״̬

uint8_t IIC_Slave_Write_State(IIC_TypeDef *IICx);                                                    //��ȡIIC�ӻ�д״̬

uint8_t IIC_Slave_Data_Type(IIC_TypeDef *IICx);                                                      //��ȡIIC�ӻ����յ�����������

void IIC_TXD_Clear(IIC_TypeDef *IICx);                                                               //IIC�������ݼĴ������

uint8_t IIC_TXD_Empty_State(IIC_TypeDef *IICx);                                                      //��ȡIIC�������ݼĴ�����״̬

uint8_t IIC_RXD_NotEmpty_State(IIC_TypeDef *IICx);                                                   //��ȡIIC�������ݼĴ����ǿ�״̬

void IIC_Set_Addr7_Mask(IIC_TypeDef *IICx,uint8_t AddrMask);                                         //���ôӻ���ַ����
         
void IIC_Set_Addr10_Mask(IIC_TypeDef *IICx,uint8_t AddrMask);                                        //���ôӻ���ַ����


#endif //__DP32G030_IIC_H__



