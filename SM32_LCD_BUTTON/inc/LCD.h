#ifndef LCD_H
#define LCD_H

#include "stm32f10x.h"
#include "main.h"

void LCD_Send_String (uint8_t str_num, char* str);
void LCD_Send_Pointer (uint8_t pntr, char* str);
void LCD_Set_Data (uint8_t data);
void LCD_Send_Command (uint8_t data);
void LCD_Send_Data (uint8_t data);
void LCD_ini (void);
void LCD_Screen (uint8_t screen);
void LCD_Pointer (uint8_t pntr);

#endif
