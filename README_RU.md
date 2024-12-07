
[![donate](https://img.shields.io/badge/%D0%9F%D0%BE%D0%B1%D0%BB%D0%B0%D0%B3%D0%BE%D0%B4%D0%B0%D1%80%D0%B8%D1%82%D1%8C%20%D0%B0%D0%B2%D1%82%D0%BE%D1%80%D0%B0-CloudTips-blue)](https://pay.cloudtips.ru/p/c197b86d) [![readme en](https://img.shields.io/badge/README%20in%20English-214a57)](/README.md)

# Bootloader for Quansheng UVK5 Firmware Switching
* Мультибут на 3 прошивки с независимыми настройками, каналами и калибровками для памяти EEPROM 256 КБ

# Function Description
* Capable of reading firmware from EEPROM and writing it to flash, allowing switching between different firmware versions.
* Reads valid firmware from EEPROM and allows selection via button press for loading.

# Principle Description
* Rewrite the UV-K5 bootloader to load Bootloader B into RAM from EEPROM on startup, then jump to Bootloader B in RAM.
* Bootloader B:
    * Reads firmware from EEPROM and writes it to FLASH.
    * Supports traditional burning communication protocols.

# Requirements
* This bootloader suitable for UVK5 with 2M (256KiB) EEPROM.
* Due to flash size limitations, individual firmware size should not exceed 60KB.
* Requires ST-Link to flash the new bootloader into UVK5's FLASH.

# Instructions
* Also refer to the losehu Bootloader Manual.pdf in this directory.
* `LOSEHU_BASE_BOOT` is the base bootloader used to replace the official Quansheng bootloader. You can make it with Keil.
* The bootloader file `BL_3_XXX.bin` generated after running `make` in the main directory is stored in EEPROM and loaded into RAM by the base bootloader.
* `BL_3_XXX.bin` performs functions such as serial port firmware flashing and firmware switching.

# Disclaimer:

* **I am not responsible**
* Radios may be bricked during the flashing process, and I am not responsible for this.
* I do not assume any legal responsibility. This project is open source; you are free to use it, but you must be responsible for your actions.
