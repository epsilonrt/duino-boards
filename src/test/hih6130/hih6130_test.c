/*
 * hih6130_test.c
 * HIH6130 Test: Takes measurements and display on the serial terminal,
 * the values are displayed in a tabular order to be processed by a spreadsheet,
 * here is a sample display:
 *  HIH6130 Demo
 *  T(oC),H(%)
 *  21.2,53.5
 *  ...
 * Under Windows, the software serialchart (https://code.google.com/archive/p/serialchart)
 * can be used to display measurements in graph form. The serialchart
 * configuration file (hih6130.scc) should be amended to match the serial link
 * connected to the PC (port = COM1) and Max humidity value
 * (max parameter in the [_default_].
 * 
 * Copyright © 2016 epsilonRT, All rights reserved.
 *
 * This software is governed by the CeCILL license under French law and
 * abiding by the rules of distribution of free software.  You can  use, 
 * modify and/ or redistribute the software under the terms of the CeCILL
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * <http://www.cecill.info>. 
 * 
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL license and that you accept its terms.
 *
 * @file
 * @brief
 */
#include <avrio/led.h>
#include <avrio/delay.h>
#include <avrio/hih6130.h>
#include <avrio/tc.h>
#include <avrio/assert.h>
#include <stdio.h>

/* constants ================================================================ */
#define TERMINAL_PORT         "tty0"
#define TERMINAL_BAUDRATE     115200

/* main ===================================================================== */
int
main (void) {
  
  eTwiStatus eTwiError;
  eHih6130Error eError;
  xHih6130Data xData;

  vLedInit ();

  // Initialization of the serial port for display
  xSerialIos settings = SERIAL_SETTINGS (TERMINAL_BAUDRATE);
  FILE * tc = xFileOpen (TERMINAL_PORT, O_WR, &settings);
  stdout = tc;
  sei();

  printf ("\nHIH6130 Test\n");

  // I²C bus initialization as master at 100 kHz and no error checking
  vTwiInit ();
  
  eTwiError = eTwiSetSpeed (400);
  if (eTwiError != TWI_SUCCESS) {

    printf ("eTwiSetSpeed failed, error = % d\n", eTwiError);
    for (;;);
  }

  // Initialization of the sensor and no error checking
  eError = eHih6130Init (0);
  assert (eError == HIH6130_SUCCESS);

  // prints the header
  printf ("T(oC),H(%%)\n");

  for (;;) {


    // The duration at the ON state of LED1 is the measurement time of the sensor
    vLedSet (LED_LED1);
    // Starting measurement and no error checking
    eError = eHih6130Start();
    assert (eError == HIH6130_SUCCESS);

    do {

      // Reading
      eError = eHih6130Read (&xData);
      // no error checking
      assert (eError >= HIH6130_SUCCESS);
    } while (eError == HIH6130_BUSY);
    vLedClear (LED_LED1);

    // Display measures
    printf ("%.1f,%.1f\n", xData.iTemp / 10.0, xData.iHum / 10.0);
    delay_ms (500);
  }
  return 0;
}

/* ========================================================================== */
