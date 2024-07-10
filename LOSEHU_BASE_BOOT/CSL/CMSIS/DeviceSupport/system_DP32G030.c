#include <stdint.h>
#include "DP32G030.h"


uint32_t SystemCoreClock  = __HSI;   				      //System Clock Frequency (Core Clock)
uint32_t CyclesPerUs      = (__HSI / 1000000); 		      //Cycles per micro second


void XTAL_Port_Init(void)
{
	PORT_InitTypeDef PORT_InitStruct = {0};
	
	PORT_InitStruct.Port = PORTA;
	PORT_InitStruct.Pin = GPIO_PIN1;
	PORT_InitStruct.Func = PORTA_PIN1_XTAL_XI;
	PORT_InitStruct.Input_En = ENABLE;           
	
	PORT_Init(&PORT_InitStruct);     //PORTA1����ΪXTAL��XI����
	
	PORT_InitStruct.Port = PORTA;
	PORT_InitStruct.Pin = GPIO_PIN2;
	PORT_InitStruct.Func = PORTA_PIN2_XTAL_XO;
	PORT_InitStruct.Input_En = ENABLE;           
	
	PORT_Init(&PORT_InitStruct);     //PORTA2����ΪXTAL��XO����
}


void XTAH_Port_Init(void)
{
	PORT_InitTypeDef PORT_InitStruct = {0};
	
	PORT_InitStruct.Port = PORTA;
	PORT_InitStruct.Pin = GPIO_PIN3;
	PORT_InitStruct.Func = PORTA_PIN3_XTAH_XI;
	PORT_InitStruct.Input_En = ENABLE;           
	
	PORT_Init(&PORT_InitStruct);     //PORTA3����ΪXTAH��XI����
	
	PORT_InitStruct.Port = PORTA;
	PORT_InitStruct.Pin = GPIO_PIN4;
	PORT_InitStruct.Func = PORTA_PIN4_XTAH_XO;
	PORT_InitStruct.Input_En = ENABLE;           
	
	PORT_Init(&PORT_InitStruct);     //PORTA4����ΪXTAH��XO����
}


uint32_t  Sys_Clk_Read(void)
{
	uint32_t temp = 0,data1 = 0,data2 = 0;
	
	temp = SYS->CLKSEL;
	
	data1 = ((temp & SYS_CLKSEL_PLL_READ_MSK) >> SYS_CLKSEL_PLL_READ_POS) << SYS_CLKSEL_PLL_POS;
	
	temp &= ~(SYS_CLKSEL_PLL_READ_MSK);
	
	data2 = ((temp & SYS_CLKSEL_ADC_READ_MSK) >> SYS_CLKSEL_ADC_READ_POS) << SYS_CLKSEL_ADC_POS;
	
	temp &= ~(SYS_CLKSEL_ADC_READ_MSK);
	
	temp |= data1;
	
	temp |= data2;
	
	return temp;
}


void Switch_CLK_48MHZ(void)
{
	uint32_t temp = 0;
	
	temp = PMU->SRC_CFG;
	
	temp |= 0x01 << PMU_SRC_CFG_RCHF_EN_POS;               //RCHFʹ�� 
	temp &= ~(0x01 << PMU_SRC_CFG_RCHF_FSEL_POS);          //RCHFѡ��48MHZ
	
	PMU->SRC_CFG = temp;
	
	temp = Sys_Clk_Read();
	
	temp &= ~(0x07 << SYS_CLKSEL_SRC_POS);                 //ʱ��Դѡ��RCHF
	temp &= ~(0x01 << SYS_CLKSEL_SYS_POS);                 //ϵͳʱ��ѡ��ΪRCHF
	
	SYS->CLKSEL = temp;
	
	SYS->CLKDIV_EN &= ~(0x01 << SYS_CLKDIV_EN_DIV_POS);    //��Ƶʱ�ӽ�ֹ���
}


void Switch_CLK_48MHZ_DIV2(void)
{
	uint32_t temp = 0;
	
	temp = PMU->SRC_CFG;
	
	temp |= 0x01 << PMU_SRC_CFG_RCHF_EN_POS;               //RCHFʹ�� 
	temp |= 0x01 << PMU_SRC_CFG_RCHF_FSEL_POS;             //RCHFѡ��24MHZ
	
	PMU->SRC_CFG = temp;
	
	temp = Sys_Clk_Read();
	
	temp &= ~(0x07 << SYS_CLKSEL_SRC_POS);                 //ʱ��Դѡ��RCHF
	temp &= ~(0x01 << SYS_CLKSEL_SYS_POS);                 //ϵͳʱ��ѡ��ΪRCHF
	
	SYS->CLKSEL = temp;
	
	SYS->CLKDIV_EN &= ~(0x01 << SYS_CLKDIV_EN_DIV_POS);    //��Ƶʱ�ӽ�ֹ���
}


void Switch_CLK_48MHZ_DIV4(void)
{
	uint32_t temp = 0;
	
	Switch_CLK_48MHZ_DIV2();                               //�л�ʱ��ʱ�����лص��ڲ�24MHZ
	
	temp = Sys_Clk_Read();
	
	temp &= ~(0x07 << SYS_CLKSEL_DIV_POS);       
	temp |= DIV_CLK_SEL_DIV2 << SYS_CLKSEL_DIV_POS;        //��Ƶʱ��ѡ��2��Ƶ

	SYS->CLKSEL = temp;
	
	SYS->CLKDIV_EN |= 0x01 << SYS_CLKDIV_EN_DIV_POS;       //��Ƶʱ����� 
	
	temp = Sys_Clk_Read();
	
	temp |= 0x01 << SYS_CLKSEL_SYS_POS;          //ϵͳʱ��ѡ���Ƶʱ��   
	
	SYS->CLKSEL = temp;
}

void Switch_CLK_XTAH(void)
{
	uint32_t k = 0,temp = 0;
	
	Switch_CLK_48MHZ_DIV2();                               //�л�ʱ��ʱ�����лص��ڲ�24MHZ
	
	XTAH_Port_Init();                                      //����Ӧ�˿�����ΪXTAH����
	
	PMU->SRC_CFG |= 0x01 << PMU_SRC_CFG_XTAH_EN_POS;       //XTAHʹ��
	
	for(k = 0; k < 1000000;k++);                           //XTAHʹ�ܺ����ٵȴ�10ms��ʹ��
	
	temp = Sys_Clk_Read();
	
	temp &= ~(0x07 << SYS_CLKSEL_DIV_POS);              //��Ƶʱ��ѡ��1��Ƶ
	
	temp &= ~(0x07 << SYS_CLKSEL_SRC_POS);       
	temp |= SRC_CLK_SEL_XTAH << SYS_CLKSEL_SRC_POS;     //ʱ��Դѡ��XTAH
	
	SYS->CLKSEL = temp;
	
	SYS->CLKDIV_EN |= 0x01 << SYS_CLKDIV_EN_DIV_POS;    //��Ƶʱ����� 
	
	temp = Sys_Clk_Read();
	
	temp |= 0x01 << SYS_CLKSEL_SYS_POS;          //ϵͳʱ��ѡ���Ƶʱ��   
	
	SYS->CLKSEL = temp;
}

void Switch_CLK_XTAH_DIV2(void)
{
	uint32_t k = 0,temp = 0;
	
	Switch_CLK_48MHZ_DIV2();                            //�л�ʱ��ʱ�����лص��ڲ�24MHZ
	
	XTAH_Port_Init();                                   //����Ӧ�˿�����ΪXTAH����
	
	PMU->SRC_CFG |= 0x01 << PMU_SRC_CFG_XTAH_EN_POS;    //XTAHʹ��
	
	for(k = 0; k < 1000000;k++);                        //XTAHʹ�ܺ����ٵȴ�10ms��ʹ��
	
	temp = Sys_Clk_Read();
	
	temp &= ~(0x07 << SYS_CLKSEL_DIV_POS);       
	temp |= 0x01 << SYS_CLKSEL_DIV_POS;                 //��Ƶʱ��ѡ��2��Ƶ
	
	temp &= ~(0x07 << SYS_CLKSEL_SRC_POS);       
	temp |= SRC_CLK_SEL_XTAH << SYS_CLKSEL_SRC_POS;     //ʱ��Դѡ��XTAH
	
	SYS->CLKSEL = temp;
	
	SYS->CLKDIV_EN |= 0x01 << SYS_CLKDIV_EN_DIV_POS;    //��Ƶʱ����� 
	
	temp = Sys_Clk_Read();
	
	temp |= 0x01 << SYS_CLKSEL_SYS_POS;          //ϵͳʱ��ѡ���Ƶʱ��   
	
	SYS->CLKSEL = temp;
}

void Switch_CLK_PLL_RCHF_Set(uint8_t Pll_M,uint8_t Pll_N)
{
	uint32_t temp = 0;
	
	Switch_CLK_48MHZ_DIV2();                            //�л�ʱ��ʱ�����лص��ڲ�24MHZ
	
	temp = Sys_Clk_Read();

	temp &= ~(0x01 << SYS_CLKSEL_PLL_POS);              //PLL�ο�ʱ��ѡ��RCHF
	
	temp &= ~(0x07 << SYS_CLKSEL_SRC_POS);       
	temp |= SRC_CLK_SEL_PLL << SYS_CLKSEL_SRC_POS;      //ʱ��Դѡ��PLL
	
	temp &= ~(0x07 << SYS_CLKSEL_DIV_POS);              //��Ƶʱ��ѡ��1��Ƶ
	
	SYS->CLKSEL = temp;
	
	temp = SYS->PLL_CTRL; 
	
	temp &= ~(0x1F << SYS_PLL_CTRL_PLL_M_POS);          //PLL�ο�ʱ�ӷ�Ƶ��������
	temp |= Pll_M << SYS_PLL_CTRL_PLL_M_POS;            //M = Pll_M     2M <= CLK/M <= 6M    ������õ�4M
	
	temp &= ~(0x1F << SYS_PLL_CTRL_PLL_N_POS);          //PLL�ο�ʱ��FEEDBACK��������
	temp |= Pll_N << SYS_PLL_CTRL_PLL_N_POS;            //N = Pll_N     PLL = CLK/M*N   
	
	temp |= 0x01 << SYS_PLL_CTRL_PLL_EN_POS;            //PLLʹ��
	
	SYS->PLL_CTRL = temp;
	
	while((SYS->PLL_ST & SYS_PLL_ST_LOCK_MSK) == 0);    //�ȴ�PLL����
	
	SYS->CLKDIV_EN |= 0x01 << SYS_CLKDIV_EN_DIV_POS;    //��Ƶʱ����� 
	
	temp = Sys_Clk_Read();
	
	temp |= 0x01 << SYS_CLKSEL_SYS_POS;          //ϵͳʱ��ѡ���Ƶʱ��   
	
	SYS->CLKSEL = temp;
}


void Switch_CLK_PLL_RCHF_72MHz(void)
{
	Switch_CLK_PLL_RCHF_Set(PLL_M_DIV6,PLL_N_MUL18);     
}


void Switch_CLK_PLL_RCHF_64MHz(void)
{
	Switch_CLK_PLL_RCHF_Set(PLL_M_DIV6,PLL_N_MUL16);
}


void Switch_CLK_PLL_XTAH_Set(uint8_t Pll_M,uint8_t Pll_N)
{
	uint32_t k = 0,temp = 0;
	
	Switch_CLK_48MHZ_DIV2();                            //�л�ʱ��ʱ�����лص��ڲ�24MHZ
	
	XTAH_Port_Init();                                   //����Ӧ�˿�����ΪXTAH����
	
	PMU->SRC_CFG |= 0x01 << PMU_SRC_CFG_XTAH_EN_POS;    //XTAHʹ��
	
	for(k = 0; k < 1000000;k++);                        //XTAHʹ�ܺ����ٵȴ�10ms��ʹ��
	
	temp = Sys_Clk_Read();

	temp |= (0x01 << SYS_CLKSEL_PLL_POS);               //PLL�ο�ʱ��ѡ��XTAH
	
	temp &= ~(0x07 << SYS_CLKSEL_SRC_POS);       
	temp |= SRC_CLK_SEL_PLL << SYS_CLKSEL_SRC_POS;      //ʱ��Դѡ��PLL
	
	temp &= ~(0x07 << SYS_CLKSEL_DIV_POS);              //��Ƶʱ��ѡ��1��Ƶ
	
	SYS->CLKSEL = temp;
	
	temp = SYS->PLL_CTRL; 
	
	temp &= ~(0x1F << SYS_PLL_CTRL_PLL_M_POS);          //PLL�ο�ʱ�ӷ�Ƶ��������
	temp |= Pll_M << SYS_PLL_CTRL_PLL_M_POS;            //M = Pll_N      2M <= HSE/M <= 6M    ������õ�4M
	
	temp &= ~(0x1F << SYS_PLL_CTRL_PLL_N_POS);          //PLL�ο�ʱ��FEEDBACK��������
	temp |= Pll_N << SYS_PLL_CTRL_PLL_N_POS;            //N = Pll_N     PLL = HSE/M*N   
	
	temp |= 0x01 << SYS_PLL_CTRL_PLL_EN_POS;            //PLLʹ��
	
	SYS->PLL_CTRL = temp;
	
	while((SYS->PLL_ST & SYS_PLL_ST_LOCK_MSK) == 0);    //�ȴ�PLL����
	
	SYS->CLKDIV_EN |= 0x01 << SYS_CLKDIV_EN_DIV_POS;    //��Ƶʱ����� 
	
	temp = Sys_Clk_Read();
	
	temp |= 0x01 << SYS_CLKSEL_SYS_POS;                 //ϵͳʱ��ѡ���Ƶʱ��   
	
	SYS->CLKSEL = temp;
}

void Switch_CLK_PLL_XTAH_72MHz(void)
{
	Switch_CLK_PLL_XTAH_Set(PLL_M_DIV2,PLL_N_MUL18);    
}

void Switch_CLK_PLL_XTAH_64MHz(void)
{
	Switch_CLK_PLL_XTAH_Set(PLL_M_DIV2,PLL_N_MUL16);
}

void Switch_CLK_PLL_XTAH_56MHz(void)
{
	Switch_CLK_PLL_XTAH_Set(PLL_M_DIV2,PLL_N_MUL14);
}

void Switch_CLK_PLL_XTAH_48MHz(void)
{
	Switch_CLK_PLL_XTAH_Set(PLL_M_DIV2,PLL_N_MUL12);
}


void SystemCoreClockUpdate(void)
{
	uint8_t Clk_Div = 1;
	
	if((SYS->CLKSEL & SYS_CLKSEL_SYS_MSK) == 0)               //ϵͳʱ��ѡ��RCHF
	{
		if(PMU->SRC_CFG & PMU_SRC_CFG_RCHF_FSEL_MSK)          
		{
			SystemCoreClock  = __HSI >> 1;                    //RCHFƵ��ѡ��24M
		}
		else
		{
			SystemCoreClock  = __HSI;                         //RCHFƵ��ѡ��48M
		}
	}
	else
	{
		Clk_Div = 0x01 << ((SYS->CLKSEL & SYS_CLKSEL_DIV_MSK) >> SYS_CLKSEL_DIV_POS);              //��ȡ���õķ�Ƶʱ�ӷ�Ƶϵ��
		
		if(((SYS->CLKSEL & SYS_CLKSEL_SRC_MSK)>> SYS_CLKSEL_SRC_POS) == SRC_CLK_SEL_RCHF)          //Դʱ��ѡ��RCHF        
		{
			if(PMU->SRC_CFG & PMU_SRC_CFG_RCHF_FSEL_MSK) 
			{
				Clk_Div  *= 2;      //���RCHF��24M�����Ƶϵ������2
			}
			
			SystemCoreClock  = __HSI / Clk_Div; 
		}
		else if(((SYS->CLKSEL & SYS_CLKSEL_SRC_MSK) >> SYS_CLKSEL_SRC_POS) == SRC_CLK_SEL_XTAH)    //Դʱ��ѡ��XTAH 
		{
			SystemCoreClock  = __HSE / Clk_Div; 
		}
		else if(((SYS->CLKSEL & SYS_CLKSEL_SRC_MSK) >> SYS_CLKSEL_SRC_POS) == SRC_CLK_SEL_PLL)     //Դʱ��ѡ��PLL
		{
			if(((SYS->CLKSEL & SYS_CLKSEL_PLL_READ_MSK) >> SYS_CLKSEL_PLL_READ_POS) == PLL_CLK_SEL_RCHF)
			{
				if(PMU->SRC_CFG & PMU_SRC_CFG_RCHF_FSEL_MSK) 
				{
					Clk_Div  *= 2;      //���RCHF��24M�����Ƶϵ������2
				}
				
				SystemCoreClock = __HSI / (((SYS->PLL_CTRL & SYS_PLL_CTRL_PLL_M_MSK) >> SYS_PLL_CTRL_PLL_M_POS) + 1);
			}
			else
			{
				SystemCoreClock = __HSE / (((SYS->PLL_CTRL & SYS_PLL_CTRL_PLL_M_MSK) >> SYS_PLL_CTRL_PLL_M_POS) + 1);
			}
			
			SystemCoreClock *= ((((SYS->PLL_CTRL & SYS_PLL_CTRL_PLL_N_MSK) >> SYS_PLL_CTRL_PLL_N_POS) + 1)*2);
				
			SystemCoreClock /= Clk_Div;
		}		
	}

	CyclesPerUs = SystemCoreClock/1000000;
}




void SystemClkSel(uint8_t clk)
{		
	switch(clk)
	{
		case SYS_CLK_48MHz:			               //0 �ڲ���Ƶ48MHz RC����
			
			Switch_CLK_48MHZ();
		
		break;
		
		case SYS_CLK_48MHz_DIV2:			       //1 �ڲ���Ƶ48MHz RC����  2��Ƶ
			
			Switch_CLK_48MHZ_DIV2();
		
		break;
		
		case SYS_CLK_48MHz_DIV4:                   //2 �ڲ���Ƶ48MHz RC����  4��Ƶ
			
			Switch_CLK_48MHZ_DIV4();
		
		break;
		
		case SYS_CLK_XTAH:                         //3 �ⲿ��Ƶ����������4-32MHz��
			
			Switch_CLK_XTAH();
		
		break;
		
		case SYS_CLK_XTAH_DIV2:                    //4 �ⲿ��Ƶ����������4-32MHz�� 2��Ƶ
			
			Switch_CLK_XTAH_DIV2();
		
		break;
		
		case SYS_CLK_PLL_RCHF_72MHz:              //5 PLLʱ��  RCHF��Ϊ����ʱ�ӱ�Ƶ���72MHz
			
			Switch_CLK_PLL_RCHF_72MHz();
		
		break;
		
		case SYS_CLK_PLL_RCHF_64MHz:              //6 PLLʱ��  RCHF��Ϊ����ʱ�ӱ�Ƶ���64MHz
			
			Switch_CLK_PLL_RCHF_64MHz();
		
		break;
		
		case SYS_CLK_PLL_XTAH_72MHz:              //7 PLLʱ��  XTAH��Ϊ����ʱ�ӱ�Ƶ���72MHz
			
			Switch_CLK_PLL_XTAH_72MHz();
		
		break;
		
		case SYS_CLK_PLL_XTAH_64MHz:              //8 PLLʱ��  XTAH��Ϊ����ʱ�ӱ�Ƶ���64MHz	
			
			Switch_CLK_PLL_XTAH_64MHz();
		
		break;
		
		case SYS_CLK_PLL_XTAH_56MHz:              //9 PLLʱ��  XTAH��Ϊ����ʱ�ӱ�Ƶ���56MHz	
			
			Switch_CLK_PLL_XTAH_56MHz();
		
		break;
		
		case SYS_CLK_PLL_XTAH_48MHz:              //10 PLLʱ��  XTAH��Ϊ����ʱ�ӱ�Ƶ���48MHz	
			
			Switch_CLK_PLL_XTAH_48MHz();
		
		break;
	}
}


/****************************************************************************************************************************************** 
* ��������: 
* ����˵��: The necessary initializaiton of system
* ��    ��: 
* ��    ��: 
* ע������: 
******************************************************************************************************************************************/
void SystemInit(void)
{		
	FLASH_Init(FLASH_ONE_CLK_WAIT);                    //FLASH��ʼ��
	
	Read_Trim_Value_From_Flash();                      //��NVR����ȡTTRIMֵ��д����Ӧ�Ĵ���
	
	SystemClkSel(SYS_CLK_48MHz);                       //����ϵͳʱ��Ϊ48MHz
	
	SystemCoreClockUpdate();	                       //�������õ�ϵͳʱ�� 
	
	FLASH_Init(FLASH_TWO_CLK_WAIT);                    //FLASH��ʼ��
}


