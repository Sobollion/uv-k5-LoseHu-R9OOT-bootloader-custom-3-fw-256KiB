#ifndef __DP32G030_RTC_H__
#define __DP32G030_RTC_H__

#include "DP32G030.h"


#define RTC_WEEK_SUN  0x00      //������
#define RTC_WEEK_MON  0x01      //����һ
#define RTC_WEEK_TUE  0x02      //���ڶ�
#define RTC_WEEK_WED  0x03      //������
#define RTC_WEEK_THU  0x04      //������
#define RTC_WEEK_FRI  0x05      //������
#define RTC_WEEK_SAT  0x06      //������


#define RTC_ALM_SUN   0x01      //����������
#define RTC_ALM_MON   0x02      //��������һ
#define RTC_ALM_TUE   0x04      //�������ڶ�
#define RTC_ALM_WED   0x08      //����������
#define RTC_ALM_THU   0x10      //����������
#define RTC_ALM_FRI   0x20      //����������
#define RTC_ALM_SAT   0x40      //����������


typedef enum
{                 
	RTC_SEL_RCLF =  0x00,            //�ڲ���Ƶ32768HZ
	RTC_SEL_XTAL =  0x01             //�ⲿ��Ƶ����32768HZ
} RTC_SelTypeDef;

typedef enum
{                 
	RTC_PREPERIOD_8S  =  0x00,       //8��У׼һ��
	RTC_PREPERIOD_16S =  0x01        //16��У׼һ��
} RTC_PrePeriodTypeDef;

typedef struct
{                 
	uint16_t Year;    //��   ȡֵ��Χ2000~2099
	uint8_t  Month;   //��   ȡֵ��Χ1~12
	uint8_t  Date;    //��   ȡֵ��Χ1~31
	uint8_t  Hour;    //ʱ   ȡֵ��Χ0~23
	uint8_t  Minute;  //��   ȡֵ��Χ0~59
	uint8_t  Second;  //��   ȡֵ��Χ0~59
	uint8_t  Week;    //���� ȡֵ��Χ1~7
} RTC_TimeTypeDef;

typedef struct
{                 
	uint8_t  Week;    //���� ȡֵ��Χ1~7
	uint8_t  Hour;    //ʱ   ȡֵ��Χ0~23
	uint8_t  Minute;  //��   ȡֵ��Χ0~59
	uint8_t  Second;  //��   ȡֵ��Χ0~59
} RTC_AlarmTypeDef;

typedef struct
{
	RTC_SelTypeDef  ClkSel;           // 0:RCLF(32768Hz), 1:XTAL(32768Hz)
	RTC_PrePeriodTypeDef pre_period;  // 0:8s, 1:16s
	float    act_freq;                // ���뵽RTCģ���ʵ��Ƶ��ֵ
	FunctionalState  LoadTime_En;     // ʱ��ʹ�ܿ���λ
	FunctionalState  Alarm_En;        // ����ʹ�ܿ���λ
	RTC_TimeTypeDef  Time;            // ����ʱ��
	RTC_AlarmTypeDef Alarm;           // ��������    	
	FunctionalState  SecIntEn;        // ���ж�ʹ��
	FunctionalState  MinIntEn;        // ���ж�ʹ��
	FunctionalState  HourIntEn;       // ʱ�ж�ʹ��
	FunctionalState  DateIntEn;       // ���ж�ʹ��
	FunctionalState  AlmIntEn;        // �����ж�ʹ��
	FunctionalState  MsIntEn;         // �����ж�ʹ��
} RTC_InitTypeDef;


//����  RTC����ʱ��ѡ��
#define IS_RTC_CLKSEL(RTC_CLKSEL) (((RTC_CLKSEL) == RTC_SEL_RCLF) || ((RTC_CLKSEL) == RTC_SEL_XTAL))

//����  RTC����ʱ��ѡ��
#define IS_RTC_PREPERIOD(RTC_PREPERIOD) (((RTC_PREPERIOD) == RTC_PREPERIOD_8S) || ((RTC_PREPERIOD) == RTC_PREPERIOD_16S))


void RTC_Init(RTC_TypeDef * RTCx, RTC_InitTypeDef * RTC_InitStruct);      //RTCģ���ʼ��

void RTC_Start(RTC_TypeDef * RTCx);                                       //����RTC

void RTC_Stop(RTC_TypeDef * RTCx);                                        //ֹͣRTC

void RTC_AlarmEnable(RTC_TypeDef * RTCx);                                 //RTC���ӹ���ʹ��

void RTC_AlarmDisable(RTC_TypeDef * RTCx);                                //RTC���ӹ��ܹر�

void RTC_LoadTimeEnable(RTC_TypeDef * RTCx);                              //װ��RTCʱ���趨ֵ

void RTC_IntSecEn(RTC_TypeDef * RTCx);                                    //RTC���ж�ʹ��

void RTC_IntSecDis(RTC_TypeDef * RTCx);                                   //RTC���жϽ�ֹ

void RTC_IntSecClr(RTC_TypeDef * RTCx);                                   //RTC���жϱ�־���

uint8_t RTC_IntSecState(RTC_TypeDef * RTCx);                              //RTC���ж�״̬��ȡ

void RTC_IntMinEn(RTC_TypeDef * RTCx);                                    //RTC���ж�ʹ��

void RTC_IntMinDis(RTC_TypeDef * RTCx);                                   //RTC���жϽ�ֹ

void RTC_IntMinClr(RTC_TypeDef * RTCx);                                   //RTC���жϱ�־���

uint8_t RTC_IntMinState(RTC_TypeDef * RTCx);                              //RTC���ж�״̬��ȡ

void RTC_IntHourEn(RTC_TypeDef * RTCx);                                   //RTCСʱ�ж�ʹ��

void RTC_IntHourDis(RTC_TypeDef * RTCx);                                  //RTCСʱ�жϽ�ֹ

void RTC_IntHourClr(RTC_TypeDef * RTCx);                                  //RTCСʱ�жϱ�־���

uint8_t RTC_IntHourState(RTC_TypeDef * RTCx);                             //RTCСʱ�ж�״̬��ȡ

void RTC_IntDateEn(RTC_TypeDef * RTCx);                                   //RTC�����ж�ʹ��

void RTC_IntDateDis(RTC_TypeDef * RTCx);                                  //RTC�����жϽ�ֹ

void RTC_IntDateClr(RTC_TypeDef * RTCx);                                  //RTC�����ж����

uint8_t RTC_IntDateState(RTC_TypeDef * RTCx);                             //RTC�����ж�״̬��ȡ

void RTC_IntAlarmEn(RTC_TypeDef * RTCx);                                  //RTC�����ж�ʹ��

void RTC_IntAlarmDis(RTC_TypeDef * RTCx);                                 //RTC�����жϽ�ֹ

void RTC_IntAlarmClr(RTC_TypeDef * RTCx);                                 //RTC�����ж����

uint8_t RTC_IntAlarmState(RTC_TypeDef * RTCx);                            //RTC�����ж�״̬��ȡ

void RTC_IntMsEn(RTC_TypeDef * RTCx);                                     //RTC�����ж�ʹ��

void RTC_IntMsDis(RTC_TypeDef * RTCx);                                    //RTC�����жϽ�ֹ

void RTC_IntMsClr(RTC_TypeDef * RTCx);                                    //RTC�����ж����

uint8_t RTC_IntMsState(RTC_TypeDef * RTCx);                               //RTC�����ж�״̬��ȡ

uint8_t RTC_TimeErrorState(RTC_TypeDef * RTCx);                           //RTCʱ���ʽ�����־��ȡ

uint8_t RTC_AlarmErrorState(RTC_TypeDef * RTCx);                          //RTC���Ӹ�ʽ�����־��ȡ

uint8_t RTC_IsLeapYear(RTC_TypeDef * RTCx);                               //RTC�����ж�

void RTC_SetTime(RTC_TypeDef * RTCx, RTC_TimeTypeDef * RTC_TimeStruct);   //RTCʱ������

void RTC_GetTime(RTC_TypeDef * RTCx, RTC_TimeTypeDef * RTC_TimeStruct);   //��ȡRTC��ǰʱ��

void RTC_SetAlarm(RTC_TypeDef * RTCx, RTC_AlarmTypeDef * RTC_AlarmStruct);//RTC��������


#endif //__DP32G030_RTC_H__


