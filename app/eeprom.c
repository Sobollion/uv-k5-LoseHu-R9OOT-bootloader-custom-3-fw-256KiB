//
// Created by RUPC on 2024/6/28.
//
#include "eeprom.h"
#include "../app/uart.h"


void ERROR_DISPLAY() {
    memset(gFrameBuffer, 0, sizeof(gFrameBuffer));
    UI_PrintStringSmall("NO Firmware !!", 0, 127, 2);
    UI_PrintStringSmall("Instructions:", 0, 127, 3);
    UI_PrintStringSmall("t.me/R9OOT_BOOT", 0, 127, 4);
    UI_PrintStringSmall("WRITE OR EXIT", 0, 127, 6);

//    show_uint32(sum_menu, 5);
    ST7565_BlitFullScreen();

    while (1) {
        if (KEYBOARD_Poll() == KEY_EXIT) {
            while (KEYBOARD_Poll() == KEY_EXIT);
            return;
        }
        UART_READ();
    }
}

void GET_FIRMWARE_NUM() {

    EEPROM_ReadBuffer(FIRMWARE_NUM_ADD, (uint8_t * ) & sum_menu, 1);
    if (sum_menu > 64 || sum_menu == 0) {
        ERROR_DISPLAY();
        NVIC_SystemReset();

    }
}

//прошивка
void LOAD_FIRMWARE() {
    uint8_t current_firm; //как и nowmenu принимает значения 1/2/3
    EEPROM_ReadBuffer(0x0FF82, (uint8_t * ) & current_firm, 1); //Читаем из 0x0FF82 номер предыдущей прошивки в переменную current_firm
    memset(gFrameBuffer, 0, sizeof(gFrameBuffer));
    UI_PrintStringSmall("KEEP POWER ON!", 0, 127, 5);
    uint32_t start_add, end_add;
    EEPROM_ReadBuffer(0x0FFA0 + 32 * now_menu - 16, (uint8_t * ) & start_add, 4); //читаем адрес начала прошивки
    EEPROM_ReadBuffer(0x0FFA0 + 32 * now_menu - 16 + 4, (uint8_t * ) & end_add, 4); //читаем адрес конца прошивки
    if (start_add > end_add || end_add > 0x40000 || start_add > 0x40000) { //избегаем ошибок если адреса выходят за границы чипа M01
        ERROR_DISPLAY();
        return;
    }
    char str[20];
    sprintf(str, "From 0x%08x", start_add);
    UI_PrintStringSmall(str, 0, 127, 6);
    uint32_t flash_add = 0;
    uint8_t flash_num = 0;
    if ((FLASH_MASK & 0x3) == 0) {
        flash_add = 0x1000;
        flash_num = 8;
    }
    for (int i = 0 + flash_num; i < 120 + flash_num; ++i) {
        Erase_Flash(i);
        char str[20];
        sprintf(str, "Erase: %03d/120", i + 1 - flash_num);
        UI_PrintStringSmall(str, 20, 0, 1);
        ST7565_BlitFullScreen();
    }
    CP_EEPROM_TO_FLASH(start_add, flash_add, end_add - start_add + 1); //Копируем прошивку из ипрома во флеш
    if (current_firm!=now_menu) {
        CP_EEPROM_TO_EEPROM(0x00000, 0x11000+0x2000*current_firm, 8192); //Сохраняем из 0x00000 в 0x11000+64*current_firm объём 8килоБайт(64килобита = 0x2000) 0-38000, 1-3A000, 2-3C000, 3-3E000
        current_firm=now_menu; //Присваиваем current_firm=номер текущей now_menu
        CP_EEPROM_TO_EEPROM(0x11000+0x2000*current_firm, 0x00000, 8192);//Сохраняем из 0x11000+64*current_firm в 0x00000 объём 8килоБайт(64килобита = 0x2000)
        EEPROM_WriteBuffer(0x0FF82, (uint8_t * ) & current_firm, 1); //Пишем в 0x0FF82 current_firm
    }
    NVIC_SystemReset();

}