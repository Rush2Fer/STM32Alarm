/*
 * alarm.c
 *
 *  Created on: Jun 1, 2025
 *      Author: abelk
 */

#include "alarm.h"
#include <stdint.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
volatile uint8_t alarm_movement=0;
static volatile uint8_t alarm_status=0;
static uint32_t touch_last_call;





void AlarmInit(void){
	touch_last_call=HAL_GetTick();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_13)  // Movement
    {
        if (HAL_GetTick() - touch_last_call >= 500)
        {
            alarm_movement = 1; // Prevent movement due to touch
        }
    }
    else if (GPIO_Pin == GPIO_PIN_14)  // Touch
    {
        if (HAL_GetTick() - touch_last_call >= 1000)
        {
            touch_last_call = HAL_GetTick();
            alarm_status ^= 1;
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, alarm_status);
            alarm_movement&=alarm_status;
        }
    }
}

/*
 * Returns
 * 0 if alarm OFF
 * 1 if alarm ON
 * 2 if alarm ON and MOVEMENT DETECTED
 * */
uint8_t getAlarmStatus(void){
	return alarm_status + (alarm_movement & alarm_status);
}
