#ifndef __DP32G030_H__
#define __DP32G030_H__

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
 */
typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers **********************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                        */
  HardFault_IRQn	          = -13,	/*!< 3 Cortex-M0 Hard Fault Interrupt				 */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M0 SV Call Interrupt                  */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M0 Pend SV Interrupt                  */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M0 System Tick Interrupt              */
  
/******  Cortex-M0 specific Interrupt Numbers ************************************************/
  WWDT_IRQn                   = 0,
  IWDT_IRQn                   = 1,
  RTC_IRQn                    = 2,
  DMA_IRQn                    = 3,
  ADC_IRQn                    = 4,
  TIMBASE0_IRQn               = 5,
  TIMBASE1_IRQn               = 6,
  TIMPLUS0_IRQn               = 7,
  TIMPLUS1_IRQn               = 8,
  PWMBASE0_IRQn               = 9,
  PWMBASE1_IRQn               = 10,
  PWMPLUS0_IRQn               = 11,
  PWMPLUS1_IRQn               = 12,
  UART0_IRQn                  = 13,
  UART1_IRQn                  = 14,
  UART2_IRQn                  = 15,
  SPI0_IRQn                   = 16,
  SPI1_IRQn                   = 17,
  IIC0_IRQn                   = 18,	
  IIC1_IRQn                   = 19,
  CMP_IRQn                    = 20,
  TIMBASE2_IRQn               = 21,
  GPIOA5_IRQn                 = 22,
  GPIOA6_IRQn                 = 23,
  GPIOA7_IRQn                 = 24,
  GPIOB0_IRQn                 = 25,
  GPIOB1_IRQn                 = 26,
  GPIOC0_IRQn                 = 27,
  GPIOC1_IRQn                 = 28,
  GPIOA_IRQn                  = 29,
  GPIOB_IRQn                  = 30,
  GPIOC_IRQn                  = 31,
} IRQn_Type;

/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __MPU_PRESENT		    0	   /*!< UART does not provide a MPU present or not	     */
#define __NVIC_PRIO_BITS		2	   /*!< UART Supports 2 Bits for the Priority Levels	 */
#define __Vendor_SysTickConfig  0	   /*!< Set to 1 if different SysTick Config is used	 */

#if   defined ( __CC_ARM )
  #pragma anon_unions
#endif

#include <stdio.h>
#include "core_cm0.h"				   /* Cortex-M0 processor and core peripherals		     */

typedef enum {RESET = 0, SET = 1} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = 1} FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = 1} ErrorStatus;


/******************************************************************************/
/*				Device Specific Peripheral registers structures			 */
/******************************************************************************/

typedef struct {
	__IO uint32_t LPOW_MD;      //�͹���ģʽѡ��
	
	__IO uint32_t LPMD_WKEN;    //�͹��Ļ���Դʹ��
	
	__IO uint32_t LPMD_WKST;    //�͹��Ļ���Դ״̬
	
	__IO uint32_t CHIPRST_ST;   //оƬ��λ״̬   
	
	__IO uint32_t SRC_CFG;      //ʱ��Դ���üĴ���
	
	uint32_t RESERVED2[3];
	
	__IO uint32_t TRIM_POW0;     
	
	__IO uint32_t TRIM_POW1;

	__IO uint32_t TRIM_POW2;   
	
	__IO uint32_t TRIM_POW3; 

	__IO uint32_t TRIM_RCHF; 

	__IO uint32_t TRIM_RCLF;

	__IO uint32_t TRIM_OPA;

	__IO uint32_t TRIM_PLL;
	
	uint32_t RESERVED3[(0x80-0x40)/4];
	
	__IO uint32_t TRIM_LOCK;
	
} PMU_TypeDef;


#define PMU_LPOW_MD_STANDBY_POS         0     //STANDBYģʽ
#define PMU_LPOW_MD_STANDBY_MSK         (0x01 << PMU_LPOW_MD_STANDBY_POS)

#define PMU_LPOW_MD_SLEEP_POS           1     //SLEEPģʽ
#define PMU_LPOW_MD_SLEEP_MSK           (0x01 << PMU_LPOW_MD_SLEEP_POS)

#define PMU_LPOW_MD_DEEPSLEEP_POS       2     //DEEPSLEEPģʽ
#define PMU_LPOW_MD_DEEPSLEEP_MSK       (0x01 << PMU_LPOW_MD_DEEPSLEEP_POS)

#define PMU_LPOW_MD_STOP_POS            3     //STOPģʽ
#define PMU_LPOW_MD_STOP_MSK            (0x01 << PMU_LPOW_MD_STOP_POS)


#define PMU_LPMD_WKEN_ALM_POS           0    //�͹���ģʽ��  RTC�����źŻ���ʹ��
#define PMU_LPMD_WKEN_ALM_MSK           (0x01 << PMU_LPMD_WKEN_ALM_POS)

#define PMU_LPMD_WKEN_TIM_POS           1    //�͹���ģʽ��  RTCʱ���źŻ���ʹ��    ����  ��  ��  ʱ  �վ�������
#define PMU_LPMD_WKEN_TIM_MSK           (0x01 << PMU_LPMD_WKEN_TIM_POS)

#define PMU_LPMD_WKEN_IO_POS            2     //�͹���ģʽ��  IO�źŻ���ʹ��
#define PMU_LPMD_WKEN_IO_MSK            (0x01 << PMU_LPMD_WKEN_IO_POS)


#define PMU_LPMD_WKST_ALM_POS           0     //�͹���ģʽ��  RTC�����źŻ��ѱ�־
#define PMU_LPMD_WKST_ALM_MSK           (0x01 << PMU_LPMD_WKST_ALM_POS)

#define PMU_LPMD_WKST_TIM_POS           1     //�͹���ģʽ��  RTCʱ���źŻ��ѱ�־
#define PMU_LPMD_WKST_TIM_MSK           (0x01 << PMU_LPMD_WKST_TIM_POS)

#define PMU_LPMD_WKST_IO_POS            2     //�͹���ģʽ��  IO�źŻ��ѱ�־
#define PMU_LPMD_WKST_IO_MSK            (0x01 << PMU_LPMD_WKST_IO_POS)


#define PMU_CHIPRST_POR_POS		      0	    //�ϵ縴λ״̬
#define PMU_CHIPRST_POR_MSK		      (0x01 << PMU_CHIPRST_POR_POS)
 
#define PMU_CHIPRST_IWDT_POS		  1	    //�������Ź���λ״̬
#define PMU_CHIPRST_IWDT_MSK		  (0x01 << PMU_CHIPRST_IWDT_POS)
 
#define PMU_CHIPRST_WWDT_POS		  2	    //���ڿ��Ź���λ״̬
#define PMU_CHIPRST_WWDT_MSK		  (0x01 << PMU_CHIPRST_WWDT_POS) 


#define PMU_SRC_CFG_RCHF_EN_POS         0     //RCHFʹ��
#define PMU_SRC_CFG_RCHF_EN_MSK         (0x01 << PMU_SRC_CFG_RCHF_EN_POS)

#define PMU_SRC_CFG_RCHF_FSEL_POS       1     //RCHFƵ��ѡ��
#define PMU_SRC_CFG_RCHF_FSEL_MSK       (0x01 << PMU_SRC_CFG_RCHF_FSEL_POS)

#define PMU_SRC_CFG_XTAH_EN_POS         2     //XTAHʹ��
#define PMU_SRC_CFG_XTAH_EN_MSK         (0x01 << PMU_SRC_CFG_XTAH_EN_POS)

#define PMU_SRC_CFG_XTAL_EN_POS         3     //XTALʹ��
#define PMU_SRC_CFG_XTAL_EN_MSK         (0x01 << PMU_SRC_CFG_XTAL_EN_POS)

#define PMU_SRC_CFG_RTC_CLK_SEL_POS     4     //RTCʱ��ѡ��  0:RCLF, 1:XTAL
#define PMU_SRC_CFG_RTC_CLK_SEL_MSK     (0x01 << PMU_SRC_CFG_RTC_CLK_SEL_POS)


#define PMU_TRIM_LOCK_POS		        0	//TRIM_LOCK       д��0x55����TRIM�Ĵ���
#define PMU_TRIM_LOCK_MSK		        (0xFF << PMU_TRIM_LOCK_POS)

#define PMU_TRIM_UNLOCK_POS		        8	//TRIM_UNLOCK     д��0xAA����TRIM�Ĵ���
#define PMU_TRIM_UNLOCK_MSK		        (0xFF << PMU_TRIM_UNLOCK_POS)


typedef struct {
	__IO uint32_t CLKSEL;				//Clock Select

	__IO uint32_t CLKDIV_EN;			//CLK_DIVʱ��Դ����

	__IO uint32_t CLKEN;			    //����Clock Enable

	uint32_t RESERVED1[(0x78 - 0x0C)/4];
	
	__IO uint32_t RC_FREQ_DELTA;        //RCHF��RCLF��ʵƵ�ʲ�ֵ�Ĵ���

	__IO uint32_t VREF_VOLT_DELTA;      //VREF��ʵ��ѹֵ��ֵ�Ĵ���	
	
	__IO uint32_t CHIPID0;              //128BIT�豸ID�Ĵ���
	
	__IO uint32_t CHIPID1;
	
	__IO uint32_t CHIPID2;
	
	__IO uint32_t CHIPID3;
	
	uint32_t RESERVED2[(0x120 - 0x90)/4];
	
	__IO uint32_t CMP_CFG;              //�Ƚ������üĴ���
	
	__IO uint32_t CMP_ST;               //�Ƚ���״̬�Ĵ���
	
	uint32_t RESERVED3[(0x140 - 0x128)/4];
	
	__IO uint32_t OPA_CFG;              //����Ŵ������üĴ���  
	
	uint32_t RESERVED4[(0x180 - 0x144)/4];
	
	__IO uint32_t PLL_CTRL;             //PLL���ƼĴ���
	
	__IO uint32_t PLL_ST;               //PLL״̬�Ĵ���
} SYS_TypeDef;


#define SYS_CLKSEL_SYS_POS		      0		//ϵͳʱ��ѡ��	0 RCHF  1 CLK_DIVx
#define SYS_CLKSEL_SYS_MSK		      (0x01 << SYS_CLKSEL_SYS_POS)

#define SYS_CLKSEL_DIV_POS		      1		//ѡ��CLK_DIVx  0 DIV1  1 DIV2  2 DIV4   3 DIV8  4  DIV16   5  DIV32
#define SYS_CLKSEL_DIV_MSK		      (0x07 << SYS_CLKSEL_DIV_POS)

#define SYS_CLKSEL_SRC_POS		      4		//ѡ��SRC  0 RCHF   1 RCLF   2 XTAH   3 XTAL  4  PLL
#define SYS_CLKSEL_SRC_MSK		      (0x07 << SYS_CLKSEL_SRC_POS)

#define SYS_CLKSEL_PLL_POS		      7		//PLL�ο�ʱ��ѡ��	0 RCHF  1 XTAH
#define SYS_CLKSEL_PLL_MSK		      (0x01 << SYS_CLKSEL_PLL_POS)

#define SYS_CLKSEL_PLL_READ_POS       11    //PLL�ο�ʱ��  ��ȡ
#define SYS_CLKSEL_PLL_READ_MSK       (0x01 << SYS_CLKSEL_PLL_READ_POS)

#define SYS_CLKSEL_ADC_POS		      10	//ADC����ʱ��ѡ��  0 1��Ƶ   1 2��Ƶ   2 4��Ƶ   3 8��Ƶ
#define SYS_CLKSEL_ADC_MSK		      (0x03 << SYS_CLKSEL_ADC_POS)

#define SYS_CLKSEL_ADC_READ_POS		  7	    //ADC����ʱ��   ��ȡ
#define SYS_CLKSEL_ADC_READ_MSK		  (0x03 << SYS_CLKSEL_ADC_READ_POS)


#define SYS_CLKDIV_EN_DIV_POS	      0		//��Ƶʱ��ѡ��	0 ʹ�ܷ�Ƶʱ�����  1 ��ֹ��Ƶʱ�����	
#define SYS_CLKDIV_EN_DIV_MSK         (0x01 << SYS_CLKDIV_EN_DIV_POS)


#define SYS_CLKEN_GPIOA_POS		      0		//GPIOAʱ���ſ�   
#define SYS_CLKEN_GPIOA_MSK		      (0x01 << SYS_CLKEN_GPIOA_POS)

#define SYS_CLKEN_GPIOB_POS		      1		//GPIOBʱ���ſ�   
#define SYS_CLKEN_GPIOB_MSK		      (0x01 << SYS_CLKEN_GPIOB_POS)

#define SYS_CLKEN_GPIOC_POS		      2		//GPIOCʱ���ſ�   
#define SYS_CLKEN_GPIOC_MSK		      (0x01 << SYS_CLKEN_GPIOC_POS)

#define SYS_CLKEN_IIC0_POS		      4		//IIC0ʱ���ſ�   
#define SYS_CLKEN_IIC0_MSK		      (0x01 << SYS_CLKEN_IIC0_POS)

#define SYS_CLKEN_IIC1_POS		      5		//IIC1ʱ���ſ�   
#define SYS_CLKEN_IIC1_MSK		      (0x01 << SYS_CLKEN_IIC1_POS)

#define SYS_CLKEN_UART0_POS		      6     //UART0ʱ���ſ�   
#define SYS_CLKEN_UART0_MSK		      (0x01 << SYS_CLKEN_UART0_POS)

#define SYS_CLKEN_UART1_POS		      7     //UART1ʱ���ſ�   
#define SYS_CLKEN_UART1_MSK		      (0x01 << SYS_CLKEN_UART1_POS)

#define SYS_CLKEN_UART2_POS		      8     //UART2ʱ���ſ�   
#define SYS_CLKEN_UART2_MSK		      (0x01 << SYS_CLKEN_UART2_POS)

#define SYS_CLKEN_SPI0_POS		      10    //SPI0ʱ���ſ�   
#define SYS_CLKEN_SPI0_MSK		      (0x01 << SYS_CLKEN_SPI0_POS)

#define SYS_CLKEN_SPI1_POS		      11    //SPI1ʱ���ſ�   
#define SYS_CLKEN_SPI1_MSK		      (0x01 << SYS_CLKEN_SPI1_POS)

#define SYS_CLKEN_TIMBASE0_POS        12    //TIMBASE0ʱ���ſ�   
#define SYS_CLKEN_TIMBASE0_MSK        (0x01 << SYS_CLKEN_TIMBASE0_POS)

#define SYS_CLKEN_TIMBASE1_POS        13    //TIMBASE1ʱ���ſ�   
#define SYS_CLKEN_TIMBASE1_MSK        (0x01 << SYS_CLKEN_TIMBASE1_POS)

#define SYS_CLKEN_TIMBASE2_POS        14    //TIMBASE2ʱ���ſ�   
#define SYS_CLKEN_TIMBASE2_MSK        (0x01 << SYS_CLKEN_TIMBASE2_POS)

#define SYS_CLKEN_TIMPLUS0_POS        15    //TIMPLUS0ʱ���ſ�   
#define SYS_CLKEN_TIMPLUS0_MSK        (0x01 << SYS_CLKEN_TIMPLUS0_POS)

#define SYS_CLKEN_TIMPLUS1_POS        16    //TIMPLUS1ʱ���ſ�   
#define SYS_CLKEN_TIMPLUS1_MSK        (0x01 << SYS_CLKEN_TIMPLUS1_POS)

#define SYS_CLKEN_PWMBASE0_POS		  17	//PWMBASE0ʱ���ſ�   
#define SYS_CLKEN_PWMBASE0_MSK		  (0x01 << SYS_CLKEN_PWMBASE0_POS)

#define SYS_CLKEN_PWMBASE1_POS		  18	//PWMBASE1ʱ���ſ�   
#define SYS_CLKEN_PWMBASE1_MSK		  (0x01 << SYS_CLKEN_PWMBASE1_POS)

#define SYS_CLKEN_PWMPLUS0_POS		  20	//PWMPLUS0ʱ���ſ�   
#define SYS_CLKEN_PWMPLUS0_MSK		  (0x01 << SYS_CLKEN_PWMPLUS0_POS)

#define SYS_CLKEN_PWMPLUS1_POS		  21	//PWMPLUS1ʱ���ſ�   
#define SYS_CLKEN_PWMPLUS1_MSK		  (0x01 << SYS_CLKEN_PWMPLUS1_POS)

#define SYS_CLKEN_RTC_POS		      22    //RTCʱ���ſ�   
#define SYS_CLKEN_RTC_MSK		      (0x01 << SYS_CLKEN_RTC_POS)

#define SYS_CLKEN_IWDT_POS		      23    //IWDTʱ���ſ�   
#define SYS_CLKEN_IWDT_MSK		      (0x01 << SYS_CLKEN_IWDT_POS)

#define SYS_CLKEN_WWDT_POS		      24    //WWDTʱ���ſ�   
#define SYS_CLKEN_WWDT_MSK		      (0x01 << SYS_CLKEN_WWDT_POS)

#define SYS_CLKEN_ADC_POS		      25    //ADCʱ���ſ�   
#define SYS_CLKEN_ADC_MSK		      (0x01 << SYS_CLKEN_ADC_POS)

#define SYS_CLKEN_CRC_POS		      27    //CRCʱ���ſ�   
#define SYS_CLKEN_CRC_MSK		      (0x01 << SYS_CLKEN_CRC_POS)

#define SYS_CLKEN_AES_POS		      28   //AESʱ���ſ�   
#define SYS_CLKEN_AES_MSK		      (0x01 << SYS_CLKEN_AES_POS)

 
#define SYS_RCLF_DELTA_POS            0     //RCLFʵ�ʲ���Ƶ�ʺ�32768֮��Ĳ�ֵ
#define SYS_RCLF_DELTA_MSK            (0x3FF << SYS_RCLF_DELTA_POS)

#define SYS_RCLF_SIG_POS              10     //RCLFʵ�ʲ���Ƶ�ʺ�32768֮��Ĳ�ֵ����λ  1  ��ֵ   0  ��ֵ
#define SYS_RCLF_SIG_MSK              (0x01 << SYS_RCLF_SIG_POS)

#define SYS_RCHF_DELTA_POS            11     //RCHFʵ�ʲ���Ƶ�ʺ�48M֮��Ĳ�ֵ
#define SYS_RCHF_DELTA_MSK            (0xFFFFF << SYS_RCHF_DELTA_POS)

#define SYS_RCHF_SIG_POS              31     //RCHFʵ�ʲ���Ƶ�ʺ�48M֮��Ĳ�ֵ����λ  1  ��ֵ   0  ��ֵ
#define SYS_RCHF_SIG_MSK              (0x01 << SYS_RCHF_SIG_POS)


#define SYS_VREF_DELTA_POS            0     //VREFʵ�ʲ��Ե�ѹֵ������ֵ֮��Ĳ�ֵ
#define SYS_VREF_DELTA_MSK            (0x3F << SYS_VREF_DELTA_POS)

#define SYS_VREF_SIG_POS              6     //VREFʵ�ʲ��Ե�ѹֵ������ֵ֮��Ĳ�ֵ����λ  1  ��ֵ   0  ��ֵ
#define SYS_VREF_SIG_MSK              (0x01 << SYS_VREF_SIG_POS)


#define SYS_CMP_CFG_CMP0_EN_POS       0     //�Ƚ���0ʹ��
#define SYS_CMP_CFG_CMP0_EN_MSK       (0x01 << SYS_CMP_CFG_CMP0_EN_POS)

#define SYS_CMP_CFG_CMP1_EN_POS       1     //�Ƚ���1ʹ��
#define SYS_CMP_CFG_CMP1_EN_MSK       (0x01 << SYS_CMP_CFG_CMP1_EN_POS)

#define SYS_CMP_CFG_CMP2_EN_POS       2     //�Ƚ���2ʹ��
#define SYS_CMP_CFG_CMP2_EN_MSK       (0x01 << SYS_CMP_CFG_CMP2_EN_POS)

#define SYS_CMP_CFG_CMP0_INTEN_POS    8     //�Ƚ���0�ж�ʹ��
#define SYS_CMP_CFG_CMP0_INTEN_MSK    (0x01 << SYS_CMP_CFG_CMP0_INTEN_POS)

#define SYS_CMP_CFG_CMP1_INTEN_POS    9     //�Ƚ���1�ж�ʹ��
#define SYS_CMP_CFG_CMP1_INTEN_MSK    (0x01 << SYS_CMP_CFG_CMP1_INTEN_POS)

#define SYS_CMP_CFG_CMP2_INTEN_POS    10    //�Ƚ���2�ж�ʹ��
#define SYS_CMP_CFG_CMP2_INTEN_MSK    (0x01 << SYS_CMP_CFG_CMP2_INTEN_POS)

#define SYS_CMP_CFG_CMP0_HYS_POS      16    //�Ƚ���0����ѡ��                //00  24mv  01  40mv  10  60mv   11  0mv
#define SYS_CMP_CFG_CMP0_HYS_MSK      (0x03 << SYS_CMP_CFG_CMP0_HYS_POS)
 
#define SYS_CMP_CFG_CMP1_HYS_POS      18    //�Ƚ���1����ѡ��                //00  24mv  01  40mv  10  60mv   11  0mv
#define SYS_CMP_CFG_CMP1_HYS_MSK      (0x03 << SYS_CMP_CFG_CMP1_HYS_POS)

#define SYS_CMP_CFG_CMP2_HYS_POS      20    //�Ƚ���2����ѡ��                //00  24mv  01  40mv  10  60mv   11  0mv
#define SYS_CMP_CFG_CMP2_HYS_MSK      (0x03 << SYS_CMP_CFG_CMP2_HYS_POS)

#define SYS_CMP_CFG_CMP_FILTER_POS    24    //�Ƚ�������˲�ѡ��             //00  ���˲�  01  2��ϵͳʱ�������˲�  10  4��ϵͳʱ�������˲�    11  8��ϵͳʱ�������˲� 
#define SYS_CMP_CFG_CMP_FILTER_MSK    (0x03 << SYS_CMP_CFG_CMP_FILTER_POS)



#define SYS_CMP_ST_CMP0_FLITER_OUT_POS       0     //�Ƚ���0�˲��������    1  P>N  0  P<N
#define SYS_CMP_ST_CMP0_FLITER_OUT_MSK       (0x01 << SYS_CMP_ST_CMP0_FLITER_OUT_POS)

#define SYS_CMP_ST_CMP1_FLITER_OUT_POS       1     //�Ƚ���1�˲��������    1  P>N  0  P<N
#define SYS_CMP_ST_CMP1_FLITER_OUT_MSK       (0x01 << SYS_CMP_ST_CMP1_FLITER_OUT_POS)

#define SYS_CMP_ST_CMP2_FLITER_OUT_POS       2     //�Ƚ���2�˲��������    1  P>N  0  P<N
#define SYS_CMP_ST_CMP2_FLITER_OUT_MSK       (0x01 << SYS_CMP_ST_CMP2_FLITER_OUT_POS)

#define SYS_CMP_ST_CMP0_OUT_POS              8     //�Ƚ���0�˲�ǰ������    1  P>N  0  P<N
#define SYS_CMP_ST_CMP0_OUT_MSK              (0x01 << SYS_CMP_ST_CMP0_OUT_POS)

#define SYS_CMP_ST_CMP1_OUT_POS              9     //�Ƚ���1�˲�ǰ������    1  P>N  0  P<N
#define SYS_CMP_ST_CMP1_OUT_MSK              (0x01 << SYS_CMP_ST_CMP1_OUT_POS)

#define SYS_CMP_ST_CMP2_OUT_POS              10     //�Ƚ���2�˲�ǰ������    1  P>N  0  P<N
#define SYS_CMP_ST_CMP2_OUT_MSK              (0x01 << SYS_CMP_ST_CMP2_OUT_POS)

#define SYS_CMP_ST_CMP0_RISEIF_POS           16     //�Ƚ���0���жϱ�־  1  �Ƚ���0�������0��1�ı仯
#define SYS_CMP_ST_CMP0_RISEIF_MSK           (0x01 << SYS_CMP_ST_CMP0_RISEIF_POS)

#define SYS_CMP_ST_CMP0_FALLIF_POS           17     //�Ƚ���0���жϱ�־  1  �Ƚ���0�������1��0�ı仯
#define SYS_CMP_ST_CMP0_FALLIF_MSK           (0x01 << SYS_CMP_ST_CMP0_FALLIF_POS)

#define SYS_CMP_ST_CMP1_RISEIF_POS           18    //�Ƚ���1���жϱ�־  1  �Ƚ���1�������0��1�ı仯
#define SYS_CMP_ST_CMP1_RISEIF_MSK           (0x01 << SYS_CMP_ST_CMP1_RISEIF_POS)

#define SYS_CMP_ST_CMP1_FALLIF_POS           19    //�Ƚ���1���жϱ�־  1  �Ƚ���1�������1��0�ı仯
#define SYS_CMP_ST_CMP1_FALLIF_MSK           (0x01 << SYS_CMP_ST_CMP1_FALLIF_POS)

#define SYS_CMP_ST_CMP2_RISEIF_POS           20    //�Ƚ���2���жϱ�־  1  �Ƚ���2�������0��1�ı仯
#define SYS_CMP_ST_CMP2_RISEIF_MSK           (0x01 << SYS_CMP_ST_CMP2_RISEIF_POS)

#define SYS_CMP_ST_CMP2_FALLIF_POS           21    //�Ƚ���2���жϱ�־  1  �Ƚ���2�������1��0�ı仯
#define SYS_CMP_ST_CMP2_FALLIF_MSK           (0x01 << SYS_CMP_ST_CMP2_FALLIF_POS)



#define SYS_OPA_CFG_OPA0_EN_POS       0     //����Ŵ���0ʹ��
#define SYS_OPA_CFG_OPA0_EN_MSK       (0x01 << SYS_OPA_CFG_OPA0_EN_POS)

#define SYS_OPA_CFG_OPA1_EN_POS       1     //����Ŵ���1ʹ��
#define SYS_OPA_CFG_OPA1_EN_MSK       (0x01 << SYS_OPA_CFG_OPA1_EN_POS)


#define SYS_PLL_CTRL_PLL_EN_POS       0     //PLLʹ�ܿ���λ
#define SYS_PLL_CTRL_PLL_EN_MSK       (0x01 << SYS_PLL_CTRL_PLL_EN_POS)

#define SYS_PLL_CTRL_PLL_N_POS        1     //PLL FEEDBACKʱ�ӷ�Ƶ
#define SYS_PLL_CTRL_PLL_N_MSK        (0x1F << SYS_PLL_CTRL_PLL_N_POS)

#define SYS_PLL_CTRL_PLL_M_POS        6     //PLL �ο�ʱ�ӷ�Ƶ
#define SYS_PLL_CTRL_PLL_M_MSK        (0x1F << SYS_PLL_CTRL_PLL_M_POS)

#define SYS_PLL_CTRL_PLL_FBH_POS      11     //PLL FEEDBACKʱ�Ӹߵ�ƽ�������
#define SYS_PLL_CTRL_PLL_FBH_MSK      (0x03 << SYS_PLL_CTRL_PLL_FBH_POS)

#define SYS_PLL_CTRL_FILTER_POS       13     //PLL ����ο�ʱ���˲�ѡ��
#define SYS_PLL_CTRL_FILTER_MSK      (0x01 << SYS_PLL_CTRL_FILTER_POS)

#define SYS_PLL_CTRL_PLL_CP_POS       14     //PLL CP����ֵ
#define SYS_PLL_CTRL_PLL_CP_MSK       (0x03 << SYS_PLL_CTRL_PLL_CP_POS)


#define SYS_PLL_ST_LOCK_POS           0
#define SYS_PLL_ST_LOCK_MSK           (0x01 << SYS_PLL_ST_LOCK_POS)



typedef struct {
	__IO uint32_t PORTA_SEL0;               //PORTA����ѡ��
	
	__IO uint32_t PORTA_SEL1;
	
	__IO uint32_t PORTB_SEL0;               //PORTB����ѡ��
	
	__IO uint32_t PORTB_SEL1;
	
	__IO uint32_t PORTC_SEL0;               //PORTC����ѡ��
	
	uint32_t RESERVED1[(0x100 - 0x14)/4];
	
	__IO uint32_t PORTA_INEN;               //PORTA����ʹ��
	
	__IO uint32_t PORTB_INEN;               //PORTB����ʹ��
	
	__IO uint32_t PORTC_INEN;               //PORTC����ʹ��
	
	uint32_t RESERVED2[(0x200 - 0x10C)/4];
	
	__IO uint32_t PORTA_PU_IN;              //PORTA����ʹ��
	
	__IO uint32_t PORTB_PU_IN;              //PORTB����ʹ��
	
	__IO uint32_t PORTC_PU_IN;              //PORTC����ʹ��
	
	uint32_t RESERVED3[(0x300 - 0x20C)/4];
	
    __IO uint32_t PORTA_PD_IN;              //PORTA����ʹ��
  
	__IO uint32_t PORTB_PD_IN;              //PORTB����ʹ��
  
	__IO uint32_t PORTC_PD_IN;              //PORTC����ʹ��
  
    uint32_t RESERVED4[(0x400 - 0x30C)/4];     
			 
	__IO uint32_t PORTA_OD_OUT;             //PORTA��©ʹ��
    
	__IO uint32_t PORTB_OD_OUT;             //PORTB��©ʹ��
	
	__IO uint32_t PORTC_OD_OUT;             //PORTC��©ʹ��
	
    uint32_t RESERVED5[(0x500 - 0x40C)/4]; 
	
	__IO uint32_t PORTA_WAKEUP;            //PORTA����ʹ��
    
	__IO uint32_t PORTB_WAKEUP;            //PORTB����ʹ��
	
	__IO uint32_t PORTC_WAKEUP;            //PORTC����ʹ��
	
    uint32_t RESERVED6[(0x600 - 0x50C)/4]; 
	
	__IO uint32_t PORT_CFG;                //�˿�����
	
	uint32_t RESERVED7[(0x700 - 0x604)/4]; 
	
	__IO uint32_t PORTA_WKSEL;             //PORTA�˿ڻ��ѱ���ѡ��Ĵ���
	
	__IO uint32_t PORTB_WKSEL;             //PORTB�˿ڻ��ѱ���ѡ��Ĵ���
	
	__IO uint32_t PORTC_WKSEL;             //PORTC�˿ڻ��ѱ���ѡ��Ĵ���
} PORT_TypeDef;


#define PORT_CFG_PORTA_DS_POS		    0		//PORTA��������ѡ��  00 5ma  01 10ma  10 15ma  11 20ma 
#define PORT_CFG_PORTA_DS_MSK		    (0x03 << PORT_CFG_PORTA_DS_POS)

#define PORT_CFG_PORTB_DS_POS		    2		//PORTB��������ѡ��  00 5ma  01 10ma  10 15ma  11 20ma  
#define PORT_CFG_PORTB_DS_MSK		    (0x03 << PORT_CFG_PORTB_DS_POS)

#define PORT_CFG_PORTC_DS_POS		    4		//PORTC��������ѡ��  00 5ma  01 10ma  10 15ma  11 20ma  
#define PORT_CFG_PORTC_DS_MSK		    (0x03 << PORT_CFG_PORTC_DS_POS)

#define PORT_CFG_HYS_POS		        10		//������͵ȼ�ѡ��  0  ������ >0.7VDD  <0.3VDD   1 ������  >0.85VDD <0.15VDD 
#define PORT_CFG_HYS_MSK		        (0x01 << PORT_CFG_HYS_POS)


typedef struct {
	__IO uint32_t DATA;                 //���ݼĴ���

	__IO uint32_t DIR;					//0 ����	1 ���

	__IO uint32_t INTLVLTRG;			//Interrupt Level Trigger  1 ��ƽ�����ж�	0 ���ش����ж�

	__IO uint32_t INTBE;			    //Both Edge����INTLVLTRG��Ϊ���ش����ж�ʱ����λ��1��ʾ�����غ��½��ض������жϣ���0ʱ����������INTRISEENѡ��

	__IO uint32_t INTRISEEN;			//Interrupt Rise Edge Enable   1 ������/�ߵ�ƽ�����ж�	0 �½���/�͵�ƽ�����ж�

	__IO uint32_t INTEN;			    //1 �ж�ʹ��	0 �жϽ�ֹ

	__IO uint32_t INTRAWSTAT;			//�жϼ�ⵥԪ�Ƿ��⵽�˴����жϵ����� 1 ��⵽���жϴ�������	0 û�м�⵽�жϴ�������

	__IO uint32_t INTSTAT;				//INTSTAT.PIN0 = INTRAWSTAT.PIN0 & INTEN.PIN0

	__IO uint32_t INTCLR;			    //д1����жϱ�־��ֻ�Ա��ش����ж�����

} GPIO_TypeDef;


typedef struct {
	__IO uint32_t LOAD;					    //IWDT��������ʼֵ
	
	uint32_t RESERVED[1];
	
	__IO uint32_t CTRL;                     //IWDT���ƼĴ���
	
	__IO uint32_t IF;						//[0] �жϱ�־��д1��� 
	
	__IO uint32_t FEED;                     //ι���Ĵ���  д��0x55����ι��
	
} IWDT_TypeDef;

#define IWDT_LOAD_POS         0             //�������Ź���ʼֵ
#define IWDT_LOAD_MSK         (0xFFFFF << IWDT_LOAD_POS)

#define IWDT_CTRL_EN_POS      0             //�������Ź�����ʹ��
#define IWDT_CTRL_EN_MSK      (0x01 << IWDT_CTRL_EN_POS)

#define IWDT_CTRL_INTEN_POS   1             //�������Ź��ж�ʹ��
#define IWDT_CTRL_INTEN_MSK   (0x01 << IWDT_CTRL_INTEN_POS)

#define IWDT_IF_POS           0             //�������Ź��ж�״̬
#define IWDT_IF_MSK           (0x01 << IWDT_IF_POS)

#define IWDT_FEED_POS         0             //�������Ź�ι���Ĵ���   д��0x55��������������
#define IWDT_FEED_MSK         (0xFF << IWDT_FEED_POS)



typedef struct {
	__IO uint32_t LOAD;					    //WWDT��������ʼֵ
	
	__IO uint32_t VALUE;					//WWDT��ǰ����ֵ
	
	__IO uint32_t CTRL;                     //WWDT���ƼĴ���
	
	__IO uint32_t IF;						//[0] �жϱ�־��д0��� 
	
	__IO uint32_t FEED;                     //ι���Ĵ���  д��0x55����ι��
	
} WWDT_TypeDef;

 
#define WWDT_LOAD_INT_POS           0             //���ڿ��Ź��жϱȽ�ֵ    ���¼�������ֵʱ���Բ����ж�   �жϱȽ�ֵһ��Ҫ���ڸ�λ�Ƚ�ֵ
#define WWDT_LOAD_INT_MSK           (0x7F << WWDT_LOAD_INT_POS)

#define WWDT_LOAD_RST_POS           8             //���ڿ��Ź���λ�Ƚ�ֵ    ���¼�������ֵ��1ʱ���Բ����жϣ���������ֵʱ���Բ�����λ  
#define WWDT_LOAD_RST_MSK           (0x3F << WWDT_LOAD_RST_POS)


#define WWDT_VALUE_POS              0             //���ڿ��Ź���ǰ����ֵ
#define WWDT_VALUE_MSK              (0x7F << WWDT_VALUE_POS)


#define WWDT_CTRL_EN_POS            0             //���ڿ��Ź�ʹ��
#define WWDT_CTRL_EN_MSK            (0x01 << WWDT_CTRL_EN_POS)

#define WWDT_CTRL_CLKDIV_POS        1             //���ڿ��Ź�����ʱ��Ԥ��Ƶ   0  1��Ƶ  1  2��Ƶ   2  4��Ƶ   3  8��Ƶ
#define WWDT_CTRL_CLKDIV_MSK        (0x03 << WWDT_CTRL_CLKDIV_POS)

#define WWDT_CTRL_INTEN_POS         3             //���ڿ��Ź��ж�ʹ��
#define WWDT_CTRL_INTEN_MSK         (0x01 << WWDT_CTRL_INTEN_POS)

#define WWDT_CTRL_PRESETINTEN_POS   4             //���ڿ��Ź�Ԥ��λ�ж�ʹ��
#define WWDT_CTRL_PRESETINTEN_MSK   (0x01 << WWDT_CTRL_PRESETINTEN_POS)
 
 
#define WWDT_IF_WININT_POS          0             //�����жϱ�־λ       VALUE==INT_LOAD
#define WWDT_IF_WININT_MSK          (0x01 << WWDT_IF_WININT_POS)

#define WWDT_IF_PRESETINT_POS       1             //Ԥ��λ�жϱ�־λ     VALUE==RST_LOAD + 1
#define WWDT_IF_PRESETINT_MSK       (0x01 << WWDT_IF_PRESETINT_POS)


#define WWDT_FEED_POS               0             //���ڿ��Ź�ι���Ĵ���   д��0x55��������������
#define WWDT_FEED_MSK               (0xFF << WWDT_FEED_POS)


typedef struct {
	__IO uint32_t EN;             //��ʱ��ʹ��
	
	__IO uint32_t DIV;            //��ʱ����Ƶֵ
	
	uint32_t RESERVED1[2];
	
	__IO uint32_t IE;             //�ж�ʹ�ܼĴ���
		
	__IO uint32_t IF;             //״̬�Ĵ���
	
	uint32_t RESERVED2[2];
	
	__IO uint32_t HIGH_PERIOD;    //��16λ�������üĴ���
	
	__IO uint32_t HIGH_CNT;       //��16λ��ǰ����ֵ�Ĵ���

	uint32_t RESERVED3[2];
	
	__IO uint32_t LOW_PERIOD;     //��16λ�������üĴ���
	
	__IO uint32_t LOW_CNT;        //��16λ��ǰ����ֵ�Ĵ���

}TIMBASE_TypeDef;


#define TIMBASE_EN_LOW_POS       0            //������ʱ����16λʹ��
#define TIMBASE_EN_LOW_MSK       (0x01 << TIMBASE_EN_LOW_POS)

#define TIMBASE_EN_HIGH_POS      1            //������ʱ����16λʹ��
#define TIMBASE_EN_HIGH_MSK      (0x01 << TIMBASE_EN_HIGH_POS)


#define TIMBASE_DIV_POS          0            //������ʱ��Ԥ��Ƶϵ��   1--65536
#define TIMBASE_DIV_MSK          (0xFFFF << TIMBASE_DIV_POS)


#define TIMBASE_IE_LOW_POS       0            //������ʱ����16λ�ж�ʹ��
#define TIMBASE_IE_LOW_MSK       (0x01 << TIMBASE_IE_LOW_POS)

#define TIMBASE_IE_HIGH_POS      1            //������ʱ����16λ�ж�ʹ��
#define TIMBASE_IE_HIGH_MSK      (0x01 << TIMBASE_IE_HIGH_POS)


#define TIMBASE_IF_LOW_POS       0            //������ʱ����16λ�ж�״̬
#define TIMBASE_IF_LOW_MSK       (0x01 << TIMBASE_IF_LOW_POS)

#define TIMBASE_IF_HIGH_POS      1            //������ʱ����16λ�ж�״̬
#define TIMBASE_IF_HIGH_MSK      (0x01 << TIMBASE_IF_HIGH_POS)


#define TIMBASE_HIGH_PERIOD_POS    0            //������ʱ����16λ��������ֵ
#define TIMBASE_HIGH_PERIOD_MSK    (0xFFFF << TIMBASE_HIGH_PERIOD_POS)


#define TIMBASE_HIGH_CNT_POS       0            //������ʱ����16λ��ǰ����ֵ
#define TIMBASE_HIGH_CNT_MSK       (0xFFFF << TIMBASE_HIGH_CNT_POS)


#define TIMBASE_LOW_PERIOD_POS     0            //������ʱ����16λ��������ֵ
#define TIMBASE_LOW_PERIOD_MSK     (0xFFFF << TIMBASE_LOW_PERIOD_POS)


#define TIMBASE_LOW_CNT_POS        0            //������ʱ����16λ��ǰ����ֵ
#define TIMBASE_LOW_CNT_MSK        (0xFFFF << TIMBASE_LOW_CNT_POS)


typedef struct {
	__IO uint32_t EN;             //��ʱ��ʹ��
	
	__IO uint32_t DIV;            //��ʱ����Ƶֵ
	
	__IO uint32_t CTR;            //��ʱ�����ƼĴ���
	
	uint32_t RESERVED1[1];
	
	__IO uint32_t IE;             //�ж�ʹ�ܼĴ���
		
	__IO uint32_t IF;             //״̬�Ĵ���
	
	uint32_t RESERVED2[2];
	
	__IO uint32_t HIGH_PERIOD;    //��16λ�������üĴ���
	
	__IO uint32_t HIGH_CNT;       //��16λ��ǰ����ֵ�Ĵ���

	__IO uint32_t HIGH_CVAL;      //��16λ����ֵ�Ĵ���	
	
	uint32_t RESERVED3[1];
	
	__IO uint32_t LOW_PERIOD;     //��16λ�������üĴ���
	
	__IO uint32_t LOW_CNT;        //��16λ��ǰ����ֵ�Ĵ���

	__IO uint32_t LOW_CVAL;       //��16λ����ֵ�Ĵ���	
	
	uint32_t RESERVED4[1];
	
	__IO uint32_t HALL_VAL;       //HALL��ԭʼ�źŵ�ƽ
	
}TIMPLUS_TypeDef;

#define TIMPLUS_EN_LOW_POS            0        //��16λ��ʱ��ʹ�ܼĴ���    
#define TIMPLUS_EN_LOW_MSK            (0x01 << TIMPLUS_EN_LOW_POS)

#define TIMPLUS_EN_HIGH_POS           1        //��16λ��ʱ��ʹ�ܼĴ���    
#define TIMPLUS_EN_HIGH_MSK           (0x01 << TIMPLUS_EN_HIGH_POS)


#define TIMPLUS_DIV_POS               0        //��ʱ����Ƶ�Ĵ���  1--65536
#define TIMPLUS_DIV_MSK               (0xFFFF << TIMPLUS_DIV_POS)  


#define TIMPLUS_CTR_LOW_MODE_POS       0        //��16λ��ʱ��ģʽ�Ĵ���  
#define TIMPLUS_CTR_LOW_MODE_MSK       (0x03 << TIMPLUS_CTR_LOW_MODE_POS)

#define TIMPLUS_CTR_LOW_CLKSEL_POS     2        //��16λ��ʱ������ʱ��Դѡ��
#define TIMPLUS_CTR_LOW_CLKSEL_MSK     (0x03 << TIMPLUS_CTR_LOW_CLKSEL_POS)

#define TIMPLUS_CTR_LOW_EXTSEL_POS     4        //��16λ��ʱ������ģʽ�����벶��ģʽ�����ź�ѡ��
#define TIMPLUS_CTR_LOW_EXTSEL_MSK     (0x01 << TIMPLUS_CTR_LOW_EXTSEL_POS)

#define TIMPLUS_CTR_LOW_EXTLEVEL_POS   5        //��16λ��ʱ������ģʽ�����벶��ģʽ�����ź���Ч����ѡ��
#define TIMPLUS_CTR_LOW_EXTLEVEL_MSK   (0x03 << TIMPLUS_CTR_LOW_EXTV_POS)

#define TIMPLUS_CTR_LOW_OUTEN_POS      7        //��16λ��ʱ�������������
#define TIMPLUS_CTR_LOW_OUTEN_MSK      (0x01 << TIMPLUS_CTR_LOW_OUTEN_POS)

#define TIMPLUS_CTR_LOW_DMAEN_POS      8        //��16λ��ʱ��DMA��ȡ����ֵʹ��
#define TIMPLUS_CTR_LOW_DMAEN_MSK      (0x01 << TIMPLUS_CTR_LOW_DMAEN_POS)

#define TIMPLUS_CTR_HIGH_MODE_POS      16        //��16λ��ʱ��ģʽ�Ĵ���  
#define TIMPLUS_CTR_HIGH_MODE_MSK      (0x03 << TIMPLUS_CTR_HIGH_MODE_POS)

#define TIMPLUS_CTR_HIGH_CLKSEL_POS    18        //��16λ��ʱ������ʱ��Դѡ��
#define TIMPLUS_CTR_HIGH_CLKSEL_MSK    (0x03 << TIMPLUS_CTR_HIGH_CLKSEL_POS)

#define TIMPLUS_CTR_HIGH_EXTSEL_POS    20        //��16λ��ʱ������ģʽ�����벶��ģʽ�����ź�ѡ��
#define TIMPLUS_CTR_HIGH_EXTSEL_MSK    (0x01 << TIMPLUS_CTR_HIGH_EXTSEL_POS)

#define TIMPLUS_CTR_HIGH_EXTLEVEL_POS  21        //��16λ��ʱ������ģʽ�����벶��ģʽ�����ź���Ч����ѡ��
#define TIMPLUS_CTR_HIGH_EXTLEVEL_MSK  (0x03 << TIMPLUS_CTR_HIGH_EXTLEVEL_POS)

#define TIMPLUS_CTR_HIGH_OUTEN_POS     23        //��16λ��ʱ�������������
#define TIMPLUS_CTR_HIGH_OUTEN_MSK     (0x01 << TIMPLUS_CTR_HIGH_OUTEN_POS)

#define TIMPLUS_CTR_HIGH_DMAEN_POS     24        //��16λ��ʱ��DMA��ȡ����ֵʹ��
#define TIMPLUS_CTR_HIGH_DMAEN_MSK     (0x01 << TIMPLUS_CTR_HIGH_DMAEN_POS)


#define TIMPLUS_IE_LOW_OVF_POS         0        //��16λ��ʱ������ж�ʹ��
#define TIMPLUS_IE_LOW_OVF_MSK         (0x01 << TIMPLUS_IE_LOW_OVF_POS)

#define TIMPLUS_IE_LOW_RISE_POS        1        //��16λ��ʱ�����������������ж�ʹ��
#define TIMPLUS_IE_LOW_RISE_MSK        (0x01 << TIMPLUS_IE_LOW_RISE_POS)

#define TIMPLUS_IE_LOW_FALL_POS        2        //��16λ��ʱ�����������½����ж�ʹ��
#define TIMPLUS_IE_LOW_FALL_MSK        (0x01 << TIMPLUS_IE_LOW_FALL_POS)

#define TIMPLUS_IE_HIGH_OVF_POS        8        //��16λ��ʱ������ж�ʹ��
#define TIMPLUS_IE_HIGH_OVF_MSK        (0x01 << TIMPLUS_IE_HIGH_OVF_POS)

#define TIMPLUS_IE_HIGH_RISE_POS       9        //��16λ��ʱ�����������������ж�ʹ��
#define TIMPLUS_IE_HIGH_RISE_MSK       (0x01 << TIMPLUS_IE_HIGH_RISE_POS)

#define TIMPLUS_IE_HIGH_FALL_POS       10       //��16λ��ʱ�����������½����ж�ʹ��
#define TIMPLUS_IE_HIGH_FALL_MSK       (0x01 << TIMPLUS_IE_HIGH_FALL_POS)

#define TIMPLUS_IE_HALL0_RISE_POS      16       //HALL0�������ж�ʹ��
#define TIMPLUS_IE_HALL0_RISE_MSK      (0x01 << TIMPLUS_IE_HALL0_RISE_POS)

#define TIMPLUS_IE_HALL0_FALL_POS      17       //HALL0�½����ж�ʹ��
#define TIMPLUS_IE_HALL0_FALL_MSK      (0x01 << TIMPLUS_IE_HALL0_FALL_POS)

#define TIMPLUS_IE_HALL1_RISE_POS      18       //HALL1�������ж�ʹ��
#define TIMPLUS_IE_HALL1_RISE_MSK      (0x01 << TIMPLUS_IE_HALL1_RISE_POS)

#define TIMPLUS_IE_HALL1_FALL_POS      19       //HALL1�½����ж�ʹ��
#define TIMPLUS_IE_HALL1_FALL_MSK      (0x01 << TIMPLUS_IE_HALL1_FALL_POS)

#define TIMPLUS_IE_HALL2_RISE_POS      20       //HALL2�������ж�ʹ��
#define TIMPLUS_IE_HALL2_RISE_MSK      (0x01 << TIMPLUS_IE_HALL2_RISE_POS)

#define TIMPLUS_IE_HALL2_FALL_POS      21       //HALL2�½����ж�ʹ��
#define TIMPLUS_IE_HALL2_FALL_MSK      (0x01 << TIMPLUS_IE_HALL2_FALL_POS)


#define TIMPLUS_IF_LOW_OVF_POS         0        //��16λ��ʱ������ж�״̬
#define TIMPLUS_IF_LOW_OVF_MSK         (0x01 << TIMPLUS_IF_LOW_OVF_POS)

#define TIMPLUS_IF_LOW_RISE_POS        1        //��16λ��ʱ�����������������ж�״̬
#define TIMPLUS_IF_LOW_RISE_MSK        (0x01 << TIMPLUS_IF_LOW_RISE_POS)

#define TIMPLUS_IF_LOW_FALL_POS        2        //��16λ��ʱ�����������½����ж�״̬
#define TIMPLUS_IF_LOW_FALL_MSK        (0x01 << TIMPLUS_IF_LOW_FALL_POS)

#define TIMPLUS_IF_HIGH_OVF_POS        8        //��16λ��ʱ������ж�״̬
#define TIMPLUS_IF_HIGH_OVF_MSK        (0x01 << TIMPLUS_IF_HIGH_OVF_POS)

#define TIMPLUS_IF_HIGH_RISE_POS       9        //��16λ��ʱ�����������������ж�״̬
#define TIMPLUS_IF_HIGH_RISE_MSK       (0x01 << TIMPLUS_IF_HIGH_RISE_POS)

#define TIMPLUS_IF_HIGH_FALL_POS       10       //��16λ��ʱ�����������½����ж�״̬
#define TIMPLUS_IF_HIGH_FALL_MSK       (0x01 << TIMPLUS_IF_HIGH_FALL_POS)

#define TIMPLUS_IF_HALL0_RISE_POS      16       //HALL0�������ж�״̬
#define TIMPLUS_IF_HALL0_RISE_MSK      (0x01 << TIMPLUS_IF_HALL0_RISE_POS)

#define TIMPLUS_IF_HALL0_FALL_POS      17       //HALL0�½����ж�״̬
#define TIMPLUS_IF_HALL0_FALL_MSK      (0x01 << TIMPLUS_IF_HALL0_FALL_POS)

#define TIMPLUS_IF_HALL1_RISE_POS      18       //HALL1�������ж�״̬
#define TIMPLUS_IF_HALL1_RISE_MSK      (0x01 << TIMPLUS_IF_HALL1_RISE_POS)

#define TIMPLUS_IF_HALL1_FALL_POS      19       //HALL1�½����ж�״̬
#define TIMPLUS_IF_HALL1_FALL_MSK      (0x01 << TIMPLUS_IF_HALL1_FALL_POS)

#define TIMPLUS_IF_HALL2_RISE_POS      20       //HALL2�������ж�״̬
#define TIMPLUS_IF_HALL2_RISE_MSK      (0x01 << TIMPLUS_IF_HALL2_RISE_POS)

#define TIMPLUS_IF_HALL2_FALL_POS      21       //HALL2�½����ж�״̬
#define TIMPLUS_IF_HALL2_FALL_MSK      (0x01 << TIMPLUS_IF_HALL2_FALL_POS)


#define TIMPLUS_HALL_VAL_HALL0_POS    0        //HALL0��ԭʼ�źŵ�ƽ
#define TIMPLUS_HALL_VAL_HALL0_MSK    (0x01 << TIMPLUS_HALL_VAL_HALL0_POS)

#define TIMPLUS_HALL_VAL_HALL1_POS    1        //HALL1��ԭʼ�źŵ�ƽ
#define TIMPLUS_HALL_VAL_HALL1_MSK    (0x01 << TIMPLUS_HALL_VAL_HALL1_POS)

#define TIMPLUS_HALL_VAL_HALL2_POS    2        //HALL2��ԭʼ�źŵ�ƽ
#define TIMPLUS_HALL_VAL_HALL2_MSK    (0x01 << TIMPLUS_HALL_VAL_HALL2_POS)



typedef struct {
	
	__IO uint32_t EN;                     //PWMBASEʹ�ܼĴ���
											
	__IO uint32_t DIV;                    //PWMBASE��Ƶ�Ĵ���
	
	__IO uint32_t OUTCTR;                 //PWMBASE������ƼĴ���
	
	__IO uint32_t PERIOD;                 //PWMBASE�������üĴ���
	
	__IO uint32_t IE;                     //PWMBASE�ж�ʹ�ܼĴ���
	
	__IO uint32_t IF;                     //PWMBASE�ж�״̬�Ĵ���
	
	__IO uint32_t CNT;                    //PWMBASE��ǰ����ֵ�Ĵ���  
	
	uint32_t RESERVED1[1];
	
	__IO uint32_t CH0_COMP;               //PWMBASEͨ��0�ıȽϵ����üĴ���
	
	uint32_t RESERVED2[3];
	
	__IO uint32_t CH1_COMP;               //PWMBASEͨ��1�ıȽϵ����üĴ���
	
	uint32_t RESERVED3[3];
	
	__IO uint32_t CH2_COMP;               //PWMBASEͨ��2�ıȽϵ����üĴ���
	
	
} PWMBASE_TypeDef;


#define PWMBASE_EN_POS                0      //PWMBASE������ʹ��
#define PWMBASE_EN_MSK                (0x01 << PWMBASE_EN_POS)

#define PWMBASE_DIV_POS               0      //PWMBASE����ʱ�ӷ�Ƶϵ��    1--65536
#define PWMBASE_DIV_MSK               (0xFFFF << PWMBASE_DIV_POS)

#define PWMBASE_OUTCTR_CH0_INV_POS    0      //PWMBASEͨ��0������Է�ת
#define PWMBASE_OUTCTR_CH0_INV_MSK    (0x01 << PWMBASE_OUTCTR_CH0_INV_POS)

#define PWMBASE_OUTCTR_CH1_INV_POS    1      //PWMBASEͨ��1������Է�ת
#define PWMBASE_OUTCTR_CH1_INV_MSK    (0x01 << PWMBASE_OUTCTR_CH1_INV_POS)

#define PWMBASE_OUTCTR_CH2_INV_POS    2      //PWMBASEͨ��2������Է�ת
#define PWMBASE_OUTCTR_CH2_INV_MSK    (0x01 << PWMBASE_OUTCTR_CH2_INV_POS)

#define PWMBASE_OUTCTR_CH0_EN_POS     4      //PWMBASEͨ��0���ʹ��
#define PWMBASE_OUTCTR_CH0_EN_MSK     (0x01 << PWMBASE_OUTCTR_CH0_EN_POS)

#define PWMBASE_OUTCTR_CH1_EN_POS     5      //PWMBASEͨ��1���ʹ��
#define PWMBASE_OUTCTR_CH1_EN_MSK     (0x01 << PWMBASE_OUTCTR_CH1_EN_POS)

#define PWMBASE_OUTCTR_CH2_EN_POS     6      //PWMBASEͨ��2���ʹ��
#define PWMBASE_OUTCTR_CH2_EN_MSK     (0x01 << PWMBASE_OUTCTR_CH2_EN_POS)

#define PWMBASE_IE_CH0_COMP_POS       0      //PWMBASEͨ��0����Ƚϵ��ж�ʹ��
#define PWMBASE_IE_CH0_COMP_MSK       (0x01 << PWMBASE_IE_CH0_COMP_POS)

#define PWMBASE_IE_CH1_COMP_POS       1      //PWMBASEͨ��1����Ƚϵ��ж�ʹ��
#define PWMBASE_IE_CH1_COMP_MSK       (0x01 << PWMBASE_IE_CH1_COMP_POS)

#define PWMBASE_IE_CH2_COMP_POS       2      //PWMBASEͨ��2����Ƚϵ��ж�ʹ��
#define PWMBASE_IE_CH2_COMP_MSK       (0x01 << PWMBASE_IE_CH2_COMP_POS)

#define PWMBASE_IE_OVF_POS            3      //PWMBASE��������ж�ʹ��
#define PWMBASE_IE_OVF_MSK            (0x01 << PWMBASE_IE_OVF_POS)

#define PWMBASE_IF_CH0_COMP_POS       0      //PWMBASEͨ��0����Ƚϵ��ж�״̬
#define PWMBASE_IF_CH0_COMP_MSK       (0x01 << PWMBASE_IF_CH0_COMP_POS)

#define PWMBASE_IF_CH1_COMP_POS       1      //PWMBASEͨ��1����Ƚϵ��ж�״̬
#define PWMBASE_IF_CH1_COMP_MSK       (0x01 << PWMBASE_IF_CH1_COMP_POS)

#define PWMBASE_IF_CH2_COMP_POS       2      //PWMBASEͨ��2����Ƚϵ��ж�״̬
#define PWMBASE_IF_CH2_COMP_MSK       (0x01 << PWMBASE_IF_CH2_COMP_POS)

#define PWMBASE_IF_OVF_POS            3      //PWMBASE��������ж�״̬
#define PWMBASE_IF_OVF_MSK            (0x01 << PWMBASE_IF_OVF_POS)


typedef struct {
	
	__IO uint32_t CTR;                    //PWMPLUS���üĴ���
											
	__IO uint32_t OUTCTR;                 //PWMPLUS������ƼĴ���
	
	__IO uint32_t CLK;                    //PWMPLUSʱ��Դѡ�񼰷�Ƶ�Ĵ���
	
	__IO uint32_t BRK_CTR;                //PWMPLUS_BRAKE���üĴ���
	
	__IO uint32_t MSK_LEVEL;              //PWMPLUSǿ�������ƽѡ��Ĵ���
	
	uint32_t RESERVED1[2];
	
	__IO uint32_t PERIOD;                 //PWMPLUS�������üĴ���
	
	__IO uint32_t CH0_COMP;               //PWMPLUSͨ��0�ıȽϵ����üĴ���
	
	__IO uint32_t CH1_COMP;               //PWMPLUSͨ��1�ıȽϵ����üĴ���
	
	__IO uint32_t CH2_COMP;               //PWMPLUSͨ��2�ıȽϵ����üĴ���
	
	uint32_t RESERVED2[1];
	
	__IO uint32_t CH0_DEADZONE;           //PWMPLUSͨ��0�����������üĴ���
	
	__IO uint32_t CH1_DEADZONE;           //PWMPLUSͨ��1�����������üĴ���
	
	__IO uint32_t CH2_DEADZONE;           //PWMPLUSͨ��2�����������üĴ���
	
	uint32_t RESERVED3[1];
	
	__IO uint32_t TRIG_COMP;              //PWMPLUS�ڲ������Ƚϵ�Ĵ���
	
	__IO uint32_t TRIG_SEL;               //PWMPLUS�ڲ��������üĴ���
	
	uint32_t RESERVED4[6];
	
	__IO uint32_t IE;                     //PWMPLUS�ж�ʹ�ܼĴ���
	
	__IO uint32_t IF;                     //PWMPLUS�ж�״̬�Ĵ���
	
	uint32_t RESERVED5[7];

	__IO uint32_t SWLOAD;                 //PWMPLUS  SWLOAD���ƼĴ���
	
	__IO uint32_t MSK_EN;                 //PWMPLUS����ʹ�ܿ��ƼĴ���
	
	uint32_t RESERVED6[21];
	
	__IO uint32_t CNT_STATE;              //PWMPLUS��ǰ����ֵ��״̬�Ĵ���  
	
	__IO uint32_t BRK_STATE;              //PWMPLUSɲ��״̬�Ĵ���  
	
}PWMPLUS_TypeDef;


#define PWMPLUS_CTR_EN_POS             0   //PWMPLUSʹ��
#define PWMPLUS_CTR_EN_MSK             (0x01 << PWMPLUS_CTR_EN_POS)

#define PWMPLUS_CTR_DIR_POS            1   //PWMPLUS������������������   0  ���ϼ���   1  ���¼���
#define PWMPLUS_CTR_DIR_MSK            (0x01 << PWMPLUS_CTR_DIR_POS)

#define PWMPLUS_CTR_OPM_POS            2   //PWMPLUS���μ���ģʽ         0  ���μ���   1  �ظ�����
#define PWMPLUS_CTR_OPM_MSK            (0x01 << PWMPLUS_CTR_OPM_POS)

#define PWMPLUS_CTR_MODE_POS           3   //PWMPLUS���ģʽ             0  ���ض���   1  ���Ķ���
#define PWMPLUS_CTR_MODE_MSK           (0x01 << PWMPLUS_CTR_MODE_POS)

#define PWMPLUS_CTR_RELOAD_POS         8   //PWMPLUS�Զ�װ�ؼĴ���
#define PWMPLUS_CTR_RELOAD_MSK         (0xFF << PWMPLUS_CTR_RELOAD_POS)


#define PWMPLUS_OUTCTR_CH0_IDLE_POS    0   //PWMPLUSԭʼͨ��0����ʱ�����ƽ
#define PWMPLUS_OUTCTR_CH0_IDLE_MSK    (0x01 << PWMPLUS_OUTCTR_CH0_IDLE_POS)

#define PWMPLUS_OUTCTR_CH0N_IDLE_POS   1   //PWMPLUSԭʼͨ��0N����ʱ�����ƽ
#define PWMPLUS_OUTCTR_CH0N_IDLE_MSK   (0x01 << PWMPLUS_OUTCTR_CH0N_IDLE_POS)

#define PWMPLUS_OUTCTR_CH1_IDLE_POS    2   //PWMPLUSԭʼͨ��1����ʱ�����ƽ
#define PWMPLUS_OUTCTR_CH1_IDLE_MSK    (0x01 << PWMPLUS_OUTCTR_CH1_IDLE_POS)

#define PWMPLUS_OUTCTR_CH1N_IDLE_POS   3   //PWMPLUSԭʼͨ��1N����ʱ�����ƽ
#define PWMPLUS_OUTCTR_CH1N_IDLE_MSK   (0x01 << PWMPLUS_OUTCTR_CH1N_IDLE_POS)

#define PWMPLUS_OUTCTR_CH2_IDLE_POS    4   //PWMPLUSԭʼͨ��2����ʱ�����ƽ
#define PWMPLUS_OUTCTR_CH2_IDLE_MSK    (0x01 << PWMPLUS_OUTCTR_CH2_IDLE_POS)

#define PWMPLUS_OUTCTR_CH2N_IDLE_POS   5   //PWMPLUSԭʼͨ��2N����ʱ�����ƽ
#define PWMPLUS_OUTCTR_CH2N_IDLE_MSK   (0x01 << PWMPLUS_OUTCTR_CH2N_IDLE_POS)

#define PWMPLUS_OUTCTR_CH0_START_POS   8   //PWMPLUSԭʼͨ��0��ʼ����ʱ�����ƽ
#define PWMPLUS_OUTCTR_CH0_START_MSK   (0x01 << PWMPLUS_OUTCTR_CH0_START_POS)

#define PWMPLUS_OUTCTR_CH1_START_POS   9   //PWMPLUSԭʼͨ��1��ʼ����ʱ�����ƽ
#define PWMPLUS_OUTCTR_CH1_START_MSK   (0x01 << PWMPLUS_OUTCTR_CH1_START_POS)

#define PWMPLUS_OUTCTR_CH2_START_POS   10   //PWMPLUSԭʼͨ��2��ʼ����ʱ�����ƽ
#define PWMPLUS_OUTCTR_CH2_START_MSK   (0x01 << PWMPLUS_OUTCTR_CH2_START_POS)

#define PWMPLUS_OUTCTR_CH0_INV_POS     16   //PWMPLUSԭʼͨ��0�����ƽ��ת
#define PWMPLUS_OUTCTR_CH0_INV_MSK     (0x01 << PWMPLUS_OUTCTR_CH0_INV_POS)

#define PWMPLUS_OUTCTR_CH0N_INV_POS    17   //PWMPLUSԭʼͨ��0N�����ƽ��ת
#define PWMPLUS_OUTCTR_CH0N_INV_MSK    (0x01 << PWMPLUS_OUTCTR_CH0N_INV_POS)

#define PWMPLUS_OUTCTR_CH1_INV_POS     18   //PWMPLUSԭʼͨ��1�����ƽ��ת
#define PWMPLUS_OUTCTR_CH1_INV_MSK     (0x01 << PWMPLUS_OUTCTR_CH1_INV_POS)

#define PWMPLUS_OUTCTR_CH1N_INV_POS    19   //PWMPLUSԭʼͨ��1N�����ƽ��ת
#define PWMPLUS_OUTCTR_CH1N_INV_MSK    (0x01 << PWMPLUS_OUTCTR_CH1N_INV_POS)

#define PWMPLUS_OUTCTR_CH2_INV_POS     20   //PWMPLUSԭʼͨ��2�����ƽ��ת
#define PWMPLUS_OUTCTR_CH2_INV_MSK     (0x01 << PWMPLUS_OUTCTR_CH2_INV_POS)

#define PWMPLUS_OUTCTR_CH2N_INV_POS    21   //PWMPLUSԭʼͨ��2N�����ƽ��ת
#define PWMPLUS_OUTCTR_CH2N_INV_MSK    (0x01 << PWMPLUS_OUTCTR_CH2N_INV_POS)

#define PWMPLUS_OUTCTR_CH0_OUTEN_POS   24   //PWMPLUSԭʼͨ��0���ʹ��
#define PWMPLUS_OUTCTR_CH0_OUTEN_MSK   (0x01 << PWMPLUS_OUTCTR_CH0_OUTEN_POS)

#define PWMPLUS_OUTCTR_CH0N_OUTEN_POS  25   //PWMPLUSԭʼͨ��0N���ʹ��
#define PWMPLUS_OUTCTR_CH0N_OUTEN_MSK  (0x01 << PWMPLUS_OUTCTR_CH0N_OUTEN_POS)

#define PWMPLUS_OUTCTR_CH1_OUTEN_POS   26   //PWMPLUSԭʼͨ��1���ʹ��
#define PWMPLUS_OUTCTR_CH1_OUTEN_MSK   (0x01 << PWMPLUS_OUTCTR_CH1_OUTEN_POS)

#define PWMPLUS_OUTCTR_CH1N_OUTEN_POS  27   //PWMPLUSԭʼͨ��1N���ʹ��
#define PWMPLUS_OUTCTR_CH1N_OUTEN_MSK  (0x01 << PWMPLUS_OUTCTR_CH1N_OUTEN_POS)

#define PWMPLUS_OUTCTR_CH2_OUTEN_POS   28   //PWMPLUSԭʼͨ��2���ʹ��
#define PWMPLUS_OUTCTR_CH2_OUTEN_MSK   (0x01 << PWMPLUS_OUTCTR_CH2_OUTEN_POS)

#define PWMPLUS_OUTCTR_CH2N_OUTEN_POS  29   //PWMPLUSԭʼͨ��2N���ʹ��
#define PWMPLUS_OUTCTR_CH2N_OUTEN_MSK  (0x01 << PWMPLUS_OUTCTR_CH2N_OUTEN_POS)


#define PWMPLUS_CLK_SRC_POS            0    //����ʱ��ѡ��   000 �ڲ�Ԥ��Ƶʱ����Ϊ����ʱ��    011  ѡ���16λ��ʱ����Ϊ����ʱ��   100  ѡ���16λ��ʱ����Ϊ����ʱ��
#define PWMPLUS_CLK_SRC_MSK            (0x07 << PWMPLUS_CLK_SRC_POS)

#define PWMPLUS_CLK_PREDIV_POS         16   //PWMPLUS����ʱ��ѡ��               1--65536
#define PWMPLUS_CLK_PREDIV_MSK         (0xFFFF << PWMPLUS_CLK_PREDIV_POS)


#define PWMPLUS_BRK_CTR_CH0EN_POS      0    //PWMPLUSͨ��0��0Nɲ������ʹ��
#define PWMPLUS_BRK_CTR_CH0EN_MSK      (0x07 << PWMPLUS_BRK_CTR_CH0EN_POS)

#define PWMPLUS_BRK_CTR_CH1EN_POS      3    //PWMPLUSͨ��1��1Nɲ������ʹ��
#define PWMPLUS_BRK_CTR_CH1EN_MSK      (0x07 << PWMPLUS_BRK_CTR_CH1EN_POS)

#define PWMPLUS_BRK_CTR_CH2EN_POS      6    //PWMPLUSͨ��2��2Nɲ������ʹ��
#define PWMPLUS_BRK_CTR_CH2EN_MSK      (0x07 << PWMPLUS_BRK_CTR_CH2EN_POS)

#define PWMPLUS_BRK_CTR_INLEV_POS      12    //PWMPLUSɲ��������Ч��ƽѡ��
#define PWMPLUS_BRK_CTR_INLEV_MSK      (0x07 << PWMPLUS_BRK_CTR_INLEV_POS)

#define PWMPLUS_BRK_CTR_CH0_POL_POS    16    //PWMPLUSɲ��ʱͨ��0�����ƽѡ��
#define PWMPLUS_BRK_CTR_CH0_POL_MSK    (0x01 << PWMPLUS_BRK_CTR_CH0_POL_POS)

#define PWMPLUS_BRK_CTR_CH0N_POL_POS   17    //PWMPLUSɲ��ʱͨ��0N�����ƽѡ��
#define PWMPLUS_BRK_CTR_CH0N_POL_MSK   (0x01 << PWMPLUS_BRK_CTR_CH0N_POL_POS)

#define PWMPLUS_BRK_CTR_CH1_POL_POS    18    //PWMPLUSɲ��ʱͨ��1�����ƽѡ��
#define PWMPLUS_BRK_CTR_CH1_POL_MSK    (0x01 << PWMPLUS_BRK_CTR_CH1_POL_POS)

#define PWMPLUS_BRK_CTR_CH1N_POL_POS   19    //PWMPLUSɲ��ʱͨ��1N�����ƽѡ��
#define PWMPLUS_BRK_CTR_CH1N_POL_MSK   (0x01 << PWMPLUS_BRK_CTR_CH1N_POL_POS)

#define PWMPLUS_BRK_CTR_CH2_POL_POS    20    //PWMPLUSɲ��ʱͨ��2�����ƽѡ��
#define PWMPLUS_BRK_CTR_CH2_POL_MSK    (0x01 << PWMPLUS_BRK_CTR_CH2_POL_POS)

#define PWMPLUS_BRK_CTR_CH2N_POL_POS   21    //PWMPLUSɲ��ʱͨ��2N�����ƽѡ��
#define PWMPLUS_BRK_CTR_CH2N_POL_MSK   (0x01 << PWMPLUS_BRK_CTR_CH2N_POL_POS)

#define PWMPLUS_BRK_CTR_FILTER_POS     24    //PWMPLUS�����˲�
#define PWMPLUS_BRK_CTR_FILTER_MSK     (0x03 << PWMPLUS_BRK_CTR_FILTER_POS)


#define PWMPLUS_MSK_LEVEL_CH0_POS      0    //PWMPLUSͨ��0���ε�ƽѡ��
#define PWMPLUS_MSK_LEVEL_CH0_MSK      (0x01 << PWMPLUS_MSK_LEVEL_CH0_POS)

#define PWMPLUS_MSK_LEVEL_CH0N_POS     1    //PWMPLUSͨ��0N���ε�ƽѡ��
#define PWMPLUS_MSK_LEVEL_CH0N_MSK     (0x01 << PWMPLUS_MSK_LEVEL_CH0N_POS)

#define PWMPLUS_MSK_LEVEL_CH1_POS      2    //PWMPLUSͨ��1���ε�ƽѡ��
#define PWMPLUS_MSK_LEVEL_CH1_MSK      (0x01 << PWMPLUS_MSK_LEVEL_CH1_POS)

#define PWMPLUS_MSK_LEVEL_CH1N_POS     3    //PWMPLUSͨ��1N���ε�ƽѡ��
#define PWMPLUS_MSK_LEVEL_CH1N_MSK     (0x01 << PWMPLUS_MSK_LEVEL_CH1N_POS)

#define PWMPLUS_MSK_LEVEL_CH2_POS      4    //PWMPLUSͨ��2���ε�ƽѡ��
#define PWMPLUS_MSK_LEVEL_CH2_MSK      (0x01 << PWMPLUS_MSK_LEVEL_CH2_POS)

#define PWMPLUS_MSK_LEVEL_CH2N_POS     5    //PWMPLUSͨ��2N���ε�ƽѡ��
#define PWMPLUS_MSK_LEVEL_CH2N_MSK     (0x01 << PWMPLUS_MSK_LEVEL_CH2N_POS)


#define PWMPLUS_TRIG_CTR_SEL0_POS      0    //PWMPLUS����Ĵ����ź�0����ѡ��
#define PWMPLUS_TRIG_CTR_SEL0_MSK      (0x0F << PWMPLUS_TRIG_CTR_SEL0_POS)

#define PWMPLUS_TRIG_CTR_SEL1_POS      4    //PWMPLUS����Ĵ����ź�1����ѡ��
#define PWMPLUS_TRIG_CTR_SEL1_MSK      (0x0F << PWMPLUS_TRIG_CTR_SEL1_POS)

#define PWMPLUS_TRIG_CTR_SEL2_POS      8    //PWMPLUS����Ĵ����ź�2����ѡ��
#define PWMPLUS_TRIG_CTR_SEL2_MSK      (0x0F << PWMPLUS_TRIG_CTR_SEL2_POS)

#define PWMPLUS_TRIG_CTR_SEL3_POS      12   //PWMPLUS����Ĵ����ź�3����ѡ��
#define PWMPLUS_TRIG_CTR_SEL3_MSK      (0x0F << PWMPLUS_TRIG_CTR_SEL3_POS)


#define PWMPLUS_IE_CH0_UP_COMP_POS      0    //PWMPLUSͨ��0���ϼ�������Ƚϵ��ж�ʹ��
#define PWMPLUS_IE_CH0_UP_COMP_MSK      (0x01 << PWMPLUS_IE_CH0_UP_COMP_POS)

#define PWMPLUS_IE_CH1_UP_COMP_POS      1    //PWMPLUSͨ��1���ϼ�������Ƚϵ��ж�ʹ��
#define PWMPLUS_IE_CH1_UP_COMP_MSK      (0x01 << PWMPLUS_IE_CH1_UP_COMP_POS)

#define PWMPLUS_IE_CH2_UP_COMP_POS      2    //PWMPLUSͨ��2���ϼ�������Ƚϵ��ж�ʹ��
#define PWMPLUS_IE_CH2_UP_COMP_MSK      (0x01 << PWMPLUS_IE_CH2_UP_COMP_POS)

#define PWMPLUS_IE_UP_OVF_POS           3    //PWMPLUS���ϼ�����������ж�ʹ��
#define PWMPLUS_IE_UP_OVF_MSK           (0x01 << PWMPLUS_IE_UP_OVF_POS)

#define PWMPLUS_IE_UP_TRIG_POS          4    //PWMPLUS���ϼ������ﴥ�����ж�ʹ��
#define PWMPLUS_IE_UP_TRIG_MSK          (0x01 << PWMPLUS_IE_UP_TRIG_POS)

#define PWMPLUS_IE_CH0_DOWN_COMP_POS    8    //PWMPLUSͨ��0���¼�������Ƚϵ��ж�ʹ��
#define PWMPLUS_IE_CH0_DOWN_COMP_MSK    (0x01 << PWMPLUS_IE_CH0_DOWN_COMP_POS)

#define PWMPLUS_IE_CH1_DOWN_COMP_POS    9    //PWMPLUSͨ��1���¼�������Ƚϵ��ж�ʹ��
#define PWMPLUS_IE_CH1_DOWN_COMP_MSK    (0x01 << PWMPLUS_IE_CH1_DOWN_COMP_POS)

#define PWMPLUS_IE_CH2_DOWN_COMP_POS    10   //PWMPLUSͨ��2���¼�������Ƚϵ��ж�ʹ��
#define PWMPLUS_IE_CH2_DOWN_COMP_MSK    (0x01 << PWMPLUS_IE_CH2_DOWN_COMP_POS)

#define PWMPLUS_IE_DOWN_OVF_POS        11   //PWMPLUS���¼�����������ж�ʹ��
#define PWMPLUS_IE_DOWN_OVF_MSK        (0x01 << PWMPLUS_IE_DOWN_OVF_POS)

#define PWMPLUS_IE_DOWN_TRIG_POS       12   //PWMPLUS���¼������ﴥ�����ж�ʹ��
#define PWMPLUS_IE_DOWN_TRIG_MSK       (0x01 << PWMPLUS_IE_DOWN_TRIG_POS)

#define PWMPLUS_IE_BRK0_POS            16   //PWMPLUSɲ��0�ж�ʹ��
#define PWMPLUS_IE_BRK0_MSK            (0x01 << PWMPLUS_IE_BRK0_POS)

#define PWMPLUS_IE_BRK1_POS            17   //PWMPLUSɲ��1�ж�ʹ��
#define PWMPLUS_IE_BRK1_MSK            (0x01 << PWMPLUS_IE_BRK1_POS)

#define PWMPLUS_IE_BRK2_POS            18   //PWMPLUSɲ��2�ж�ʹ��
#define PWMPLUS_IE_BRK2_MSK            (0x01 << PWMPLUS_IE_BRK2_POS)

#define PWMPLUS_IE_RELOAD_POS          19   //PWMPLUS�Զ�װ���ж�ʹ��
#define PWMPLUS_IE_RELOAD_MSK          (0x01 << PWMPLUS_IE_RELOAD_POS)


#define PWMPLUS_IF_CH0_UP_COMP_POS      0    //PWMPLUSͨ��0���ϼ�������Ƚϵ��ж�״̬
#define PWMPLUS_IF_CH0_UP_COMP_MSK      (0x01 << PWMPLUS_IF_CH0_UP_COMP_POS)

#define PWMPLUS_IF_CH1_UP_COMP_POS      1    //PWMPLUSͨ��1���ϼ�������Ƚϵ��ж�״̬
#define PWMPLUS_IF_CH1_UP_COMP_MSK      (0x01 << PWMPLUS_IF_CH1_UP_COMP_POS)

#define PWMPLUS_IF_CH2_UP_COMP_POS      2    //PWMPLUSͨ��2���ϼ�������Ƚϵ��ж�״̬
#define PWMPLUS_IF_CH2_UP_COMP_MSK      (0x01 << PWMPLUS_IF_CH2_UP_COMP_POS)

#define PWMPLUS_IF_UP_OVF_POS           3    //PWMPLUS���ϼ�����������ж�״̬
#define PWMPLUS_IF_UP_OVF_MSK           (0x01 << PWMPLUS_IF_UP_OVF_POS)

#define PWMPLUS_IF_UP_TRIG_POS          4    //PWMPLUS���ϼ������ﴥ�����ж�״̬
#define PWMPLUS_IF_UP_TRIG_MSK          (0x01 << PWMPLUS_IF_UP_TRIG_POS)

#define PWMPLUS_IF_CH0_DOWN_COMP_POS    8    //PWMPLUSͨ��0���¼�������Ƚϵ��ж�״̬
#define PWMPLUS_IF_CH0_DOWN_COMP_MSK    (0x01 << PWMPLUS_IF_CH0_DOWN_COMP_POS)

#define PWMPLUS_IF_CH1_DOWN_COMP_POS    9    //PWMPLUSͨ��1���¼�������Ƚϵ��ж�״̬
#define PWMPLUS_IF_CH1_DOWN_COMP_MSK    (0x01 << PWMPLUS_IF_CH1_DOWN_COMP_POS)

#define PWMPLUS_IF_CH2_DOWN_COMP_POS    10   //PWMPLUSͨ��2���¼�������Ƚϵ��ж�״̬
#define PWMPLUS_IF_CH2_DOWN_COMP_MSK    (0x01 << PWMPLUS_IF_CH2_DOWN_COMP_POS)

#define PWMPLUS_IF_DOWN_OVF_POS         11   //PWMPLUS���¼�����������ж�״̬
#define PWMPLUS_IF_DOWN_OVF_MSK         (0x01 << PWMPLUS_IF_DOWN_OVF_POS)

#define PWMPLUS_IF_DOWN_TRIG_POS        12   //PWMPLUS���¼������ﴥ�����ж�״̬
#define PWMPLUS_IF_DOWN_TRIG_MSK        (0x01 << PWMPLUS_IF_DOWN_TRIG_POS)

#define PWMPLUS_IF_BRK0_POS             16   //PWMPLUSɲ��0�ж�״̬
#define PWMPLUS_IF_BRK0_MSK             (0x01 << PWMPLUS_IF_BRK0_POS)

#define PWMPLUS_IF_BRK1_POS             17   //PWMPLUSɲ��1�ж�״̬
#define PWMPLUS_IF_BRK1_MSK             (0x01 << PWMPLUS_IF_BRK1_POS)

#define PWMPLUS_IF_BRK2_POS             18   //PWMPLUSɲ��2�ж�״̬
#define PWMPLUS_IF_BRK2_MSK             (0x01 << PWMPLUS_IF_BRK2_POS)

#define PWMPLUS_IF_RELOAD_POS           19   //PWMPLUS�Զ�װ���ж�״̬
#define PWMPLUS_IF_RELOAD_MSK           (0x01 << PWMPLUS_IF_RELOAD_POS)


#define PWMPLUS_SWLOAD_POS              0    //PWMPLUS���LOAD
#define PWMPLUS_SWLOAD_MSK              (0x01 << PWMPLUS_SWLOAD_POS)


#define PWMPLUS_MSK_EN_CH0_POS         0    //PWMPLUSͨ��0����ʹ��
#define PWMPLUS_MSK_EN_CH0_MSK         (0x01 << PWMPLUS_MSK_EN_CH0_POS)

#define PWMPLUS_MSK_EN_CH0N_POS        1    //PWMPLUSͨ��0N����ʹ��
#define PWMPLUS_MSK_EN_CH0N_MSK        (0x01 << PWMPLUS_MSK_EN_CH0N_POS)

#define PWMPLUS_MSK_EN_CH1_POS         2    //PWMPLUSͨ��1����ʹ��
#define PWMPLUS_MSK_EN_CH1_MSK         (0x01 << PWMPLUS_MSK_EN_CH1_POS)

#define PWMPLUS_MSK_EN_CH1N_POS        3    //PWMPLUSͨ��1N����ʹ��
#define PWMPLUS_MSK_EN_CH1N_MSK        (0x01 << PWMPLUS_MSK_EN_CH1N_POS)

#define PWMPLUS_MSK_EN_CH2_POS         4    //PWMPLUSͨ��2����ʹ��
#define PWMPLUS_MSK_EN_CH2_MSK         (0x01 << PWMPLUS_MSK_EN_CH2_POS)

#define PWMPLUS_MSK_EN_CH2N_POS        5    //PWMPLUSͨ��2N����ʹ��
#define PWMPLUS_MSK_EN_CH2N_MSK        (0x01 << PWMPLUS_MSK_EN_CH2N_POS)


#define PWMPLUS_CNT_STATE_CNT_POS      0    //PWMPLUS��ǰ����ֵ
#define PWMPLUS_CNT_STATE_CNT_MSK      (0xFFFF << PWMPLUS_CNT_STATE_CNT_POS)

#define PWMPLUS_CNT_STATE_DIR_POS      16    //PWMPLUS��ǰ��������
#define PWMPLUS_CNT_STATE_DIR_MSK      (0x01 << PWMPLUS_CNT_STATE_DIR_POS)

#define PWMPLUS_CNT_STATE_STATE_POS    17    //PWMPLUS����������״̬
#define PWMPLUS_CNT_STATE_STATE_MSK    (0x01 << PWMPLUS_CNT_STATE_STATE_POS)

#define PWMPLUS_BRK0_STATE_POS         0     //PWMPLUSɲ��0�����źŵ�ǰ״̬
#define PWMPLUS_BRK0_STATE_MSK         (0x01 << PWMPLUS_BRK0_STATE_POS)

#define PWMPLUS_BRK1_STATE_POS         1     //PWMPLUSɲ��1�����źŵ�ǰ״̬
#define PWMPLUS_BRK1_STATE_MSK         (0x01 << PWMPLUS_BRK1_STATE_POS)



typedef struct {
	__IO uint32_t CFG;        //���ƼĴ���

	__IO uint32_t IE;         //�ж�ʹ��

	__IO uint32_t IF;         //�ж�״̬ 
	
	uint32_t RESERVED[1];
	
	__IO uint32_t MS;         //����ʼֵ
	
	__IO uint32_t TR;         //ʱ��Ĵ���
	
	__IO uint32_t DR;         //���ڼĴ���
	
	__IO uint32_t AR;         //���ӼĴ���
	
	__IO uint32_t TSTR;       //��ǰʱ��Ĵ���
	
	__IO uint32_t TSDR;       //��ǰ���ڼĴ���
	
	__IO uint32_t TSMR;       //��ǰ���Ĵ��� 
	
	__IO uint32_t VALID;      //��ǰʱ����Ч��־�Ĵ���
	
} RTC_TypeDef;


#define RTC_CFG_RTC_EN_POS     0      //RTCʹ��λ
#define RTC_CFG_RTC_EN_MSK     (0x01 << RTC_CFG_RTC_EN_POS)

#define RTC_CFG_ALM_EN_POS     1      //����ʹ��λ
#define RTC_CFG_ALM_EN_MSK     (0x01 << RTC_CFG_ALM_EN_POS)

#define RTC_CFG_LOAD_EN_POS    2      //���ؼĴ���TR��DR�趨ֵʹ��λ
#define RTC_CFG_LOAD_EN_MSK    (0x01 << RTC_CFG_LOAD_EN_POS)


#define RTC_IE_SEC_POS         0      //���ж�ʹ��
#define RTC_IE_SEC_MSK         (0x01 << RTC_IE_SEC_POS)

#define RTC_IE_MIN_POS         1      //�����ж�ʹ��
#define RTC_IE_MIN_MSK         (0x01 << RTC_IE_MIN_POS)

#define RTC_IE_HOUR_POS        2      //Сʱ�ж�ʹ��
#define RTC_IE_HOUR_MSK        (0x01 << RTC_IE_HOUR_POS)

#define RTC_IE_DATE_POS        3      //���ж�ʹ��
#define RTC_IE_DATE_MSK        (0x01 << RTC_IE_DATE_POS)

#define RTC_IE_ALM_POS         4      //�����ж�ʹ��
#define RTC_IE_ALM_MSK         (0x01 << RTC_IE_ALM_POS)

#define RTC_IE_MS_POS          5      //�����ж�ʹ��
#define RTC_IE_MS_MSK          (0x01 << RTC_IE_MS_POS)


#define RTC_IF_SEC_POS         0      //���ж�״̬
#define RTC_IF_SEC_MSK         (0x01 << RTC_IF_SEC_POS)

#define RTC_IF_MIN_POS         1      //�����ж�״̬
#define RTC_IF_MIN_MSK         (0x01 << RTC_IF_MIN_POS)

#define RTC_IF_HOUR_POS        2      //Сʱ�ж�״̬
#define RTC_IF_HOUR_MSK        (0x01 << RTC_IF_HOUR_POS)

#define RTC_IF_DATE_POS        3      //���ж�״̬
#define RTC_IF_DATE_MSK        (0x01 << RTC_IF_DATE_POS)

#define RTC_IF_ALM_POS         4      //�����ж�״̬
#define RTC_IF_ALM_MSK         (0x01 << RTC_IF_ALM_POS)

#define RTC_IF_MS_POS          5      //�����ж�״̬
#define RTC_IF_MS_MSK          (0x01 << RTC_IF_MS_POS)

#define RTC_IF_TIME_ERR_POS    8      //ʱ���趨��Ч��־
#define RTC_IF_TIME_ERR_MSK    (0x01 << RTC_IF_TIME_ERR_POS)

#define RTC_IF_ALM_ERR_POS     9     //�����趨��Ч��־
#define RTC_IF_ALM_ERR_MSK     (0x01 << RTC_IF_ALM_ERR_POS)


#define RTC_MS_PRE_ROUND_POS         0      //Ԥ��Ƶ��������
#define RTC_MS_PRE_ROUND_MSK         (0xFFFFF << RTC_MS_PRE_ROUND_POS) 
                                     
#define RTC_MS_PRE_DECIMAL_POS       20     //Ԥ��ƵС������
#define RTC_MS_PRE_DECIMAL_MSK       (0xF << RTC_MS_PRE_DECIMAL_POS) 
                                     
#define RTC_MS_PRE_PERIOD_POS        24     //С����������ѡ��
#define RTC_MS_PRE_PERIOD_MSK        (0x1 << RTC_MS_PRE_PERIOD_POS) 


#define RTC_TR_BCD_SEC_POS           0     //���ӵĸ�λ��  BCD��
#define RTC_TR_BCD_SEC_MSK           (0xF << RTC_TR_BCD_SEC_POS) 

#define RTC_TR_BCD_SEC_DEC_POS       4     //���ӵ�ʮλ��  BCD��
#define RTC_TR_BCD_SEC_DEC_MSK       (0x7 << RTC_TR_BCD_SEC_DEC_POS) 

#define RTC_TR_BCD_MIN_POS           8     //���ӵĸ�λ��  BCD��
#define RTC_TR_BCD_MIN_MSK           (0xF << RTC_TR_BCD_MIN_POS) 

#define RTC_TR_BCD_MIN_DEC_POS       12     //���ӵ�ʮλ��  BCD��
#define RTC_TR_BCD_MIN_DEC_MSK       (0x7 << RTC_TR_BCD_MIN_DEC_POS) 

#define RTC_TR_BCD_HOUR_POS          16     //Сʱ�ĸ�λ��  BCD��
#define RTC_TR_BCD_HOUR_MSK          (0xF << RTC_TR_BCD_HOUR_POS) 

#define RTC_TR_BCD_HOUR_DEC_POS      20     //Сʱ��ʮλ��  BCD��
#define RTC_TR_BCD_HOUR_DEC_MSK      (0x3 << RTC_TR_BCD_HOUR_DEC_POS) 

#define RTC_TR_BCD_WEEK_POS          24     //���ڵ�BCD��
#define RTC_TR_BCD_WEEK_MSK          (0x7 << RTC_TR_BCD_WEEK_POS) 


#define RTC_DR_BCD_DATE_POS          0      //���ڵĸ�λ�� BCD��
#define RTC_DR_BCD_DATE_MSK          (0xF << RTC_DR_BCD_DATE_POS) 

#define RTC_DR_BCD_DATE_DEC_POS      4      //���ڵ�ʮλ�� BCD��
#define RTC_DR_BCD_DATE_DEC_MSK      (0x3 << RTC_DR_BCD_DATE_DEC_POS) 

#define RTC_DR_BCD_MONTH_POS         8      //�·ݵĸ�λ�� BCD��
#define RTC_DR_BCD_MONTH_MSK         (0xF << RTC_DR_BCD_MONTH_POS) 

#define RTC_DR_BCD_MONTH_DEC_POS     12     //�·ݵ�ʮλ�� BCD��
#define RTC_DR_BCD_MONTH_DEC_MSK     (0x1 << RTC_DR_BCD_MONTH_DEC_POS) 

#define RTC_DR_BCD_YEAR_POS          16     //��ĸ�λ�� BCD��
#define RTC_DR_BCD_YEAR_MSK          (0xF << RTC_DR_BCD_YEAR_POS) 

#define RTC_DR_BCD_YEAR_DEC_POS      20     //���ʮλ�� BCD��
#define RTC_DR_BCD_YEAR_DEC_MSK      (0x3 << RTC_DR_BCD_YEAR_DEC_POS)


#define RTC_AR_BCD_SEC_POS           0     //���� ���ӵĸ�λ��  BCD��
#define RTC_AR_BCD_SEC_MSK           (0xF << RTC_AR_BCD_SEC_POS) 

#define RTC_AR_BCD_SEC_DEC_POS       4     //���� ���ӵ�ʮλ��  BCD��
#define RTC_AR_BCD_SEC_DEC_MSK       (0x7 << RTC_AR_BCD_SEC_DEC_POS) 

#define RTC_AR_BCD_MIN_POS           8     //���� ���ӵĸ�λ��  BCD��
#define RTC_AR_BCD_MIN_MSK           (0xF << RTC_AR_BCD_MIN_POS) 

#define RTC_AR_BCD_MIN_DEC_POS       12     //���� ���ӵ�ʮλ��  BCD��
#define RTC_AR_BCD_MIN_DEC_MSK       (0x7 << RTC_AR_BCD_MIN_DEC_POS) 

#define RTC_AR_BCD_HOUR_POS          16     //���� Сʱ�ĸ�λ��  BCD��
#define RTC_AR_BCD_HOUR_MSK          (0xF << RTC_AR_BCD_HOUR_POS) 

#define RTC_AR_BCD_HOUR_DEC_POS      20     //���� Сʱ��ʮλ��  BCD��
#define RTC_AR_BCD_HOUR_DEC_MSK      (0x3 << RTC_AR_BCD_HOUR_DEC_POS) 

#define RTC_AR_BCD_WEEK_POS          24     //���� ���ڵ�BCD��
#define RTC_AR_BCD_WEEK_MSK          (0x7F << RTC_AR_BCD_WEEK_POS) 


#define RTC_TSTR_BCD_SEC_POS           0     //���ӵĸ�λ��  BCD��    ��ǰʱ��
#define RTC_TSTR_BCD_SEC_MSK           (0xF << RTC_TSTR_BCD_SEC_POS) 

#define RTC_TSTR_BCD_SEC_DEC_POS       4     //���ӵ�ʮλ��  BCD��    ��ǰʱ��
#define RTC_TSTR_BCD_SEC_DEC_MSK       (0x7 << RTC_TSTR_BCD_SEC_DEC_POS) 

#define RTC_TSTR_BCD_MIN_POS           8     //���ӵĸ�λ��  BCD��    ��ǰʱ��
#define RTC_TSTR_BCD_MIN_MSK           (0xF << RTC_TSTR_BCD_MIN_POS) 

#define RTC_TSTR_BCD_MIN_DEC_POS       12     //���ӵ�ʮλ��  BCD��   ��ǰʱ��
#define RTC_TSTR_BCD_MIN_DEC_MSK       (0x7 << RTC_TSTR_BCD_MIN_DEC_POS) 

#define RTC_TSTR_BCD_HOUR_POS          16     //Сʱ�ĸ�λ��  BCD��   ��ǰʱ��
#define RTC_TSTR_BCD_HOUR_MSK          (0xF << RTC_TSTR_BCD_HOUR_POS) 

#define RTC_TSTR_BCD_HOUR_DEC_POS      20     //Сʱ��ʮλ��  BCD��   ��ǰʱ��
#define RTC_TSTR_BCD_HOUR_DEC_MSK      (0x3 << RTC_TSTR_BCD_HOUR_DEC_POS) 

#define RTC_TSTR_BCD_WEEK_POS          24     //���ڵ�BCD��           ��ǰʱ��
#define RTC_TSTR_BCD_WEEK_MSK          (0x7 << RTC_TSTR_BCD_WEEK_POS) 


#define RTC_TSDR_BCD_DATE_POS          0      //���ڵĸ�λ�� BCD��        ��ǰʱ��
#define RTC_TSDR_BCD_DATE_MSK          (0xF << RTC_TSDR_BCD_DATE_POS) 
 
#define RTC_TSDR_BCD_DATE_DEC_POS      4      //���ڵ�ʮλ�� BCD��        ��ǰʱ��
#define RTC_TSDR_BCD_DATE_DEC_MSK      (0x3 << RTC_TSDR_BCD_DATE_DEC_POS) 

#define RTC_TSDR_BCD_MOUTH_POS         8      //�·ݵĸ�λ�� BCD��        ��ǰʱ��
#define RTC_TSDR_BCD_MOUTH_MSK         (0xF << RTC_TSDR_BCD_MOUTH_POS) 

#define RTC_TSDR_BCD_MOUTH_DEC_POS     12     //�·ݵ�ʮλ�� BCD��        ��ǰʱ��
#define RTC_TSDR_BCD_MOUTH_DEC_MSK     (0x1 << RTC_TSDR_BCD_MOUTH_DEC_POS) 

#define RTC_TSDR_BCD_YEAR_POS          16     //��ĸ�λ�� BCD��          ��ǰʱ��
#define RTC_TSDR_BCD_YEAR_MSK          (0xF << RTC_TSDR_BCD_YEAR_POS) 
 
#define RTC_TSDR_BCD_YEAR_DEC_POS      20     //���ʮλ�� BCD��          ��ǰʱ��
#define RTC_TSDR_BCD_YEAR_DEC_MSK      (0x3 << RTC_TSDR_BCD_YEAR_DEC_POS)

#define RTC_TSDR_LEAPYEAR_POS          24     //�����־λ  1:����, 0:ƽ��
#define RTC_TSDR_LEAPYEAR_MSK          (0x1 << RTC_TSDR_LEAPYEAR_POS)


#define RTC_TSMS_CNT_20_POS            0     //��굱ǰ����ֵ
#define RTC_TSMS_CNT_20_MSK            (0xFFFFF << RTC_TSMS_CNT_20_POS) 


#define RTC_CUR_VALID_POS              0     //��ǰʱ����Ч��־λ  1:��Ч, 2:��Ч
#define RTC_CUR_VALID_MSK              (0x1 << RTC_CUR_VALID_POS) 


typedef struct {
	
	__IO uint32_t CTRL;       //���ƼĴ���
	
	__IO uint32_t BAUD;       //���������üĴ���
	
	__IO uint32_t TDR;        //�������ݼĴ���
	
	__IO uint32_t RDR;        //�������ݼĴ���
	
	__IO uint32_t IE;         //�ж�ʹ�ܼĴ���  
	
	__IO uint32_t IF;         //�ж�״̬�Ĵ���
	
	__IO uint32_t FIFO;       //FIFO���ƼĴ���
	
	__IO uint32_t FC;         //�������üĴ��� 
	
	__IO uint32_t RXTO;       //���ճ�ʱ���üĴ��� 
		
} UART_TypeDef;


#define UART_CTRL_EN_POS         0       //����ʹ��
#define UART_CTRL_EN_MSK         (0x01 << UART_CTRL_EN_POS)

#define UART_CTRL_RXEN_POS       1       //���ڽ���ʹ��
#define UART_CTRL_RXEN_MSK       (0x01 << UART_CTRL_RXEN_POS)

#define UART_CTRL_TXEN_POS       2       //���ڷ���ʹ��
#define UART_CTRL_TXEN_MSK       (0x01 << UART_CTRL_TXEN_POS)

#define UART_CTRL_RXDMAEN_POS    3       //���ڽ���DMA����ʹ��
#define UART_CTRL_RXDMAEN_MSK    (0x01 << UART_CTRL_RXDMAEN_POS)

#define UART_CTRL_TXDMAEN_POS    4       //���ڷ���DMA����ʹ��
#define UART_CTRL_TXDMAEN_MSK    (0x01 << UART_CTRL_TXDMAEN_POS)

#define UART_CTRL_NINEBIT_POS    5       //9bit����ģʽʹ��
#define UART_CTRL_NINEBIT_MSK    (0x01 << UART_CTRL_NINEBIT_POS)

#define UART_CTRL_PARITY_POS     6       //��żУ��
#define UART_CTRL_PARITY_MSK     (0x07 << UART_CTRL_PARITY_POS)

#define UART_CTRL_STOP_POS       9       //ֹͣλ����ѡ��
#define UART_CTRL_STOP_MSK       (0x03 << UART_CTRL_STOP_POS)

#define UART_CTRL_ABRDEN_POS     11      //�Զ������ʼ��ʹ��
#define UART_CTRL_ABRDEN_MSK     (0x01 << UART_CTRL_ABRDEN_POS)

#define UART_CTRL_ABRDBIT_POS    12      //�Զ������ʼ��λ������
#define UART_CTRL_ABRDBIT_MSK    (0x03 << UART_CTRL_ABRDBIT_POS)

#define UART_CTRL_TXDLY_POS      14      //�����ӳ�ʱ������
#define UART_CTRL_TXDLY_MSK      (0x07 << UART_CTRL_TXDLY_POS)

#define UART_BAUD_POS            0       //��������������
#define UART_BAUD_MSK            (0xFFFF << UART_BAUD_POS)

#define UART_TDR_POS             0       //�������ݼĴ���
#define UART_TDR_MSK             (0x1FF << UART_TDR_POS)

#define UART_RDR_POS             0       //�������ݼĴ���
#define UART_RDR_MSK             (0x1FF << UART_RDR_POS)


#define UART_IE_TXDONE_POS       2       //����ȫ����������ж�ʹ��
#define UART_IE_TXDONE_MSK       (0x01 << UART_IE_TXDONE_POS)

#define UART_IE_PARITYE_POS      3       //�������ݳ�����żУ������ж�ʹ��
#define UART_IE_PARITYE_MSK      (0x01 << UART_IE_PARITYE_POS)

#define UART_IE_STOPE_POS        4       //�������ݳ���ֹͣλ�����ж�ʹ��
#define UART_IE_STOPE_MSK        (0x01 << UART_IE_STOPE_POS)

#define UART_IE_RXTO_POS         5       //���ճ�ʱ�ж�ʹ��
#define UART_IE_RXTO_MSK         (0x01 << UART_IE_RXTO_POS)

#define UART_IE_RXFIFO_POS       6       //����FIFO�н��յ����ݴﵽ���趨��ˮλ�ж�ʹ��
#define UART_IE_RXFIFO_MSK       (0x01 << UART_IE_RXFIFO_POS)   

#define UART_IE_TXFIFO_POS       7       //����FIFO�н��յ����ݴﵽ���趨��ˮλ�ж�ʹ��
#define UART_IE_TXFIFO_MSK       (0x01 << UART_IE_TXFIFO_POS)  

#define UART_IE_RXFIFO_OVF_POS   8       //����FIFO����ж�ʹ��
#define UART_IE_RXFIFO_OVF_MSK   (0x01 << UART_IE_RXFIFO_OVF_POS)   

#define UART_IE_ABRD_OVF_POS     9       //�Զ������ʼ�����������ж�ʹ��
#define UART_IE_ABRD_OVF_MSK     (0x01 << UART_IE_ABRD_OVF_POS) 


#define UART_IF_TXDONE_POS       2       //����ȫ����������ж�״̬
#define UART_IF_TXDONE_MSK       (0x01 << UART_IF_TXDONE_POS)

#define UART_IF_PARITYE_POS      3       //�������ݳ�����żУ������ж�״̬
#define UART_IF_PARITYE_MSK      (0x01 << UART_IF_PARITYE_POS)

#define UART_IF_STOPE_POS        4       //�������ݳ���ֹͣλ�����ж�״̬
#define UART_IF_STOPE_MSK        (0x01 << UART_IF_STOPE_POS)

#define UART_IF_RXTO_POS         5       //���ճ�ʱ�ж�״̬
#define UART_IF_RXTO_MSK         (0x01 << UART_IF_RXTO_POS)

#define UART_IF_RXFIFO_POS       6       //����FIFO�н��յ����ݴﵽ���趨��ˮλ�ж�״̬
#define UART_IF_RXFIFO_MSK       (0x01 << UART_IF_RXFIFO_POS)   

#define UART_IF_TXFIFO_POS       7       //����FIFO�н��յ����ݴﵽ���趨��ˮλ�ж�״̬
#define UART_IF_TXFIFO_MSK       (0x01 << UART_IF_TXFIFO_POS)  

#define UART_IF_RXFIFO_OVF_POS   8       //����FIFO����ж�״̬
#define UART_IF_RXFIFO_OVF_MSK   (0x01 << UART_IF_RXFIFO_OVF_POS)   

#define UART_IF_ABRD_OVF_POS     9       //�Զ������ʼ�����������ж�״̬
#define UART_IF_ABRD_OVF_MSK     (0x01 << UART_IF_ABRD_OVF_POS) 

#define UART_IF_RXFIFO_EMPTY_POS    10       //����FIFO�ձ�־
#define UART_IF_RXFIFO_EMPTY_MSK    (0x01 << UART_IF_RXFIFO_EMPTY_POS) 

#define UART_IF_RXFIFO_FULL_POS     11       //����FIFO����־
#define UART_IF_RXFIFO_FULL_MSK     (0x01 << UART_IF_RXFIFO_FULL_POS) 

#define UART_IF_RXFIFO_HFULL_POS    12      //����FIFO������־
#define UART_IF_RXFIFO_HFULL_MSK    (0x01 << UART_IF_RXFIFO_HFULL_POS) 

#define UART_IF_TXFIFO_EMPTY_POS    13      //����FIFO�ձ�־
#define UART_IF_TXFIFO_EMPTY_MSK    (0x01 << UART_IF_TXFIFO_EMPTY_POS) 

#define UART_IF_TXFIFO_FULL_POS     14      //����FIFO����־
#define UART_IF_TXFIFO_FULL_MSK     (0x01 << UART_IF_TXFIFO_FULL_POS) 

#define UART_IF_TXFIFO_HFULL_POS    15      //����FIFO������־
#define UART_IF_TXFIFO_HFULL_MSK    (0x01 << UART_IF_TXFIFO_HFULL_POS) 

#define UART_IF_TXBUSY_POS          16      //���ݷ���æ��־
#define UART_IF_TXBUSY_MSK          (0x01 << UART_IF_TXBUSY_POS) 

#define UART_IF_RX_LEVEL_POS        17      //����FIFOˮλ��־�ź�
#define UART_IF_RX_LEVEL_MSK        (0x07 << UART_IF_RX_LEVEL_POS) 

#define UART_IF_TX_LEVEL_POS        20      //����FIFOˮλ��־�ź�
#define UART_IF_TX_LEVEL_MSK        (0x07 << UART_IF_TX_LEVEL_POS) 


#define UART_FIFO_RF_LEVEL_POS      0       //RXFIFO�����жϵ�ˮλ����
#define UART_FIFO_RF_LEVEL_MSK      (0x07 << UART_FIFO_RF_LEVEL_POS)

#define UART_FIFO_TF_LEVEL_POS      3       //TXFIFO�����жϵ�ˮλ����
#define UART_FIFO_TF_LEVEL_MSK      (0x07 << UART_FIFO_TF_LEVEL_POS)

#define UART_FIFO_RF_CLR_POS        6       //RXFIFO���ʹ��
#define UART_FIFO_RF_CLR_MSK        (0x01 << UART_FIFO_RF_CLR_POS)

#define UART_FIFO_TF_CLR_POS        7       //TXFIFO���ʹ��
#define UART_FIFO_TF_CLR_MSK        (0x01 << UART_FIFO_TF_CLR_POS)


#define UART_FC_CTS_EN_POS          0       //CTS����ʹ��
#define UART_FC_CTS_EN_MSK          (0x01 << UART_FC_CTS_EN_POS)

#define UART_FC_RTS_EN_POS          1       //RTS����ʹ��
#define UART_FC_RTS_EN_MSK          (0x01 << UART_FC_RTS_EN_POS)

#define UART_FC_CTS_POL_POS         2       //CTS�źż�������
#define UART_FC_CTS_POL_MSK         (0x01 << UART_FC_CTS_POL_POS)

#define UART_FC_RTS_POL_POS         3       //RTS�źż�������
#define UART_FC_RTS_POL_MSK         (0x01 << UART_FC_RTS_POL_POS)

#define UART_FC_CTS_SIGNAL_POS      4       //CTS��ǰ�ź�״̬
#define UART_FC_CTS_SIGNAL_MSK      (0x01 << UART_FC_CTS_SIGNAL_POS)

#define UART_FC_RTS_SIGNAL_POS      5       //RTS��ǰ�ź�״̬
#define UART_FC_RTS_SIGNAL_MSK      (0x01 << UART_FC_RTS_SIGNAL_POS)


#define UART_RXTO_POS               0       //�������ݳ�ʱ�����Ƚ�ֵ
#define UART_RXTO_MSK               (0xFF << UART_RXTO_POS)



typedef struct {
	__IO uint32_t CTRL;       //���ƼĴ���

	__IO uint32_t WDATA;      //д���ݼĴ���

	__IO uint32_t RDATA;      //�����ݼĴ���

	uint32_t RESERVED1[1];
	
	__IO uint32_t IE;         //�ж�ʹ��

	__IO uint32_t IF;         //�ж�״̬ 
	
	__IO uint32_t FIFOST;     //FIFO״̬ 
	
} SPI_TypeDef;


#define SPI_CTRL_CLKDIV_POS     0           //Clock Divider, SPI����ʱ�� = SYS_Freq/pow(2, CLKDIV+2)
#define SPI_CTRL_CLKDIV_MSK     (0x07 << SPI_CTRL_CLKDIV_POS)

#define SPI_CTRL_EN_POS         3           //SPIϵͳʹ��
#define SPI_CTRL_EN_MSK         (0x01 << SPI_CTRL_EN_POS)

#define SPI_CTRL_CPHA_POS		4		    //0 ��SCLK�ĵ�һ�������ز�������	1 ��SCLK�ĵڶ��������ز�������
#define SPI_CTRL_CPHA_MSK		(0x01 << SPI_CTRL_CPHA_POS)

#define SPI_CTRL_CPOL_POS		5		    //0 ����״̬��SCLKΪ�͵�ƽ		  1 ����״̬��SCLKΪ�ߵ�ƽ
#define SPI_CTRL_CPOL_MSK		(0x01 << SPI_CTRL_CPOL_POS)

#define SPI_CTRL_MSTR_POS		6		    //Master, 1 ��ģʽ	0 ��ģʽ
#define SPI_CTRL_MSTR_MSK		(0x01 << SPI_CTRL_MSTR_POS)

#define SPI_CTRL_LSBF_POS		7		    //���ݴ���˳��ѡ��  0 MSB Fisrt  1 LSB Fisrt
#define SPI_CTRL_LSBF_MSK		(0x01 << SPI_CTRL_LSBF_POS)

#define SPI_CTRL_DATAHOLD_POS   8           //��ģʽ��CPHAΪ1ʱ�����ݱ���ʱ�����üĴ���
#define SPI_CTRL_DATAHOLD_MSK   (0x0F << SPI_CTRL_DATAHOLD_POS)

#define SPI_CTRL_MST_SSN_POS    12          //����ģʽ�£�SSN���   Ĭ������ߵ�ƽ
#define SPI_CTRL_MST_SSN_MSK    (0x01 << SPI_CTRL_MST_SSN_POS)

#define SPI_CTRL_RX_DMAEN_POS   13          //����DMA����ʹ��
#define SPI_CTRL_RX_DMAEN_MSK   (0x01 << SPI_CTRL_RX_DMAEN_POS)

#define SPI_CTRL_TX_DMAEN_POS   14          //����DMA����ʹ��
#define SPI_CTRL_TX_DMAEN_MSK   (0x01 << SPI_CTRL_TX_DMAEN_POS)

#define SPI_CTRL_RF_CLR_POS     15         //RXFIFO���ʹ��
#define SPI_CTRL_RF_CLR_MSK     (0x01 << SPI_CTRL_RF_CLR_POS)

#define SPI_CTRL_TF_CLR_POS     16         //TXFIFO���ʹ��
#define SPI_CTRL_TF_CLR_MSK     (0x01 << SPI_CTRL_TF_CLR_POS)


#define SPI_IE_RXFIFO_OVF_POS      0        //����FIFO����ж�ʹ��
#define SPI_IE_RXFIFO_OVF_MSK      (0x01 << SPI_IE_RXFIFO_OVF_POS)

#define SPI_IE_RXFIFO_FULL_POS     1        //����FIFO���ж�ʹ��
#define SPI_IE_RXFIFO_FULL_MSK     (0x01 << SPI_IE_RXFIFO_FULL_POS)

#define SPI_IE_RXFIFO_HFULL_POS    2        //����FIFO�����ж�ʹ��
#define SPI_IE_RXFIFO_HFULL_MSK    (0x01 << SPI_IE_RXFIFO_HFULL_POS)

#define SPI_IE_TXFIFO_EMPTY_POS    3        //����FIFO���ж�ʹ��
#define SPI_IE_TXFIFO_EMPTY_MSK    (0x01 << SPI_IE_TXFIFO_EMPTY_POS)

#define SPI_IE_TXFIFO_HFULL_POS    4        //����FIFO�����ж�ʹ��
#define SPI_IE_TXFIFO_HFULL_MSK    (0x01 << SPI_IE_TXFIFO_HFULL_POS)


#define SPI_IF_RXFIFO_OVF_POS      0        //����FIFO����ж�״̬
#define SPI_IF_RXFIFO_OVF_MSK      (0x01 << SPI_IF_RXFIFO_OVF_POS)

#define SPI_IF_RXFIFO_FULL_POS     1        //����FIFO���ж�״̬
#define SPI_IF_RXFIFO_FULL_MSK     (0x01 << SPI_IF_RXFIFO_FULL_POS)

#define SPI_IF_RXFIFO_HFULL_POS    2        //����FIFO�����ж�״̬
#define SPI_IF_RXFIFO_HFULL_MSK    (0x01 << SPI_IF_RXFIFO_HFULL_POS)

#define SPI_IF_TXFIFO_EMPTY_POS    3        //����FIFO���ж�״̬
#define SPI_IF_TXFIFO_EMPTY_MSK    (0x01 << SPI_IF_TXFIFO_EMPTY_POS)

#define SPI_IF_TXFIFO_HFULL_POS    4        //����FIFO�����ж�״̬
#define SPI_IF_TXFIFO_HFULL_MSK    (0x01 << SPI_IF_TXFIFO_HFULL_POS)

#define SPI_IF_TXFIFO_BUSY_POS     5        //SPI ����æ״̬��־
#define SPI_IF_TXFIFO_BUSY_MSK     (0x01 << SPI_IF_TXFIFO_BUSY_POS)

#define SPI_FIFOST_RXFIFO_EMPTY_POS      0        //����FIFO��״̬
#define SPI_FIFOST_RXFIFO_EMPTY_MSK      (0x01 << SPI_FIFOST_RXFIFO_EMPTY_POS)

#define SPI_FIFOST_RXFIFO_FULL_POS       1        //����FIFO��״̬
#define SPI_FIFOST_RXFIFO_FULL_MSK       (0x01 << SPI_FIFOST_RXFIFO_FULL_POS)

#define SPI_FIFOST_RXFIFO_HFULL_POS      2        //����FIFO����״̬
#define SPI_FIFOST_RXFIFO_HFULL_MSK      (0x01 << SPI_FIFOST_RXFIFO_HFULL_POS)

#define SPI_FIFOST_TXFIFO_EMPTY_POS      3        //����FIFO��״̬
#define SPI_FIFOST_TXFIFO_EMPTY_MSK      (0x01 << SPI_FIFOST_TXFIFO_EMPTY_POS)

#define SPI_FIFOST_TXFIFO_FULL_POS       4        //����FIFO��״̬
#define SPI_FIFOST_TXFIFO_FULL_MSK       (0x01 << SPI_FIFOST_TXFIFO_FULL_POS)

#define SPI_FIFOST_TXFIFO_HFULL_POS      5        //����FIFO����״̬
#define SPI_FIFOST_TXFIFO_HFULL_MSK      (0x01 << SPI_FIFOST_TXFIFO_HFULL_POS)

#define SPI_FIFOST_RX_LEVEL_POS          6        //����FIFOˮλ��־�ź�
#define SPI_FIFOST_RX_LEVEL_MSK          (0x07 << SPI_FIFOST_RX_LEVEL_POS) 

#define SPI_FIFOST_TX_LEVEL_POS          9       //����FIFOˮλ��־�ź�
#define SPI_FIFOST_TX_LEVEL_MSK          (0x07 << SPI_FIFOST_TX_LEVEL_POS) 


typedef struct {
	
	__IO uint32_t CCFG;          //ͨ�����üĴ���
	
	__IO uint32_t CST;           //ͨ��״̬�Ĵ���
	
	__IO uint32_t CTRANS;        //ͨ�ô���Ĵ���
	
	__IO uint32_t RXDATA;        //�������ݼĴ���
	
	__IO uint32_t TXDATA;        //�������ݼĴ���
	
	__IO uint32_t IE;            //�ж�ʹ�ܼĴ���
	
	__IO uint32_t IF;            //�ж�״̬�Ĵ���
	
	uint32_t RESERVED1[1];
	
	__IO uint32_t MCTRL;         //����ģʽ���ƼĴ���
	
	__IO uint32_t MSPC;          //ʱ�����üĴ���
	
	uint32_t RESERVED2[2];
	
	__IO uint32_t SCTRL;         //�ӻ�ģʽ���ƼĴ��� 
	
	__IO uint32_t SADDR;         //�ӻ���ַ�Ĵ���
	
} IIC_TypeDef;


#define IIC_CCFG_EN_POS         0     //IICʹ��
#define IIC_CCFG_EN_MSK         (0x01 << IIC_CCFG_EN_POS)

#define IIC_CCFG_MODE_POS       1     //ģʽѡ��
#define IIC_CCFG_MODE_MSK       (0x01 << IIC_CCFG_MODE_POS)

#define IIC_CCFG_HS_POS         2     //HIGH SPEED MODE
#define IIC_CCFG_HS_MSK         (0x01 << IIC_CCFG_HS_POS)

#define IIC_CCFG_DNF_POS        3     //�����˲�
#define IIC_CCFG_DNF_MSK        (0x0F << IIC_CCFG_DNF_POS)

#define IIC_CST_BUSY_POS        0     //����æ״̬
#define IIC_CST_BUSY_MSK        (0x01 << IIC_CST_BUSY_POS)

#define IIC_CST_SCL_POS         1     //SCL״̬
#define IIC_CST_SCL_MSK         (0x01 << IIC_CST_SCL_POS)

#define IIC_CST_SDA_POS         2     //SDA״̬
#define IIC_CST_SDA_MSK         (0x01 << IIC_CST_SDA_POS)

#define IIC_CST_SLV_RD_POS      9     //SLAVEģʽ��״̬
#define IIC_CST_SLV_RD_MSK      (0x01 << IIC_CST_SLV_RD_POS)

#define IIC_CST_SLV_WR_POS      10    //SLAVEģʽ��״̬
#define IIC_CST_SLV_WR_MSK      (0x01 << IIC_CST_SLV_WR_POS)

#define IIC_CST_SLV_BUSY_POS    11    //SLAVEʱ��STRETCHæ״̬
#define IIC_CST_SLV_BUSY_MSK    (0x01 << IIC_CST_SLV_BUSY_POS)

#define IIC_CST_SLV_RXDT_POS    12    //SLAVE���յ�����������
#define IIC_CST_SLV_RXDT_MSK    (0x03 << IIC_CST_SLV_RXDT_POS)


#define IIC_CTRANS_TX_ACK_POS   0     //����Ϊ���շ�ʱ������ACK��NACK
#define IIC_CTRANS_TX_ACK_MSK   (0x01 << IIC_CTRANS_TX_ACK_POS)

#define IIC_CTRANS_RX_ACK_POS   1     //����Ϊ���ͷ�ʱ�����յ�ACK��NACK
#define IIC_CTRANS_RX_ACK_MSK   (0x01 << IIC_CTRANS_RX_ACK_POS)

#define IIC_CTRANS_TXD_CLR_POS  2     //�������ݼĴ������
#define IIC_CTRANS_TXD_CLR_MSK  (0x01 << IIC_CTRANS_TXD_CLR_POS)


#define IIC_RXDATA_POS          0     //�������ݼĴ���
#define IIC_RXDATA_MSK          (0xFF << IIC_RXDATA_POS)


#define IIC_TXDATA_POS          0     //�������ݼĴ���
#define IIC_TXDATA_MSK          (0xFF << IIC_TXDATA_POS)


#define IIC_IE_RXOVF_POS        2     //�������ݼĴ�������ж�ʹ��
#define IIC_IE_RXOVF_MSK        (0x01 << IIC_IE_RXOVF_POS)

#define IIC_IE_TXF_POS          3     //�������ݽ����ж�ʹ��
#define IIC_IE_TXF_MSK          (0x01 << IIC_IE_TXF_POS)

#define IIC_IE_RXF_POS          4     //�������ݽ����ж�ʹ��
#define IIC_IE_RXF_MSK          (0x01 << IIC_IE_RXF_POS)

#define IIC_IE_SLV_STA_POS      8     //SLAVE��⵽START�ж�ʹ��
#define IIC_IE_SLV_STA_MSK      (0x01 << IIC_IE_SLV_STA_POS)

#define IIC_IE_SLV_STO_POS      9     //SLAVE��⵽STOP�ж�ʹ��
#define IIC_IE_SLV_STO_MSK      (0x01 << IIC_IE_SLV_STO_POS)

#define IIC_IE_MLTO_POS         17     //MASTER SCL LOW��ʱ�ж�ʹ��
#define IIC_IE_MLTO_MSK         (0x01 << IIC_IE_MLTO_POS)


#define IIC_IF_TXE_POS          0     //�������ݼĴ������ж�״̬
#define IIC_IF_TXE_MSK          (0x01 << IIC_IF_TXE_POS)

#define IIC_IF_RXNE_POS         1     //�������ݼĴ����ǿ��ж�״̬
#define IIC_IF_RXNE_MSK         (0x01 << IIC_IF_RXNE_POS)

#define IIC_IF_RXOVF_POS        2     //�������ݼĴ�������ж�״̬
#define IIC_IF_RXOVF_MSK        (0x01 << IIC_IF_RXOVF_POS)

#define IIC_IF_TXF_POS          3     //�������ݽ����ж�״̬
#define IIC_IF_TXF_MSK          (0x01 << IIC_IF_TXF_POS)

#define IIC_IF_RXF_POS          4     //�������ݽ����ж�״̬
#define IIC_IF_RXF_MSK          (0x01 << IIC_IF_RXF_POS)

#define IIC_IF_SLV_STA_POS      8     //SLAVE��⵽START�ж�״̬
#define IIC_IF_SLV_STA_MSK      (0x01 << IIC_IF_SLV_STA_POS)

#define IIC_IF_SLV_STO_POS      9     //SLAVE��⵽STOP�ж�״̬
#define IIC_IF_SLV_STO_MSK      (0x01 << IIC_IF_SLV_STO_POS)

#define IIC_IF_MLTO_POS         17     //MASTER SCL LOW��ʱ�ж�״̬
#define IIC_IF_MLTO_MSK         (0x01 << IIC_IF_MLTO_POS)


#define IIC_MCTRL_STA_POS       0      //����START�ź�
#define IIC_MCTRL_STA_MSK       (0x01 << IIC_MCTRL_STA_POS)

#define IIC_MCTRL_RD_POS        1      //�������ݵ�RXDATA
#define IIC_MCTRL_RD_MSK        (0x01 << IIC_MCTRL_RD_POS)

#define IIC_MCTRL_WR_POS        2      //����TXDATA�е�����
#define IIC_MCTRL_WR_MSK        (0x01 << IIC_MCTRL_WR_POS)

#define IIC_MCTRL_STO_POS       3      //����STOP�ź�
#define IIC_MCTRL_STO_MSK       (0x01 << IIC_MCTRL_STO_POS)


#define IIC_MSPC_SCL_LOW_POS    0      //SCLʱ�ӵ͵�ƽʱ������
#define IIC_MSPC_SCL_LOW_MSK    (0xFF << IIC_MSPC_SCL_LOW_POS)

#define IIC_MSPC_SCL_HI_POS     8     //SCLʱ�Ӹߵ�ƽʱ������
#define IIC_MSPC_SCL_HI_MSK     (0xFF << IIC_MSPC_SCL_HI_POS)

#define IIC_MSPC_CPD_POS        16    //ʱ��Ԥ��Ƶ
#define IIC_MSPC_CPD_MSK        (0xFF << IIC_MSPC_CPD_POS)

#define IIC_MSPC_DATAHOLD_POS   24    //SDA���ݱ���ʱ������
#define IIC_MSPC_DATAHOLD_MSK   (0x0F << IIC_MSPC_DATAHOLD_POS)


#define IIC_SCTRL_ADMD_POS      0     //SLAVE��ַģʽѡ��
#define IIC_SCTRL_ADMD_MSK      (0x01 << IIC_SCTRL_ADMD_POS)

#define IIC_SCTRL_MCDE_POS      1     //MASTER CODE ���ʹ��
#define IIC_SCTRL_MCDE_MSK      (0x01 << IIC_SCTRL_MCDE_POS)

#define IIC_SCTRL_STRETCH_POS   2     //ʱ��STRETCHʹ��
#define IIC_SCTRL_STRETCH_MSK   (0x01 << IIC_SCTRL_STRETCH_POS)

#define IIC_SCTRL_ASDS_POS      3     //ʱ��STRETCH�����ݽ���ʱ������Ӧʹ��
#define IIC_SCTRL_ASDS_MSK      (0x01 << IIC_SCTRL_ASDS_POS)


#define IIC_SADDR_ADDR0_POS     0     //ADDR0
#define IIC_SADDR_ADDR0_MSK     (0x01 << IIC_SADDR_ADDR0_POS)

#define IIC_SADDR_ADDR1_7_POS   1     //ADDR1--7
#define IIC_SADDR_ADDR1_7_MSK   (0x7F << IIC_SADDR_ADDR1_7_POS)

#define IIC_SADDR_ADDR8_9_POS   8     //ADDR8--9
#define IIC_SADDR_ADDR8_9_MSK   (0x03 << IIC_SADDR_ADDR8_9_POS)

#define IIC_SADDR_MASK_ADDR0_POS     16  //SLAVE��Ӧ��ַλ����
#define IIC_SADDR_MASK_ADDR0_MSK     (0x01 << IIC_SADDR_MASK_ADDR0_POS)

#define IIC_SADDR_MASK_ADDR1_7_POS   17  //SLAVE��Ӧ��ַλ����
#define IIC_SADDR_MASK_ADDR1_7_MSK   (0x7F << IIC_SADDR_MASK_ADDR1_7_POS)


typedef struct {
	__IO uint32_t CFG;               //ADC���üĴ���      
	
	__IO uint32_t START;             //ADC�����Ĵ���  

	__IO uint32_t IE;                //ADC�ж�ʹ�ܼĴ���  
	
	__IO uint32_t IF;                //ADC�ж�״̬�Ĵ���  
	
 	struct {
		__IO uint32_t STAT;          //ͨ��״̬�Ĵ���
		
		__IO uint32_t DATA;          //ͨ�����ݼĴ���
	} CH[16];
	
	uint32_t RESERVED1[4];
	
	__IO uint32_t FIFO_STAT;         //FIFO״̬�Ĵ���
	
	__IO uint32_t FIFO_DATA;         //FIFO���ݼĴ���
	
	uint32_t RESERVED2[2];
	
	__IO uint32_t EXTTRIG_SEL;       //�ⲿ�źŴ���ADCѡ��Ĵ���
	
	uint32_t RESERVED3[15];
	
	__IO uint32_t CALIB_OFFSET;     //ADCУ׼OFFSET�Ĵ���
	
	__IO uint32_t CALIB_KD;         //ADCУ׼KD�Ĵ���
	
} ADC_TypeDef;


#define ADC_CFG_CH0_POS			    0		//ͨ��0ѡ��
#define ADC_CFG_CH0_MSK			    (0x01 << ADC_CFG_CH0_POS)

#define ADC_CFG_CH1_POS			    1		//ͨ��1ѡ��
#define ADC_CFG_CH1_MSK			    (0x01 << ADC_CFG_CH1_POS)

#define ADC_CFG_CH2_POS			    2		//ͨ��2ѡ��
#define ADC_CFG_CH2_MSK			    (0x01 << ADC_CFG_CH2_POS)

#define ADC_CFG_CH3_POS			    3		//ͨ��3ѡ��
#define ADC_CFG_CH3_MSK			    (0x01 << ADC_CFG_CH3_POS)

#define ADC_CFG_CH4_POS			    4		//ͨ��4ѡ��
#define ADC_CFG_CH4_MSK			    (0x01 << ADC_CFG_CH4_POS)

#define ADC_CFG_CH5_POS			    5		//ͨ��5ѡ��
#define ADC_CFG_CH5_MSK			    (0x01 << ADC_CFG_CH5_POS)

#define ADC_CFG_CH6_POS			    6		//ͨ��6ѡ��
#define ADC_CFG_CH6_MSK			    (0x01 << ADC_CFG_CH6_POS)
 
#define ADC_CFG_CH7_POS			    7		//ͨ��7ѡ��
#define ADC_CFG_CH7_MSK			    (0x01 << ADC_CFG_CH7_POS)

#define ADC_CFG_CH8_POS			    8		//ͨ��8ѡ��
#define ADC_CFG_CH8_MSK			    (0x01 << ADC_CFG_CH8_POS)

#define ADC_CFG_CH9_POS			    9		//ͨ��9ѡ��
#define ADC_CFG_CH9_MSK			    (0x01 << ADC_CFG_CH9_POS)

#define ADC_CFG_CH10_POS			10		//ͨ��10ѡ��
#define ADC_CFG_CH10_MSK			(0x01 << ADC_CFG_CH10_POS)

#define ADC_CFG_CH11_POS			11		//ͨ��11ѡ��
#define ADC_CFG_CH11_MSK			(0x01 << ADC_CFG_CH11_POS)

#define ADC_CFG_CH12_POS			12		//ͨ��12ѡ��
#define ADC_CFG_CH12_MSK			(0x01 << ADC_CFG_CH12_POS)

#define ADC_CFG_CH13_POS			13		//ͨ��13ѡ��
#define ADC_CFG_CH13_MSK			(0x01 << ADC_CFG_CH13_POS)

#define ADC_CFG_CH14_POS			14		//ͨ��14ѡ��
#define ADC_CFG_CH14_MSK			(0x01 << ADC_CFG_CH14_POS)

#define ADC_CFG_CH15_POS			15		//ͨ��15ѡ��
#define ADC_CFG_CH15_MSK			(0x01 << ADC_CFG_CH15_POS)

#define ADC_CFG_AVG_POS		        16		//0 1�β���	  1 2�β���ȡƽ��ֵ	  2 4�β���ȡƽ��ֵ	  3 8�β���ȡƽ��ֵ	
#define ADC_CFG_AVG_MSK		        (0x03 << ADC_CFG_AVG_POS)

#define ADC_CFG_CONT_POS		    18		//Continuous conversion��ֻ���������ģʽ����Ч��0 ����ת����ת����ɺ�STARTλ�Զ����ֹͣת��
#define ADC_CFG_CONT_MSK		    (0x01 << ADC_CFG_CONT_POS)							//   1 ����ת����������һֱ������ת����ֱ��������STARTλ

#define ADC_CFG_SMPL_SETUP_POS      19      //ADC�ⲿ����ʱ�ӷ�ʽ�²�������ʱ��   0:1  1:2  2:4  3:8  4:16  5:32  6:64  7:128
#define ADC_CFG_SMPL_SETUP_MSK      (0x07 << ADC_CFG_SPL_SETUP_POS)

#define ADC_CFG_MEM_MODE_POS        22      //ADC���ݴ洢��ʽѡ��   0:FIFOģʽ   1:ͨ��ģʽ
#define ADC_CFG_MEM_MODE_MSK        (0x01 << ADC_CFG_MEM_MODE_POS)

#define ADC_CFG_SMPL_CLK_POS        23      //ADC����ģʽѡ��    0:�ڲ�����ʱ��  1:�ⲿ����ʱ��
#define ADC_CFG_SMPL_CLK_MSK        (0x01 << ADC_CFG_SMPL_CLK_POS)

#define ADC_CFG_IN_SMPL_WIN_POS     24      //ADC�ڲ�����ʱ�ӷ�ʽ������������   0:1Tclk   1:3Tclk   2:5Tclk   3:7Tclk  4:9Tclk  5:11Tclk  6:13Tclk  7:15Tclk
#define ADC_CFG_IN_SMPL_WIN_MSK     (0x07 << ADC_CFG_IN_SMPL_WIN_POS)

#define ADC_CFG_EN_POS              27      //ADCʹ�ܿ���λ   0:��ʹ��  1:ʹ��
#define ADC_CFG_EN_MSK              (0x01 << ADC_CFG_EN_POS)

#define ADC_CFG_TRIG_POS            28      //ADC����Դѡ��
#define ADC_CFG_TRIG_MSK            (0x01 << ADC_CFG_TRIG_POS)

#define ADC_CFG_DMAEN_POS           29      //DMA��ȡFIFOʹ��
#define ADC_CFG_DMAEN_MSK           (0x01 << ADC_CFG_DMAEN_POS)


#define ADC_START_START_POS         0      //ADC�����ź�   0:������  1:����
#define ADC_START_START_MSK         (0x01 << ADC_START_START_POS) 

#define ADC_START_BUSY_POS          1      //ADCæ״̬   0:����  1:æ
#define ADC_START_BUSY_MSK          (0x01 << ADC_START_BUSY_POS) 

#define ADC_START_SOFT_RESET_POS    2      //ADC��λʹ��λ
#define ADC_START_SOFT_RESET_MSK    (0x01 << ADC_START_SOFT_RESET_POS) 

#define ADC_START_FIFOCLR_POS       3      //ADC FIFO���ʹ��
#define ADC_START_FIFOCLR_MSK       (0x01 << ADC_START_FIFOCLR_POS) 


#define ADC_IE_CH0EOC_POS			0		//CH0ת������ж�ʹ��
#define ADC_IE_CH0EOC_MSK			(0x01 << ADC_IE_CH0EOC_POS)

#define ADC_IE_CH1EOC_POS			1		//CH1ת������ж�ʹ��
#define ADC_IE_CH1EOC_MSK			(0x01 << ADC_IE_CH1EOC_POS)

#define ADC_IE_CH2EOC_POS			2		//CH2ת������ж�ʹ��
#define ADC_IE_CH2EOC_MSK			(0x01 << ADC_IE_CH2EOC_POS)

#define ADC_IE_CH3EOC_POS			3		//CH3ת������ж�ʹ��
#define ADC_IE_CH3EOC_MSK			(0x01 << ADC_IE_CH3EOC_POS)

#define ADC_IE_CH4EOC_POS			4		//CH4ת������ж�ʹ��
#define ADC_IE_CH4EOC_MSK			(0x01 << ADC_IE_CH4EOC_POS)

#define ADC_IE_CH5EOC_POS			5		//CH5ת������ж�ʹ��
#define ADC_IE_CH5EOC_MSK			(0x01 << ADC_IE_CH5EOC_POS)

#define ADC_IE_CH6EOC_POS			6		//CH6ת������ж�ʹ��
#define ADC_IE_CH6EOC_MSK			(0x01 << ADC_IE_CH6EOC_POS)

#define ADC_IE_CH7EOC_POS			7		//CH7ת������ж�ʹ��
#define ADC_IE_CH7EOC_MSK			(0x01 << ADC_IE_CH7EOC_POS)

#define ADC_IE_CH8EOC_POS			8		//CH8ת������ж�ʹ��
#define ADC_IE_CH8EOC_MSK			(0x01 << ADC_IE_CH8EOC_POS)

#define ADC_IE_CH9EOC_POS			9		//CH9ת������ж�ʹ��
#define ADC_IE_CH9EOC_MSK			(0x01 << ADC_IE_CH9EOC_POS)

#define ADC_IE_CH10EOC_POS			10		//CH10ת������ж�ʹ��
#define ADC_IE_CH10EOC_MSK			(0x01 << ADC_IE_CH10EOC_POS)

#define ADC_IE_CH11EOC_POS			11		//CH11ת������ж�ʹ��
#define ADC_IE_CH11EOC_MSK			(0x01 << ADC_IE_CH11EOC_POS)

#define ADC_IE_CH12EOC_POS			12		//CH12ת������ж�ʹ��
#define ADC_IE_CH12EOC_MSK			(0x01 << ADC_IE_CH12EOC_POS)

#define ADC_IE_CH13EOC_POS			13		//CH13ת������ж�ʹ��
#define ADC_IE_CH13EOC_MSK			(0x01 << ADC_IE_CH13EOC_POS)

#define ADC_IE_CH14EOC_POS			14		//CH4ת������ж�ʹ��
#define ADC_IE_CH14EOC_MSK			(0x01 << ADC_IE_CH14EOC_POS)

#define ADC_IE_CH15EOC_POS			15		//CH15ת������ж�ʹ��
#define ADC_IE_CH15EOC_MSK			(0x01 << ADC_IE_CH15EOC_POS)

#define ADC_IE_FIFO_FULL_POS	    16       //FIFO���ж�ʹ��
#define ADC_IE_FIFO_FULL_MSK	    (0x01 << ADC_IE_FIFO_FULL_POS)

#define ADC_IE_FIFO_HFULL_POS	    17       //FIFO�����ж�ʹ��
#define ADC_IE_FIFO_HFULL_MSK	    (0x01 << ADC_IE_FIFO_HFULL_POS)

#define ADC_IE_FIFO_OVF_POS			18		//FIFO����ж�ʹ��
#define ADC_IE_FIFO_OVF_MSK			(0x01 << ADC_IE_FIFO_OVF_POS)


#define ADC_IF_CH0EOC_POS			0		//CH0ת������ж�״̬
#define ADC_IF_CH0EOC_MSK			(0x01 << ADC_IF_CH0EOC_POS)

#define ADC_IF_CH1EOC_POS			1		//CH1ת������ж�״̬
#define ADC_IF_CH1EOC_MSK			(0x01 << ADC_IF_CH1EOC_POS)

#define ADC_IF_CH2EOC_POS			2		//CH2ת������ж�״̬
#define ADC_IF_CH2EOC_MSK			(0x01 << ADC_IF_CH2EOC_POS)

#define ADC_IF_CH3EOC_POS			3		//CH3ת������ж�״̬
#define ADC_IF_CH3EOC_MSK			(0x01 << ADC_IF_CH3EOC_POS)

#define ADC_IF_CH4EOC_POS			4		//CH4ת������ж�״̬
#define ADC_IF_CH4EOC_MSK			(0x01 << ADC_IF_CH4EOC_POS)

#define ADC_IF_CH5EOC_POS			5		//CH5ת������ж�״̬
#define ADC_IF_CH5EOC_MSK			(0x01 << ADC_IF_CH5EOC_POS)

#define ADC_IF_CH6EOC_POS			6		//CH6ת������ж�״̬
#define ADC_IF_CH6EOC_MSK			(0x01 << ADC_IF_CH6EOC_POS)

#define ADC_IF_CH7EOC_POS			7		//CH7ת������ж�״̬
#define ADC_IF_CH7EOC_MSK			(0x01 << ADC_IF_CH7EOC_POS)

#define ADC_IF_CH8EOC_POS			8		//CH8ת������ж�״̬
#define ADC_IF_CH8EOC_MSK			(0x01 << ADC_IF_CH8EOC_POS)

#define ADC_IF_CH9EOC_POS			9		//CH9ת������ж�״̬
#define ADC_IF_CH9EOC_MSK			(0x01 << ADC_IF_CH9EOC_POS)

#define ADC_IF_CH10EOC_POS			10		//CH10ת������ж�״̬
#define ADC_IF_CH10EOC_MSK			(0x01 << ADC_IF_CH10EOC_POS)

#define ADC_IF_CH11EOC_POS			11		//CH11ת������ж�״̬
#define ADC_IF_CH11EOC_MSK			(0x01 << ADC_IF_CH11EOC_POS)

#define ADC_IF_CH12EOC_POS			12		//CH12ת������ж�״̬
#define ADC_IF_CH12EOC_MSK			(0x01 << ADC_IF_CH12EOC_POS)

#define ADC_IF_CH13EOC_POS			13		//CH13ת������ж�״̬
#define ADC_IF_CH13EOC_MSK			(0x01 << ADC_IF_CH13EOC_POS)

#define ADC_IF_CH14EOC_POS			14		//CH14ת������ж�״̬
#define ADC_IF_CH14EOC_MSK			(0x01 << ADC_IF_CH14EOC_POS)

#define ADC_IF_CH15EOC_POS			15		//CH15ת������ж�״̬
#define ADC_IF_CH15EOC_MSK			(0x01 << ADC_IF_CH15EOC_POS)

#define ADC_IF_FIFO_FULL_POS	    16       //FIFO���ж�״̬
#define ADC_IF_FIFO_FULL_MSK	    (0x01 << ADC_IF_FIFO_FULL_POS)

#define ADC_IF_FIFO_HFULL_POS	    17       //FIFO�����ж�״̬
#define ADC_IF_FIFO_HFULL_MSK	    (0x01 << ADC_IF_FIFO_HFULL_POS)


#define ADC_STAT_EOC_POS			0		//��ADC_IF��Ӧͨ����Ӧλд1������
#define ADC_STAT_EOC_MSK			(0x01 << ADC_STAT_EOC_POS)


#define ADC_DATA_DATA_POS           0       //ADCͨ�����ݼĴ���
#define ADC_DATA_DATA_MSK           (0xFFF << ADC_DATA_DATA_POS)

#define ADC_DATA_NUM_POS            12      //ADC���ݶ�Ӧ��ͨ�����
#define ADC_DATA_NUM_MSK            (0x0F << ADC_DATA_NUM_POS)


#define ADC_FIFO_STAT_FULL_POS      0       //ADC����FIFO����־λ
#define ADC_FIFO_STAT_FULL_MSK      (0x01 << ADC_FIFO_STAT_FULL_POS)

#define ADC_FIFO_STAT_HFULL_POS     1       //ADC����FIFO������־λ
#define ADC_FIFO_STAT_HFULL_MSK     (0x01 << ADC_FIFO_STAT_HFULL_POS)

#define ADC_FIFO_STAT_EMPTY_POS     2       //ADC����FIFO�ձ�־λ
#define ADC_FIFO_STAT_EMPTY_MSK     (0x01 << ADC_FIFO_STAT_EMPTY_POS)

#define ADC_FIFO_STAT_LEVEL_POS     4       //ADC����FIFOˮ������
#define ADC_FIFO_STAT_LEVEL_MSK     (0x0F << ADC_FIFO_STAT_LEVEL_POS)


#define ADC_FIFO_DATA_POS           0       //ADC����FIFO�Ĵ���
#define ADC_FIFO_DATA_MSK           (0xFFF << ADC_FIFO_DATA_POS)

#define ADC_FIFO_NUM_POS            12      //ADC����FIFO��Ӧ��ͨ�����
#define ADC_FIFO_NUM_MSK            (0x0F << ADC_FIFO_NUM_POS)


#define ADC_EXTTRIG_PWMPLUS0_TRIG0_POS   0       //ѡ��PWMPLUS0_TRIG0����ADC����
#define ADC_EXTTRIG_PWMPLUS0_TRIG0_MSK   (0x01 << ADC_EXTTRIG_PWMPLUS0_TRIG0_POS)

#define ADC_EXTTRIG_PWMPLUS0_TRIG1_POS   1       //ѡ��PWMPLUS0_TRIG1����ADC����
#define ADC_EXTTRIG_PWMPLUS0_TRIG1_MSK   (0x01 << ADC_EXTTRIG_PWMPLUS0_TRIG1_POS)

#define ADC_EXTTRIG_PWMPLUS0_TRIG2_POS   2       //ѡ��PWMPLUS0_TRIG2����ADC���� 
#define ADC_EXTTRIG_PWMPLUS0_TRIG2_MSK   (0x01 << ADC_EXTTRIG_PWMPLUS0_TRIG2_POS)

#define ADC_EXTTRIG_PWMPLUS0_TRIG3_POS   3       //ѡ��PWMPLUS0_TRIG3����ADC����
#define ADC_EXTTRIG_PWMPLUS0_TRIG3_MSK   (0x01 << ADC_EXTTRIG_PWMPLUS0_TRIG3_POS)

#define ADC_EXTTRIG_PWMPLUS1_TRIG0_POS   4       //ѡ��PWMPLUS1_TRIG0����ADC����
#define ADC_EXTTRIG_PWMPLUS1_TRIG0_MSK   (0x01 << ADC_EXTTRIG_PWMPLUS1_TRIG0_POS)

#define ADC_EXTTRIG_PWMPLUS1_TRIG1_POS   5       //ѡ��PWMPLUS1_TRIG1����ADC����
#define ADC_EXTTRIG_PWMPLUS1_TRIG1_MSK   (0x01 << ADC_EXTTRIG_PWMPLUS1_TRIG1_POS)

#define ADC_EXTTRIG_PWMPLUS1_TRIG2_POS   6       //ѡ��PWMPLUS1_TRIG2����ADC���� 
#define ADC_EXTTRIG_PWMPLUS1_TRIG2_MSK   (0x01 << ADC_EXTTRIG_PWMPLUS1_TRIG2_POS)

#define ADC_EXTTRIG_PWMPLUS1_TRIG3_POS   7       //ѡ��PWMPLUS1_TRIG3����ADC����
#define ADC_EXTTRIG_PWMPLUS1_TRIG3_MSK   (0x01 << ADC_EXTTRIG_PWMPLUS1_TRIG3_POS)

#define ADC_EXTTRIG_TIMPLUS0_LOW_POS     8       //ѡ��TIMERPLUS0_LOW����ADC����
#define ADC_EXTTRIG_TIMPLUS0_LOW_MSK     (0x01 << ADC_EXTTRIG_TIMPLUS0_LOW_POS)

#define ADC_EXTTRIG_TIMPLUS0_HIGH_POS    9       //ѡ��TIMERPLUS0_HIGH����ADC����
#define ADC_EXTTRIG_TIMPLUS0_HIGH_MSK    (0x01 << ADC_EXTTRIG_TIMPLUS0_HIGH_POS)

#define ADC_EXTTRIG_TIMPLUS1_LOW_POS     10      //ѡ��TIMERPLUS1_LOW����ADC����
#define ADC_EXTTRIG_TIMPLUS1_LOW_MSK     (0x01 << ADC_EXTTRIG_TIMPLUS1_LOW_POS)

#define ADC_EXTTRIG_TIMPLUS1_HIGH_POS    11      //ѡ��TIMERPLUS1_HIGH����ADC����
#define ADC_EXTTRIG_TIMPLUS1_HIGH_MSK    (0x01 << ADC_EXTTRIG_TIMPLUS1_HIGH_POS)


#define ADC_CALIB_OFFSET_POS        0       //ADC����У׼OFFSET
#define ADC_CALIB_OFFSET_MSK        (0xFF << ADC_CALIB_OFFSET_POS)

#define ADC_CALIB_OFFSET_VALID_POS  16      //ADC����У׼OFFSET�����Ƿ���Ч
#define ADC_CALIB_OFFSET_VALID_MSK  (0xFF << ADC_CALIB_OFFSET_VALID_POS)


#define ADC_CALIB_KD_POS            0       //ADC����У׼KD
#define ADC_CALIB_KD_MSK            (0x3FF << ADC_CALIB_KD_POS)

#define ADC_CALIB_KD_VALID_POS      16      //ADC����У׼KD�����Ƿ���Ч
#define ADC_CALIB_KD_VALID_MSK      (0xFF << ADC_CALIB_KD_VALID_POS)


typedef struct {
	__IO uint32_t CFG;          //FLASH���üĴ���      
	
	__IO uint32_t ADDR;         //FLASH��ַ�Ĵ���   

	__IO uint32_t WDATA;        //FLASHд���ݼĴ���
	
	__IO uint32_t RDATA;        //FLASH�����ݼĴ���
	
	__IO uint32_t START;        //FLASH�����Ĵ���
	
	__IO uint32_t STATE;        //FLASH״̬�Ĵ���  
	
	__IO uint32_t LOCK;         //FLASH�������ƼĴ���

	__IO uint32_t UNLOCK; 	    //FLASH�������ƼĴ���
	
	__IO uint32_t MASK;         //FLASH���ο��ƼĴ���

	__IO uint32_t ERASETIME;    //FLASH����ʱ��������üĴ���
	
	__IO uint32_t PROGTIME;     //FLASH���ʱ��������üĴ���
	
} FLASH_TypeDef;


#define FLASH_CFG_CLK_WAIT_POS      0       //FLASH������ģʽѡ��
#define FLASH_CFG_CLK_WAIT_MSK      (0x01 << FLASH_CFG_CLK_WAIT_POS)

#define FLASH_CFG_NVR_SEL_POS       1       //FLASH MAIN����NVR��ѡ��
#define FLASH_CFG_NVR_SEL_MSK       (0x01 << FLASH_CFG_NVR_SEL_POS)

#define FLASH_CFG_MODE_POS          2       //FLASH ����ģʽ����
#define FLASH_CFG_MODE_MSK          (0x07 << FLASH_CFG_MODE_POS)

#define FLASH_CFG_DEEP_PD_POS       31       //FLASH����DEEP POWER DOWNģʽ
#define FLASH_CFG_DEEP_PD_MSK       ((uint32_t)0x01 << FLASH_CFG_DEEP_PD_POS)


#define FLASH_ADDR_POS              0        //��̻��߲�����ַ�Ĵ���  ����Ϊ��λ
#define FLASH_ADDR_MSK              (0x3FFF << FLASH_ADDR_POS)


#define FLASH_START_EN_POS          0        //������������λ
#define FLASH_START_EN_MSK          (0x01 << FLASH_START_EN_POS)


#define FLASH_STATE_INITBUSY_POS    0        //FLASH��ʼ��æ��־
#define FLASH_STATE_INITBUSY_MSK    (0x01 << FLASH_STATE_INITBUSY_POS)

#define FLASH_STATE_BUSY_POS        1        //FLASHæ��־
#define FLASH_STATE_BUSY_MSK        (0x01 << FLASH_STATE_BUSY_POS)

#define FLASH_STATE_BUFEMPTY_POS    2        //FLASH������ݻ���Ĵ����ձ�־
#define FLASH_STATE_BUFEMPTY_MSK    (0x01 << FLASH_STATE_BUFEMPTY_POS)


#define FLASH_LOCK_POS              0        //FLASH�������ƼĴ���   д��0x55��������FLASH
#define FLASH_LOCK_MSK              (0xFF << FLASH_LOCK_POS)


#define FLASH_UNLOCK_POS            0        //FLASH�������ƼĴ���   д��0xAA���ɽ���FLASH
#define FLASH_UNLOCK_MSK            (0xFF << FLASH_UNLOCK_POS)


#define FLASH_MASK_SEL_POS          0        //MASKѡ��
#define FLASH_MASK_SEL_MSK          (0x03 << FLASH_MASK_SEL_POS)

#define FLASH_MASK_LOCK_POS         2        //MASKѡ����������λ
#define FLASH_MASK_LOCK_MSK         (0x01 << FLASH_MASK_LOCK_POS)


#define FLASH_ERASETIME_TERASE_POS  0
#define FLASH_ERASETIME_TERASE_MSK  (0x7FFFF << FLASH_ERASETIME_TERASE_POS)

#define FLASH_ERASETIME_TRCV_POS    19
#define FLASH_ERASETIME_TRCV_MSK    (0xFFFF << FLASH_ERASETIME_TRCV_POS)


#define FLASH_PROGTIME_TPROG_POS    0
#define FLASH_PROGTIME_TPROG_MSK    (0x7FFF << FLASH_PROGTIME_TPROG_POS)

#define FLASH_PROGTIME_TPGS_POS     11
#define FLASH_PROGTIME_TPGS_MSK     (0x7FFF << FLASH_PROGTIME_TPGS_POS)


typedef struct {
	__IO uint32_t CR;          //CRC���ƼĴ���
	
	__IO uint32_t IV;          //CRC��ʼֵ�Ĵ���
	
	__IO uint32_t DATAIN;      //CRC�������ݼĴ���
	
	__IO uint32_t DATAOUT;     //CRC������ݼĴ���
	
} CRC_TypeDef;


#define CRC_CR_EN_POS               0      //CRCʹ��
#define CRC_CR_EN_MSK               (0x01 << CRC_CR_EN_POS)

#define CRC_CR_INPUT_REV_POS        1      //CRC���������Ƿ�ȡ��
#define CRC_CR_INPUT_REV_MSK        (0x01 << CRC_CR_INPUT_REV_POS)

#define CRC_CR_INPUT_INV_POS        2      //CRC�������ݷ�ת�Ĵ���
#define CRC_CR_INPUT_INV_MSK        (0x03 << CRC_CR_INPUT_INV_POS)

#define CRC_CR_OUTPUT_REV_POS       4      //CRC��������Ƿ�ȡ��
#define CRC_CR_OUTPUT_REV_MSK       (0x01 << CRC_CR_OUTPUT_REV_POS)

#define CRC_CR_OUTPUT_INV_POS       5      //CRC������ݷ�ת�Ĵ���
#define CRC_CR_OUTPUT_INV_MSK       (0x03 << CRC_CR_OUTPUT_INV_POS)

#define CRC_CR_DATA_WIDTH_POS       7      //CRC����������Чλ���Ĵ���
#define CRC_CR_DATA_WIDTH_MSK       (0x03 << CRC_CR_DATA_WIDTH_POS)

#define CRC_CR_SEL_POS              9      //CRC�㷨ѡ��Ĵ���
#define CRC_CR_SEL_MSK              (0x03 << CRC_CR_SEL_POS)



typedef struct {
	__IO uint32_t CTR;             //DMA���ƼĴ���          
	
	__IO uint32_t INTEN;           //DMA�ж�ʹ�ܼĴ���         
	
	__IO uint32_t INTST;           //DMA�ж�״̬�Ĵ��� 
	
	uint32_t RESERVED1[(0x100 - 0x0C)/4];
	
	struct {
		__IO uint32_t CH_CTR;      //ͨ�����ƼĴ���
		
		__IO uint32_t CH_MODE;     //ͨ��ģʽ�Ĵ��� 
		
		__IO uint32_t CH_MSADDR;   //ͨ��Դ��ַ�Ĵ���
		
		__IO uint32_t CH_MDADDR;   //ͨ��Ŀ�ĵ�ַ�Ĵ���	
		
		__IO uint32_t CH_ST;       //ͨ��״̬�Ĵ���
		
		uint32_t RESERVED2[3];
	} CH[4];
	
} DMA_TypeDef;


#define DMA_CTR_EN_POS              0    //DMAʹ��    1  ʹ��  0 ����
#define DMA_CTR_EN_MSK              (0x01 << DMA_CTR_EN_POS)


#define DMA_INTEN_CH0_TC_EN_POS     0    //DMAͨ��0��������ж�ʹ��
#define DMA_INTEN_CH0_TC_EN_MSK     (0x01 << DMA_INTEN_CH0_TC_EN_POS)

#define DMA_INTEN_CH1_TC_EN_POS     1    //DMAͨ��1��������ж�ʹ��
#define DMA_INTEN_CH1_TC_EN_MSK     (0x01 << DMA_INTEN_CH1_TC_EN_POS)

#define DMA_INTEN_CH2_TC_EN_POS     2    //DMAͨ��2��������ж�ʹ��
#define DMA_INTEN_CH2_TC_EN_MSK     (0x01 << DMA_INTEN_CH2_TC_EN_POS)

#define DMA_INTEN_CH3_TC_EN_POS     3    //DMAͨ��3��������ж�ʹ��
#define DMA_INTEN_CH3_TC_EN_MSK     (0x01 << DMA_INTEN_CH3_TC_EN_POS)

#define DMA_INTEN_CH0_THC_EN_POS    8    //DMAͨ��0����һ������ж�ʹ�� 
#define DMA_INTEN_CH0_THC_EN_MSK    (0x01 << DMA_INTEN_CH0_THC_EN_POS)

#define DMA_INTEN_CH1_THC_EN_POS    9    //DMAͨ��1����һ������ж�ʹ�� 
#define DMA_INTEN_CH1_THC_EN_MSK    (0x01 << DMA_INTEN_CH1_THC_EN_POS)

#define DMA_INTEN_CH2_THC_EN_POS    10   //DMAͨ��2����һ������ж�ʹ�� 
#define DMA_INTEN_CH2_THC_EN_MSK    (0x01 << DMA_INTEN_CH2_THC_EN_POS)

#define DMA_INTEN_CH3_THC_EN_POS    11   //DMAͨ��3����һ������ж�ʹ�� 
#define DMA_INTEN_CH3_THC_EN_MSK    (0x01 << DMA_INTEN_CH3_THC_EN_POS)


#define DMA_INTST_CH0_TC_ST_POS     0    //DMAͨ��0��������ж�״̬
#define DMA_INTST_CH0_TC_ST_MSK     (0x01 << DMA_INTST_CH0_TC_ST_POS)

#define DMA_INTST_CH1_TC_ST_POS     1    //DMAͨ��1��������ж�״̬
#define DMA_INTST_CH1_TC_ST_MSK     (0x01 << DMA_INTST_CH1_TC_ST_POS)

#define DMA_INTST_CH2_TC_ST_POS     2    //DMAͨ��2��������ж�״̬
#define DMA_INTST_CH2_TC_ST_MSK     (0x01 << DMA_INTST_CH2_TC_ST_POS)

#define DMA_INTST_CH3_TC_ST_POS     3    //DMAͨ��3��������ж�״̬
#define DMA_INTST_CH3_TC_ST_MSK     (0x01 << DMA_INTST_CH3_TC_ST_POS)

#define DMA_INTST_CH0_THC_ST_POS    8    //DMAͨ��0����һ������ж�״̬
#define DMA_INTST_CH0_THC_ST_MSK    (0x01 << DMA_INTST_CH0_THC_ST_POS)

#define DMA_INTST_CH1_THC_ST_POS    9    //DMAͨ��1����һ������ж�״̬
#define DMA_INTST_CH1_THC_ST_MSK    (0x01 << DMA_INTST_CH1_THC_ST_POS)

#define DMA_INTST_CH2_THC_ST_POS    10   //DMAͨ��2����һ������ж�״̬
#define DMA_INTST_CH2_THC_ST_MSK    (0x01 << DMA_INTST_CH2_THC_ST_POS)

#define DMA_INTST_CH3_THC_ST_POS    11   //DMAͨ��3����һ������ж�״̬
#define DMA_INTST_CH3_THC_ST_MSK    (0x01 << DMA_INTST_CH3_THC_ST_POS)


#define DMA_CH_CTR_EN_POS            0    //DMAͨ��ʹ��
#define DMA_CH_CTR_EN_MSK            (0x01 << DMA_CH_CTR_EN_POS)

#define DMA_CH_CTR_LENTH_POS         1    //DMAͨ����������    �����Դ���4096
#define DMA_CH_CTR_LENTH_MSK         (0xFFF << DMA_CH_CTR_LENTH_POS)

#define DMA_CH_CTR_LOOP_POS          13  //DMAͨ��ѭ����ʽ����λ   0 ����ģʽ  1 ѭ��ģʽ
#define DMA_CH_CTR_LOOP_MSK          (0x01 << DMA_CH_CTR_LOOP_POS)

#define DMA_CH_CTR_PRI_POS           14    //DMAͨ�����ȼ�   00 ��  01  ��  10 ��  11 ���
#define DMA_CH_CTR_PRI_MSK           (0x03 << DMA_CH_CTR_PRI_POS)

#define DMA_CH_CTR_SWREQ_POS         16    //DMAͨ�������ʽ������   ������Դ��ַ��Ϊ�洢�豸ʱ����
#define DMA_CH_CTR_SWREQ_MSK         (0x01 << DMA_CH_CTR_SWREQ_POS)


#define DMA_CH_MODE_MS_ADDR_POS      0    //DMAͨ��Դ��ַ���ַ�仯��ʽѡ��   0  ��ַ����  1  ��ַ����
#define DMA_CH_MODE_MS_ADDR_MSK      (0x01 << DMA_CH_MODE_MS_ADDR_POS)

#define DMA_CH_MODE_MS_SIZE_POS      1    //DMAͨ��Դ��ַ�����ߴ�����       00  8bits  01 16bits   10 32bits  11 ����
#define DMA_CH_MODE_MS_SIZE_MSK      (0x03 << DMA_CH_MODE_MS_SIZE_POS)

#define DMA_CH_MODE_MS_SEL_POS       3    //DMAͨ��Դ��ַ������ѡ��           000  RAM   001--111  ��������  
#define DMA_CH_MODE_MS_SEL_MSK       (0x07 << DMA_CH_MODE_MS_SEL_POS)

#define DMA_CH_MODE_MD_ADDR_POS      8    //DMAͨ��Ŀ�ĵ�ַ���ַ�仯��ʽѡ��   0  ��ַ����  1  ��ַ����
#define DMA_CH_MODE_MD_ADDR_MSK      (0x01 << DMA_CH_MODE_MD_ADDR_POS)

#define DMA_CH_MODE_MD_SIZE_POS      9    //DMAͨ��Ŀ�ĵ�ַ�����ߴ�����       00  8bits  01 16bits   10 32bits  11 ����
#define DMA_CH_MODE_MD_SIZE_MSK      (0x03 << DMA_CH_MODE_MD_SIZE_POS)

#define DMA_CH_MODE_MD_SEL_POS       11    //DMAͨ��Ŀ�ĵ�ַ������ѡ��          000  RAM   001--111  ��������  
#define DMA_CH_MODE_MD_SEL_MSK       (0x07 << DMA_CH_MODE_MD_SEL_POS)


#define DMA_CH_ST_CUR_LENTH_POS      0    //DMAͨ����ǰ�������
#define DMA_CH_ST_CUR_LENTH_MSK      (0xFFF << DMA_CH_ST_CUR_LENTH_POS)


typedef struct {
	__IO uint32_t CR;              //���ƼĴ���
            
	__IO uint32_t SR;              //״̬�Ĵ���

	__IO uint32_t DINR;            //�������ݼĴ���

	__IO uint32_t DOUTR;           //������ݼĴ���

	__IO uint32_t KEYR0;           //��Կ�Ĵ���0
	
	__IO uint32_t KEYR1;           //��Կ�Ĵ���1
	
	__IO uint32_t KEYR2;           //��Կ�Ĵ���2
	
	__IO uint32_t KEYR3;           //��Կ�Ĵ���3
	
	__IO uint32_t IVR0;            //������ʼ��Ĵ���0
	
	__IO uint32_t IVR1;            //������ʼ��Ĵ���1
	
	__IO uint32_t IVR2;            //������ʼ��Ĵ���2
	
	__IO uint32_t IVR3;            //������ʼ��Ĵ���3
	
} AES128_TypeDef;


#define AES128_CR_EN_POS               0          //AES128ʹ���ź�
#define AES128_CR_EN_MSK               (0x01 << AES128_CR_EN_POS)

#define AES128_CR_DATATYPE_POS         1          //AES128��������ѡ��
#define AES128_CR_DATATYPE_MSK         (0x03 << AES128_CR_DATATYPE_POS)

#define AES128_CR_MODE_POS             3          //AES128ģʽѡ��
#define AES128_CR_MODE_MSK             (0x03 << AES128_CR_MODE_POS)

#define AES128_CR_CHMODE_POS           5          //AES128����ģʽѡ��
#define AES128_CR_CHMODE_MSK           (0x03 << AES128_CR_CHMODE_POS)

#define AES128_CR_CCFC_POS             7          //AES128������ɱ�־���
#define AES128_CR_CCFC_MSK             (0x01 << AES128_CR_CCFC_POS)

#define AES128_CR_ERRC_POS             8          //AES128�����־���
#define AES128_CR_ERRC_MSK             (0x01 << AES128_CR_ERRC_POS)

#define AES128_SR_CCF_POS              0          //AES128������ɱ�־
#define AES128_SR_CCF_MSK              (0x01 << AES128_SR_CCF_POS)

#define AES128_SR_RDERR_POS            1          //AES128��ȡ�����־
#define AES128_SR_RDERR_MSK            (0x01 << AES128_SR_RDERR_POS)

#define AES128_SR_WRERR_POS            2          //AES128д������־
#define AES128_SR_WRERR_MSK            (0x01 << AES128_SR_WRERR_POS)





/******************************************************************************/
/*						 Peripheral memory map							  */
/******************************************************************************/
#define RAM_BASE		    ((uint32_t)0x20000000)
#define AHB_BASE			((uint32_t)0x40000000)
#define APB1_BASE		 	((uint32_t)0x40060000)
#define APB2_BASE			((uint32_t)0x400B0000)

/* AHB Peripheral memory map */
#define SYS_BASE			(AHB_BASE + 0x0000)
#define PMU_BASE			(AHB_BASE + 0x0800)
#define DMA_BASE			(AHB_BASE + 0x1000)
#define CRC_BASE			(AHB_BASE + 0x3000)

/* APB1 Peripheral memory map */
#define GPIOA_BASE		    (APB1_BASE + 0x0000)
#define GPIOB_BASE		    (APB1_BASE + 0x0800)
#define GPIOC_BASE		    (APB1_BASE + 0x1000)

#define TIMBASE0_BASE       (APB1_BASE + 0x4000)
#define TIMBASE1_BASE       (APB1_BASE + 0x4800)
#define TIMBASE2_BASE       (APB1_BASE + 0x5000)

#define TIMPLUS0_BASE       (APB1_BASE + 0x7000)
#define TIMPLUS1_BASE       (APB1_BASE + 0x7800)

#define RTC_BASE		    (APB1_BASE + 0x9000)

#define IWDT_BASE		    (APB1_BASE + 0xA000)
#define WWDT_BASE		    (APB1_BASE + 0xA800)

#define UART0_BASE		    (APB1_BASE + 0xB000)
#define UART1_BASE		    (APB1_BASE + 0xB800)
#define UART2_BASE		    (APB1_BASE + 0xC000)

#define FLASH_CTRL_BASE		(APB1_BASE + 0xF000)

/* APB2 Peripheral memory map */
#define PORT_BASE			(APB2_BASE + 0x0000)

#define PWMBASE0_BASE		(APB2_BASE + 0x1000)
#define PWMBASE1_BASE		(APB2_BASE + 0x1800)

#define PWMPLUS0_BASE		(APB2_BASE + 0x4000)
#define PWMPLUS1_BASE		(APB2_BASE + 0x4800)

#define SPI0_BASE			(APB2_BASE + 0x8000)
#define SPI1_BASE			(APB2_BASE + 0x8800)

#define IIC0_BASE			(APB2_BASE + 0x9000)
#define IIC1_BASE			(APB2_BASE + 0x9800)

#define ADC_BASE			(APB2_BASE + 0xA000)

#define AES128_BASE		    (APB2_BASE + 0xD000)

/******************************************************************************/
/*						 Peripheral declaration							 */
/******************************************************************************/
#define SYS					((SYS_TypeDef  *) SYS_BASE)

#define PMU 				((PMU_TypeDef  *) PMU_BASE)

#define DMA				    ((DMA_TypeDef*) DMA_BASE)

#define CRC				    ((CRC_TypeDef*) CRC_BASE)

#define GPIOA				((GPIO_TypeDef *) GPIOA_BASE)

#define GPIOB				((GPIO_TypeDef *) GPIOB_BASE)

#define GPIOC				((GPIO_TypeDef *) GPIOC_BASE)

#define TIMBASE0			((TIMBASE_TypeDef *) TIMBASE0_BASE)

#define TIMBASE1			((TIMBASE_TypeDef *) TIMBASE1_BASE)

#define TIMBASE2			((TIMBASE_TypeDef *) TIMBASE2_BASE)

#define TIMPLUS0			((TIMPLUS_TypeDef *) TIMPLUS0_BASE)

#define TIMPLUS1			((TIMPLUS_TypeDef *) TIMPLUS1_BASE)

#define RTC				    ((RTC_TypeDef  *) RTC_BASE)

#define IWDT				((IWDT_TypeDef  *) IWDT_BASE)

#define WWDT				((WWDT_TypeDef  *) WWDT_BASE)

#define UART0				((UART_TypeDef *) UART0_BASE)

#define UART1				((UART_TypeDef *) UART1_BASE)

#define UART2				((UART_TypeDef *) UART2_BASE)

#define FLASH               ((FLASH_TypeDef  *) FLASH_CTRL_BASE)


#define PORT				((PORT_TypeDef *) PORT_BASE)

#define PWMBASE0			((PWMBASE_TypeDef  *) PWMBASE0_BASE)

#define PWMBASE1			((PWMBASE_TypeDef  *) PWMBASE1_BASE)

#define PWMPLUS0			((PWMPLUS_TypeDef  *) PWMPLUS0_BASE)

#define PWMPLUS1			((PWMPLUS_TypeDef  *) PWMPLUS1_BASE)

#define SPI0				((SPI_TypeDef  *) SPI0_BASE)

#define SPI1				((SPI_TypeDef  *) SPI1_BASE)

#define IIC0                ((IIC_TypeDef  *) IIC0_BASE)

#define IIC1                ((IIC_TypeDef  *) IIC1_BASE)

#define ADC				    ((ADC_TypeDef  *) ADC_BASE)

#define AES128			    ((AES128_TypeDef  *) AES128_BASE)


#include "system_DP32G030.h"
#include "DP32G030_port.h"
#include "DP32G030_gpio.h"
#include "DP32G030_flash.h"
#include "DP32G030_conf.h"
#include "DP32G030_uart.h"
#include "DP32G030_exti.h"
#include "DP32G030_spi.h"
#include "DP32G030_iic.h"
#include "DP32G030_pwmbase.h"
#include "DP32G030_pwmplus.h"
#include "DP32G030_timerbase.h"
#include "DP32G030_timerplus.h"
#include "DP32G030_iwdt.h"
#include "DP32G030_wwdt.h"
#include "DP32G030_crc.h"
#include "DP32G030_rtc.h"
#include "DP32G030_dma.h"
#include "DP32G030_aes.h"
#include "DP32G030_power.h"
#include "DP32G030_adc.h"
#include "DP32G030_cmp.h"
#include "DP32G030_opa.h"
#endif //__DP32G030_H__
