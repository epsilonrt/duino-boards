/* Copyright © 2018 Pascal JEAN, All rights reserved.
 * This file is part of the Duino Boards Package.
 *
 * The Duino Boards Package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * The Duino Boards Package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with the Duino Boards Package; if not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _VARIANTS_H_
#define _VARIANTS_H_

#define STANDARD        0
#define TOUERIS_DHMI    1
#define TOUERIS_MODBUS  2

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
#define USBPWR_AUTODETECT 0
#define USBPWR_AUTOSWITCH 0
#define USBPWR_MODE USB_CONFIG_ATTR_BUSPOWERED

#elif VARIANT == TOUERIS_MODBUS
#define TX_LED_DDR DDRD
#define TX_LED_PORT PORTD
#define TX_LED_BIT 5
#define TX_LED_ACT 0
#define RX_LED_DDR DDRD
#define RX_LED_PORT PORTD
#define RX_LED_BIT 5
#define RX_LED_ACT 0
#define L_LED_DDR DDRB
#define L_LED_PORT PORTB
#define L_LED_BIT 0
#define L_LED_ACT 0

#define USBPWR_AUTODETECT 1
#define USBPWR_AUTOSWITCH 0
#define USBPWR_MODE USB_CONFIG_ATTR_SELFPOWERED
#define USBPWR_AD_CHAN 0

#elif VARIANT == TOUERIS_DHMI
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

#define USBPWR_AUTODETECT 1
#define USBPWR_AUTOSWITCH 1
#define USBPWR_MODE USB_CONFIG_ATTR_SELFPOWERED
#define USBPWR_AD_CHAN 0
#define USBPWR_AS_DDR DDRF
#define USBPWR_AS_PORT PORTF
#define USBPWR_AS_BIT 1
#define USBPWR_AS_ACT 0

#endif

#if USBPWR_AUTOSWITCH && !USBPWR_AUTODETECT
#warning USBPWR_AUTOSWITCH implies that USBPWR_AUTODETECT is enabled !
#undef USBPWR_AUTODETECT
#define USBPWR_AUTODETECT 1
#endif

/* ========================================================================== */
#endif /* _VARIANTS_H_ defined */
