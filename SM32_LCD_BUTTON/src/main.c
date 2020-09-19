#include "main.h"

int main(void)
{

	uint8_t pntr = 0;
	uint8_t scr_c = 0;
	uint8_t scr_l = 0;
	uint8_t ScreenCount = 0;
	uint8_t buttonState = 1;
	uint8_t startButtonState = 0;

	SysTick_Config(SystemCoreClock/1000);
	delay_ms(20);
	LCD_ini();
	ButtonPinInit();
	PinInit ();
	while(1)
	{

//-------------------------------------------------------------

		if (SelectButton() == 1)
		{
			buttonState = 1;
		}
		else
		{
			buttonState = 2;
		}


		if (StartButton() == 0)
		{
			startButtonState = 0;
		}
		else
		{
			startButtonState = 1;
		}

//-------------------------------------------------------------

		if ((buttonState == 1) && (ScreenCount == 0))
		{
			pntr = 1;
			scr_c = 0;
			ScreenCount = 1;
		}
		else if ((buttonState == 2) && (ScreenCount == 1))
		{
			pntr = 0;
			scr_c = 0;
			ScreenCount = 2;
		}
		else if ((buttonState == 1) && (ScreenCount == 2))
		{
			pntr = 1;
			scr_c = 1;
			ScreenCount = 3;
		}
		else if ((buttonState == 2) && (ScreenCount == 3))
		{
			pntr = 0;
			scr_c = 1;
			ScreenCount = 0;
		}

//-------------------------------------------------------------

		if ((startButtonState == 1) && (buttonState == 1) && (ScreenCount == 1))
		{
			uint8_t x = 1;
			uint8_t SecondScreenCount = 0;

			if (x == 1)
			{
				if ((buttonState == 1) && (SecondScreenCount == 0))
				{
					pntr = 1;
					scr_c = 2;
					SecondScreenCount = 1;
				}
				else if ((buttonState == 2) && (SecondScreenCount == 1))
				{
					pntr = 0;
					scr_c = 2;
					SecondScreenCount = 2;
				}
				else if ((buttonState == 1) && (SecondScreenCount == 2))
				{
					pntr = 1;
					scr_c = 2;
					SecondScreenCount = 0;

					/*if ((startButtonState == 1) && (buttonState == 1) && (ScreenCount == 3))
					{
						x = 0;
						ScreenCount = 0;
					}
				*/}

			}
		}


//-------------------------------------------------------------

		if ((scr_c == 1) && (scr_l == 0)) 		// Очистка дисплея при
		{								  		// перехде на новый экран
			LCD_Send_Command(0x01);
			delay_ms(2);
			scr_l = 1;
		}
		else if ((scr_c == 0) && (scr_l == 1))
		{
			LCD_Send_Command(0x01);
			delay_ms(2);
			scr_l = 0;
		}

//-------------------------------------------------------------

		LCD_Screen(scr_c);

		LCD_Pointer(pntr);
	}
}



