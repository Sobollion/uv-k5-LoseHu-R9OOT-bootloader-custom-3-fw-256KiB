#include "DP32G030_cmp.h"


/****************************************************************************************************************************************** 
* ��������: CMP_Init()
* ����˵��:	�Ƚ�����ʼ��
* ��    ��: CMP_InitTypeDef* CMP_InitStruct  
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void CMP_Init(CMP_InitTypeDef* CMP_InitStruct)
{
	uint32_t temp = 0;
	
	assert_param(IS_CMP_ALL(CMP_InitStruct->CMP));         //�������Ĳ���CMP�Ƿ�Ϸ�  
  
	assert_param(IS_CMP_HYS(CMP_InitStruct->HYS));         //�������Ĳ���HYS�Ƿ�Ϸ�  
 
	assert_param(IS_CMP_FILTER(CMP_InitStruct->FILTER));   //�������Ĳ���FILTER�Ƿ�Ϸ�  

	assert_param(IS_CMP_IE(CMP_InitStruct->IE));           //�������Ĳ���IE�Ƿ�Ϸ�  
	 
	
	CMP_Close(CMP_InitStruct->CMP);
	
	temp = SYS->CMP_CFG;
	
	temp &= ~(0x03 << SYS_CMP_CFG_CMP_FILTER_POS);
	
	temp |= CMP_InitStruct->FILTER << SYS_CMP_CFG_CMP_FILTER_POS;
	
	if(CMP_InitStruct->CMP == CMP0)
	{
		temp &= ~(0x03 << SYS_CMP_CFG_CMP0_HYS_POS);	
		temp |= CMP_InitStruct->HYS << SYS_CMP_CFG_CMP0_HYS_POS;	
		
		if(CMP_InitStruct->IE == ENABLE)
		{
			temp |= 0x01<<SYS_CMP_CFG_CMP0_INTEN_POS;
		}
	}
	else if(CMP_InitStruct->CMP == CMP1)
	{
		temp &= ~(0x03 << SYS_CMP_CFG_CMP1_HYS_POS);	
		temp |= CMP_InitStruct->HYS << SYS_CMP_CFG_CMP1_HYS_POS;

		if(CMP_InitStruct->IE == ENABLE)
		{
			temp |= 0x01<<SYS_CMP_CFG_CMP1_INTEN_POS;
		}		
	}
	else if(CMP_InitStruct->CMP == CMP2)
	{
		temp &= ~(0x03 << SYS_CMP_CFG_CMP2_HYS_POS);	
		temp |= CMP_InitStruct->HYS << SYS_CMP_CFG_CMP2_HYS_POS;

		if(CMP_InitStruct->IE == ENABLE)
		{
			temp |= 0x01<<SYS_CMP_CFG_CMP2_INTEN_POS;
		}
	}
	
	SYS->CMP_CFG = temp;
	
	if(CMP_InitStruct->IE == ENABLE)
	{
		NVIC_EnableIRQ(CMP_IRQn);
	}	
}

/****************************************************************************************************************************************** 
* ��������: CMP_Open()
* ����˵��:	�Ƚ�����
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2  
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void CMP_Open(CMP_TypeDef Cmp)
{
	assert_param(IS_CMP_ALL(Cmp));    //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if((Cmp & CMP0) == CMP0)
	{
		SYS->CMP_CFG |= (0x01 << SYS_CMP_CFG_CMP0_EN_POS);
	}
	
	if((Cmp & CMP1) == CMP1)
	{
		SYS->CMP_CFG |= (0x01 << SYS_CMP_CFG_CMP1_EN_POS);
	}
	
	if((Cmp & CMP2) == CMP2)
	{
		SYS->CMP_CFG |= (0x01 << SYS_CMP_CFG_CMP2_EN_POS);
	}
}

/****************************************************************************************************************************************** 
* ��������: CMP_Close()
* ����˵��:	�Ƚ����ر�
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2  
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void CMP_Close(CMP_TypeDef Cmp)
{
	assert_param(IS_CMP_ALL(Cmp));    //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if((Cmp & CMP0) == CMP0)
	{
		SYS->CMP_CFG &= ~(0x01 << SYS_CMP_CFG_CMP0_EN_POS);
	}
	
	if((Cmp & CMP1) == CMP1)
	{
		SYS->CMP_CFG &= ~(0x01 << SYS_CMP_CFG_CMP1_EN_POS);
	}
	
	if((Cmp & CMP2) == CMP2)
	{
		SYS->CMP_CFG &= ~(0x01 << SYS_CMP_CFG_CMP2_EN_POS);
	}
}

/****************************************************************************************************************************************** 
* ��������: CMP_INTEn()
* ����˵��:	�Ƚ����ж�ʹ��
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2  
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void CMP_INTEn(CMP_TypeDef Cmp)
{
	assert_param(IS_CMP_ALL(Cmp));    //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if((Cmp & CMP0) == CMP0)
	{
		SYS->CMP_CFG |= (0x01 << SYS_CMP_CFG_CMP0_INTEN_POS);
	}
	
	if((Cmp & CMP1) == CMP1)
	{
		SYS->CMP_CFG |= (0x01 << SYS_CMP_CFG_CMP1_INTEN_POS);
	}
	
	if((Cmp & CMP2) == CMP2)
	{
		SYS->CMP_CFG |= (0x01 << SYS_CMP_CFG_CMP2_INTEN_POS);
	}
	
	NVIC_EnableIRQ(CMP_IRQn);
}

/****************************************************************************************************************************************** 
* ��������: CMP_INTDis()
* ����˵��:	�Ƚ����жϽ���
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2  
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void CMP_INTDis(CMP_TypeDef Cmp)
{
	assert_param(IS_CMP_ALL(Cmp));    //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if((Cmp & CMP0) == CMP0)
	{
		SYS->CMP_CFG &= ~(0x01 << SYS_CMP_CFG_CMP0_INTEN_POS);
	}
	
	if((Cmp & CMP1) == CMP1)
	{
		SYS->CMP_CFG &= ~(0x01 << SYS_CMP_CFG_CMP1_INTEN_POS);
	}
	
	if((Cmp & CMP2) == CMP2)
	{
		SYS->CMP_CFG &= ~(0x01 << SYS_CMP_CFG_CMP2_INTEN_POS);
	}
}

/****************************************************************************************************************************************** 
* ��������: CMP_SetHys()
* ����˵��:	�Ƚ������ó��͵�ѹ
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2  
            CMP_HYS_TypeDef Cmp_Hys  ��Чֵ��CMP_HYS_24MV  CMP_HYS_40MV  CMP_HYS_60MV  CMP_HYS_0MV
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void CMP_SetHys(CMP_TypeDef Cmp,CMP_HYS_TypeDef Cmp_Hys)
{
	uint32_t temp = 0;
	
	assert_param(IS_CMP_ALL(Cmp));        //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	assert_param(IS_CMP_HYS(Cmp_Hys));    //�������Ĳ���Cmp_Hys�Ƿ�Ϸ�  
	
	temp = SYS->CMP_CFG;
	
	if((Cmp & CMP0) == CMP0)
	{
		temp &= ~(0x03 << SYS_CMP_CFG_CMP0_HYS_POS);	
		temp |= Cmp_Hys << SYS_CMP_CFG_CMP0_HYS_POS;	
	}
	
	if((Cmp & CMP1) == CMP1)
	{
		temp &= ~(0x03 << SYS_CMP_CFG_CMP1_HYS_POS);
		temp |= Cmp_Hys << SYS_CMP_CFG_CMP1_HYS_POS;
	}
	
	if((Cmp & CMP2) == CMP2)
	{
		temp &= ~(0x03 << SYS_CMP_CFG_CMP2_HYS_POS);	
		temp |= Cmp_Hys << SYS_CMP_CFG_CMP2_HYS_POS;
	}
	
	SYS->CMP_CFG = temp;
}

/****************************************************************************************************************************************** 
* ��������: CMP_SetFilter()
* ����˵��:	�Ƚ��������˲�
* ��    ��: CMP_FILTER_TypeDef Cmp_Filter       ��Чֵ��CMP_FILTER_0CLK  CMP_FILTER_2CLK  CMP_FILTER_4CLK  CMP_FILTER_8CLK 
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void CMP_SetFilter(CMP_FILTER_TypeDef Cmp_Filter)
{
	uint32_t temp = 0;
	
	assert_param(IS_CMP_FILTER(Cmp_Filter));    //�������Ĳ���Cmp_Filter�Ƿ�Ϸ�  
	
	temp = SYS->CMP_CFG;
	
	temp &= ~(0x03 << SYS_CMP_CFG_CMP_FILTER_POS);
	
	temp |= Cmp_Filter << SYS_CMP_CFG_CMP_FILTER_POS;
	
	SYS->CMP_CFG = temp;
}

/****************************************************************************************************************************************** 
* ��������: CMP_Get_Value_AfterFilter()
* ����˵��:	�Ƚ�����ȡ�˲���ıȽϽ��
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2 
* ��    ��: 0  P��<N��  1  P��>N��
* ע������: ��
******************************************************************************************************************************************/
uint8_t CMP_Get_Value_AfterFilter(CMP_TypeDef Cmp)
{
	uint8_t value = 0;
	
	assert_param(IS_CMP_TYPE(Cmp));        //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if(Cmp == CMP0)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP0_FLITER_OUT_POS) & 0x01;
	}
	else if(Cmp == CMP1)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP1_FLITER_OUT_POS) & 0x01;
	}
	else if(Cmp == CMP2)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP2_FLITER_OUT_POS) & 0x01;
	}
	
	return value;
}

/****************************************************************************************************************************************** 
* ��������: CMP_Get_Value_BeforeFilter()
* ����˵��:	�Ƚ�����ȡ�˲�ǰ�ıȽϽ��
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2 
* ��    ��: 0  P��<N��  1  P��>N��
* ע������: ��
******************************************************************************************************************************************/
uint8_t CMP_Get_Value_BeforeFilter(CMP_TypeDef Cmp)
{
	uint8_t value = 0;
	
	assert_param(IS_CMP_TYPE(Cmp));        //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if(Cmp == CMP0)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP0_OUT_POS) & 0x01;
	}
	else if(Cmp == CMP1)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP1_OUT_POS) & 0x01;
	}
	else if(Cmp == CMP2)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP2_OUT_POS) & 0x01;
	}
	
	return value;
}

/****************************************************************************************************************************************** 
* ��������: CMP_INTRiseStat()
* ����˵��:	�Ƚ�������Ƿ�����0��1�ı仯
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2 
* ��    ��: 0  û�з�����0��1�ı仯   1  ������0��1�ı仯
* ע������: ��
******************************************************************************************************************************************/
uint8_t CMP_INTRiseStat(CMP_TypeDef Cmp)
{
	uint8_t value = 0;
	
	assert_param(IS_CMP_TYPE(Cmp));        //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if(Cmp == CMP0)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP0_RISEIF_POS) & 0x01;
	}
	else if(Cmp == CMP1)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP1_RISEIF_POS) & 0x01;
	}
	else if(Cmp == CMP2)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP2_RISEIF_POS) & 0x01;
	}
	
	return value;
}


/****************************************************************************************************************************************** 
* ��������: CMP_INTFallStat()
* ����˵��:	�Ƚ�������Ƿ�����1��0�ı仯
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2 
* ��    ��: 0  û�з�����1��0�ı仯   1  ������1��0�ı仯
* ע������: ��
******************************************************************************************************************************************/
uint8_t CMP_INTFallStat(CMP_TypeDef Cmp)
{
	uint8_t value = 0;
	
	assert_param(IS_CMP_TYPE(Cmp));        //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if(Cmp == CMP0)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP0_FALLIF_POS) & 0x01;
	}
	else if(Cmp == CMP1)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP1_FALLIF_POS) & 0x01;
	}
	else if(Cmp == CMP2)
	{
		value = (SYS->CMP_ST >> SYS_CMP_ST_CMP2_FALLIF_POS) & 0x01;
	}
	
	return value;
}


/****************************************************************************************************************************************** 
* ��������: CMP_INTRiseClr()
* ����˵��:	�Ƚ������������0��1�ı仯�жϱ�־���
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2 
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void CMP_INTRiseClr(CMP_TypeDef Cmp)
{
	assert_param(IS_CMP_TYPE(Cmp));        //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if(Cmp == CMP0)
	{
		SYS->CMP_ST = 0x01 << SYS_CMP_ST_CMP0_RISEIF_POS;
	}
	else if(Cmp == CMP1)
	{
		SYS->CMP_ST = 0x01 << SYS_CMP_ST_CMP1_RISEIF_POS;
	}
	else if(Cmp == CMP2)
	{
		SYS->CMP_ST = 0x01 << SYS_CMP_ST_CMP2_RISEIF_POS;
	}
}


/****************************************************************************************************************************************** 
* ��������: CMP_INTFallClr()
* ����˵��:	�Ƚ������������1��0�ı仯�жϱ�־���
* ��    ��: CMP_TypeDef Cmp       ��Чֵ��CMP0  CMP1  CMP2 
* ��    ��: ��
* ע������: ��
******************************************************************************************************************************************/
void CMP_INTFallClr(CMP_TypeDef Cmp)
{
	assert_param(IS_CMP_TYPE(Cmp));        //�������Ĳ���Cmp�Ƿ�Ϸ�  
	
	if(Cmp == CMP0)
	{
		SYS->CMP_ST = 0x01 << SYS_CMP_ST_CMP0_FALLIF_POS;
	}
	else if(Cmp == CMP1)
	{
		SYS->CMP_ST = 0x01 << SYS_CMP_ST_CMP1_FALLIF_POS;
	}
	else if(Cmp == CMP2)
	{
		SYS->CMP_ST = 0x01 << SYS_CMP_ST_CMP2_FALLIF_POS;
	}
}

