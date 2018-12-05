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
#ifndef _USB_POWER_H_
#define _USB_POWER_H_

#include <avr/io.h>
#include <stdint.h>

#include "Variants.h"

// -----------------------------------------------------------------------------
static inline void
USBPWR_AS_SETUP (void) {

#if USBPWR_AUTOSWITCH != 0
  USBPWR_AS_DDR |= (1 << USBPWR_AS_BIT);
#if USBPWR_AS_ACT != 0
  USBPWR_AS_PORT |= (1 << USBPWR_AS_BIT);
#else
  USBPWR_AS_PORT &= ~ (1 << USBPWR_AS_BIT);
#endif /* USBPWR_AS_ACT == 0 */
#endif /* USBPWR_AUTOSWITCH != 0*/
}

// -----------------------------------------------------------------------------
static inline void
USBPWR_AD_SETUP (void) {

#if USBPWR_AUTODETECT != 0
  ADMUX = (1 << REFS1) | (1 << REFS0) | USBPWR_AD_CHAN;
  ADCSRA = (1 << ADEN) | (1 << ADIF) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
#endif  /* USBPWR_AUTODETECT != 0*/
}

// -----------------------------------------------------------------------------
static inline void
USBPWR_AD_RELEASE (void) {

#if USBPWR_AUTODETECT != 0
  ADCSRA = 0;
  ADMUX = 0;
#endif  /* USBPWR_AUTODETECT != 0*/
}

// -----------------------------------------------------------------------------
static inline uint8_t
USBPWR_GET_MODE (void) {
#if USBPWR_AUTODETECT != 0
  for (int8_t i = 0; i < 4; i++) {
    ADCSRA |= 1 << ADSC;
    while (ADCSRA & (1 << ADSC))
      ;
  }
  if (ADC < 680) {

    USBPWR_AS_SETUP();
    return USB_DEVICE_OPT_FULLSPEED | USB_OPT_AUTO_PLL | USB_OPT_REG_DISABLED;
  }
#endif  /* USBPWR_AUTODETECT != 0*/
  return USB_DEVICE_OPT_FULLSPEED | USB_OPT_AUTO_PLL | USB_OPT_REG_ENABLED;
}

// -----------------------------------------------------------------------------
static inline void
BLBUT_INIT (void) {
#ifdef BL_BUT
  BL_BUT_PORT |= _BV (BL_BUT);
#endif
}

// -----------------------------------------------------------------------------
static inline uint8_t
BLBUT_GET (void) {
#ifdef BL_BUT
  return (BL_BUT_PIN & _BV (BL_BUT)) != 0;
#endif
}

// -----------------------------------------------------------------------------
static inline void
BLBUT_RELEASE (void) {
#ifdef BL_BUT
  BL_BUT_PORT &= ~_BV (BL_BUT);
#endif
}

/* ========================================================================== */
#endif /* _USB_POWER_H_ defined */
