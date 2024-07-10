#ifndef __DP32G030_UART_H__
#define __DP32G030_UART_H__

#include "DP32G030.h"


typedef enum
{ 
	UART_DATA_8BIT =  0x00,       //����λ8bit
	UART_DATA_9BIT =  0x01        //����λ9bit
} DataBits_TypeDef;

typedef enum
{ 
	UART_PARITY_NONE =  0x00,     //��У��
	UART_PARITY_ODD  =  0x01,     //��У��
    UART_PARITY_EVEN =  0x03,     //żУ��
	UART_PARITY_ONE  =  0x05,     //��1
	UART_PARITY_ZERO =  0x07      //��0
} Parity_TypeDef;

typedef enum
{ 
	AUTOBAUD_LEN_1BIT =  0x00,       //1λʱ��  ����ʼλ����1�������أ���������λ0x01
	AUTOBAUD_LEN_2BIT =  0x01,       //2λʱ��  ����ʼλ����1�������أ���������λ0x02
	AUTOBAUD_LEN_4BIT =  0x02,       //4λʱ��  ����ʼλ����1�������أ���������λ0x08
	AUTOBAUD_LEN_8BIT =  0x03,       //8λʱ��  ����ʼλ����1�������أ���������λ0x80
} AutoBaud_Len_TypeDef;

typedef enum
{ 
	CTS_POL_LOW_ACTIVE  =  0x00,       //�͵�ƽ��Ч  ��CTS�ź�����Ϊ�͵�ƽʱ����ʾ���Է�������
	CTS_POL_HIGH_ACTIVE =  0x01,       //�ߵ�ƽ��Ч  ��CTS�ź�����Ϊ�ߵ�ƽʱ����ʾ���Է�������
} CTS_Pol_TypeDef;

typedef enum
{ 
	RTS_POL_LOW_ACTIVE  =  0x00,       //�͵�ƽ��Ч  ��RTS�ź����Ϊ�͵�ƽʱ����ʾ���Խ�������
	RTS_POL_HIGH_ACTIVE =  0x01,       //�ߵ�ƽ��Ч  ��RTS�ź����Ϊ�ߵ�ƽʱ����ʾ���Խ�������
} RTS_Pol_TypeDef;


typedef enum
{ 
	TXFIFO_LEVEL_0 =  0x00,       //����ֵΪ0
	TXFIFO_LEVEL_1 =  0x01,       //����ֵΪ1
	TXFIFO_LEVEL_2 =  0x02,       //����ֵΪ2
	TXFIFO_LEVEL_3 =  0x03,       //����ֵΪ3
	TXFIFO_LEVEL_4 =  0x04,       //����ֵΪ4
	TXFIFO_LEVEL_5 =  0x05,       //����ֵΪ5
	TXFIFO_LEVEL_6 =  0x06,       //����ֵΪ6
	TXFIFO_LEVEL_7 =  0x07,       //����ֵΪ7
} TXFIFO_Level_TypeDef;           //����FIFO�д����͵����ݸ�������������ֵ�����ж�


typedef enum
{ 
	RXFIFO_LEVEL_1 =  0x00,       //����ֵΪ1
	RXFIFO_LEVEL_2 =  0x01,       //����ֵΪ2
	RXFIFO_LEVEL_3 =  0x02,       //����ֵΪ3
	RXFIFO_LEVEL_4 =  0x03,       //����ֵΪ4
	RXFIFO_LEVEL_5 =  0x04,       //����ֵΪ5
	RXFIFO_LEVEL_6 =  0x05,       //����ֵΪ6
	RXFIFO_LEVEL_7 =  0x06,       //����ֵΪ7
	RXFIFO_LEVEL_8 =  0x07,       //����ֵΪ8
} RXFIFO_Level_TypeDef;           //����FIFO�н��յ����������ٴﵽ����ֵ�����ж�


typedef struct {
	uint32_t          Baudrate;         //������
	
	DataBits_TypeDef  DataBits;			//����λλ������ȡֵUART_DATA_8BIT��UART_DATA_9BIT
	
	Parity_TypeDef    Parity;			//��żУ��λ����ȡֵUART_PARITY_NONE��UART_PARITY_ODD��UART_PARITY_EVEN��UART_PARITY_ONE��UART_PARITY_ZERO
	
	FunctionalState   TX_Enable;        //����ʹ��
	
	FunctionalState   RX_Enable;        //����ʹ��
	
	FunctionalState   RX_DMAEnable;     //����DMA����ʹ��
	
	FunctionalState   AutoBaud_Enable;  //�Զ������ʼ��ʹ��
	
	AutoBaud_Len_TypeDef AutoBaud_Len;  //�Զ������ʼ��λ������
	
	uint16_t          Rx_TimeOut;       //���ճ�ʱ����ֵ
	
	FunctionalState   CTS_Enable;       //CTS����ʹ��
	
	FunctionalState   RTS_Enable;       //RTS����ʹ��
	
	CTS_Pol_TypeDef   CTS_Pol;          //CTS�źż�������
	
	RTS_Pol_TypeDef   RTS_Pol;          //RTS�źż�������
	
	TXFIFO_Level_TypeDef  TXFIFO_Level; //����FIFOˮλ����
	
	RXFIFO_Level_TypeDef  RXFIFO_Level; //����FIFOˮλ����
	
	FunctionalState  TXFIFO_Clr_Enable; //����FIFO���ʹ��
	
	FunctionalState  RXFIFO_Clr_Enable; //����FIFO���ʹ��
	
	FunctionalState  TX_DONE_IE;        //ȫ�����ݷ�������ж�ʹ�� 
	
	FunctionalState  PARITY_ERROR_IE;   //�������ݳ�����żУ������ж�ʹ��
	
	FunctionalState  STOP_ERROR_IE;     //�������ݳ���ֹͣλ�����ж�ʹ��
	
	FunctionalState  RX_TIMEOUT_IE;     //���ճ�ʱ�ж�ʹ��
	
	FunctionalState  RXFIFO_LEVEL_IE;   //����FIFO�н��յ������ݴﵽ�趨ˮλ�ж�ʹ��
	
	FunctionalState  TXFIFO_LEVEL_IE;   //����FIFO�д����͵����ݸ�������������ֵ�ж�ʹ��
	
	FunctionalState  RXFIFO_OVF_IE;     //����FIFO����ж�ʹ��
	
	FunctionalState  AUTOBAUD_OVF_IE;   //�Զ������ʼ�⹦�ܼ���������ж�ʹ��
		
} UART_InitTypeDef;


//����  UART0  UART1   UART2
#define IS_UART_ALL(UART) (((UART) == UART0) || ((UART) == UART1)|| ((UART) == UART2))

//���Դ�������λλ��
#define IS_UART_DATABITS(UART_DATABITS)  ( ((UART_DATABITS) == UART_DATA_8BIT) || ((UART_DATABITS) == UART_DATA_9BIT) )  
										 
//���Դ�����żУ��λ
#define IS_UART_PARITY(UART_PARITY)      ( ((UART_PARITY) == UART_PARITY_NONE) || ((UART_PARITY) == UART_PARITY_ODD) ||  \
                                           ((UART_PARITY) == UART_PARITY_EVEN) || ((UART_PARITY) == UART_PARITY_ONE) ||  \
                                           ((UART_PARITY) == UART_PARITY_ZERO) )

//���Դ����Զ�������λ��
#define IS_UART_AUTOBAUD_LEN(UART_AUTOBAUD_LEN)  (((UART_AUTOBAUD_LEN) == AUTOBAUD_LEN_1BIT) || ((UART_AUTOBAUD_LEN) == AUTOBAUD_LEN_2BIT)  \
                                                  ((UART_AUTOBAUD_LEN) == AUTOBAUD_LEN_4BIT) || ((UART_AUTOBAUD_LEN) == AUTOBAUD_LEN_8BIT) )

//���Դ���CTS�źż�������
#define IS_UART_CTS_POL(UART_CTS_POL)     (((UART_CTS_POL) == CTS_POL_LOW_ACTIVE) || ((UART_CTS_POL) == CTS_POL_HIGH_ACTIVE))

//���Դ���RTS�źż�������
#define IS_UART_RTS_POL(UART_RTS_POL)     (((UART_RTS_POL) == RTS_POL_LOW_ACTIVE) || ((UART_RTS_POL) == RTS_POL_HIGH_ACTIVE))


//���Դ��ڷ���FIFOˮλ����
#define IS_UART_TXFIFO_LEVEL(UART_TXFIFO_LEVEL)  (((UART_TXFIFO_LEVEL) == TXFIFO_LEVEL_0) || ((UART_TXFIFO_LEVEL) == TXFIFO_LEVEL_1)  \
                                                  ((UART_TXFIFO_LEVEL) == TXFIFO_LEVEL_2) || ((UART_TXFIFO_LEVEL) == TXFIFO_LEVEL_3)  \
                                                  ((UART_TXFIFO_LEVEL) == TXFIFO_LEVEL_4) || ((UART_TXFIFO_LEVEL) == TXFIFO_LEVEL_5)  \
                                                  ((UART_TXFIFO_LEVEL) == TXFIFO_LEVEL_6) || ((UART_TXFIFO_LEVEL) == TXFIFO_LEVEL_7) )

//���Դ��ڽ���FIFOˮλ����
#define IS_UART_RXFIFO_LEVEL(UART_RXFIFO_LEVEL)  (((UART_RXFIFO_LEVEL) == RXFIFO_LEVEL_1) || ((UART_RXFIFO_LEVEL) == RXFIFO_LEVEL_2)  \
                                                  ((UART_RXFIFO_LEVEL) == RXFIFO_LEVEL_3) || ((UART_RXFIFO_LEVEL) == RXFIFO_LEVEL_4)  \
                                                  ((UART_RXFIFO_LEVEL) == RXFIFO_LEVEL_5) || ((UART_RXFIFO_LEVEL) == RXFIFO_LEVEL_6)  \
                                                  ((UART_RXFIFO_LEVEL) == RXFIFO_LEVEL_7) || ((UART_RXFIFO_LEVEL) == RXFIFO_LEVEL_8) )



void UART_Init(UART_TypeDef * UARTx, UART_InitTypeDef * UART_InitStruct);	//UART���ڳ�ʼ��

void UART_Open(UART_TypeDef * UARTx);                                       //���ڴ�
void UART_Close(UART_TypeDef * UARTx);                                      //���ڹر�

void UART_Set_BaudRate(UART_TypeDef * UARTx,uint32_t BaudRate);             //���ô��ڲ����� 

void UART_TX_Enable(UART_TypeDef * UARTx);                                  //���ڷ���ʹ��
void UART_TX_Disable(UART_TypeDef * UARTx);                                 //���ڷ��ͽ���

void UART_RX_Enable(UART_TypeDef * UARTx);                                  //���ڽ���ʹ��
void UART_RX_Disable(UART_TypeDef * UARTx);                                 //���ڽ��ս���

void UART_RXDMA_Enable(UART_TypeDef * UARTx);                               //���ڽ���DMA����ʹ��
void UART_RXDMA_Disable(UART_TypeDef * UARTx);                              //���ڽ���DMA�������

void UART_AutoBaud_Enable(UART_TypeDef * UARTx);                            //�����Զ������ʼ��ʹ��
void UART_AutoBaud_Disable(UART_TypeDef * UARTx);                           //�����Զ������ʼ�����

void UART_Set_AutoBaud_Len(UART_TypeDef * UARTx,AutoBaud_Len_TypeDef AutoBaud_Len);   //�����Զ������ʼ��λ������  

uint8_t UART_AutoBaud_Finished_Check(UART_TypeDef * UARTx);                 //�����Զ������ʼ�����״̬

void UART_Set_RX_TimeOut(UART_TypeDef * UARTx,uint8_t RX_TimeOut);          //���ڽ��ճ�ʱʱ������

void UART_CTS_Enable(UART_TypeDef * UARTx);                                 //����CTS����ʹ��
void UART_CTS_Disable(UART_TypeDef * UARTx);                                //����CTS���ؽ���

void UART_RTS_Enable(UART_TypeDef * UARTx);                                 //����RTS����ʹ��
void UART_RTS_Disable(UART_TypeDef * UARTx);                                //����RTS���ؽ���

void UART_Set_CTS_Pol(UART_TypeDef * UARTx,CTS_Pol_TypeDef   CTS_Pol);      //����CTS�źż�������
void UART_Set_RTS_Pol(UART_TypeDef * UARTx,RTS_Pol_TypeDef RTS_Pol);        //����RTS�źż������� 

uint8_t UART_Get_CTS_Pol(UART_TypeDef * UARTx);                             //��ȡCTS�źż���
uint8_t UART_Get_RTS_Pol(UART_TypeDef * UARTx);                             //��ȡRTS�źż���

void UART_Set_TXFIFO_Level(UART_TypeDef * UARTx,TXFIFO_Level_TypeDef  TXFIFO_Level);   //���ڷ���FIFOˮλ����
void UART_Set_RXFIFO_Level(UART_TypeDef * UARTx,RXFIFO_Level_TypeDef  RXFIFO_Level);   //���ڽ���FIFOˮλ����

void UART_Set_TXFIFO_Clr(UART_TypeDef * UARTx);                             //���ڷ���FIFO���ʹ������
void UART_Set_RXFIFO_Clr(UART_TypeDef * UARTx);                             //���ڽ���FIFO���ʹ������

void UART_IntTxDoneEn(UART_TypeDef * UARTx);                                //��������ȫ����������ж�ʹ��
void UART_IntTxDoneDis(UART_TypeDef * UARTx);                               //��������ȫ����������жϽ���
void UART_IntTxDoneClr(UART_TypeDef * UARTx);                               //��������ȫ����������жϱ�־���
uint8_t UART_IntTxDoneState(UART_TypeDef * UARTx);                          //��������ȫ����������ж�״̬

void UART_IntParityErrorEn(UART_TypeDef * UARTx);                           //���ڽ������ݳ�����żУ������ж�ʹ��
void UART_IntParityErrorDis(UART_TypeDef * UARTx);                          //���ڽ������ݳ�����żУ������жϽ���
void UART_IntParityErrorClr(UART_TypeDef * UARTx);                          //���ڽ������ݳ�����żУ������жϱ�־���
uint8_t UART_IntParityErrorState(UART_TypeDef * UARTx);                     //���ڽ������ݳ�����żУ������ж�״̬

void UART_IntStopErrorEn(UART_TypeDef * UARTx);                             //���ڽ������ݳ���ֹͣλ�����ж�ʹ��
void UART_IntStopErrorDis(UART_TypeDef * UARTx);                            //���ڽ������ݳ���ֹͣλ�����жϽ���
void UART_IntStopErrorClr(UART_TypeDef * UARTx);                            //���ڽ������ݳ���ֹͣλ�����жϱ�־���
uint8_t UART_IntStopErrorState(UART_TypeDef * UARTx);                       //���ڽ������ݳ���ֹͣλ�����ж�״̬

void UART_IntRxTimeOutEn(UART_TypeDef * UARTx);                             //�������ݽ��ճ�ʱ�ж�ʹ��
void UART_IntRxTimeOutDis(UART_TypeDef * UARTx);                            //�������ݽ��ճ�ʱ�жϽ���
void UART_IntRxTimeOutClr(UART_TypeDef * UARTx);                            //�������ݽ��ճ�ʱ�жϱ�־���
uint8_t UART_IntRxTimeOutState(UART_TypeDef * UARTx);                       //�������ݽ��ճ�ʱ�ж�״̬

void UART_IntRXFIFOLevelEn(UART_TypeDef * UARTx);                           //���ڽ���FIFO�н��յ������ݴﵽ�趨ˮλ�ж�ʹ��
void UART_IntRXFIFOLevelDis(UART_TypeDef * UARTx);                          //���ڽ���FIFO�н��յ������ݴﵽ�趨ˮλ�жϽ���
void UART_IntRXFIFOLevelClr(UART_TypeDef * UARTx);                          //���ڽ���FIFO�н��յ������ݴﵽ�趨ˮλ�жϱ�־���
uint8_t UART_IntRXFIFOLevelState(UART_TypeDef * UARTx);                     //���ڽ���FIFO�н��յ������ݴﵽ�趨ˮλ�ж�״̬

void UART_IntTXFIFOLevelEn(UART_TypeDef * UARTx);                           //���ڷ���FIFO�д����͵����ݸ�������������ֵ�ж�ʹ��
void UART_IntTXFIFOLevelDis(UART_TypeDef * UARTx);                          //���ڷ���FIFO�д����͵����ݸ�������������ֵ�жϽ���
void UART_IntTXFIFOLevelClr(UART_TypeDef * UARTx);                          //���ڷ���FIFO�д����͵����ݸ�������������ֵ�жϱ�־���
uint8_t UART_IntTXFIFOLevelState(UART_TypeDef * UARTx);                     //���ڷ���FIFO�д����͵����ݸ�������������ֵ�ж�״̬

void UART_IntRXFIFOOvfEn(UART_TypeDef * UARTx);                             //���ڽ���FIFO����ж�ʹ��
void UART_IntRXFIFOOvfDis(UART_TypeDef * UARTx);                            //���ڽ���FIFO����жϽ���
void UART_IntRXFIFOOvfClr(UART_TypeDef * UARTx);                            //���ڽ���FIFO����жϱ�־���
uint8_t UART_IntRXFIFOOvfState(UART_TypeDef * UARTx);                       //���ڽ���FIFO����ж�״̬

void UART_IntAutoBaudOvfEn(UART_TypeDef * UARTx);                           //�����Զ������ʼ�⹦�ܼ���������ж�ʹ��
void UART_IntAutoBaudOvfDis(UART_TypeDef * UARTx);                          //�����Զ������ʼ�⹦�ܼ���������жϽ���
void UART_IntAutoBaudOvfClr(UART_TypeDef * UARTx);                          //�����Զ������ʼ�⹦�ܼ���������жϱ�־���
uint8_t UART_IntAutoBaudOvfState(UART_TypeDef * UARTx);                     //�����Զ������ʼ�⹦�ܼ���������ж�״̬

void UART_SendData(UART_TypeDef * UARTx, uint16_t data);                    //���ڷ��ͺ���  

uint16_t UART_ReceiveData(UART_TypeDef * UARTx);                            //���ڽ��պ���  

uint8_t UART_RXFIFOEmptyState(UART_TypeDef * UARTx);                        //���ڽ���FIFO��״̬

uint8_t UART_RXFIFOFullState(UART_TypeDef * UARTx);                         //���ڽ���FIFO��״̬

uint8_t UART_RXFIFOHalfFullState(UART_TypeDef * UARTx);                     //���ڽ���FIFO����״̬

uint8_t UART_TXFIFOEmptyState(UART_TypeDef * UARTx);                        //���ڷ���FIFO��״̬

uint8_t UART_TXFIFOFullState(UART_TypeDef * UARTx);                         //���ڷ���FIFO��״̬

uint8_t UART_TXFIFOHalfFullState(UART_TypeDef * UARTx);                     //���ڷ���FIFO����״̬

uint8_t UART_TXBusyState(UART_TypeDef * UARTx);                             //���ڷ���æ״̬

uint8_t UART_RXFIFOLevelState(UART_TypeDef * UARTx);                        //���ڽ���FIFOˮλ

uint8_t UART_TXFIFOLevelState(UART_TypeDef * UARTx);                        //���ڷ���FIFOˮλ


void UART_RX_Stop_2bit(UART_TypeDef * UARTx);

void UART_TXRX_Stop_2bit(UART_TypeDef * UARTx);

void UART_TX_Stop_1bit(UART_TypeDef * UARTx);

void UART_TX_Stop_2bit(UART_TypeDef * UARTx);

void UART_TX_Stop_2bit_Idle_1bit(UART_TypeDef * UARTx);

void UART_TX_Stop_2bit_Idle_2bit(UART_TypeDef * UARTx);

void UART_TX_Stop_2bit_Idle_3bit(UART_TypeDef * UARTx);

void UART_TX_Stop_2bit_Idle_4bit(UART_TypeDef * UARTx);

void UART_TX_Stop_2bit_Idle_5bit(UART_TypeDef * UARTx);

void UART_TX_Stop_2bit_Idle_6bit(UART_TypeDef * UARTx);




#endif //__DP32G030_UART_H__
