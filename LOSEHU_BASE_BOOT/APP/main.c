#include "delay.h"
#include "key.h"
#include "iap.h"
#include "eeprom.h"
#include "string.h"
#include "port.h"
// void write_to_memory(uint32_t address, uint32_t data) {
//    // ����ַ��ֵת��Ϊָ��
//    uint32_t *target_address = (uint32_t *) address;
//    // ��Ŀ���ַд������
//    *target_address = data;
//    // Ϊ�˱����Ż���ȷ�����벻�ᱻ�Ż���
//    volatile uint32_t read_back = *target_address;
//	 
//}

typedef void (*pFunction)(void);

/* APP flash address */
#define APP_FLASH_ADDR             (0x20000800)

void jump_to_app(void) {
    uint32_t JumpAddress;
    pFunction Jump_To_Application;

    /* ���ջ����ַ�Ƿ�Ϸ� */

    /* ���������жϣ���ֹ����ת�����У��жϸ��ų����쳣 */
    __disable_irq();

    /* �û��������ڶ��� �� Ϊ����ʼ��ַ(��λ��ַ) */
    JumpAddress = *(__IO
    uint32_t *) (APP_FLASH_ADDR + 4);

    /* Initialize user application's Stack Pointer */
    /* ��ʼ��APP��ջָ��(�û��������ĵ�һ�������ڴ��ջ����ַ) */
    __set_MSP(*(__IO
    uint32_t *) APP_FLASH_ADDR);

    /* ����ת�� */
    Jump_To_Application = (pFunction) JumpAddress;

    /* ��ת�� APP */
    Jump_To_Application();

}


void write_to_memory1(uint32_t address, uint32_t *data, size_t length) {
    // ����ַ��ֵת��Ϊָ��
    uint32_t *target_address = (uint32_t *) address;

    // ѭ��д�����ݵ�Ŀ���ַ
    for (size_t i = 0; i < length; i++) {
        target_address[i] = data[i];
        // Ϊ�˱����Ż���ȷ�����벻�ᱻ�Ż���
        volatile uint32_t read_back = target_address[i];
    }
}


int main(void) {
    SystemInit();           //ʱ�ӳ�ʼ��
    Key_Init();
    delay_init();           //��ʱ��ʼ��
    uint8_t boot_mode = 1;
    if (!GPIO_GetBit(KEY1_GPIO_PORT, KEY1_GPIO_PIN) || !GPIO_GetBit(GPIOA, GPIO_PIN3)) {
        if (!GPIO_GetBit(KEY1_GPIO_PORT, KEY1_GPIO_PIN)) {
            boot_mode = 2;
        }
        EEPROM_WriteBuffer(0X40001, (uint8_t * ) & boot_mode, 1);//��������
        LED1_OFF;
#define NUM  16
        for (int i = 0; i < 12 * 1024 / NUM; i += 4) {
            uint32_t c[NUM];
            EEPROM_ReadBuffer(0x10000 + i * NUM, (uint8_t * )
            c, NUM * 4);
            write_to_memory1(0x20000800 + i * NUM, c, NUM);
        }
        jump_to_app();
    }
    boot_to_app();
}

