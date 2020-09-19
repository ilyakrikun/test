#include "button.h"

uint8_t lastButtonState = 0;
uint8_t currentButtonState = 0;
uint8_t buttonState_count = 0;
uint8_t butt_count = 0;
uint8_t pntr_count = 0;

uint8_t lastSelectButtonState = 0;
uint8_t currentSelectButtonState = 0;
uint8_t selectButtonState_count = 1;

//-------------------------------------------------------------
//
//-------------------------------------------------------------

uint8_t DebounceStartButton (uint8_t lastStartState)
{
	SysTick_Config(SystemCoreClock/1000);

	uint8_t currentState = BUTTONREAD();
	if (currentState != lastStartState)
	{
		delay_ms(5);
		currentState = BUTTONREAD();
	}
	return currentState;
}

//-------------------------------------------------------------
//
//-------------------------------------------------------------

uint8_t DebounceSelectButton (uint8_t lastSelectState)
{
	SysTick_Config(SystemCoreClock/1000);

	uint8_t currentState = SELECTBUTTONREAD();
	if (currentState != lastSelectState)
	{
		delay_ms(5);
		currentState = SELECTBUTTONREAD();
	}
	return currentState;
}

//-------------------------------------------------------------
//
//-------------------------------------------------------------



uint8_t StartButton (void)
{

	currentButtonState = DebounceStartButton(lastButtonState);

	if (currentButtonState == 1 && lastButtonState == 0)
	{
		buttonState_count++;
		lastButtonState = currentButtonState;

		if (buttonState_count > 1)
		{
			buttonState_count = 0;
		}

	}
	else if (currentButtonState == 0 && lastButtonState == 1)
	{
		lastButtonState = currentButtonState;
	}
/*
	if ((buttonState_count == 1) && (pntr == 1))
	{
		pntr_count = 1;
		buttonState_count = 0;

	}
	else if ((buttonState_count == 1) && (pntr == 0))
	{
		pntr_count = 0;
		buttonState_count = 0;
	}

	if (pntr_count == 1)
	{
		ON();
	}
	else
	{
		OFF();
	}
*/
	return buttonState_count;
}


//-------------------------------------------------------------
//
//-------------------------------------------------------------

uint8_t SelectButton (void)
{

	uint8_t countNumber = 2;

	currentSelectButtonState = DebounceSelectButton(lastSelectButtonState);

	if (currentSelectButtonState == 1 && lastSelectButtonState == 0)
	{
		selectButtonState_count++;
		lastSelectButtonState = currentSelectButtonState;

		if (selectButtonState_count > countNumber)
		{
			selectButtonState_count = 1;
		}

	}
	else if (currentSelectButtonState == 0 && lastSelectButtonState == 1)
	{
		lastSelectButtonState = currentSelectButtonState;
	}

	return selectButtonState_count ;
}

//-------------------------------------------------------------
//
//-------------------------------------------------------------
