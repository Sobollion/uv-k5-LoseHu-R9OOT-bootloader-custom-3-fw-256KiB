#ifndef __DP32G030_AES_H__
#define __DP32G030_AES_H__

#include "DP32G030.h"

typedef enum
{ 
	ECB =  0x00,             //ECBģʽ                       
	CBC =  0x01,             //CBCģʽ
    CTR =  0x02,             //CTRģʽ
} AESConnectMode_TypeDef;

typedef enum
{ 
	Encrypt    =  0x00,      //����     
	Key        =  0x01,      //��Կ����
    Decrypt    =  0x02,      //����
	KeyDecrypt =  0x03       //��Կ�����ӽ���
} AESMode_TypeDef;

typedef enum
{ 
	BIT32    =  0x00,        //32λ���ݲ�����    
	BIT16    =  0x01,        //16λ���ݽ���       
    BIT08    =  0x02,        //8λ���ݽ���
	BIT01    =  0x03         //1λ���ݽ���
} AESDataType_TypeDef;

typedef struct {
	
	AESConnectMode_TypeDef  AESConnectMode;	    //����ģʽ		
	AESMode_TypeDef         AESMode;	        //ģʽ
	AESDataType_TypeDef     AESDataType;	    //��������
} AES_InitTypeDef;

//����AES����ģʽ
#define IS_AES_CON_MODE(AES_CON_MODE)    (((AES_CON_MODE) == ECB) || ((AES_CON_MODE) == CBC) || ((AES_CON_MODE) == CTR))

//����AESģʽ
#define IS_AES_MODE(AES_MODE)            (((AES_MODE) == Encrypt) || ((AES_MODE) == Key) || ((AES_MODE) == Decrypt) || ((AES_MODE) == KeyDecrypt))        

//����AES��������
#define IS_AES_DATATYPE(AES_DATATYPE)    (((AES_DATATYPE) == BIT32) || ((AES_DATATYPE) == BIT16) || ((AES_DATATYPE) == BIT08) || ((AES_DATATYPE) == BIT01))


void AES_Init(AES_InitTypeDef * AES_InitStruct);         //AES��ʼ��

void AES_Set_Key(uint32_t *key);                         //AES����KEY
void AES_Set_Key_IV(uint32_t *key,uint32_t *iv);         //AES����KEY��IV

void AES_Get_KeyDerived(uint32_t *key_derived);          //AES��ȡ������Կ

void AES_Data_WriteRead(uint32_t *din,uint32_t*dout);    //AES����д�����
void AES_Data_Write(uint32_t *din);                      //AES����д��
void AES_Data_Read(uint32_t*dout);                       //AES���ݶ���

#endif //__DP32G030_AES_H__
