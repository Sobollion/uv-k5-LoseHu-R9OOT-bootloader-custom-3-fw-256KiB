
[![support me](https://img.shields.io/badge/Support%20me-CloudTips-blue)](https://pay.cloudtips.ru/p/c197b86d) [![readme ru](https://img.shields.io/badge/README%20%D0%BD%D0%B0%20%D1%80%D1%83%D1%81%D1%81%D0%BA%D0%BE%D0%BC-214a57)](/README_RU.md)

# Bootloader for Quansheng UVK5 Firmware Switching
* 3 firmware Multiboot with independent settings, channels and calibrations for 256 KiB EEPROM
* 4 firmware Multiboot with independent settings, channels and calibrations for 512 KiB EEPROM
* 6 firmware Multiboot with independent settings, channels and calibrations for 512 KiB EEPROM

# Function Description
* Capable of reading firmware from EEPROM and writing it to flash, allowing switching between different firmware versions.
* Reads valid firmware from EEPROM and allows selection via button press for loading.
* Also reading configs for each firmware and put on top of EEPROM. And replace it while firmware change.

# Principle Description
* Rewrite the UV-K5 bootloader to load Bootloader B into RAM from EEPROM on startup, then jump to Bootloader B in RAM.
* Bootloader B:
    * Reads firmware from EEPROM and writes it to FLASH.
    * Supports traditional burning communication protocols.

# Requirements
* This bootloaders suitable for UVK5 with 2M (256KiB) and 4M (512KiB) EEPROM.
* Due to flash size limitations, individual firmware size should not exceed 60KB.
* Requires ST-Link to flash the new bootloader into UVK5's FLASH.

# Instructions
* Use https://github.com/Sobollion/R9OOT_BOOT on windows or run it with python on other OS.
* `LOSEHU_BASE_BOOT` is the base bootloader used to replace the official Quansheng bootloader. You can make it with Keil.
* The bootloader file `BL_3_XXX.bin`/`BL_4_XXX.bin`/`BL_6_XXX.bin` generated after running `make` in the main directory is stored in EEPROM and loaded into RAM by the base bootloader.
* `BL_X_XXX.bin` performs functions such as serial port firmware flashing and firmware switching. NEED TO DEBUG!

# Disclaimer:

* **I am not responsible**
* Radios may be bricked during the flashing process, and I am not responsible for this.
* I do not assume any legal responsibility. This project is open source; you are free to use it, but you must be responsible for your actions.

# This development exists thanks to LoseHu
Donation QR code:

[![Donation QR code](https://github.com/losehu/uv-k5-firmware-chinese/blob/main/payment/show.png)](https://losehu.github.io/payment-codes/)
