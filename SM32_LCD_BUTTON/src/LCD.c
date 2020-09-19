#include "LCD.h"

//-------------------------------------------------------------
//Настройка
//-------------------------------------------------------------

void LCD_Set_Data (uint8_t data)
{
	if ( ((data >> 7) & 0x01) == 1){ DB7(1); } else { DB7(0); }
	if ( ((data >> 6) & 0x01) == 1){ DB6(1); } else { DB6(0); }
	if ( ((data >> 5) & 0x01) == 1){ DB5(1); } else { DB5(0); }
	if ( ((data >> 4) & 0x01) == 1){ DB4(1); } else { DB4(0); }
	if ( ((data >> 3) & 0x01) == 1){ DB3(1); } else { DB3(0); }
	if ( ((data >> 2) & 0x01) == 1){ DB2(1); } else { DB2(0); }
	if ( ((data >> 1) & 0x01) == 1){ DB1(1); } else { DB1(0); }
	if ( ((data >> 0) & 0x01) == 1){ DB0(1); } else { DB0(0); }
}

void LCD_Send_Command (uint8_t data)
{
	RS(0);
	LCD_Set_Data (data);
	EN(1);
	LCD_delay_ms();
	EN(0);
}

void LCD_Send_Data (uint8_t data)
{
	RS(1);
	LCD_Set_Data (data);
	EN(1);
	LCD_delay_ms();
	EN(0);
}

void LCD_ini (void)
{
	LCD_GPIO_ini();

// Настройка дисплея

	LCD_Send_Command(0x38);
	delay_ms(1);
	LCD_Send_Command(0x38);
	delay_ms(1);
	LCD_Send_Command(0x0C); // Настройка курсора
	delay_ms(2);
	LCD_Send_Command(0x01); // Очистка дисплея
	delay_ms(2);
	LCD_Send_Command(0x06);
	delay_ms(1);
	LCD_Send_Command(0x02);
	delay_ms(2);
}

//-------------------------------------------------------------
// Вывод изображения
//-------------------------------------------------------------

void LCD_Send_String (uint8_t str_num, char* str)
{
	uint8_t i = 0;

	if (str_num == 0)
	{
		LCD_Send_Command(0x80);
	}
	else
	{
		LCD_Send_Command(0xC0);
	}
	delay_ms(1);

	while (str[i] != 0)
	{
		LCD_Send_Data(str[i]);
		i++;
		LCD_delay_ms();
	}
}

void LCD_Send_Pointer (uint8_t pntr, char* str)
{
	uint8_t i = 0;
	if (pntr == 0)
	{
		LCD_Send_Command(0x8C);
		delay_ms(1);
	}
	else
	{
		LCD_Send_Command(0xCC);
		delay_ms(1);

	}
	while (str[i] != 0)
	{
		LCD_Send_Data(str[i]);
		i++;
		LCD_delay_ms();
	}
}


void LCD_Screen (uint8_t screen)
{

	char str1[] = "Short";
	char str2[] = "Long";
	char str3[] = "Beer";
	char str4[] = "Wine";
	char str5[] = "Vodka";
	char str6[] = "Kognak";
	char str7[] = "Back";

	if (screen == 0)
	{
		LCD_Send_String(0, str1);
		LCD_Send_String(1, str2);

	}
	else if (screen == 1)
	{
		LCD_Send_String(0, str3);
		LCD_Send_String(1, str4);
	}
	else if (screen == 2)
	{
		LCD_Send_String(0, str5);
		LCD_Send_String(1, str6);
	}
	else if (screen == 3)
	{
		LCD_Send_String(0, str7);
		//LCD_Send_String(1, str6);
	}
}

void LCD_Pointer (uint8_t pntr)
{

	char str1[] = "<";
	char str2[] = " ";

	if (pntr == 1)
	{
		LCD_Send_Pointer (0, str1);
		LCD_Send_Pointer (1, str2);
	}
	else
	{
		LCD_Send_Pointer (0, str2);
		LCD_Send_Pointer (1, str1);
	}
}

//-------------------------------------------------------------
//
//-------------------------------------------------------------
