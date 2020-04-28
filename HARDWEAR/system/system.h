#ifndef __SYSTEM_H
#define __SYSTEM_H
#include "system.h"
#include "stm32f4xx_hal.h"
#include "cmd.h"
#include "pwm.h"
#include "usart.h"
void System_Init(void);
void SystemClock_Config(void);

#endif
