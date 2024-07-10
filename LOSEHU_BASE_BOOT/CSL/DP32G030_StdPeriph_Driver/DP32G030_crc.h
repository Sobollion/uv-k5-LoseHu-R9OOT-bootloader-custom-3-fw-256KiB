#ifndef __DP32G030_CRC_H__
#define __DP32G030_CRC_H__

#include "DP32G030.h"

typedef enum
{ 
	CRC_SEL_CCITT         =  0x00,  // �㷨ѡ��CCITT
	CRC_SEL_8             =  0x01,  // �㷨ѡ��CRC8
	CRC_SEL_16            =  0x02,  // �㷨ѡ��CRC16
	CRC_SEL_32            =  0x03,  // �㷨ѡ��CRC32
} CrcSel_TypeDef;

typedef enum
{ 
	DATA_WIDTH_32         =  0x00,  // ��������λ��Ϊ32bit
	DATA_WIDTH_16         =  0x01,  // ��������λ��Ϊ16bit
	DATA_WIDTH_8          =  0x02,  // ��������λ��Ϊ8bit
} DataWidth_TypeDef;

typedef enum
{ 
	INPUT_INV_NORMAL      =  0x00,  // �������ݲ���ת
	INPUT_INV_BIT         =  0x01,  // �������ݰ�bit��ת
	INPUT_INV_BIT_BYTE    =  0x02,  // �������ݰ�byte��bit��ת
	INPUT_INV_BYTE        =  0x03,  // �������ݰ�byte��ת
} InputInv_TypeDef;

typedef enum
{ 
	INPUT_REV_DISABLE     =  0x00,  // �������ݲ�ȡ��
	INPUT_REV_ENABLE      =  0x01,  // ��������ȡ��
} InputRev_TypeDef;

typedef enum
{ 
	OUTPUT_INV_NORMAL     =  0x00,  // ������ݲ���ת
	OUTPUT_INV_BIT        =  0x01,  // ������ݰ�bit��ת
	OUTPUT_INV_BIT_BYTE   =  0x02,  // ������ݰ�byte��bit��ת
	OUTPUT_INV_BYTE       =  0x03,  // ������ݰ�byte��ת
} OutputInv_TypeDef;

typedef enum
{ 
	OUTPUT_REV_DISABLE    =  0x00,  // ������ݲ�ȡ��
	OUTPUT_REV_ENABLE     =  0x01,  // �������ȡ��
} OutputRev_TypeDef;


typedef struct
{                                               	
	CrcSel_TypeDef    CrcSel;     // CRC�㷨����ʽѡ��
	
	DataWidth_TypeDef DataWidth;  // CRC�������ݿ��
	
	InputInv_TypeDef  InputInv;   // CRC�������ݷ�תģʽѡ��
	
	InputRev_TypeDef  InputRev;   // CRC��������ȡ��ʹ��
	
	OutputInv_TypeDef OutputInv;  // CRC������ݷ�תģʽѡ��
	
	OutputRev_TypeDef OutputRev;  // CRC�������ȡ��ʹ��
} CRC_InitTypeDef;


//����  CRC�㷨����ʽ  
#define IS_CRC_SEL(CRC_SEL) (((CRC_SEL) == CRC_SEL_CCITT) || ((CRC_SEL) == CRC_SEL_8) || ((CRC_SEL) == CRC_SEL_16) || ((CRC_SEL) == CRC_SEL_32))

//����  CRC�������ݿ��
#define IS_CRC_DATAWIDTH(CRC_DATAWIDTH) (((CRC_DATAWIDTH) == DATA_WIDTH_32) || ((CRC_DATAWIDTH) == DATA_WIDTH_16) || ((CRC_DATAWIDTH) == DATA_WIDTH_8))

//����  CRC�������ݷ�תģʽѡ��
#define IS_CRC_INPUT_INV(CRC_INPUT_INV) (((CRC_INPUT_INV) == INPUT_INV_NORMAL) || ((CRC_INPUT_INV) == INPUT_INV_BIT) || ((CRC_INPUT_INV) == INPUT_INV_BIT_BYTE) || ((CRC_INPUT_INV) == INPUT_INV_BYTE))

//����  CRC��������ȡ��ʹ�� 
#define IS_CRC_INPUT_REV(CRC_INPUT_REV) (((CRC_INPUT_REV) == INPUT_REV_DISABLE) || ((CRC_INPUT_REV) == INPUT_REV_ENABLE))

//����  CRC������ݷ�תģʽѡ��
#define IS_CRC_OUTPUT_INV(CRC_OUTPUT_INV) (((CRC_OUTPUT_INV) == OUTPUT_INV_NORMAL) || ((CRC_OUTPUT_INV) == OUTPUT_INV_BIT) || ((CRC_OUTPUT_INV) == OUTPUT_INV_BIT_BYTE) || ((CRC_OUTPUT_INV) == OUTPUT_INV_BYTE))

//����  CRC�������ȡ��ʹ�� 
#define IS_CRC_OUTPUT_REV(CRC_OUTPUT_REV) (((CRC_OUTPUT_REV) == OUTPUT_REV_DISABLE) || ((CRC_OUTPUT_REV) == OUTPUT_REV_ENABLE))



void CRC_Init(CRC_InitTypeDef *CRC_InitStruct);               //��ʼ��CRC

void CRC_Start(void);                                         //����CRC

void CRC_Stop(void);                                          //�ر�CRC

void CRC_Sel(CrcSel_TypeDef Crc_Sel);                         //����CRC�㷨

void CRC_Data_Width(DataWidth_TypeDef DataWidth);             //����CRC����λ��

void CRC_Input_Inv(InputInv_TypeDef InputInv);                //����CRC���������Ƿ�ת

void CRC_Input_Rev(InputRev_TypeDef InputRev);                //����CRC���������Ƿ�ȡ��

void CRC_Output_Inv(OutputInv_TypeDef OutputInv);             //����CRC��������Ƿ�ת

void CRC_Output_Rev(OutputRev_TypeDef OutputRev);             //����CRC��������Ƿ�ȡ��

void CRC_WriteIV(uint32_t data);                              //д��CRC��ʼֵ

void CRC_WriteData(uint32_t data);                            //д��CRCУ������

uint32_t CRC_ReadData(void);                                  //��ȡCRCУ��ֵ
 

#endif //__DP32G030_CRC_H__
