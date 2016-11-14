/*Library concerned with the control of the serial OLED display.
will utilize the SPI library to achieve communicaiton
*/

#include <SPI.h>

#ifndef display_h_
#define display_h_

void initializeDisplay(); //setup the splash screen and main overlay
void changeSpeed(uint8_t speed); //change the value of the speed displayed on the overlay.
void changeCharge(uint8_t charge); //change the value of the battery charge displayed on the overlay
void changeRPM(uint8_t rpm); //change the value of the rpm displayed on the overlay.

#endif