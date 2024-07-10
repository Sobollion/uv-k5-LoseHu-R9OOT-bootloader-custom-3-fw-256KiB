#ifndef __KEY_H
#define __KEY_H

#include "common.h"


#define KEY1_GPIO_PORT    	GPIOC		                /* GPIO�˿� */
#define KEY1_GPIO_PIN		GPIO_PIN5		        /* ���ӵ�KEY1��GPIO */


/* ����LED1���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED1���� */
#define LED1_GPIO_PORT    	GPIOB                /* GPIO�˿� */
#define LED1_GPIO_PIN		GPIO_PIN6			        /* ���ӵ�LED1��GPIO */

/* ����LED2���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED2���� */
#define SCL_GPIO_PORT    	GPIOA		                /* GPIO�˿� */
#define SCL_GPIO_PIN		GPIO_PIN10			        /* ���ӵ�LED2��GPIO */

/* ����LED3���ӵ�GPIO�˿�, �û�ֻ��Ҫ�޸�����Ĵ��뼴�ɸı���Ƶ�LED3���� */
#define SDA_GPIO_PORT    	GPIOA		                /* GPIO�˿� */
#define SDA_GPIO_PIN		GPIO_PIN11			        /* ���ӵ�LED3��GPIO */




/* �������IO�ĺ�  �˴������LED���ǹ���������ģ�Ҳ��������͵�ƽLED����*/
#define LED1_TOGGLE		   GPIO_InvBit(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_OFF		   GPIO_SetBit(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED1_ON			   GPIO_ClrBit(LED1_GPIO_PORT,LED1_GPIO_PIN)





extern void Key_Init(void);

#endif
