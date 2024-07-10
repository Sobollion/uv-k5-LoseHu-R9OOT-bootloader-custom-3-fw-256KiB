#include "DP32G030_port.h"


/****************************************************************************************************************************************** 
* ��������: PORT_Init()
* ����˵��:	�˿����Ź���ѡ��
* ��    ��: PORT_InitTypeDef* PORT_InitStruct
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void PORT_Init(PORT_InitTypeDef* PORT_InitStruct)
{
	uint32_t temp = 0;
	
	assert_param(IS_PORT_ALL(PORT_InitStruct->Port));                             //�������Ĳ���Port�Ƿ�Ϸ�   
	
	assert_param(IS_INPUT_EN(PORT_InitStruct->Input_En));                         //�������Ĳ���Input_En�Ƿ�Ϸ�   
	
	assert_param(IS_PORT_FUNC(PORT_InitStruct->Func));                            //�������Ĳ���Func�Ƿ�Ϸ� 
	
	switch(PORT_InitStruct->Port)
	{
		case PORTA:
			
			assert_param(IS_GPIOA_PIN(PORT_InitStruct->Pin));                     //�������Ĳ���Pin�Ƿ�Ϸ�    
		
			if(PORT_InitStruct->Pin <= GPIO_PIN7)
			{
				temp = PORT->PORTA_SEL0;
				
				temp &= ~(0x0F << ((PORT_InitStruct->Pin)*4)); 
				temp |= ((PORT_InitStruct->Func) << ((PORT_InitStruct->Pin)*4));
				
				PORT->PORTA_SEL0 = temp;          //PORTA0-7 IO�˿ڹ�������
			}
			else if(PORT_InitStruct->Pin <= GPIO_PIN15)
			{
				temp = PORT->PORTA_SEL1;
				
				temp &= ~(0x0F << ((PORT_InitStruct->Pin - GPIO_PIN8)*4)); 
				temp |= ((PORT_InitStruct->Func) << ((PORT_InitStruct->Pin - GPIO_PIN8)*4));

				PORT->PORTA_SEL1 = temp;          //PORTA8-15 IO�˿ڹ�������
			}
			
			if(PORT_InitStruct->Input_En == ENABLE)                                 
			{
				PORT->PORTA_INEN |=  (0x01 << (PORT_InitStruct->Pin));           //����ʹ�ܴ�
			}
			else
			{
				PORT->PORTA_INEN &= ~(0x01 << (PORT_InitStruct->Pin));           //����ʹ�ܹر�
			}
			
		break;

		case PORTB:
			
			assert_param(IS_GPIOB_PIN(PORT_InitStruct->Pin));                     //�������Ĳ���Pin�Ƿ�Ϸ�  
			
			if(PORT_InitStruct->Pin <= GPIO_PIN7)
			{
				temp = PORT->PORTB_SEL0;
				
				temp &= ~(0x0F << ((PORT_InitStruct->Pin)*4)); 
				temp |= ((PORT_InitStruct->Func) << ((PORT_InitStruct->Pin)*4));
				
				PORT->PORTB_SEL0 = temp;          //PORTB0-7 IO�˿ڹ�������
			}
			else if(PORT_InitStruct->Pin <= GPIO_PIN15)
			{
				temp = PORT->PORTB_SEL1;
				
				temp &= ~(0x0F << ((PORT_InitStruct->Pin - GPIO_PIN8)*4)); 
				temp |= ((PORT_InitStruct->Func) << ((PORT_InitStruct->Pin - GPIO_PIN8)*4));

				PORT->PORTB_SEL1 = temp;          //PORTB8-15 IO�˿ڹ�������
			}
			
			if(PORT_InitStruct->Input_En == ENABLE)                                 
			{
				PORT->PORTB_INEN |=  (0x01 << (PORT_InitStruct->Pin));           //����ʹ�ܴ�
			}
			else
			{
				PORT->PORTB_INEN &= ~(0x01 << (PORT_InitStruct->Pin));           //����ʹ�ܹر�
			}
			
		break;
			
		case PORTC:
		
			assert_param(IS_GPIOC_PIN(PORT_InitStruct->Pin));                     //�������Ĳ���Pin�Ƿ�Ϸ�  
			
			if(PORT_InitStruct->Pin <= GPIO_PIN7)
			{
				temp = PORT->PORTC_SEL0;
				
				temp &= ~(0x0F << ((PORT_InitStruct->Pin)*4)); 
				temp |= ((PORT_InitStruct->Func) << ((PORT_InitStruct->Pin)*4));
				
				PORT->PORTC_SEL0 = temp;          //PORTC0-7 IO�˿ڹ�������
			}
			
			if(PORT_InitStruct->Input_En == ENABLE)                                 
			{
				PORT->PORTC_INEN |=  (0x01 << (PORT_InitStruct->Pin));           //����ʹ�ܴ�
			}
			else
			{
				PORT->PORTC_INEN &= ~(0x01 << (PORT_InitStruct->Pin));           //����ʹ�ܹر�
			}

		break;
		
		default:
		break;
	}
}

/****************************************************************************************************************************************** 
* ��������: PORT_CFG_Init()
* ����˵��:	�˿�����
* ��    ��: PORT_CFGTypeDef* PORT_CFGStruct
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void PORT_CFG_Init(PORT_CFGTypeDef* PORT_CFGStruct)
{
	uint32_t temp = 0;
	
	assert_param(IS_OUT_CURRENT(PORT_CFGStruct->PortA_Out_Cur));                           //�������Ĳ���PortA_Out_Cur�Ƿ�Ϸ�     
	
	assert_param(IS_OUT_CURRENT(PORT_CFGStruct->PortB_Out_Cur));                           //�������Ĳ���PortB_Out_Cur�Ƿ�Ϸ�  
	
	assert_param(IS_OUT_CURRENT(PORT_CFGStruct->PortC_Out_Cur));                           //�������Ĳ���PortC_Out_Cur�Ƿ�Ϸ�  
	
	assert_param(IS_INPUT_HYS(PORT_CFGStruct->InputHys));                                  //�������Ĳ���InputHys�Ƿ�Ϸ�   
	
	
	temp = PORT->PORT_CFG;

	temp &= ~(0x03 << PORT_CFG_PORTA_DS_POS);
	temp |=  ((PORT_CFGStruct->PortA_Out_Cur) << PORT_CFG_PORTA_DS_POS);          //����PORTA����������
	
	temp &= ~(0x03 << PORT_CFG_PORTB_DS_POS);
	temp |=  ((PORT_CFGStruct->PortB_Out_Cur) << PORT_CFG_PORTB_DS_POS);          //����PORTB����������
	
	temp &= ~(0x03 << PORT_CFG_PORTC_DS_POS);
	temp |=  ((PORT_CFGStruct->PortC_Out_Cur) << PORT_CFG_PORTC_DS_POS);          //����PORTC����������
	
	temp &= ~(0x01 << PORT_CFG_HYS_POS);
	temp |=  ((PORT_CFGStruct->InputHys) << PORT_CFG_HYS_POS);                    //����PORT��������͵ȼ�

	PORT->PORT_CFG = temp;	
}



