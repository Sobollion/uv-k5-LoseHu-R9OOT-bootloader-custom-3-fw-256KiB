#include "DP32G030_exti.h"

/****************************************************************************************************************************************** 
* ��������: EXTI_Assert_Param()
* ����˵��:	�������Ĳ����Ƿ�Ϸ�    
* ��    ��: GPIO_TypeDef * GPIOx	    ָ��GPIO�˿ڣ���Чֵ����GPIOA��GPIOB��GPIOC
*			uint32_t GPIO_Pin		    ָ��GPIO���ţ���Чֵ����PIN0��PIN1��PIN2��... ... PIN14��PIN15
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void EXTI_Assert_Param(GPIO_TypeDef * GPIOx, uint32_t GPIO_Pin)
{
	assert_param(IS_GPIO_ALL(GPIOx));                                 //�������Ĳ���GPIOx�Ƿ�Ϸ�    
	
	if((uint32_t)GPIOx == (uint32_t)GPIOA)
	{
		assert_param(IS_GPIOA_PIN(GPIO_Pin));                         //�������Ĳ���Pin�Ƿ�Ϸ�    
	}
	else if((uint32_t)GPIOx == (uint32_t)GPIOB)
	{
		assert_param(IS_GPIOB_PIN(GPIO_Pin));                         //�������Ĳ���Pin�Ƿ�Ϸ�  
	}
	else if((uint32_t)GPIOx == (uint32_t)GPIOC)
	{
		assert_param(IS_GPIOC_PIN(GPIO_Pin));                         //�������Ĳ���Pin�Ƿ�Ϸ�  
	}
}


/****************************************************************************************************************************************** 
* ��������: EXTI_Init()
* ����˵��:	ָ�������ⲿ�жϳ�ʼ��
* ��    ��: GPIO_TypeDef * GPIOx	ָ�������ⲿ�жϵ�GPIO�˿ڣ���Чֵ����GPIOA��GPIOB��GPIOC
*			uint32_t GPIO_Pin 		ָ�������ⲿ�жϵ�GPIO���ţ���Чֵ����PIN0��PIN1��PIN2��... ... PIN14��PIN15
*			uint32_t mode	        ��Чֵ��EXTI_FALL_EDGE��EXTI_RISE_EDGE��EXTI_BOTH_EDGE��EXTI_LOW_LEVEL��EXTI_HIGH_LEVEL
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void EXTI_Init(GPIO_TypeDef * GPIOx, uint32_t GPIO_Pin, uint32_t mode)
{
	EXTI_Assert_Param(GPIOx,GPIO_Pin);                     //�������Ĳ����Ƿ�Ϸ�    
	
	assert_param(IS_EXTI_MODE(mode));                      //�������Ĳ���Pin�Ƿ�Ϸ�  
	
	
	EXTI_Close(GPIOx, GPIO_Pin);			               //���ùؼ��Ĵ���ǰ�ȹر�
	
	if(mode & 0x10)
	{
		GPIOx->INTLVLTRG |= (0x01 << GPIO_Pin);			   //��ƽ����
		
		if(mode & 0x01)
			GPIOx->INTRISEEN |= (0x01 << GPIO_Pin);		   //�ߵ�ƽ����
		else
			GPIOx->INTRISEEN &= ~(0x01 << GPIO_Pin);	   //�͵�ƽ����
	}		
	else
	{
		GPIOx->INTLVLTRG &= ~(0x01 << GPIO_Pin);		   //���ش���
		
		if(mode & 0x02)
		{
			GPIOx->INTBE |= (0x01 << GPIO_Pin);			   //˫���ش���	
		}
		else
		{
			GPIOx->INTBE &= ~(0x01 << GPIO_Pin);		   //�����ش���
			
			if(mode & 0x01)
				GPIOx->INTRISEEN |= (0x01 << GPIO_Pin);	   //�����ش���
			else
				GPIOx->INTRISEEN &= ~(0x01 << GPIO_Pin);   //�½��ش���
		}
	}
	
	GPIOx->INTCLR = (1 << GPIO_Pin);		//�������Ϊģʽ���ÿ��ܲ������ж�
}

/****************************************************************************************************************************************** 
* ��������:	EXTI_Open()
* ����˵��:	ָ�������ⲿ�жϴ򿪣���ʹ�ܣ�
* ��    ��: GPIO_TypeDef * GPIOx	ָ�������ⲿ�жϵ�GPIO�˿ڣ���Чֵ����GPIOA��GPIOB��GPIOC
*			uint32_t GPIO_Pin 		ָ�������ⲿ�жϵ�GPIO���ţ���Чֵ����PIN0��PIN1��PIN2��... ... PIN14��PIN15
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void EXTI_Open(GPIO_TypeDef * GPIOx, uint32_t GPIO_Pin)
{
	EXTI_Assert_Param(GPIOx,GPIO_Pin);                     //�������Ĳ����Ƿ�Ϸ�    
	
	GPIOx->INTEN |= (0x01 << GPIO_Pin);
}

/****************************************************************************************************************************************** 
* ��������:	EXTI_Close()
* ����˵��:	ָ�������ⲿ�жϹرգ������ܣ�
* ��    ��: GPIO_TypeDef * GPIOx	ָ�������ⲿ�жϵ�GPIO�˿ڣ���Чֵ����GPIOA��GPIOB��GPIOC
*			uint32_t GPIO_Pin 		ָ�������ⲿ�жϵ�GPIO���ţ���Чֵ����PIN0��PIN1��PIN2��... ... PIN14��PIN15
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void EXTI_Close(GPIO_TypeDef * GPIOx, uint32_t GPIO_Pin)
{
	EXTI_Assert_Param(GPIOx,GPIO_Pin);                     //�������Ĳ����Ƿ�Ϸ�    
	
	GPIOx->INTEN &= ~(0x01 << GPIO_Pin);
}

/****************************************************************************************************************************************** 
* ��������:	EXTI_State()
* ����˵��:	ָ�������Ƿ񴥷����ж�
* ��    ��: GPIO_TypeDef * GPIOx	ָ�������ⲿ�жϵ�GPIO�˿ڣ���Чֵ����GPIOA��GPIOB��GPIOC
*			uint32_t GPIO_Pin 		ָ�������ⲿ�жϵ�GPIO���ţ���Чֵ����PIN0��PIN1��PIN2��... ... PIN14��PIN15
* ��    ��: uint32_t	            1 �����Ŵ������ж�    0 ������δ�����ж�
* ע������: ��
******************************************************************************************************************************************/
uint32_t EXTI_State(GPIO_TypeDef * GPIOx, uint32_t GPIO_Pin)
{
	EXTI_Assert_Param(GPIOx,GPIO_Pin);                     //�������Ĳ����Ƿ�Ϸ�    
	
	return (GPIOx->INTSTAT >> GPIO_Pin) & 0x01;
}

/****************************************************************************************************************************************** 
* ��������:	EXTI_RawState()
* ����˵��:	ָ�������Ƿ������/���жϴ��������������жϹر�ʱ��ͨ�����ô˺����Բ�ѯ�ķ�ʽ����������Ƿ������/���жϴ�������
* ��    ��: GPIO_TypeDef * GPIOx	ָ�������ⲿ�жϵ�GPIO�˿ڣ���Чֵ����GPIOA��GPIOB��GPIOC
*			uint32_t GPIO_Pin 	    ָ�������ⲿ�жϵ�GPIO���ţ���Чֵ����PIN0��PIN1��PIN2��... ... PIN14��PIN15
* ��    ��: uint32_t	            1 �����������/���жϴ�������    0 ������δ�����/���жϴ�������
* ע������: ��
******************************************************************************************************************************************/
uint32_t EXTI_RawState(GPIO_TypeDef * GPIOx, uint32_t GPIO_Pin)
{
	EXTI_Assert_Param(GPIOx,GPIO_Pin);                     //�������Ĳ����Ƿ�Ϸ�    
	
	return (GPIOx->INTRAWSTAT >> GPIO_Pin) & 0x01;
}

/****************************************************************************************************************************************** 
* ��������:	EXTI_Clear()
* ����˵��:	ָ�������ⲿ�ж������������жϱ�־�������ٴν�����жϣ�
* ��    ��: GPIO_TypeDef * GPIOx	ָ�������ⲿ�жϵ�GPIO�˿ڣ���Чֵ����GPIOA��GPIOB��GPIOC
*			uint32_t GPIO_Pin 	    ָ�������ⲿ�жϵ�GPIO���ţ���Чֵ����PIN0��PIN1��PIN2��... ... PIN14��PIN15
* ��    ��: ��
* ע������: ֻ��������ش����жϵı�־����ƽ�����жϵı�־�޷������ֻ�������ŵ�ƽ�������жϴ���������Ӳ���Զ����
******************************************************************************************************************************************/
void EXTI_Clear(GPIO_TypeDef * GPIOx, uint32_t GPIO_Pin)
{
	EXTI_Assert_Param(GPIOx,GPIO_Pin);                     //�������Ĳ����Ƿ�Ϸ�    
	
	GPIOx->INTCLR = (0x01 << GPIO_Pin);
}

