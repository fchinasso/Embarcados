#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "driverlib/systick.h"
#include "driverleds.h" // Projects/drivers

// MEF com apenas 2 estados e 1 evento temporal que alterna entre eles
// Seleção por estado

typedef enum {s0,s1,s2,s3,s4,s5,s6,s7} state_t;

volatile uint8_t Evento = 0;

void SysTick_Handler(void){
  Evento = 1;
} // SysTick_Handler

void main(void){
  static state_t Estado = s0; // estado inicial da MEF
  
  LEDInit(LED1);
  LEDInit(LED2);
  LEDInit(LED3);
 
  SysTickPeriodSet(12000000); // f = 1Hz para clock = 24MHz
  SysTickIntEnable();
  SysTickEnable();

  while(1){
    switch(Estado){
    case s0:
      LEDOff(LED1);
      LEDOff(LED2);
      LEDOff(LED3);
      if(Evento){
        Evento = 0;
        Estado = s1;
      } // if
      break;
    case s1:
       LEDOff(LED1);
      LEDOff(LED2);
      LEDOn(LED3);
      if(Evento){
        Evento = 0;
        Estado = s2;
      } // if
      break;
      case s2:
      LEDOff(LED1);
      LEDOn(LED3);
      LEDOn(LED2);
      if(Evento){
        Evento = 0;
        Estado = s3;
      } // if
      break;
     case s3:
      LEDOff(LED1);
      LEDOn(LED2);
      LEDOff(LED3);
      if(Evento){
        Evento = 0;
        Estado = s4;
      } // if
      break;
      case s4:
      LEDOn(LED1);
      LEDOn(LED2);
      LEDOff(LED3);
      if(Evento){
        Evento = 0;
        Estado = s5;
      } // if
      break;
      case s5:
      LEDOn(LED1);
      LEDOn(LED2);
      LEDOn(LED3);
      if(Evento){
        Evento = 0;
        Estado = s6;
      } // if
      break;
      case s6:
       LEDOn(LED1);
      LEDOff(LED2);
      LEDOn(LED3);
      if(Evento){
        Evento = 0;
        Estado = s7;
      } // if
      break;
      case s7:
      LEDOn(LED1);
      LEDOff(LED2);
      LEDOff(LED3);
      if(Evento){
        Evento = 0;
        Estado = s0;
      } // if
      break;
    } // switch
  } // while
} // main
