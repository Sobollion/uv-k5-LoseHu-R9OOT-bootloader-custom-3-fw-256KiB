#include "key.h"




/***********************************************
KEY��ʼ������

�������º󣬲ɼ����͵�ƽ��
û�а���ʱ���ɼ����ߵ�ƽ
***********************************************/
void Key_Init(void)
{
	
	
	    GPIO_InitTypeDef GPIO_InitStruct;              /*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
	
	GPIO_InitStruct.Pin = LED1_GPIO_PIN;           /*ѡ��Ҫ���Ƶ�GPIO����*/
	
	GPIO_InitStruct.Mode = MODE_PP_OUT;            /*��������ģʽΪ�������*/
	
	GPIO_Init(LED1_GPIO_PORT,&GPIO_InitStruct);    /*���ÿ⺯������ʼ��GPIO*/
	
	
	
	GPIO_InitStruct.Pin = SCL_GPIO_PIN;           /*ѡ��Ҫ���Ƶ�GPIO����*/
	
	GPIO_InitStruct.Mode = MODE_PP_OUT;            /*��������ģʽΪ�������*/
	
	GPIO_Init(SCL_GPIO_PORT,&GPIO_InitStruct);    /*���ÿ⺯������ʼ��GPIO*/

	
		
	GPIO_InitStruct.Pin = SDA_GPIO_PIN;           /*ѡ��Ҫ���Ƶ�GPIO����*/
	
	GPIO_InitStruct.Mode = MODE_PP_OUT;            /*��������ģʽΪ�������*/
	
	GPIO_Init(SDA_GPIO_PORT,&GPIO_InitStruct);    /*���ÿ⺯������ʼ��GPIO*/
	
	
	GPIO_InitStruct.Pin = KEY1_GPIO_PIN;           /*ѡ��Ҫ���Ƶ�GPIO����*/
	
	GPIO_InitStruct.Mode = MODE_PU_IN;             /*��������ģʽΪ��������*/
	
	GPIO_Init(KEY1_GPIO_PORT,&GPIO_InitStruct);    /*���ÿ⺯������ʼ��GPIO*/
	
	

		
	GPIO_InitStruct.Pin = GPIO_PIN3;           /*ѡ��Ҫ���Ƶ�GPIO����*/
	
	GPIO_InitStruct.Mode = MODE_PU_IN;             /*��������ģʽΪ��������*/
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);    /*���ÿ⺯������ʼ��GPIO*/

	
	
	
			
	GPIO_InitStruct.Pin = GPIO_PIN4;           /*ѡ��Ҫ���Ƶ�GPIO����*/
	
	GPIO_InitStruct.Mode = MODE_PP_OUT;            /*��������ģʽΪ�������*/
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);    /*���ÿ⺯������ʼ��GPIO*/
	
	
	
		GPIO_InitStruct.Pin = GPIO_PIN5;           /*ѡ��Ҫ���Ƶ�GPIO����*/
	
	GPIO_InitStruct.Mode = MODE_PP_OUT;            /*��������ģʽΪ�������*/
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);    /*���ÿ⺯������ʼ��GPIO*/
	
	
	
		GPIO_InitStruct.Pin = GPIO_PIN6;           /*ѡ��Ҫ���Ƶ�GPIO����*/
	
	GPIO_InitStruct.Mode = MODE_PP_OUT;            /*��������ģʽΪ�������*/
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);    /*���ÿ⺯������ʼ��GPIO*/
	
	
	
		GPIO_InitStruct.Pin = GPIO_PIN7;           /*ѡ��Ҫ���Ƶ�GPIO����*/
	
	GPIO_InitStruct.Mode = MODE_PP_OUT;            /*��������ģʽΪ�������*/
	
	GPIO_Init(GPIOA,&GPIO_InitStruct);    /*���ÿ⺯������ʼ��GPIO*/
	
GPIO_SetBit(GPIOA,GPIO_PIN5);
GPIO_SetBit(GPIOA,GPIO_PIN6);
GPIO_SetBit(GPIOA,GPIO_PIN7);
	GPIO_ClrBit(GPIOA,GPIO_PIN4);

}



