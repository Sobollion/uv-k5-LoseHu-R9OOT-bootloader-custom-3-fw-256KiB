#include "DP32G030_timerbase.h"

/****************************************************************************************************************************************** 
* ��������: TIMBASE_Init()
* ����˵��:	������ʱ����ʼ��
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1  TIMBASE2
*			uint8_t type	��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ�� 
*			TIMBASE_InitTypeDef * TIMBASE_InitStruct   
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void TIMBASE_Init(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type,TIMBASE_InitTypeDef * TIMBASE_InitStruct)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));                          //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));                             //�������Ĳ���type�Ƿ�Ϸ�  
	
	assert_param(IS_TIMBASE_CLKDIV(TIMBASE_InitStruct->ClkDiv));     //�������Ĳ���ClkDiv�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_PERIOD(TIMBASE_InitStruct->Period));     //�������Ĳ���Period�Ƿ�Ϸ�  
	
	assert_param(IS_TIMBASE_OVF_IE(TIMBASE_InitStruct->Ovf_IE));     //�������Ĳ���Ovf_IE�Ƿ�Ϸ�  
	
	
	switch((uint32_t)TIMBASEx)
	{
		case((uint32_t)TIMBASE0):
		
			SYS->CLKEN |= 0x01 << SYS_CLKEN_TIMBASE0_POS;           //����TIMBASE0ʱ��
		
		break;
		
		case((uint32_t)TIMBASE1):
		
			SYS->CLKEN |= 0x01 << SYS_CLKEN_TIMBASE1_POS;           //����TIMBASE1ʱ��
		
		break;
		
		case((uint32_t)TIMBASE2):
		
			SYS->CLKEN |= 0x01 << SYS_CLKEN_TIMBASE2_POS;           //����TIMBASE2ʱ��
		
		break;
	}
	
	TIMBASE_Stop(TIMBASEx,type);                                    //�رն�ʱ�����
	
	TIMBASEx->DIV = TIMBASE_InitStruct->ClkDiv;                     //TIMBASE��Ƶϵ��,ʵ�ʷ�ƵΪ����ֵ��1
	
	
	if((type & TIMBASE_LOW) == TIMBASE_LOW)
	{
		TIMBASEx->LOW_PERIOD = TIMBASE_InitStruct->Period;
		
		TIMBASEx->IE &= ~(0x01 << TIMBASE_IE_LOW_POS);
		TIMBASEx->IE |= (TIMBASE_InitStruct->Ovf_IE << TIMBASE_IE_LOW_POS);
	}
	
	if((type & TIMBASE_HIGH) == TIMBASE_HIGH)
	{
		TIMBASEx->HIGH_PERIOD = TIMBASE_InitStruct->Period;
		
		TIMBASEx->IE &= ~(0x01 << TIMBASE_IE_HIGH_POS);
		TIMBASEx->IE |= (TIMBASE_InitStruct->Ovf_IE << TIMBASE_IE_HIGH_POS);
	}
	
	if(TIMBASE_InitStruct->Ovf_IE)
	{
		switch((uint32_t)TIMBASEx)
		{
			case((uint32_t)TIMBASE0):
			
				NVIC_EnableIRQ(TIMBASE0_IRQn);
			
			break;
			
			case((uint32_t)TIMBASE1):
			
				NVIC_EnableIRQ(TIMBASE1_IRQn);
			
			break;
			
			case((uint32_t)TIMBASE2):
			
				NVIC_EnableIRQ(TIMBASE2_IRQn);
			
			break;
		}
	}
}


/****************************************************************************************************************************************** 
* ��������:	TIMBASE_Start()
* ����˵��:	������ʱ�����ӳ�ʼֵ��ʼ��ʱ/����
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1  TIMBASE2
*           uint8_t type	��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ�� 

* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void TIMBASE_Start(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));                          //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));                             //�������Ĳ���type�Ƿ�Ϸ�  
	
	if((type & TIMBASE_LOW) == TIMBASE_LOW)
	{
		TIMBASEx->EN |= (0x01 << TIMBASE_EN_LOW_POS);
	}
	
	if((type & TIMBASE_HIGH) == TIMBASE_HIGH)
	{
		TIMBASEx->EN |= (0x01 << TIMBASE_EN_HIGH_POS);
	}
}


/****************************************************************************************************************************************** 
* ��������:	TIMBASE_Stop()
* ����˵��:	ֹͣ��ʱ��
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1  TIMBASE2
*           uint8_t type	��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ�� 

* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void TIMBASE_Stop(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));                          //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));                             //�������Ĳ���type�Ƿ�Ϸ�  
	
	if((type & TIMBASE_LOW) == TIMBASE_LOW)
	{
		TIMBASEx->EN &= ~(0x01 << TIMBASE_EN_LOW_POS);
	}
	
	if((type & TIMBASE_HIGH) == TIMBASE_HIGH)
	{
		TIMBASEx->EN &= ~(0x01 << TIMBASE_EN_HIGH_POS);
	}
}

/****************************************************************************************************************************************** 
* ��������:	TIMBASE_SetClkDiv()
* ����˵��:	����Ԥ��Ƶϵ��   ʵ�ʷ�ƵΪ����ֵ��1
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1  TIMBASE2
*           uint16_t Clk_Div      ʱ��Ԥ��Ƶϵ��  
*			
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void TIMBASE_SetClkDiv(TIMBASE_TypeDef * TIMBASEx,uint16_t Clk_Div)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));       //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_CLKDIV(Clk_Div));     //�������Ĳ���ClkDiv�Ƿ�Ϸ�   
	
	TIMBASEx->DIV = Clk_Div;                      //TIMBASE��Ƶϵ��  ʵ�ʷ�ƵΪ����ֵ��1
}


/****************************************************************************************************************************************** 
* ��������:	TIMPLUS_SetPeriod()
* ����˵��:	���ö�ʱ����������ֵ
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1  TIMBASE2
            TIMPLUS_TypeTypeDef type         ��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ�� 
*	        uint16_t Period          	     ��ʱ����������ֵ
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void TIMBASE_SetPeriod(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type,uint16_t Period)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));      //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));         //�������Ĳ���type�Ƿ�Ϸ�  
	
	assert_param(IS_TIMBASE_PERIOD(Period));     //�������Ĳ���Period�Ƿ�Ϸ�  
	
	if((type & TIMBASE_LOW) == TIMBASE_LOW)
	{
		TIMBASEx->LOW_PERIOD = Period;           //��ʱ����������ֵ
	}
	
	if((type & TIMBASE_HIGH) == TIMBASE_HIGH)
	{
		TIMBASEx->HIGH_PERIOD = Period;          //��ʱ����������ֵ
	}	
}


/****************************************************************************************************************************************** 
* ��������:	TIMBASE_GetPeriod()
* ����˵��:	��ȡ��ʱ����������ֵ
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1  TIMBASE2
            TIMBASE_TypeTypeDef type         ��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ��        	     
* ��    ��: ��ʱ����������ֵ
* ע������: ��
******************************************************************************************************************************************/
uint16_t TIMBASE_GetPeriod(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));      //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));         //�������Ĳ���type�Ƿ�Ϸ�  
	
	if(type == TIMBASE_LOW)
	{
		return TIMBASEx->LOW_PERIOD;             //���ص�16λ��ʱ����������ֵ
	}
	else if(type == TIMBASE_HIGH)
	{
		return TIMBASEx->HIGH_PERIOD;            //���ظ�16λ��ʱ����������ֵ
	}

	return 0;
}

/****************************************************************************************************************************************** 
* ��������:	TIMBASE_GetCurValue()
* ����˵��:	��ȡ��ǰ����ֵ
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1  TIMBASE2
            TIMBASE_TypeTypeDef type         ��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ��    
* ��    ��: ��ʱ����ǰ����ֵ
* ע������: ��
******************************************************************************************************************************************/
uint16_t TIMBASE_GetCurValue(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));      //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));         //�������Ĳ���type�Ƿ�Ϸ�  
	
	if(type == TIMBASE_LOW)
	{
		return TIMBASEx->LOW_CNT;                //���ض�ʱ����ǰ����ֵ
	}
	else if(type == TIMBASE_HIGH)
	{
		return TIMBASEx->HIGH_CNT;              //���ض�ʱ����ǰ����ֵ
	}
	
	return 0;
}


/****************************************************************************************************************************************** 
* ��������:	TIMBASE_INTEn()
* ����˵��:	ʹ���ж�
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1  TIMBASE2
            TIMBASE_TypeTypeDef type         ��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ��  
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void TIMBASE_INTEn(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));                   //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));                      //�������Ĳ���type�Ƿ�Ϸ�  
	
	if((type & TIMBASE_LOW) == TIMBASE_LOW)
	{
		TIMBASEx->IE |= (0x01 << TIMBASE_IE_LOW_POS);         //��ʱ������ж�ʹ��
	}
	
	if((type & TIMBASE_HIGH) == TIMBASE_HIGH)
	{
		TIMBASEx->IE |= (0x01 << TIMBASE_IE_HIGH_POS);        //��ʱ������ж�ʹ��
	}
}


/****************************************************************************************************************************************** 
* ��������:	TIMBASE_INTDis()
* ����˵��:	�����ж�
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1   TIMBASE2
            TIMBASE_TypeTypeDef type         ��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ��  
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void TIMBASE_INTDis(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));                    //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));                       //�������Ĳ���type�Ƿ�Ϸ�  
	
	if((type & TIMBASE_LOW) == TIMBASE_LOW)
	{
		TIMBASEx->IE &= ~(0x01 << TIMBASE_IE_LOW_POS);         //��ʱ������жϽ���
	}
	
	if((type & TIMBASE_HIGH) == TIMBASE_HIGH)
	{
		TIMBASEx->IE &= ~(0x01 << TIMBASE_IE_HIGH_POS);        //��ʱ������жϽ���
	}
}


/****************************************************************************************************************************************** 
* ��������:	TIMBASE_INTClr()
* ����˵��:	����жϱ�־
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1   TIMBASE2
            TIMBASE_TypeTypeDef type         ��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ��  
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void TIMBASE_INTClr(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));                  //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));                     //�������Ĳ���type�Ƿ�Ϸ�  
	
	if((type & TIMBASE_LOW) == TIMBASE_LOW)
	{
		TIMBASEx->IF = (0x01 << TIMBASE_IF_LOW_POS);         //�����ʱ������ж�״̬
	}
	
	if((type & TIMBASE_HIGH) == TIMBASE_HIGH)
	{
		TIMBASEx->IF = (0x01 << TIMBASE_IF_HIGH_POS);        //�����ʱ������ж�״̬
	}
}

/****************************************************************************************************************************************** 
* ��������: TIMBASE_INTStat()
* ����˵��:	��ȡ�ж�״̬
* ��    ��: TIMBASE_TypeDef * TIMBASEx       ��Чֵ��TIMBASE0  TIMBASE1  TIMBASE2
            TIMBASE_TypeTypeDef type         ��ʱ��ѡ��   1����16λ��ʱ��  2����16λ��ʱ��  
* ��    ��: uint8_t 			   0 TIMBASExδ�����ж�    1 TIMBASEx�������ж�
* ע������: ��
******************************************************************************************************************************************/
uint8_t TIMBASE_INTStat(TIMBASE_TypeDef * TIMBASEx,TIMBASE_TypeTypeDef type)
{
	assert_param(IS_TIMBASE_ALL(TIMBASEx));              //�������Ĳ���TIMBASEx�Ƿ�Ϸ�   
	
	assert_param(IS_TIMBASE_TYPE(type));                 //�������Ĳ���type�Ƿ�Ϸ�  
	
	if(type == TIMBASE_LOW)
	{
		if(TIMBASEx->IF & TIMBASE_IF_LOW_MSK)
		{
			return 1;
		}
	}
	else if(type == TIMBASE_HIGH)
	{
		if(TIMBASEx->IF & TIMBASE_IF_HIGH_MSK)
		{
			return 1;
		}
	}
	
	return 0;
}



