#include "delay.h"

uint16_t delay_count = 0;

//-------------------------------------------------------------
//Задержка
//-------------------------------------------------------------

void SysTick_Handler (void)
{
	if (delay_count > 0)
	{
		delay_count--;
	}
}

void delay_ms (uint16_t delay_par)
{
	delay_count = delay_par;
	while(delay_count) {}
}

void LCD_delay_ms (void)
{
	uint16_t i;
	for (i = 0; i < 1000; i++)
	{

	}
}

//-------------------------------------------------------------
//
//-------------------------------------------------------------
