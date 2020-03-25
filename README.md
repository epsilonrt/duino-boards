# Duino Boards Package

*Arduino IDE compatible boards*

---
Copyright © 2015-2018 Pascal JEAN, All rights reserved.

# How to install

## Boards Manager Installation

This installation method requires Arduino IDE version 1.6.5 or greater.

* Find the desired Duino Boards release on the [Duino Boards Release page](https://github.com/epsilonrt/duino-boards/releases)  
* Use the "Copy link address" feature of your browser to copy the URL of the associated **.json** file  
* Open the Arduino IDE  
* Open the **File > Preferences** menu item  
* Paste the following URL in **Additional Boards Manager URLs**  
    * Separate the URLs using a comma ( **,** ) if you have more than one URL  
* Open the **Tools > Board > Boards Manager...** menu item  
* Wait for the platform indexes to finish downloading  
* Scroll down until you see the **Duino Boards** entry and click on it  
* Click **Install**.
* After installation is complete close the **Boards Manager** window.

## Manual Installation

* Find the desired Duino Boards release on the [Duino Boards Release page](https://github.com/epsilonrt/duino-boards/releases)  
* Click on the `duino-boards.tar.gz` file. Extract the archive file, and move the extracted folder to the location "**~/Documents/Arduino/hardware**". Create the "hardware" folder if it doesn't exist.
* Open Arduino IDE, and a new category in the boards menu called "Duino Boards" will show up.

## IDE Board options

## BOD option

Brown out detection, or BOD for short lets the microcontroller sense the input voltage and shut down if the voltage goes below the brown out setting. To change the BOD settings you'll have to connect an ISP programmer and hit "Burn bootloader". Below is a table that shows the available BOD options:


## Link time optimization / LTO

Link time optimization (LTO for short) have been supported by the IDE since v1.6.11. The LTO optimizes the code at link time, making the code (often) significantly smaller without making it "slower". In Arduino IDE 1.6.11 and newer LTO is enabled by default. I've chosen to disable this by default to make sure the core keep backward compatibility. Enabling LTO in IDE 1.6.10 and older will return an error. 
I encourage you to try the new LTO option and see how much smaller your code gets! Note that you don't need to hit "Burn Bootloader" in order to enable LTO. Simply enable it in the "Tools" menu, and your code is ready for compilation. If you want to read more about LTO and GCC flags in general, head over to the [GNU GCC website](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)!
<br/> <br/>
Here's some numbers to convince you. These sketches were compiled for an **ATmega1284** using **Arduino IDE 1.6.12 (avr-gcc 4.9.2)**. Impressing, right?
<br/>

|                  | Blink.ino  | AnalogReadSerial.ino  | SerialReadWrite.ino | CardInfo.ino |
|------------------|------------|-----------------------|---------------------|--------------|
| **LTO enabled**  | 1084 bytes | 1974 bytes            | 7190 bytes          | 9416 bytes   |
| **LTO disabled** | 1216 bytes | 2414 bytes            | 7710 bytes          | 11518 bytes  |

## Boards List

* [Hmi4DinBox](https://github.com/epsilonrt/Hmi4DinBox) Human-Machine Interface for Din Box 
* [xPLBee Board](https://github.com/epsilonrt/xplbee)  
* MODBUS Slave boards from Toueris project
* MODBUS Slave boards from PointCast Supervisor project
* MODBUS Slave boards from LoRaBus project

------
