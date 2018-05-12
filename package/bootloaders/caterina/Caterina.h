/*
             LUFA Library
     Copyright (C) Dean Camera, 2011.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2011  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for BootloaderCDC.c.
 */

#ifndef _CDC_H_
#define _CDC_H_

/* Includes: */
#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/boot.h>
#include <avr/eeprom.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <stdbool.h>

#include "Descriptors.h"

#include <LUFA/Drivers/USB/USB.h>
/* Macros: */
/** Version major of the CDC bootloader. */
#define BOOTLOADER_VERSION_MAJOR     0x01

/** Version minor of the CDC bootloader. */
#define BOOTLOADER_VERSION_MINOR     0x00

/** Hardware version major of the CDC bootloader. */
#define BOOTLOADER_HWVERSION_MAJOR   0x01

/** Hardware version minor of the CDC bootloader. */
#define BOOTLOADER_HWVERSION_MINOR   0x00

/** Eight character bootloader firmware identifier reported to the host when requested */
#define SOFTWARE_IDENTIFIER          "CATERINA"

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

#define STANDARD    0
#define TOUERIS_HMI 1

#if VARIANT == STANDARD
#define L_LED_DDR DDRC
#define L_LED_PORT PORTC
#define L_LED_BIT 7
#define L_LED_ACT 1
#define TX_LED_DDR DDRD
#define TX_LED_PORT PORTD
#define TX_LED_BIT 5
#define TX_LED_ACT 0
#define RX_LED_DDR DDRB
#define RX_LED_PORT PORTB
#define RX_LED_BIT 0
#define RX_LED_ACT 0
#elif VARIANT == TOUERIS_HMI
#define L_LED_DDR DDRD
#define L_LED_PORT PORTD
#define L_LED_BIT 7
#define L_LED_ACT 1
#define TX_LED_DDR DDRD
#define TX_LED_PORT PORTD
#define TX_LED_BIT 5
#define TX_LED_ACT 1
#define RX_LED_DDR DDRB
#define RX_LED_PORT PORTB
#define RX_LED_BIT 0
#define RX_LED_ACT 1
#endif

#define LED_SETUP()   do { L_LED_DDR |= (1<<L_LED_BIT); RX_LED_DDR |= (1<<RX_LED_BIT); TX_LED_DDR |= (1<<TX_LED_BIT); } while(0)

#if L_LED_ACT != 0
#define L_LED_OFF()     L_LED_PORT &= ~(1<<L_LED_BIT)
#define L_LED_ON()      L_LED_PORT |= (1<<L_LED_BIT)
#else
#define L_LED_OFF()     L_LED_PORT |= (1<<L_LED_BIT)
#define L_LED_ON()      L_LED_PORT &= ~(1<<L_LED_BIT)
#endif

#define L_LED_TOGGLE()  L_LED_PORT ^= (1<<L_LED_BIT)

#if TX_LED_ACT != 0
#define TX_LED_OFF()    TX_LED_PORT &= ~(1<<TX_LED_BIT)
#define TX_LED_ON()     TX_LED_PORT |= (1<<TX_LED_BIT)
#else
#define TX_LED_OFF()    TX_LED_PORT |= (1<<TX_LED_BIT)
#define TX_LED_ON()     TX_LED_PORT &= ~(1<<TX_LED_BIT)
#endif

#if RX_LED_ACT != 0
#define RX_LED_OFF()    RX_LED_PORT &= ~(1<<RX_LED_BIT)
#define RX_LED_ON()     RX_LED_PORT |= (1<<RX_LED_BIT)
#else
#define RX_LED_OFF()    RX_LED_PORT |= (1<<RX_LED_BIT)
#define RX_LED_ON()     RX_LED_PORT &= ~(1<<RX_LED_BIT)
#endif

/* Type Defines: */
/** Type define for a non-returning pointer to the start of the loaded application in flash memory. */
typedef void (*AppPtr_t) (void) ATTR_NO_RETURN;

/* Function Prototypes: */
void StartSketch (void);
void LEDPulse (void);

void CDC_Task (void);
void SetupHardware (void);

void EVENT_USB_Device_ConfigurationChanged (void);

#if defined(INCLUDE_FROM_CATERINA_C) || defined(__DOXYGEN__)
#if !defined(NO_BLOCK_SUPPORT)
static void    ReadWriteMemoryBlock (const uint8_t Command);
#endif
static uint8_t FetchNextCommandByte (void);
static void    WriteNextResponseByte (const uint8_t Response);
#endif

#endif
