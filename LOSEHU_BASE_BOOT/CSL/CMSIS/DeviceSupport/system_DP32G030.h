#ifndef __SYSTEM_HBM32G030_H__
#define __SYSTEM_HBM32G030_H__

#include "core_cm0.h"


#ifdef __cplusplus
 extern "C" {
#endif


/******************************************************************************************************************************************
 * ϵͳʱ���趨
 *****************************************************************************************************************************************/
#define SYS_CLK_48MHz		       0	 	//0 �ڲ���Ƶ48MHz RC����
#define SYS_CLK_48MHz_DIV2	       1		//1 �ڲ���Ƶ48MHz RC����  2��Ƶ
#define SYS_CLK_48MHz_DIV4	       2		//2 �ڲ���Ƶ48MHz RC����  4��Ƶ
#define SYS_CLK_XTAH		       3		//3 �ⲿ��Ƶ����������4-32MHz��
#define SYS_CLK_XTAH_DIV2	       4		//4 �ⲿ��Ƶ����������4-32MHz�� 2��Ƶ
#define SYS_CLK_PLL_RCHF_72MHz     5        //5 PLLʱ��  RCHF��Ϊ����ʱ�ӱ�Ƶ���72MHz
#define SYS_CLK_PLL_RCHF_64MHz     6        //6 PLLʱ��  RCHF��Ϊ����ʱ�ӱ�Ƶ���64MHz
#define SYS_CLK_PLL_XTAH_72MHz     7        //7 PLLʱ��  XTAH��Ϊ����ʱ�ӱ�Ƶ���72MHz
#define SYS_CLK_PLL_XTAH_64MHz     8        //8 PLLʱ��  XTAH��Ϊ����ʱ�ӱ�Ƶ���64MHz	
#define SYS_CLK_PLL_XTAH_56MHz     9        //9 PLLʱ��  XTAH��Ϊ����ʱ�ӱ�Ƶ���56MHz	
#define SYS_CLK_PLL_XTAH_48MHz     10      //10 PLLʱ��  XTAH��Ϊ����ʱ�ӱ�Ƶ���48MHz	
	 
	 
#define __HSI		(48000000UL)		//�����ڲ�ʱ��
#define __LSI		(   32768UL)		//�����ڲ�ʱ��
#define __HSE		( 8000000UL)		//�����ⲿʱ��	 
#define __LSE		(   32768UL)		//�����ⲿʱ�� 
	
	
#define PLL_CLK_SEL_RCHF        0x00    //PLLʱ��ѡ��RCHF	
#define PLL_CLK_SEL_XTAH        0x01    //PLLʱ��ѡ��XTAH	

#define SRC_CLK_SEL_RCHF        0x00    //Դʱ��ѡ��RCHF
#define SRC_CLK_SEL_RCLF        0x01    //Դʱ��ѡ��RCLF
#define SRC_CLK_SEL_XTAH        0x02    //Դʱ��ѡ��XTAH	
#define SRC_CLK_SEL_XTAL        0x03    //Դʱ��ѡ��XTAL		
#define SRC_CLK_SEL_PLL         0x04    //Դʱ��ѡ��PLL	
	
#define DIV_CLK_SEL_DIV1        0x00    //Դʱ��1��Ƶ	
#define DIV_CLK_SEL_DIV2        0x01    //Դʱ��2��Ƶ		
#define DIV_CLK_SEL_DIV4        0x02    //Դʱ��4��Ƶ		
#define DIV_CLK_SEL_DIV8        0x03    //Դʱ��8��Ƶ		
#define DIV_CLK_SEL_DIV16       0x04    //Դʱ��16��Ƶ		
#define DIV_CLK_SEL_DIV32       0x05    //Դʱ��32��Ƶ		
	
#define PLL_M_DIV1              0x00    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ1
#define PLL_M_DIV2              0x01    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ2
#define PLL_M_DIV3              0x02    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ3
#define PLL_M_DIV4              0x03    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ4
#define PLL_M_DIV5              0x04    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ5
#define PLL_M_DIV6              0x05    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ6
#define PLL_M_DIV7              0x06    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ7
#define PLL_M_DIV8              0x07    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ8
#define PLL_M_DIV9              0x08    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ9
#define PLL_M_DIV10             0x09    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ10
#define PLL_M_DIV11             0x0A    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ11
#define PLL_M_DIV12             0x0B    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ12
#define PLL_M_DIV13             0x0C    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ13
#define PLL_M_DIV14             0x0D    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ14
#define PLL_M_DIV15             0x0E    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ15
#define PLL_M_DIV16             0x0F    //PLL�ο�ʱ�ӷ�Ƶϵ��Ϊ16


#define PLL_N_MUL2              0x00    //PLLʱ�ӱ�Ƶϵ��Ϊ2
#define PLL_N_MUL4              0x01    //PLLʱ�ӱ�Ƶϵ��Ϊ4
#define PLL_N_MUL6              0x02    //PLLʱ�ӱ�Ƶϵ��Ϊ6
#define PLL_N_MUL8              0x03    //PLLʱ�ӱ�Ƶϵ��Ϊ8
#define PLL_N_MUL10             0x04    //PLLʱ�ӱ�Ƶϵ��Ϊ10
#define PLL_N_MUL12             0x05    //PLLʱ�ӱ�Ƶϵ��Ϊ12
#define PLL_N_MUL14             0x06    //PLLʱ�ӱ�Ƶϵ��Ϊ14
#define PLL_N_MUL16             0x07    //PLLʱ�ӱ�Ƶϵ��Ϊ16
#define PLL_N_MUL18             0x08    //PLLʱ�ӱ�Ƶϵ��Ϊ18
#define PLL_N_MUL20             0x09    //PLLʱ�ӱ�Ƶϵ��Ϊ20
#define PLL_N_MUL22             0x0A    //PLLʱ�ӱ�Ƶϵ��Ϊ22
#define PLL_N_MUL24             0x0B    //PLLʱ�ӱ�Ƶϵ��Ϊ24
#define PLL_N_MUL26             0x0C    //PLLʱ�ӱ�Ƶϵ��Ϊ26
#define PLL_N_MUL28             0x0D    //PLLʱ�ӱ�Ƶϵ��Ϊ28
#define PLL_N_MUL30             0x0E    //PLLʱ�ӱ�Ƶϵ��Ϊ30
#define PLL_N_MUL32             0x0F    //PLLʱ�ӱ�Ƶϵ��Ϊ32


extern uint32_t SystemCoreClock;		// System Clock Frequency (Core Clock)
extern uint32_t CyclesPerUs;			// Cycles per micro second

extern uint32_t  Sys_Clk_Read(void);
extern void SystemInit(void);


#ifdef __cplusplus
}
#endif

#endif //__SYSTEM_HBM32G030_H__
