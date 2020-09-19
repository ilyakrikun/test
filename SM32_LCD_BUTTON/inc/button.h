#ifndef BUTTON_H
#define BUTTON_H

#include "stm32f10x.h"
#include "main.h"

uint8_t DebounceStartButton (uint8_t lastStartState);
uint8_t DebounceSelectButton (uint8_t lastSelectState);
uint8_t StartButton (void);
uint8_t SelectButton (void);

#endif
