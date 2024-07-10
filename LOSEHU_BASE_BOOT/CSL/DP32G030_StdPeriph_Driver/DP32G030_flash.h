#ifndef __DP32G030_FLASH_H__
#define __DP32G030_FLASH_H__

#include "DP32G030.h"


#define FLASH_MODE_READ          0x00       //FLASH������
#define FLASH_MODE_WRITE         0x01       //FLASHд����
#define FLASH_MODE_SECTOR_ERASE  0x02       //FLASH����������
#define FLASH_MODE_RECALL_READ   0x05       //FLASH RECALL������

#define FLASH_MAIN_ARRAY         0x00       //FLASHѡ��MAIN��
#define FLASH_NVR_ARRAY          0x01       //FLASHѡ��NVR��

#define FLASH_ONE_CLK_WAIT       0x00       //������ѡ��  1��ʱ�����ڵȴ�  ϵͳʱ��С�ڵ���56MHz
#define FLASH_TWO_CLK_WAIT       0x01       //������ѡ��  2��ʱ�����ڵȴ�  ϵͳʱ�Ӵ���56MHz

#define FLASH_MAIN_NO_MASK       0x00       //FLASH��MAIN��������ȫ����Ϊ������
#define FLASH_MAIN_2K_MASK       0x01       //FLASH��MAIN�����2K�ֽ�������ΪBOOT����
#define FLASH_MAIN_4K_MASK       0x02       //FLASH��MAIN�����4K�ֽ�������ΪBOOT����
#define FLASH_MAIN_8K_MASK       0x03       //FLASH��MAIN�����8K�ֽ�������ΪBOOT����

#define FLASH_TRCV_TIME          52         //���ٴ���50us  ��������Ϊ60us
#define FLASH_TERASE_TIME        3600       //��3.2ms��4ms֮��  ��������Ϊ3.6ms  Ҳ����3600us

#define FLASH_TPGS_TIME          22         //���ٴ���20us  ��������Ϊ30us
#define FLASH_TPROG_TIME         18         //��16us��20us֮��  ��������Ϊ18us


#define FLASH_CHIPID3_ADDR        0xF024    //CHIP ID3
#define FLASH_CHIPID2_ADDR        0xF020    //CHIP ID2
#define FLASH_CHIPID1_ADDR        0xF01C    //CHIP ID1
#define FLASH_CHIPID0_ADDR        0xF018    //CHIP ID0

#define FLASH_TRIM_PWR0_ADDR      0x7E4     //��ѹ���TRIMֵ
#define FLASH_TRIM_PWR1_ADDR      0x7E0     //��ѹ���TRIMֵ
#define FLASH_TRIM_RCHF_ADDR      0x7D8     //�ڲ���ƵTRIMֵ
#define FLASH_TRIM_RCLF_ADDR      0x7D4     //�ڲ���ƵTRIMֵ
#define FLASH_TRIM_OPA_ADDR       0x7D0     //�˷�TRIMֵ
#define FLASH_TRIM_PLLRES_ADDR    0x7CC     //PLL����TRIMֵ
#define FLASH_FREQ_DELTA_ADDR     0x7C8     //�ڲ���Ƶ�͵�Ƶʱ��ʵ��ֵ������ֵ�Ĳ�ֵ
#define FLASH_VREF_DELTA_ADDR     0x7C4     //VREF��ѹ��ֵ
#define FLASH_TRIM_ADC_ADDR       0x7BC     //ADCģ��TRIMֵ
#define FLASH_TRIM_TEMP_ADDR      0x7B8     //�¶ȴ�����TRIMֵ


extern uint32_t Temp_Trim_Value;                 //�¶ȴ�����У׼ֵ

uint8_t FLASH_Check_Init_Complete(void);         //FLASH����������ʼ���Ƿ����

uint8_t FLASH_Check_Busy(void);                  //FLASH��������æ

uint8_t FLASH_Check_BufEmpty(void);              //FLASH��������ݻ���Ĵ����Ƿ�Ϊ��

void FLASH_Set_DeepSleep_Mode(void);             //FLASH�������˯��ģʽ�����Խ��͹���

void FLASH_Set_Normal_Mode(void);                //FLASH������������ģʽ

void FLASH_Set_ClkWait(uint8_t ClkWait);         //FLASH���ö�����ģʽʱ�����ڵȴ�ʱ��   0  1��ϵͳʱ�ӵȴ�  1  2��ϵͳʱ�ӵȴ�

void FLASH_Set_Array(uint8_t Array);             //FLASH��������ѡ��   0  MAIN ARRAY(64K)   1 NVR ARRAY(2K) 

void FLASH_Set_Operate_Mode(uint8_t Mode);       //FLASH���ù���ģʽ   0 ��  1 д  2 ������ 3 ȫƬ�� 

void FLASH_Set_EraseTime(void);                  //FLASH���ò���ʱ�����

void FLASH_Set_ProgramTime(void);                //FLASH���ñ��ʱ�����

void FLASH_Operate_Lock(void);                   //FLASH�������ܽ���FLASH���

void FLASH_Operate_UnLock(void);                 //FLASH��������Խ���FLASH���

void FLASH_Init(uint8_t ClkWait);                //FLASH��ʼ��   

void FLASH_Command_Start(void);                  //FLASH��������������

void FLASH_Mask_Lock(void);                      //FLASH MASKѡ�������󣬲��ܽ�������ѡ��

void FLASH_Mask_UnLock(void);                    //FLASH MASK��������Խ�������ѡ��

void FLASH_Mask_Sel(uint8_t Mask_Sel);           //FLASH MASK����ѡ��   0 ������  1 2KB����   2  4KB����   3  8KB����

void FLASH_Unlock_Lock(void);                    //FLASH������ִ������ȴ���ɣ����ض�����������

void FLASH_Sector_Erase(uint32_t addr);          //FLASH������   һ������512�ֽ�  ����ĵ�ַ���������512��������

void FLASH_Write_Word(uint32_t addr,uint32_t data);                      //FLASH���һ����

uint8_t FLASH_Write_Words(uint32_t addr,uint32_t data[],uint8_t num);    //FLASH��̶����   

uint32_t FLASH_Recall_Read(uint32_t addr);															 //FLASH RECALL������

uint32_t FLASH_Read_Word(uint32_t addr);                                 //FLASH��������

void FLASH_Read_Words(uint32_t addr,uint32_t data[],uint32_t num);       //FLASH������� 

void Read_Trim_Value_From_Flash(void);                                   //��NVR����ȡTRIMֵд����Ӧ�Ĵ���


#endif //__DP32G030_FLASH_H__




