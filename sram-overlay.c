/* Copyright 2023 Dual Tachyon
 * https://github.com/DualTachyon
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#include "ARMCM0.h"
#include "bsp/dp32g030/pmu.h"
#include "bsp/dp32g030/saradc.h"
#include "bsp/dp32g030/syscon.h"
#include "sram-overlay.h"
#include "driver/eeprom.h"
#include "ui/helper.h"

#include "bsp/dp32g030/gpio.h"
#include "driver/gpio.h"
#include "sram-overlay.h"
#include "string.h"
#include "ui/helper.h"
#include "external/printf/printf.h"


#include "board.h"

#include "bsp/dp32g030/syscon.h"


#include "driver/systick.h"


#include "driver/eeprom.h"
#include "driver/st7565.h"
#include "sram-overlay.h"
#include "ARMCM0.h"

static volatile uint32_t *pFlash = 0;
uint32_t overlay_FLASH_MainClock;
uint32_t overlay_FLASH_ClockMultiplier;
uint32_t overlay_0x20000478;         // Nothing is using this???

void overlay_FLASH_RebootToBootloader(void) {
    overlay_FLASH_MaskUnlock();
    overlay_FLASH_SetMaskSel(FLASH_MASK_SELECTION_NONE);
    overlay_FLASH_MaskLock();
    overlay_SystemReset();
}

bool overlay_FLASH_IsBusy(void) {
    return (FLASH_ST & FLASH_ST_BUSY_MASK) != FLASH_ST_BUSY_BITS_READY;
}

bool overlay_FLASH_IsInitComplete(void) {
    return (FLASH_ST & FLASH_ST_INIT_BUSY_MASK) == FLASH_ST_INIT_BUSY_BITS_COMPLETE;
}

bool overlay_FLASH_IsNotEmpty(void) {
    return (FLASH_ST & 4) != 4;
}

void overlay_FLASH_Start(void) {
    overlay_FLASH_Unlock();
    FLASH_START |= FLASH_START_START_BITS_START;
}

void overlay_FLASH_Init(FLASH_READ_MODE ReadMode) {
    overlay_FLASH_WakeFromDeepSleep();
    overlay_FLASH_SetMode(FLASH_MODE_READ_AHB);
    overlay_FLASH_SetReadMode(ReadMode);
    overlay_FLASH_SetEraseTime();
    overlay_FLASH_SetProgramTime();
    overlay_FLASH_Lock();
}

void overlay_FLASH_MaskLock(void) {
    FLASH_MASK = (FLASH_MASK & ~FLASH_MASK_LOCK_MASK) | FLASH_MASK_LOCK_BITS_SET;
}

void overlay_FLASH_SetMaskSel(FLASH_MASK_SELECTION Mask) {
    FLASH_MASK = (FLASH_MASK & ~FLASH_MASK_SEL_MASK) | ((Mask << FLASH_MASK_SEL_SHIFT) & FLASH_MASK_SEL_MASK);
}

void overlay_FLASH_MaskUnlock(void) {
    FLASH_MASK = (FLASH_MASK & ~FLASH_MASK_LOCK_MASK) | FLASH_MASK_LOCK_BITS_NOT_SET;
}

void overlay_FLASH_Lock(void) {
    FLASH_LOCK = FLASH_LOCK_LOCK_BITS_LOCK;
}

void overlay_FLASH_Unlock(void) {
    FLASH_UNLOCK = FLASH_UNLOCK_UNLOCK_BITS_UNLOCK;
}

uint32_t overlay_FLASH_ReadByAHB(uint32_t Offset) {

    return pFlash[(Offset & ~3U) / 4];
}

uint32_t overlay_FLASH_ReadByAPB(uint32_t Offset) {
    uint32_t Data;

    while (overlay_FLASH_IsBusy()) {}

    overlay_FLASH_SetMode(FLASH_MODE_READ_APB);
    FLASH_ADDR = Offset >> 2;

    overlay_FLASH_Start();

    while (overlay_FLASH_IsBusy()) {}

    Data = FLASH_RDATA;

    overlay_FLASH_SetMode(FLASH_MODE_READ_AHB);
    overlay_FLASH_Lock();

    return Data;
}

void overlay_FLASH_SetArea(FLASH_AREA Area) {
    FLASH_CFG = (FLASH_CFG & ~FLASH_CFG_NVR_SEL_MASK) | ((Area << FLASH_CFG_NVR_SEL_SHIFT) & FLASH_CFG_NVR_SEL_MASK);
}

void overlay_FLASH_SetReadMode(FLASH_READ_MODE Mode) {
    if (Mode == FLASH_READ_MODE_1_CYCLE)
        FLASH_CFG = (FLASH_CFG & ~FLASH_CFG_READ_MD_MASK) | FLASH_CFG_READ_MD_BITS_1_CYCLE;
    else if (Mode == FLASH_READ_MODE_2_CYCLE)
        FLASH_CFG = (FLASH_CFG & ~FLASH_CFG_READ_MD_MASK) | FLASH_CFG_READ_MD_BITS_2_CYCLE;
}

void overlay_FLASH_SetEraseTime(void) {
    FLASH_ERASETIME =
            ((overlay_FLASH_ClockMultiplier & 0xFFFFU) * 0x1A00000U) + (overlay_FLASH_ClockMultiplier * 3600U);
}

void overlay_FLASH_WakeFromDeepSleep(void) {
    FLASH_CFG = (FLASH_CFG & ~FLASH_CFG_DEEP_PD_MASK) | FLASH_CFG_DEEP_PD_BITS_NORMAL;
    while (!overlay_FLASH_IsInitComplete()) {}
}

void overlay_FLASH_SetMode(FLASH_MODE Mode) {
    FLASH_CFG = (FLASH_CFG & ~FLASH_CFG_MODE_MASK) | ((Mode << FLASH_CFG_MODE_SHIFT) & FLASH_CFG_MODE_MASK);
}

void overlay_FLASH_SetProgramTime(void) {
    FLASH_PROGTIME = overlay_FLASH_ClockMultiplier * 45074;
}

void overlay_SystemReset(void) {
    // Lifted from core_cm0.h to preserve function order in the object file.

    __DSB();     // Ensure all outstanding memory accesses included buffered write are completed before reset
    SCB->AIRCR = (0x5FAUL << SCB_AIRCR_VECTKEY_Pos) | SCB_AIRCR_SYSRESETREQ_Msk;
    __DSB();     // Ensure completion of memory access

    for (;;)     // wait until reset
        __NOP();
}

uint32_t overlay_FLASH_ReadNvrWord(uint32_t Offset) {
    uint32_t Data;
    overlay_FLASH_SetArea(FLASH_AREA_NVR);
    Data = overlay_FLASH_ReadByAHB(Offset);
    overlay_FLASH_SetArea(FLASH_AREA_MAIN);
    return Data;
}

void overlay_FLASH_ConfigureTrimValues(void) {
    uint32_t Data;

    overlay_FLASH_SetArea(FLASH_AREA_NVR);

    SYSCON_CHIP_ID0 = overlay_FLASH_ReadByAPB(0xF018);
    SYSCON_CHIP_ID1 = overlay_FLASH_ReadByAPB(0xF01C);
    SYSCON_CHIP_ID2 = overlay_FLASH_ReadByAPB(0xF020);
    SYSCON_CHIP_ID3 = overlay_FLASH_ReadByAPB(0xF024);

    SYSCON_RC_FREQ_DELTA = overlay_FLASH_ReadByAHB(0x07C8);
    SYSCON_VREF_VOLT_DELTA = overlay_FLASH_ReadByAHB(0x07C4);

    PMU_TRIM_POW0 = overlay_FLASH_ReadByAHB(0x07E4);
    PMU_TRIM_POW1 = overlay_FLASH_ReadByAHB(0x07E0);
    PMU_TRIM_RCHF = overlay_FLASH_ReadByAHB(0x07D8);
    PMU_TRIM_RCLF = overlay_FLASH_ReadByAHB(0x07D4);
    PMU_TRIM_OPA = overlay_FLASH_ReadByAHB(0x07D0);
    PMU_TRIM_PLL = overlay_FLASH_ReadByAHB(0x07CC);

    overlay_0x20000478 = overlay_FLASH_ReadByAHB(0x07B8);

    Data = overlay_FLASH_ReadByAHB(0x07BC);
    SYSCON_DEV_CLK_GATE =
            (SYSCON_DEV_CLK_GATE & ~SYSCON_DEV_CLK_GATE_SARADC_MASK) | SYSCON_DEV_CLK_GATE_SARADC_BITS_ENABLE;
    SARADC_CALIB_OFFSET = ((Data & 0xFFFF) << SARADC_CALIB_OFFSET_OFFSET_SHIFT) & SARADC_CALIB_OFFSET_OFFSET_MASK;
    SARADC_CALIB_KD = (((Data >> 16) & 0xFFFF) << SARADC_CALIB_KD_KD_SHIFT) & SARADC_CALIB_KD_KD_MASK;
    overlay_FLASH_SetArea(FLASH_AREA_MAIN);
}

//запись в ОЗУ+ (uint32_t адрес, uint32_t слова, uint32_t количество слов)
void ProgramMoreWords(uint32_t DestAddr, const uint32_t *words, uint32_t num) {
    const uint32_t *pWord = (const uint32_t *) words;

    while (overlay_FLASH_IsBusy()) {}//Запросите флаг занятости контроллера FLASH и подождите, пока контроллер перейдет в состояние READY;
    overlay_FLASH_SetMode(FLASH_MODE_PROGRAM); //Режим конфигурации — это операция программирования;

    for (uint32_t i = 0;i < num; i++) { //Если еще есть данные для программирования, определите, равен ли бит PROG_BUF_EMPTY 0. Если он равен 0, вы можете записать следующее слово, которое нужно запрограммировать (если оно 1, подождите и не сможете записать), пока все данные, которые нужно запрограммировать, не будут записаны. написано;
        FLASH_ADDR = (DestAddr + i * 4) >> 2; //Напишите адрес программирования прописью;
        FLASH_WDATA = *pWord++; //Поместите данные для программирования в регистр данных;
        overlay_FLASH_Start();//Настройте разблокировку FLASH и подайте команду СТАРТ;
        while (overlay_FLASH_IsNotEmpty());

    }
    while (overlay_FLASH_IsBusy()) {}//Запросите флаг занятости контроллера FLASH и подождите, пока контроллер перейдет в состояние READY;
    overlay_FLASH_SetMode(FLASH_CFG_MODE_VALUE_READ_AHB); //Режим конфигурации — это операция программирования;
    overlay_FLASH_Lock();
}

//запись в ОЗУ (uint32_t адрес, uint32_t слова)
void ProgramWords(uint32_t DestAddr, uint32_t words) {
    __disable_irq();

    while (overlay_FLASH_IsBusy()) {}//Запросите флаг занятости контроллера FLASH и подождите, пока контроллер перейдет в состояние READY;

    overlay_FLASH_SetMode(FLASH_MODE_PROGRAM); //Режим конфигурации — это операция программирования;

    FLASH_ADDR = DestAddr >> 2; //Напишите адрес программирования прописью;
    FLASH_WDATA = words; //Поместите данные для программирования в регистр данных;
    overlay_FLASH_Start();//Настройте разблокировку FLASH и подайте команду СТАРТ;
    while (overlay_FLASH_IsBusy()) {}//Запросите флаг занятости контроллера FLASH и подождите, пока контроллер перейдет в состояние READY;
    overlay_FLASH_SetMode(FLASH_CFG_MODE_VALUE_READ_AHB); //Режим конфигурации — это операция программирования;
    overlay_FLASH_Lock();
}

//копирование из EEPROM в EEPROM
void CP_EEPROM_TO_EEPROM(uint32_t eeprom_from, uint32_t eeprom_to, uint32_t size) {
    char str[20];
    uint16_t once_size=128;
    uint8_t c[128];

    for (int i = 0; i < size / once_size; ++i) { //size конфига 8192 байта, количество итераций 64 раза
        EEPROM_ReadBuffer(eeprom_from + i * once_size, (uint8_t *) & c, once_size); //читаем в переменную c в RAM 128 Байт
        EEPROM_WriteBuffer(eeprom_to + i * once_size, (uint8_t * ) & c, once_size); //пишем из RAM 128 Байт (при бэкапе последней проши, на последней итерации, size=8192, адрес=3E000+1F80 )
        if (i % (2048/once_size) == 0) {
            sprintf(str, "Config: %02d%%", i * 100 / (size / once_size));
            UI_PrintStringSmall(str, 20, 0, 3);
            ST7565_BlitFullScreen();
        }
    }
    EEPROM_ReadBuffer(eeprom_from + (size / once_size) * once_size, (uint8_t *) & c, size-(size / once_size) * once_size);
    EEPROM_WriteBuffer((size / once_size) * once_size+ eeprom_to, (uint8_t * ) & c, (size-(size / once_size) * once_size));
}

//копирование из EEPROM во Flash
void CP_EEPROM_TO_FLASH(uint32_t eeprom_add, uint32_t flash_add, uint32_t size) {
    char str[20];
    uint16_t once_size=128;
    uint32_t c[once_size/4];

    for (int i = 0; i < size / once_size; ++i) { //количество итераций не более 480 раз
        EEPROM_ReadBuffer(eeprom_add + i * once_size, (uint8_t *) &c, once_size); //читаем в переменную c в RAM 128 байт
        ProgramMoreWords(i * once_size + flash_add, c, once_size/4); //пишем 32 слова по 32 бита (4 Байта) = в сумме те же самые 128 байт
        if (i % (2048/once_size) == 0) {
            sprintf(str, "Load: %02d%%", i * 100 / (size / once_size));
            UI_PrintStringSmall(str, 20, 0, 2);
            ST7565_BlitFullScreen();
        }
    }

    EEPROM_ReadBuffer(eeprom_add + (size / once_size) * once_size, (uint8_t *) &c, size-(size / once_size) * once_size);
    ProgramMoreWords((size / once_size) * once_size+ flash_add, c, (size-(size / once_size) * once_size)/4);
}

//JUMP_TO_FLASH(0xa10A,0x20003ff0);
void JUMP_TO_FLASH(uint32_t flash_add, uint32_t stack_add) {
    __disable_irq();
    ClearStack();
    __set_MSP(stack_add);
    __set_PC(flash_add);
}

void Erase_Flash(uint32_t sector) {
    __disable_irq();

    while (overlay_FLASH_IsBusy()) {}//Запросите флаг занятости контроллера FLASH и подождите, пока контроллер перейдет в состояние READY;
    overlay_FLASH_SetMode(FLASH_CFG_MODE_VALUE_ERASE); //Режим конфигурации — операция стирания сектора;

    FLASH_ADDR = sector << 7;//    3 Напишите прописью начальный адрес стирания сектора;

    overlay_FLASH_Start();//    4 Настройте FLASH для разблокировки и запуска команды СТАРТ;
    while (overlay_FLASH_IsBusy()) {}//Запросите флаг занятости контроллера FLASH и подождите, пока контроллер перейдет в состояние READY;
    overlay_FLASH_SetMode(FLASH_CFG_MODE_VALUE_READ_AHB); //Режим конфигурации — это операция программирования;
    overlay_FLASH_Lock();
//    5 Запросите флаг занятости контроллера FLASH и подождите, пока контроллер перейдет в состояние READY;
//    6 Режим конфигурации — операция чтения, FLASH заблокирована, операция стирания сектора завершена.
}

void write_to_memory(uint32_t address, uint32_t data) {
    // Преобразовать значение адреса в указатель
    uint32_t *target_address = (uint32_t *) address;
    // Запись данных на целевой адрес
    *target_address = data;
    // Чтобы избежать оптимизации, убедитесь, что код не оптимизирован
    volatile uint32_t read_back = *target_address;
}
