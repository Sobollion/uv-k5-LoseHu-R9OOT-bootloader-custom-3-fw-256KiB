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

#include <string.h>
#include "font.h"
#include "../external/CMSIS_5/Device/ARM/ARMCM0/Include/ARMCM0.h"


#include "version.h"
#include "app/uart.h"
#include "board.h"
#include "bsp/dp32g030/dma.h"
#include "bsp/dp32g030/gpio.h"
#include "driver/aes.h"

#include "driver/eeprom.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "functions.h"
#include "misc.h"


#if defined(ENABLE_OVERLAY)

#include "sram-overlay.h"

#endif


#define DMA_INDEX(x, y) (((x) + (y)) % sizeof(UART_DMA_Buffer))

typedef struct {
    uint16_t ID;
    uint16_t Size;
} Header_t;
#ifdef ENABLE_DOCK
typedef struct {
        Header_t Header;
        uint8_t Key;
        uint8_t Padding;
        uint32_t Timestamp;
    } CMD_0801_t; // simulate key press
#endif
typedef struct {
    uint8_t Padding[2];
    uint16_t ID;
} Footer_t;

typedef struct {
    Header_t Header;
    uint32_t Timestamp;
} CMD_0514_t;

typedef struct {
    Header_t Header;
    struct {
        char Version[16];
        bool bHasCustomAesKey;
        bool bIsInLockScreen;
        uint8_t Padding[2];
        uint32_t Challenge[4];
    } Data;
} REPLY_0514_t;

typedef struct {
    Header_t Header;
    uint16_t Offset;
    uint8_t Size;
    uint8_t Padding;
    uint32_t Timestamp;
    uint8_t ADD[2];
} CMD_051B_t;
typedef struct {
    Header_t Header;
    uint16_t Offset;
    uint8_t Size;
    uint8_t Padding;
    uint32_t Timestamp;
    uint8_t ADD[2];

} CMD_052B_t;
typedef struct {
    Header_t Header;
    struct {
        uint16_t Offset;
        uint8_t Size;
        uint8_t Padding;
        uint8_t Data[128];
    } Data;
} REPLY_051B_t;

typedef struct {
    Header_t Header;
    uint16_t Offset;
    uint8_t Size;
    bool bAllowPassword;
    uint32_t Timestamp;
    uint8_t Data[0];
} CMD_051D_t;

typedef struct {
    Header_t Header;
    struct {
        uint16_t Offset;
    } Data;
} REPLY_051D_t;

typedef struct {
    Header_t Header;
    struct {
        uint16_t RSSI;
        uint8_t ExNoiseIndicator;
        uint8_t GlitchIndicator;
    } Data;
} REPLY_0527_t;

typedef struct {
    Header_t Header;
    struct {
        uint16_t Voltage;
        uint16_t Current;
    } Data;
} REPLY_0529_t;

typedef struct {
    Header_t Header;
    uint32_t Response[4];
} CMD_052D_t;
#ifdef ENABLE_BLOCK
typedef struct {
    Header_t Header;
    struct {
        bool bIsLocked;
        uint8_t Padding[3];
    } Data;
} REPLY_052D_t;
#endif
typedef struct {
    Header_t Header;
    uint32_t Timestamp;
} CMD_052F_t;

static const uint8_t Obfuscation[16] =
        {
                0x16, 0x6C, 0x14, 0xE6, 0x2E, 0x91, 0x0D, 0x40, 0x21, 0x35, 0xD5, 0x40, 0x13, 0x03, 0xE9, 0x80
        };
static union {
    uint8_t Buffer[UART_SIZE];
    struct {
        Header_t Header;
        uint8_t Data[UART_SIZE - 4];
    };
} UART_Command;

static uint32_t Timestamp;
static uint16_t gUART_WriteIndex;
static bool bIsEncrypted = true;

static void SendReply(void *pReply, uint16_t Size) {
    Header_t Header;
    Footer_t Footer;

    if (bIsEncrypted) {
        uint8_t *pBytes = (uint8_t *) pReply;
        unsigned int i;
        for (i = 0; i < Size; i++)
            pBytes[i] ^= Obfuscation[i % 16];
    }

    Header.ID = 0xCDAB;
    Header.Size = Size;
    UART_Send(&Header, sizeof(Header));
    UART_Send(pReply, Size);

    if (bIsEncrypted) {
        Footer.Padding[0] = Obfuscation[(Size + 0) % 16] ^ 0xFF;
        Footer.Padding[1] = Obfuscation[(Size + 1) % 16] ^ 0xFF;
    } else {
        Footer.Padding[0] = 0xFF;
        Footer.Padding[1] = 0xFF;
    }
    Footer.ID = 0xBADC;

    UART_Send(&Footer, sizeof(Footer));
}

static void SendVersion(void) {
    REPLY_0514_t Reply;

    Reply.Header.ID = 0x0515;
    Reply.Header.Size = sizeof(Reply.Data);
    strcpy(Reply.Data.Version, Version);
    Reply.Data.bHasCustomAesKey = bHasCustomAesKey;
    Reply.Data.bIsInLockScreen = bIsInLockScreen;
    Reply.Data.Challenge[0] = gChallenge[0];
    Reply.Data.Challenge[1] = gChallenge[1];
    Reply.Data.Challenge[2] = gChallenge[2];
    Reply.Data.Challenge[3] = gChallenge[3];

    SendReply(&Reply, sizeof(Reply));
}

#ifdef ENABLE_BLOCK
static bool IsBadChallenge(const uint32_t *pKey, const uint32_t *pIn, const uint32_t *pResponse) {
    unsigned int i;
    uint32_t IV[4];

    IV[0] = 0;
    IV[1] = 0;
    IV[2] = 0;
    IV[3] = 0;

    AES_Encrypt(pKey, IV, pIn, IV, true);

    for (i = 0; i < 4; i++)
        if (IV[i] != pResponse[i])
            return true;

    return false;
}
#endif

static void CMD_0514(const uint8_t *pBuffer) {
    const CMD_0514_t *pCmd = (const CMD_0514_t *) pBuffer;

    Timestamp = pCmd->Timestamp;

#ifdef ENABLE_FMRADIO
    gFmRadioCountdown_500ms = fm_radio_countdown_500ms;
#endif

    gSerialConfigCountDown_500ms = 12; // 6 sec


    SendVersion();
}

static void CMD_051B(const uint8_t *pBuffer) {
    const CMD_051B_t *pCmd = (const CMD_051B_t *) pBuffer;
    REPLY_051B_t Reply;

    if (pCmd->Timestamp != Timestamp)
        return;
    gSerialConfigCountDown_500ms = 12; // 6 sec
    Reply.Header.ID = 0x051C;
    Reply.Header.Size = pCmd->Size + 4;
    Reply.Data.Offset = pCmd->Offset;
    Reply.Data.Size = pCmd->Size;

    if (pCmd->Header.ID == 0x051B)
        EEPROM_ReadBuffer(pCmd->Offset, Reply.Data.Data, pCmd->Size);
    else
        EEPROM_ReadBuffer(((pCmd->Offset) << 16) + ((pCmd->ADD[1]) << 8) + (pCmd->ADD[0]), Reply.Data.Data, pCmd->Size);
    SendReply(&Reply, pCmd->Size + 8);
}

static void CMD_051D(const uint8_t *pBuffer) {
    const CMD_051D_t *pCmd = (const CMD_051D_t *) pBuffer;
    REPLY_051D_t Reply;

    if (pCmd->Timestamp != Timestamp)
        return;

    gSerialConfigCountDown_500ms = 12; // 6 sec



    Reply.Header.ID = 0x051E;
    Reply.Header.Size = sizeof(Reply.Data);
    Reply.Data.Offset = pCmd->Offset;


    for (unsigned int i = 0; i < (pCmd->Size / 8); i++) {
        const uint16_t Offset = pCmd->Offset + (i * 8U);


        EEPROM_WriteBuffer(Offset, &pCmd->Data[i * 8U], 8);

    }


#ifdef ENABLE_BLOCK

    }
#endif

    SendReply(&Reply, sizeof(Reply));
}


static void CMD_0529(void) {
    REPLY_0529_t Reply;

    Reply.Header.ID = 0x52A;
    Reply.Header.Size = sizeof(Reply.Data);

    // Original doesn't actually send current!
    BOARD_ADC_GetBatteryInfo(&Reply.Data.Voltage, &Reply.Data.Current);

    SendReply(&Reply, sizeof(Reply));
}

#define CRC16_XMODEM_POLY 0x1021

uint16_t CRC_Calculate1(void *pBuffer, uint16_t Size) {
    uint8_t *pData = (uint8_t *) pBuffer;
    uint16_t crc = 0; // ��ʼCRCֵΪ0

    while (Size--) {
        crc ^= (*pData++) << 8; // �������ֽڵ����λ��CRC���
        for (uint8_t i = 0; i < 8; i++) {
            if (crc & 0x8000) { // ������λ�Ƿ�Ϊ1
                crc = (crc << 1) ^ CRC16_XMODEM_POLY; // ������λΪ1��ִ��CRC����ʽ����
            } else {
                crc = crc << 1; // ������λΪ0����������
            }
        }
    }

    return crc;
}

bool UART_IsCommandAvailable(void) {
    uint16_t Index;
    uint16_t TailIndex;
    uint16_t Size;
    uint16_t CRC;
    uint16_t CommandLength;
    uint16_t DmaLength = DMA_CH0->ST & 0xFFFU;


    while (1) {
        if (gUART_WriteIndex == DmaLength)
            return false;

        while (gUART_WriteIndex != DmaLength && UART_DMA_Buffer[gUART_WriteIndex] != 0xABU)
            gUART_WriteIndex = DMA_INDEX(gUART_WriteIndex, 1);

        if (gUART_WriteIndex == DmaLength)
            return false;

        if (gUART_WriteIndex < DmaLength)
            CommandLength = DmaLength - gUART_WriteIndex;
        else
            CommandLength = (DmaLength + sizeof(UART_DMA_Buffer)) - gUART_WriteIndex;

        if (CommandLength < 8)
            return 0;

        if (UART_DMA_Buffer[DMA_INDEX(gUART_WriteIndex, 1)] == 0xCD)
            break;

        gUART_WriteIndex = DMA_INDEX(gUART_WriteIndex, 1);
    }

    Index = DMA_INDEX(gUART_WriteIndex, 2);
    Size = (UART_DMA_Buffer[DMA_INDEX(Index, 1)] << 8) | UART_DMA_Buffer[Index];

    if ((Size + 8u) > sizeof(UART_DMA_Buffer)) {
        gUART_WriteIndex = DmaLength;
        return false;
    }

    if (CommandLength < (Size + 8))
        return false;

    Index = DMA_INDEX(Index, 2);
    TailIndex = DMA_INDEX(Index, Size + 2);

    if (UART_DMA_Buffer[TailIndex] != 0xDC || UART_DMA_Buffer[DMA_INDEX(TailIndex, 1)] != 0xBA) {
        gUART_WriteIndex = DmaLength;
        return false;
    }

    if (TailIndex < Index) {
        const uint16_t ChunkSize = sizeof(UART_DMA_Buffer) - Index;
        memcpy(UART_Command.Buffer, UART_DMA_Buffer + Index, ChunkSize);
        memcpy(UART_Command.Buffer + ChunkSize, UART_DMA_Buffer, TailIndex);
    } else
        memcpy(UART_Command.Buffer, UART_DMA_Buffer + Index, TailIndex - Index);

    TailIndex = DMA_INDEX(TailIndex, 2);
    if (TailIndex < gUART_WriteIndex) {
        memset(UART_DMA_Buffer + gUART_WriteIndex, 0, sizeof(UART_DMA_Buffer) - gUART_WriteIndex);
        memset(UART_DMA_Buffer, 0, TailIndex);
    } else
        memset(UART_DMA_Buffer + gUART_WriteIndex, 0, TailIndex - gUART_WriteIndex);

    gUART_WriteIndex = TailIndex;

    if (UART_Command.Header.ID == 0x0514)
        bIsEncrypted = false;

    if (UART_Command.Header.ID == 0x6902)
        bIsEncrypted = true;

    if (bIsEncrypted) {
        unsigned int i;
        for (i = 0; i < (Size + 2u); i++)
            UART_Command.Buffer[i] ^= Obfuscation[i % 16];
    }

    CRC = UART_Command.Buffer[Size] | (UART_Command.Buffer[Size + 1] << 8);
//    char b[2]="3K";
//     uint8_t tmp[Size];
//    for (int i = 0; i < Size; i++) {
//        tmp[i]=UART_Command.Buffer[i];
//    }
    bool judge = (CRC_Calculate1(UART_Command.Buffer, Size) != CRC) ? false : true;

    return judge;
}


static void CMD_0538(const uint8_t *pBuffer)//write
{
    const CMD_051D_t *pCmd = (const CMD_051D_t *) pBuffer;
    REPLY_051D_t Reply;
    if (pCmd->Timestamp != Timestamp)
        return;
    gSerialConfigCountDown_500ms = 12; // 6 sec

    Reply.Header.ID = 0x051E;
    Reply.Header.Size = sizeof(Reply.Data);
    Reply.Data.Offset = pCmd->Offset;
    int add = ((pCmd->Size) - 2) % 8;


    for (int i = 0; i < ((pCmd->Size) - 2) / 8 + (add == 0 ? 0 : 1); i++) {
        const uint32_t Offset = ((pCmd->Offset) << 16) + ((pCmd->Data[1]) << 8) + (pCmd->Data[0]) + (i * 8U);
        if (add && i == ((pCmd->Size) - 2) / 8 + (add == 0 ? 0 : 1) - 1)
            EEPROM_WriteBuffer(Offset, &pCmd->Data[i * 8U + 2], add);
        else
            EEPROM_WriteBuffer(Offset, &pCmd->Data[i * 8U + 2], 8);
    }

    SendReply(&Reply, sizeof(Reply));
}


void payload_xor(uint8_t *payload, size_t length) {
    uint8_t XOR_ARRAY[] = {0x16, 0x6c, 0x14, 0xe6, 0x2e, 0x91, 0x0d, 0x40,
                           0x21, 0x35, 0xd5, 0x40, 0x13, 0x03, 0xe9, 0x80};
    for (size_t i = 0; i < length; ++i) {
        payload[i] ^= XOR_ARRAY[i % 16];
    }
}

bool a = 0;

void CMD_0519(const uint8_t *pBuffer) {
    uint8_t send_back[12];
    memcpy(send_back + 4, pBuffer + 4, 6); //ʱ���Լ���ַ
    send_back[0] = 0x1a;
    send_back[1] = 0x05;
    send_back[2] = 0x08;
    send_back[3] = 0x00;
    send_back[10] = 0x00;
    send_back[11] = 0x00;
    payload_xor(send_back, 12);
    uint8_t send_now[20];
    memcpy(send_now + 4, send_back, 12);
    send_now[0] = 0xab;
    send_now[1] = 0xcd;
    send_now[2] = 0x0c;
    send_now[3] = 0x00;
    send_now[16] = 0xFF;
    send_now[17] = 0xFF;
    send_now[18] = 0xDC;
    send_now[19] = 0xBA;
    uint32_t flash_add = 0;
    if ((FLASH_MASK & 0x3) == 0) {
        flash_add = 0x1000;
    }

    ProgramMoreWords(flash_add + (pBuffer[8] << 8 | pBuffer[9]), (uint32_t * )(pBuffer + 16), 256 / 4);
    UART_Send(send_now, 20);

    if (a) {
        GPIO_SetBit(&GPIOC->DATA, GPIOC_PIN_FLASHLIGHT);
    } else GPIO_ClearBit(&GPIOC->DATA, GPIOC_PIN_FLASHLIGHT);
    a = !a;

    if ((pBuffer[8] << 8 | pBuffer[9]) + 0x100 == (pBuffer[10] << 8 | pBuffer[11])) {
        GPIO_ClearBit(&GPIOC->DATA, GPIOC_PIN_FLASHLIGHT);

        SYSTEM_DelayMs(500);
        NVIC_SystemReset();

    }
}

uint8_t uart_flag = 0;

void UART_HandleCommand(void) {
    switch (UART_Command.Header.ID) {
        case 0x051B:
        case 0x052B://read
            CMD_051B(UART_Command.Buffer);
            break;
        case 0x0538://write
            CMD_0538(UART_Command.Buffer);
            break;
        case 0x051D:
            CMD_051D(UART_Command.Buffer);
            break;
        case 0x0514:
            CMD_0514(UART_Command.Buffer);
            break;
        case 0x0519:
            CMD_0519(UART_Command.Buffer);
            break;

        case 0x0530:
            uart_flag = 1;
            uint8_t flash_num = 0;
            if ((FLASH_MASK & 0x3) == 0) {
                flash_num = 8;
            }
            for (int i = 0 + flash_num; i < 120 + flash_num; ++i) {
                Erase_Flash(i);
            }
            break;
        case 0x05DD:
            NVIC_SystemReset();
    }
}

void UART_READ() {
    if (UART_IsCommandAvailable()) {
        __disable_irq();
        UART_HandleCommand();
//        __enable_irq();

    }
}