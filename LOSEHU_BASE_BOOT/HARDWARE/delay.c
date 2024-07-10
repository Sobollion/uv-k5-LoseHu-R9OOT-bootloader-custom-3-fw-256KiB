#include "delay.h"

static uint8_t  fac_us = 0;							//us��ʱ������			   
static uint32_t fac_ms = 0;							//ms��ʱ������,��ucos��,����ÿ�����ĵ�ms��
			   
void delay_init(void)
{
	fac_us = SystemCoreClock/1000000;	
	fac_ms = fac_us*1000;
}

//��ʱnus
//nusΪҪ��ʱ��us��.		    								   
void delay_us(uint32_t nus)
{		
	uint32_t temp;	
	
	SysTick->LOAD = nus*fac_us; 				//ʱ�����	  		 
	SysTick->VAL = 0x00;        				//��ռ�����
	SysTick->CTRL |=SysTick_CTRL_ENABLE_Msk;  //��ʼ���� 	 
	do
	{
		temp = SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));	//�ȴ�ʱ�䵽��   
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;      	 			//�رռ�����
	SysTick->VAL = 0x00;       				//��ռ�����	 
}
//ע��nms�ķ�Χ
//SysTick->LOADΪ24λ�Ĵ���,����,�����ʱΪ:
//nms<=0xffffff*1000/SystemCoreClock
//SystemCoreClock��λΪHz,nms��λΪms
//��24M������,nms<=699
//��48M������,nms<=349
//��72M������,nms<=233
void delay_nms(uint16_t nms)
{	 		  	  
	uint32_t temp;
	
	SysTick->LOAD =(uint32_t)nms*fac_ms;			//ʱ�����(SysTick->LOADΪ24bit)
	SysTick->VAL =0x00;           			//��ռ�����
	SysTick->CTRL |=SysTick_CTRL_ENABLE_Msk;  //��ʼ���� 	 
	do
	{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));	//�ȴ�ʱ�䵽��   
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;   //�رռ�����
	SysTick->VAL =0x00;       				//��ռ�����	  	    
} 

void delay_ms(uint16_t nms)
{	 		  	  	
	while(nms>200)
	{
		delay_nms(200);
		nms-=200;
	}
	if(nms>0)
	{
		delay_nms(nms);
	}	    
}
