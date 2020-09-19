#ifndef MAIN_H
#define MAIN_H

#include "stm32f10x.h"
#include "ini.h"
#include "delay.h"
#include "LCD.h"
#include "button.h"



//-------------------------------------------------------------
//Дефайны дисплея
//-------------------------------------------------------------

#define RS_RCC_FUNC			RCC_APB2PeriphClockCmd
#define RS_RCC				RCC_APB2Periph_GPIOA
#define RS_PIN				GPIO_Pin_1
#define RS_PORT				GPIOA

#define RW_RCC_FUNC			RCC_APB2PeriphClockCmd
#define RW_RCC				RCC_APB2Periph_GPIOA
#define RW_PIN				GPIO_Pin_2
#define RW_PORT				GPIOA

#define EN_RCC_FUNC			RCC_APB2PeriphClockCmd
#define EN_RCC				RCC_APB2Periph_GPIOA
#define EN_PIN				GPIO_Pin_3
#define EN_PORT				GPIOA

#define DB0_RCC_FUNC		RCC_APB2PeriphClockCmd
#define DB0_RCC				RCC_APB2Periph_GPIOA
#define DB0_PIN				GPIO_Pin_4
#define DB0_PORT			GPIOA

#define DB1_RCC_FUNC		RCC_APB2PeriphClockCmd
#define DB1_RCC				RCC_APB2Periph_GPIOA
#define DB1_PIN				GPIO_Pin_5
#define DB1_PORT			GPIOA

#define DB2_RCC_FUNC		RCC_APB2PeriphClockCmd
#define DB2_RCC				RCC_APB2Periph_GPIOA
#define DB2_PIN				GPIO_Pin_6
#define DB2_PORT			GPIOA

#define DB3_RCC_FUNC		RCC_APB2PeriphClockCmd
#define DB3_RCC				RCC_APB2Periph_GPIOA
#define DB3_PIN				GPIO_Pin_7
#define DB3_PORT			GPIOA

#define DB4_RCC_FUNC		RCC_APB2PeriphClockCmd
#define DB4_RCC				RCC_APB2Periph_GPIOA
#define DB4_PIN				GPIO_Pin_8
#define DB4_PORT			GPIOA

#define DB5_RCC_FUNC 		RCC_APB2PeriphClockCmd
#define DB5_RCC				RCC_APB2Periph_GPIOA
#define DB5_PIN				GPIO_Pin_9
#define DB5_PORT			GPIOA

#define DB6_RCC_FUNC		RCC_APB2PeriphClockCmd
#define DB6_RCC				RCC_APB2Periph_GPIOA
#define DB6_PIN				GPIO_Pin_10
#define DB6_PORT			GPIOA

#define DB7_RCC_FUNC		RCC_APB2PeriphClockCmd
#define DB7_RCC				RCC_APB2Periph_GPIOA
#define DB7_PIN				GPIO_Pin_11
#define DB7_PORT			GPIOA

#define RS(a)				GPIO_WriteBit(RS_PORT, RS_PIN, (BitAction)a)
#define RW(a)				GPIO_WriteBit(RW_PORT, RW_PIN, (BitAction)a)
#define EN(a)				GPIO_WriteBit(EN_PORT, EN_PIN, (BitAction)a)

#define DB0(a)				GPIO_WriteBit(DB0_PORT, DB0_PIN, (BitAction)a)
#define DB1(a)				GPIO_WriteBit(DB1_PORT, DB1_PIN, (BitAction)a)
#define DB2(a)				GPIO_WriteBit(DB2_PORT, DB2_PIN, (BitAction)a)
#define DB3(a)				GPIO_WriteBit(DB3_PORT, DB3_PIN, (BitAction)a)
#define DB4(a)				GPIO_WriteBit(DB4_PORT, DB4_PIN, (BitAction)a)
#define DB5(a)				GPIO_WriteBit(DB5_PORT, DB5_PIN, (BitAction)a)
#define DB6(a)				GPIO_WriteBit(DB6_PORT, DB6_PIN, (BitAction)a)
#define DB7(a)				GPIO_WriteBit(DB7_PORT, DB7_PIN, (BitAction)a)

//-------------------------------------------------------------
//Дефайны кнопок
//-------------------------------------------------------------

#define BUTTONREAD()			GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)
#define	SELECTBUTTONREAD()		GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_0)
#define BUTTON_RCC_FUNC			RCC_APB2PeriphClockCmd
#define BUTTON_RCC				RCC_APB2Periph_GPIOB
#define BUTTON_PIN_1			GPIO_Pin_11
#define BUTTON_PIN_2			GPIO_Pin_0
#define BUTTON_PORT				GPIOB
#define ON()  					GPIO_SetBits(GPIOB, GPIO_Pin_10)
#define OFF() 					GPIO_ResetBits(GPIOB, GPIO_Pin_10)

//-------------------------------------------------------------
//Дефайны выходов
//-------------------------------------------------------------

#endif
