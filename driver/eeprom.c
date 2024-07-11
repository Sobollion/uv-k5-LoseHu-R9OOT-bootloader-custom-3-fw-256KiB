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

#include <stddef.h>
#include <string.h>

#include "driver/eeprom.h"
#include "driver/i2c.h"
#include "driver/system.h"
#include "assert.h"

#include "ARMCM0.h"


void EEPROM_ReadBuffer(uint32_t Address, void *pBuffer, uint16_t Size) {

    __disable_irq();
    I2C_Start();

    uint8_t IIC_ADD =    0xA0 | Address >> 15 &14;

    I2C_Write(IIC_ADD);
    I2C_Write((Address >> 8) & 0xFF);
    I2C_Write((Address >> 0) & 0xFF);

    I2C_Start();

    I2C_Write(IIC_ADD + 1);

    I2C_ReadBuffer(pBuffer, Size);

    I2C_Stop();
//    __enable_irq();

}

void EEPROM_WriteBuffer(uint32_t Address, const void *pBuffer, uint8_t WRITE_SIZE) {

    __disable_irq();

    if (pBuffer == NULL)
        return;
    uint8_t buffer[128];
    EEPROM_ReadBuffer(Address, buffer, WRITE_SIZE);
    if (memcmp(pBuffer, buffer, WRITE_SIZE) != 0) {
        uint8_t IIC_ADD =    0xA0 | Address >> 15 &14;
        I2C_Start();

        I2C_Write(IIC_ADD);

        I2C_Write((Address >> 8) & 0xFF);
        I2C_Write((Address) & 0xFF);
        I2C_WriteBuffer(pBuffer, WRITE_SIZE);
        I2C_Stop();
    }
    SYSTEM_DelayMs(8);

}


void EEPROM_Buffer_MORE(uint32_t Address, void *pBuffer, uint16_t WRITE_SIZE, uint8_t TYPE) {
    uint16_t SUM_WRITE = 0;
    while (WRITE_SIZE) {
        uint16_t NOW_WRITE_SIZE = (WRITE_SIZE < 128 ? WRITE_SIZE : 128) - (Address & 0x7f);
        WRITE_SIZE -= NOW_WRITE_SIZE;
        if (TYPE) EEPROM_WriteBuffer(Address, pBuffer + SUM_WRITE, NOW_WRITE_SIZE);
        else EEPROM_ReadBuffer(Address, pBuffer + SUM_WRITE, NOW_WRITE_SIZE);

        SUM_WRITE += NOW_WRITE_SIZE;
        Address += NOW_WRITE_SIZE;
    }
}