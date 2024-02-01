#include "MKL25Z4.h"                    // Device header

#define RED_LED 	18 // PortB Pin 18
#define GREEN_LED 19 // PortB Pin 19
#define BLUE_LED 	1 // PortD Pin 1
#define MASK(x) 	(1 << (x))

unsigned int counter = 0;

//TODO: led_color_t Enum

void InitGPIO(void)
{
  // Enable Clock to PORTB and PORTD
  SIM->SCGC5 |= ((SIM_SCGC5_PORTB_MASK) | (SIM_SCGC5_PORTD_MASK));
	
  // Configure MUX settings to make all 3 pins GPIO
  PORTB->PCR[RED_LED] &= ~PORT_PCR_MUX_MASK;
  PORTB->PCR[RED_LED] |= PORT_PCR_MUX(1);
	
  PORTB->PCR[GREEN_LED] &= ~PORT_PCR_MUX_MASK;
  PORTB->PCR[GREEN_LED] |= PORT_PCR_MUX(1);
	
  PORTD->PCR[BLUE_LED] &= ~PORT_PCR_MUX_MASK;
  PORTD->PCR[BLUE_LED] |= PORT_PCR_MUX(1);
	
  // Set Data Direction Registers for PortB and PortD
  PTB->PDDR |= (MASK(RED_LED) | MASK(GREEN_LED));
  PTD->PDDR |= MASK(BLUE_LED);
}

//TODO: offRGB function

/* TODO: led_control(led_color_t color) function
	- led_color_t is a enum holding possible color types
	- This function takes only the color value and controls the appropriate LED
*/

/* Delay function */
static void delay(volatile uint32_t nof) {
  while(nof!=0) {
    __asm("NOP");
    nof--;
  }
}


/* MAIN function */
int main(void) {
  SystemCoreClockUpdate();
  InitGPIO();
  
  //TODO: Light RGB one colour at a time, RED->GREEN->BLUE->RED->GREEN->...
}
