/*
 * display.h
 *
 *  Created on: 11 juin 2025
 *      Author: abelk
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_


typedef enum {
    DISPLAY_INIT,
    DISPLAY_ALARM_ON,
    DISPLAY_ALARM_OFF,
    DISPLAY_MOTION_DETECTED
} DisplayMode;

void display_init(void); // Init screen
void display_show(DisplayMode mode); // Display selected mode


#endif /* INC_DISPLAY_H_ */
