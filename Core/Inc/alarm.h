/*
 * alarm.h
 *
 *  Created on: Jun 1, 2025
 *      Author: abelk
 */

#ifndef INC_ALARM_H_
#define INC_ALARM_H_

#include <stdint.h>

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
uint8_t getAlarmStatus(void);
void AlarmInit(void);

#endif /* INC_ALARM_H_ */
