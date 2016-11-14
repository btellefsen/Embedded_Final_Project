#ifndef ADC_H_
#define ADC_H_

void setupADC(uint8_t port, uint8_t pin); //set the necessary registers for a pin to read analog voltages.
uint16_t readADC(uint8_t port, uint8_t pin); //begin a read. The ADC handler will send the value over UART once it's ready


#endif