#ifndef __DP32G030_PORT_H__
#define __DP32G030_PORT_H__          

#include "DP32G030.h"


typedef struct
{
	uint8_t Port;         //�˿�       
    uint8_t Pin;          //���ź�                              
    uint8_t Func;         //����
	uint8_t Input_En;     //����ʹ��     
} PORT_InitTypeDef;


typedef enum
{ 
	OUT_CURRENT_5MA  =  0x00,    // �������5MA
	OUT_CURRENT_10MA =  0x01,    // �������10MA
	OUT_CURRENT_15MA =  0x02,    // �������15MA
	OUT_CURRENT_20MA =  0x03,    // �������20MA
} OutCurrent_TypeDef;

typedef enum
{ 
	INPUT_HYS_LOW =   0x00,      // ���������  
	INPUT_HYS_HIGH =  0x01,      // ���������  
} InputHys_TypeDef;


typedef struct
{
	OutCurrent_TypeDef   PortA_Out_Cur;          //PORTA����������
	OutCurrent_TypeDef   PortB_Out_Cur;          //PORTB����������
	OutCurrent_TypeDef   PortC_Out_Cur;          //PORTC����������
	InputHys_TypeDef     InputHys;               //PORT��������͵ȼ�
} PORT_CFGTypeDef;

//����  PORTA  
#define IS_PORT_ALL(PORT)           (((PORT) == PORTA) || ((PORT) == PORTB) || ((PORT) == PORTC))

//���Զ˿ڹ���
#define IS_PORT_FUNC(PORT_FUNC)     ((PORT_FUNC) < 8)

//��������ʹ��
#define IS_INPUT_EN(INPUT_EN)       (((INPUT_EN) == ENABLE) || ((INPUT_EN) == DISABLE))

//������������
#define IS_OUT_CURRENT(OUT_CURRENT) (((OUT_CURRENT) == OUT_CURRENT_5MA ) || ((OUT_CURRENT) == OUT_CURRENT_10MA) || \
                                     ((OUT_CURRENT) == OUT_CURRENT_15MA) || ((OUT_CURRENT) == OUT_CURRENT_20MA) )

//����������͵ȼ�
#define IS_INPUT_HYS(INPUT_HYS)     (((INPUT_HYS) == INPUT_HYS_LOW) || ((INPUT_HYS) == INPUT_HYS_HIGH))


#define PORTA	                   0             //�˿�A
#define PORTB	                   1             //�˿�B
#define PORTC	                   2             //�˿�C


#define PORTA_PIN0_GPIO		 	   0             //PORTA0����ΪGPIOA0
#define PORTA_PIN0_PWMP1_PULSE0    1             //PORTA0����ΪPWMPLUS1��PULSE0
#define PORTA_PIN0_PWMP0_PULSE1    2             //PORTA0����ΪPWMPLUS0��PULSE1
#define PORTA_PIN0_TM	 	       3             //PORTA0����ΪRTC��1/2���
#define PORTA_PIN0_WAKEUP0	 	   4             //PORTA0����Ϊ��������0

#define PORTA_PIN1_GPIO			   0             //PORTA1����ΪGPIOA1
#define PORTA_PIN1_XTAL_XI		   1             //PORTA1����ΪXTAL_XI

#define PORTA_PIN2_GPIO			   0             //PORTA2����ΪGPIOA2
#define PORTA_PIN2_XTAL_XO		   1             //PORTA2����ΪXTAL_XO

#define PORTA_PIN3_GPIO			   0             //PORTA3����ΪGPIOA3
#define PORTA_PIN3_CMP0_VN		   1             //PORTA3����Ϊ�Ƚ���0��N������
#define PORTA_PIN3_XTAH_XI		   2             //PORTA3����ΪXTAH_XI

#define PORTA_PIN4_GPIO			   0             //PORTA4����ΪGPIOA4
#define PORTA_PIN4_CMP0_VP		   1             //PORTA4����Ϊ�Ƚ���0��P������
#define PORTA_PIN4_XTAH_XO		   2             //PORTA4����ΪXTAH_XO

#define PORTA_PIN5_GPIO			   0             //PORTA5����ΪGPIOA5
#define PORTA_PIN5_UART1_CTS	   1             //PORTA5����Ϊ����1��CTS����
#define PORTA_PIN5_PWMP1_PULSE1    2             //PORTA5����ΪPWMPLUS1��PULSE1
#define PORTA_PIN5_TIMP1_IN0       3             //PORTA5����ΪTIMPLUS1������0
#define PORTA_PIN5_TIMP1_OUT_L     4             //PORTA5����ΪTIMPLUS1�ĵ�16λ��ʱ�������
#define PORTA_PIN5_WAKEUP1	 	   5             //PORTA5����Ϊ��������1
#define PORTA_PIN5_ADC_CH0	       7             //PORTA5����ΪADC��ͨ��0

#define PORTA_PIN6_GPIO			   0             //PORTA6����ΪGPIOA6
#define PORTA_PIN6_UART1_RTS	   1             //PORTA6����Ϊ����1��RTS����
#define PORTA_PIN6_TIMP1_IN1       2             //PORTA6����ΪTIMPLUS1������1
#define PORTA_PIN6_TIMP1_OUT_H     3             //PORTA6����ΪTIMPLUS1�ĸ�16λ��ʱ�������
#define PORTA_PIN6_ADC_CH1	       4             //PORTA6����ΪADC��ͨ��1
#define PORTA_PIN6_OPA0_OUT		   5             //PORTA6����Ϊ����Ŵ���0���������

#define PORTA_PIN7_GPIO			   0             //PORTA7����ΪGPIOA7
#define PORTA_PIN7_UART1_TX	       1             //PORTA7����Ϊ����1�ķ�������
#define PORTA_PIN7_TIMP0_IN0       2             //PORTA7����ΪTIMPLUS0������0
#define PORTA_PIN7_TIMP0_OUT_L     3             //PORTA7����ΪTIMPLUS0�ĵ�16λ��ʱ�������
#define PORTA_PIN7_ADC_CH2	       4             //PORTA7����ΪADC��ͨ��2
#define PORTA_PIN7_OPA0_VP		   5             //PORTA7����Ϊ����Ŵ���0��P������

#define PORTA_PIN8_GPIO		 	   0             //PORTA8����ΪGPIOA8
#define PORTA_PIN8_UART1_RX	       1             //PORTA8����Ϊ����1�Ľ�������
#define PORTA_PIN8_TIMP0_IN1       2             //PORTA8����ΪTIMPLUS0������1
#define PORTA_PIN8_TIMP0_OUT_H     3             //PORTA8����ΪTIMPLUS0�ĸ�16λ��ʱ�������
#define PORTA_PIN8_ADC_CH3	       4             //PORTA8����ΪADC��ͨ��3
#define PORTA_PIN8_OPA0_VN		   5             //PORTA8����Ϊ����Ŵ���0��N������

#define PORTA_PIN9_GPIO			   0             //PORTA9����ΪGPIOA9
#define PORTA_PIN9_SPI0_SSN	       1             //PORTA9����ΪSPI0��Ƭѡ
#define PORTA_PIN9_TIMP1_IN0       2             //PORTA9����ΪTIMPLUS1������0
#define PORTA_PIN9_TIMP1_OUT_L     3             //PORTA9����ΪTIMPLUS1�ĵ�16λ��ʱ�������
#define PORTA_PIN9_TM	           4             //PORTA9����ΪRTC��1/2���
#define PORTA_PIN9_ADC_CH4	       5             //PORTA9����ΪADC��ͨ��4
#define PORTA_PIN9_CMP1_VN		   6             //PORTA9����Ϊ�Ƚ���1��N������

#define PORTA_PIN10_GPIO		   0             //PORTA10����ΪGPIOA10
#define PORTA_PIN10_SPI0_CLK       1             //PORTA10����ΪSPI0��ʱ��
#define PORTA_PIN10_ADC_CH5	       2             //PORTA10����ΪADC��ͨ��5
#define PORTA_PIN10_CMP1_VP		   3             //PORTA10����Ϊ�Ƚ���1��P������

#define PORTA_PIN11_GPIO		   0             //PORTA11����ΪGPIOA11
#define PORTA_PIN11_SPI0_MISO	   1             //PORTA11����ΪSPI0������ӳ�
#define PORTA_PIN11_PWMB0_CH0      2             //PORTA11����ΪPWMBASE0��ͨ��0
#define PORTA_PIN11_PWMP0_BRK0     3             //PORTA11����ΪPWMPLUS0��BREAK0
#define PORTA_PIN11_TIMP1_IN1      4             //PORTA11����ΪTIMPLUS1������1
#define PORTA_PIN11_TIMP1_OUT_H    5             //PORTA11����ΪTIMPLUS1�ĸ�16λ��ʱ�������
#define PORTA_PIN11_ADC_CH6	       6             //PORTA11����ΪADC��ͨ��6

#define PORTA_PIN12_GPIO		   0             //PORTA12����ΪGPIOA12
#define PORTA_PIN12_SPI0_MOSI	   1             //PORTA12����ΪSPI0����������
#define PORTA_PIN12_PWMB0_CH1      2             //PORTA12����ΪPWMBASE0��ͨ��1
#define PORTA_PIN12_PWMP0_CH0N     3             //PORTA12����ΪPWMPLUS0��ͨ��0N
#define PORTA_PIN12_TIMP0_IN0      4             //PORTA12����ΪTIMPLUS0������0
#define PORTA_PIN12_TIMP0_OUT_L    5             //PORTA12����ΪTIMPLUS0�ĵ�16λ��ʱ�������
#define PORTA_PIN12_ADC_CH7	       6             //PORTA12����ΪADC��ͨ��7

#define PORTA_PIN13_GPIO		   0             //PORTA13����ΪGPIOA13
#define PORTA_PIN13_PWMB0_CH2      1             //PORTA13����ΪPWMBASE0��ͨ��2
#define PORTA_PIN13_PWMP0_CH1N     2             //PORTA13����ΪPWMPLUS0��ͨ��1N
#define PORTA_PIN13_TIMP0_IN1      3             //PORTA13����ΪTIMPLUS0������1
#define PORTA_PIN13_TIMP0_OUT_H    4             //PORTA13����ΪTIMPLUS0�ĸ�16λ��ʱ�������
#define PORTA_PIN13_ADC_CH8	       5             //PORTA13����ΪADC��ͨ��8

#define PORTA_PIN14_GPIO		   0             //PORTA14����ΪGPIOA14
#define PORTA_PIN14_PWMB1_CH0      1             //PORTA14����ΪPWMBASE1��ͨ��0
#define PORTA_PIN14_PWMP0_CH2N     2             //PORTA14����ΪPWMPLUS0��ͨ��2N
#define PORTA_PIN14_TIMP1_IN0      3             //PORTA14����ΪTIMPLUS1������0
#define PORTA_PIN14_TIMP1_OUT_L    4             //PORTA14����ΪTIMPLUS1�ĵ�16λ��ʱ�������
#define PORTA_PIN14_ADC_CH9	       5             //PORTA14����ΪADC��ͨ��9

#define PORTA_PIN15_GPIO		   0             //PORTA15����ΪGPIOA15
#define PORTA_PIN15_PWMB1_CH1      1             //PORTA15����ΪPWMBASE1��ͨ��1
#define PORTA_PIN15_PWMP0_CH0      2             //PORTA15����ΪPWMPLUS0��ͨ��0
#define PORTA_PIN15_TIMP1_IN1      3             //PORTA15����ΪTIMPLUS1������1
#define PORTA_PIN15_TIMP1_OUT_H    4             //PORTA15����ΪTIMPLUS1�ĸ�16λ��ʱ�������


#define PORTB_PIN0_GPIO		 	   0             //PORTB0����ΪGPIOB0
#define PORTB_PIN0_UART2_TX	       1             //PORTB0����Ϊ����2�ķ�������
#define PORTB_PIN0_IIC0_SCL	       2             //PORTB0����ΪIIC0��ʱ������
#define PORTB_PIN0_PWMB1_CH2       3             //PORTB0����ΪPWMBASE1��ͨ��2
#define PORTB_PIN0_PWMP0_CH1       4             //PORTB0����ΪPWMPLUS0��ͨ��1

#define PORTB_PIN1_GPIO		 	   0             //PORTB1����ΪGPIOB1
#define PORTB_PIN1_UART2_RX	       1             //PORTB1����Ϊ����2�Ľ�������
#define PORTB_PIN1_IIC0_SDA	       2             //PORTB1����ΪIIC0����������
#define PORTB_PIN1_PWMP0_CH2       3             //PORTB1����ΪPWMPLUS0��ͨ��2

#define PORTB_PIN2_GPIO		 	   0             //PORTB2����ΪGPIOB2
#define PORTB_PIN2_SPI1_SSN	       1             //PORTB2����ΪSPI1��Ƭѡ
#define PORTB_PIN2_PWMP0_BRK1      2             //PORTB2����ΪPWMPLUS0��BREAK1
#define PORTB_PIN2_TIMP1_HALL0     3             //PORTB2����ΪTIMPLUS1��HALL0

#define PORTB_PIN3_GPIO		 	   0             //PORTB3����ΪGPIOB3
#define PORTB_PIN3_SPI1_CLK        1             //PORTB3����ΪSPI1��ʱ��
#define PORTB_PIN3_IIC1_SDA	       2             //PORTB3����ΪIIC1����������
#define PORTB_PIN3_PWMP0_CH0N      3             //PORTB3����ΪPWMPLUS0��ͨ��0N
#define PORTB_PIN3_TIMP1_HALL1     4             //PORTB3����ΪTIMPLUS1��HALL1

#define PORTB_PIN4_GPIO		 	   0             //PORTB4����ΪGPIOB4
#define PORTB_PIN4_SPI1_MISO	   1             //PORTB4����ΪSPI1������ӳ�
#define PORTB_PIN4_IIC1_SCL	       2             //PORTB4����ΪIIC1��ʱ������
#define PORTB_PIN4_PWMP1_CH0       3             //PORTB4����ΪPWMPLUS1��ͨ��0
#define PORTB_PIN4_PWMP0_CH1N      4             //PORTB4����ΪPWMPLUS0��ͨ��1N
#define PORTB_PIN4_TIMP1_HALL2     5             //PORTB4����ΪTIMPLUS1��HALL2

#define PORTB_PIN5_GPIO		 	   0             //PORTB5����ΪGPIOB5
#define PORTB_PIN5_SPI1_MOSI	   1             //PORTB5����ΪSPI1����������
#define PORTB_PIN5_PWMP1_CH0N      2             //PORTB5����ΪPWMPLUS1��ͨ��0N
#define PORTB_PIN5_PWMP0_CH2N      3             //PORTB5����ΪPWMPLUS0��ͨ��2N
#define PORTB_PIN5_TIMP0_IN0       4             //PORTB5����ΪTIMPLUS0������0
#define PORTB_PIN5_TIMP0_OUT_L     5             //PORTB5����ΪTIMPLUS0�ĵ�16λ��ʱ�������

#define PORTB_PIN6_GPIO		 	   0             //PORTB6����ΪGPIOB6
#define PORTB_PIN6_PWMP0_CH0       1             //PORTB6����ΪPWMPLUS0��ͨ��0
#define PORTB_PIN6_TIMP0_IN1       2             //PORTB6����ΪTIMPLUS0������1
#define PORTB_PIN6_TIMP0_OUT_H     3             //PORTB6����ΪTIMPLUS0�ĸ�16λ��ʱ�������

#define PORTB_PIN7_GPIO		 	   0             //PORTB7����ΪGPIOB7
#define PORTB_PIN7_SPI0_SSN	       1             //PORTB7����ΪSPI0��Ƭѡ
#define PORTB_PIN7_UART0_TX	       2             //PORTB7����Ϊ����0�ķ�������
#define PORTB_PIN7_IIC0_SCL	       3             //PORTB7����ΪIIC0��ʱ������
#define PORTB_PIN7_PWMP1_BRK0      4             //PORTB7����ΪPWMPLUS1��BREAK0
#define PORTB_PIN7_PWMP0_CH1       5             //PORTB7����ΪPWMPLUS0��ͨ��1

#define PORTB_PIN8_GPIO		 	   0             //PORTB8����ΪGPIOB8
#define PORTB_PIN8_SPI0_CLK        1             //PORTB8����ΪSPI0��ʱ��
#define PORTB_PIN8_UART0_RX	       2             //PORTB8����Ϊ����0�Ľ�������
#define PORTB_PIN8_IIC0_SDA	       3             //PORTB8����ΪIIC0����������
#define PORTB_PIN8_PWMB0_CH0       4             //PORTB8����ΪPWMBASE0��ͨ��0
#define PORTB_PIN8_PWMP1_BRK1      5             //PORTB8����ΪPWMPLUS1��BREAK1
#define PORTB_PIN8_PWMP0_CH2       6             //PORTB8����ΪPWMPLUS0��ͨ��2

#define PORTB_PIN9_GPIO		 	   0             //PORTB9����ΪGPIOB9
#define PORTB_PIN9_SPI0_MISO	   1             //PORTB9����ΪSPI0������ӳ�
#define PORTB_PIN9_UART0_CTS	   2             //PORTB9����Ϊ����0��CTS����
#define PORTB_PIN9_PWMB0_CH1       3             //PORTB9����ΪPWMBASE0��ͨ��1
#define PORTB_PIN9_PWMP1_CH0       4             //PORTB9����ΪPWMPLUS1��ͨ��0
#define PORTB_PIN9_TIMP1_IN1       5             //PORTB9����ΪTIMPLUS1������1
#define PORTB_PIN9_TIMP1_OUT_H     6             //PORTB9����ΪTIMPLUS1�ĸ�16λ��ʱ�������

#define PORTB_PIN10_GPIO		   0             //PORTB10����ΪGPIOB10
#define PORTB_PIN10_SPI0_MOSI	   1             //PORTB10����ΪSPI0����������
#define PORTB_PIN10_UART0_RTS	   2             //PORTB10����Ϊ����0��RTS����
#define PORTB_PIN10_PWMB0_CH2      3             //PORTB10����ΪPWMBASE0��ͨ��2
#define PORTB_PIN10_PWMP1_CH1      4             //PORTB10����ΪPWMPLUS1��ͨ��1
#define PORTB_PIN10_PWMP0_PULSE0   5             //PORTB10����ΪPWMPLUS0��PULSE0
#define PORTB_PIN10_TIMP1_IN0      6             //PORTB10����ΪTIMPLUS1������0
#define PORTB_PIN10_TIMP1_OUT_L    7             //PORTB10����ΪTIMPLUS1�ĵ�16λ��ʱ�������

#define PORTB_PIN11_GPIO		   0             //PORTB11����ΪGPIOB11
#define PORTB_PIN11_SWDIO		   1             //PORTB11����ΪSW���ص�����
#define PORTB_PIN11_PWMP1_CH2      2             //PORTB11����ΪPWMPLUS1��ͨ��2
#define PORTB_PIN11_PWMP0_BRK2     3             //PORTB11����ΪPWMPLUS0��BREAK2

#define PORTB_PIN12_GPIO		   0             //PORTB12����ΪGPIOB12
#define PORTB_PIN12_UART1_TX	   1             //PORT12����Ϊ����1�ķ�������
#define PORTB_PIN12_IIC1_SCL	   2             //PORTB12����ΪIIC1��ʱ������
#define PORTB_PIN12_PWMP1_CH0N     3             //PORTB12����ΪPWMPLUS1��ͨ��0N

#define PORTB_PIN13_GPIO		   0             //PORTB13����ΪGPIOB13
#define PORTB_PIN13_UART1_RX	   1             //PORTB13����Ϊ����1�Ľ�������
#define PORTB_PIN13_IIC1_SDA	   2             //PORTB13����ΪIIC1����������
#define PORTB_PIN13_PWMP1_CH1N     3             //PORTB13����ΪPWMPLUS1��ͨ��1N

#define PORTB_PIN14_GPIO		   0             //PORTB14����ΪGPIOB14
#define PORTB_PIN14_SWCLK		   1             //PORTB14����ΪSW���ص�ʱ��
#define PORTB_PIN14_UART2_TX	   2             //PORTB14����Ϊ����2�ķ�������
#define PORTB_PIN14_PWMP1_CH2N     3             //PORTB14����ΪPWMPLUS1��ͨ��2N

#define PORTB_PIN15_GPIO		   0             //PORTB15����ΪGPIOB15
#define PORTB_PIN15_SPI1_SSN	   1             //PORTB15����ΪSPI1��Ƭѡ
#define PORTB_PIN15_UART2_RX	   2             //PORTB15����Ϊ����2�Ľ�������


#define PORTC_PIN0_GPIO		 	   0             //PORTC0����ΪGPIOC0
#define PORTC_PIN0_SPI1_CLK        1             //PORTC0����ΪSPI1��ʱ��
#define PORTC_PIN0_UART2_CTS	   2             //PORTC0����Ϊ����2��CTS����
#define PORTC_PIN0_PWMB1_CH0       3             //PORTC0����ΪPWMBASE1��ͨ��0

#define PORTC_PIN1_GPIO		 	   0             //PORTC1����ΪGPIOC1
#define PORTC_PIN1_SPI1_MISO	   1             //PORTC1����ΪSPI1������ӳ�
#define PORTC_PIN1_UART2_RTS	   2             //PORTC1����Ϊ����2��RTS����
#define PORTC_PIN1_PWMB1_CH1       3             //PORTC1����ΪPWMBASE1��ͨ��1
#define PORTC_PIN1_TIMP0_IN0       4             //PORTC1����ΪTIMPLUS0������0
#define PORTC_PIN1_TIMP0_OUT_L     5             //PORTC1����ΪTIMPLUS0�ĵ�16λ��ʱ�������

#define PORTC_PIN2_GPIO		 	   0             //PORTC2����ΪGPIOC2
#define PORTC_PIN2_SPI1_MOSI	   1             //PORTC2����ΪSPI1����������
#define PORTC_PIN2_PWMB1_CH2       2             //PORTC2����ΪPWMBASE1��ͨ��2
#define PORTC_PIN2_PWMP1_BRK2      3             //PORTC2����ΪPWMPLUS1��BREAK2
#define PORTC_PIN2_TIMP0_IN1       4             //PORTC2����ΪTIMPLUS0������1
#define PORTC_PIN2_TIMP0_OUT_H     5             //PORTC2����ΪTIMPLUS0�ĸ�16λ��ʱ�������

#define PORTC_PIN3_GPIO		 	   0             //PORTC3����ΪGPIOC3
#define PORTC_PIN3_UART0_TX	       1             //PORTC3����Ϊ����0�ķ�������
#define PORTC_PIN3_IIC0_SCL	       2             //PORTC3����ΪIIC0��ʱ������
#define PORTC_PIN3_PWMP1_CH1N      3             //PORTC3����ΪPWMPLUS1��ͨ��1N
#define PORTC_PIN3_TIMP0_HALL0     4             //PORTC3����ΪTIMPLUS0��HALL0
#define PORTC_PIN3_CMP2_VN		   5             //PORTC3����Ϊ�Ƚ���2��N������

#define PORTC_PIN4_GPIO		 	   0             //PORTC4����ΪGPIOC4
#define PORTC_PIN4_UART0_RX	       1             //PORTC4����Ϊ����0�Ľ�������
#define PORTC_PIN4_IIC0_SDA	       2             //PORTC4����ΪIIC0����������
#define PORTC_PIN4_PWMP1_CH2N      3             //PORTC4����ΪPWMPLUS1��ͨ��2N
#define PORTC_PIN4_TIMP0_HALL1     4             //PORTC4����ΪTIMPLUS0��HALL1
#define PORTC_PIN4_CMP2_VP		   5             //PORTC4����Ϊ�Ƚ���2��P������

#define PORTC_PIN5_GPIO		 	   0             //PORTC5����ΪGPIOC5
#define PORTC_PIN5_TIMP0_HALL2     1             //PORTC5����ΪTIMPLUS0��HALL2
#define PORTC_PIN5_TM	           2             //PORTC5����ΪRTC��1/2���
#define PORTC_PIN5_OPA1_VP		   3             //PORTC5����Ϊ����Ŵ���1��P������


#define PORTC_PIN6_GPIO		 	   0             //PORTC6����ΪGPIOC6
#define PORTC_PIN6_IIC1_SCL	       1             //PORTC6����ΪIIC1��ʱ������
#define PORTC_PIN6_PWMP1_CH1       2             //PORTC6����ΪPWMPLUS1��ͨ��1
#define PORTC_PIN6_TIMP1_IN1       3             //PORTC6����ΪTIMPLUS1������1
#define PORTC_PIN6_TIMP1_OUT_H     4             //PORTC6����ΪTIMPLUS1�ĸ�16λ��ʱ�������
#define PORTC_PIN6_OPA1_VN		   5             //PORTC6����Ϊ����Ŵ���1��N������

#define PORTC_PIN7_GPIO		 	   0             //PORTC7����ΪGPIOC7
#define PORTC_PIN7_IIC1_SDA	       1             //PORTC7����ΪIIC1����������
#define PORTC_PIN7_PWMP1_CH2       2             //PORTC7����ΪPWMPLUS1��ͨ��2
#define PORTC_PIN7_TIMP1_IN0       3             //PORTC7����ΪTIMPLUS1������0
#define PORTC_PIN7_TIMP1_OUT_L     4             //PORTC7����ΪTIMPLUS1�ĵ�16λ��ʱ�������
#define PORTC_PIN7_OPA1_OUT		   5             //PORTC7����Ϊ����Ŵ���1�����
#define PORTC_PIN7_ADC_CH10	       6             //PORTC7����ΪADC��ͨ��10


void PORT_Init(PORT_InitTypeDef* PORT_InitStruct);               //PORT��ʼ������
void PORT_CFG_Init(PORT_CFGTypeDef* PORT_CFGStruct);             //PORT���üĴ�������

#endif //__DP32G030_PORT_H__
