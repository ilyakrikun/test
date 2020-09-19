#ifndef DELAY_H
#define DELAY_H

#include "stm32f10x.h"
#include "main.h"

void SysTick_Handler (void);
void delay_ms (uint16_t delay_par);
void LCD_delay_ms (void);

#endif
