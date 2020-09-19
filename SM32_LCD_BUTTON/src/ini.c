#include "ini.h"

//-------------------------------------------------------------
//Инициализация дисплея
//-------------------------------------------------------------

void LCD_GPIO_ini (void)
{
	GPIO_InitTypeDef GPIO_Init_Pin;

	RS_RCC_FUNC(RS_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = RS_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(RS_PORT, &GPIO_Init_Pin);


	RW_RCC_FUNC(RW_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = RW_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(RW_PORT, &GPIO_Init_Pin);


	EN_RCC_FUNC(EN_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = EN_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(EN_PORT, &GPIO_Init_Pin);


	DB0_RCC_FUNC(DB0_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = DB0_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(DB0_PORT, &GPIO_Init_Pin);


	DB1_RCC_FUNC(DB1_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = DB1_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(DB1_PORT, &GPIO_Init_Pin);


	DB2_RCC_FUNC(DB2_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = DB2_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(DB2_PORT, &GPIO_Init_Pin);


	DB3_RCC_FUNC(DB3_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = DB3_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(DB3_PORT, &GPIO_Init_Pin);


	DB4_RCC_FUNC(DB4_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = DB4_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(DB4_PORT, &GPIO_Init_Pin);


	DB5_RCC_FUNC(DB5_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = DB5_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(DB5_PORT, &GPIO_Init_Pin);


	DB6_RCC_FUNC(DB6_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = DB6_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(DB6_PORT, &GPIO_Init_Pin);


	DB7_RCC_FUNC(DB7_RCC, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = DB7_PIN;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(DB7_PORT, &GPIO_Init_Pin);

	RW(0);
}

void PinInit (void)
{
	GPIO_InitTypeDef GPIO_Init_Pin;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_Init_Pin.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init_Pin.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB, &GPIO_Init_Pin);
}

//-------------------------------------------------------------
//Инициализация кнопок
//-------------------------------------------------------------

void ButtonPinInit (void)
{
	GPIO_InitTypeDef GPIO_Init_Button_Pin;

	BUTTON_RCC_FUNC(BUTTON_RCC, ENABLE);

	GPIO_Init_Button_Pin.GPIO_Pin = BUTTON_PIN_1 | BUTTON_PIN_2;
	GPIO_Init_Button_Pin.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init_Button_Pin.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(BUTTON_PORT, &GPIO_Init_Button_Pin);
}

//-------------------------------------------------------------
//
//-------------------------------------------------------------
