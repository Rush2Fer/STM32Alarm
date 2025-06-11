/*
 * display.c
 *
 *  Created on: 11 juin 2025
 *      Author: abelk
 */


#include "display.h"

#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "bitmaps.h"

void display_init(void) {
    // Init
  ssd1306_Init();
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();
  HAL_Delay(500);
  ssd1306_Init();
  ssd1306_Fill(Black);
  ssd1306_UpdateScreen();
}

void display_show(DisplayMode mode) {
    switch (mode) {
        case DISPLAY_INIT:
        	ssd1306_Fill(Black);
            ssd1306_DrawBitmap(5, 5, github_logo_64x64, 64, 64, White);
            ssd1306_SetCursor(80, 20);
            ssd1306_WriteString("Rush2Fer", Font_6x8, White);
            ssd1306_SetCursor(80, 40);
            ssd1306_WriteString("Alarm", Font_6x8, White);
            ssd1306_SetCursor(70, 50);
            ssd1306_WriteString("System", Font_6x8, White);
            ssd1306_UpdateScreen();
            break;
        case DISPLAY_ALARM_ON:
        	for(int i=0;i<27;i++){
				ssd1306_Fill(Black);
				ssd1306_DrawBitmap(50, 0, alarm_on_32x32[i], 32, 32, White);
				ssd1306_SetCursor(10, 40);
				ssd1306_WriteString("ALARM ON", Font_11x18, White);
				ssd1306_UpdateScreen();
			}
            break;
        case DISPLAY_ALARM_OFF:
        	for(int i=0;i<27;i++){
				ssd1306_Fill(Black);
				ssd1306_DrawBitmap(30, 0, loading_64x64[i], 64, 64, White);
				ssd1306_SetCursor(40, 50);
				ssd1306_WriteString("Standby...", Font_7x10, White);
				ssd1306_UpdateScreen();
			}
            break;
        case DISPLAY_MOTION_DETECTED:
        	for(int i=0;i<27;i++){
				ssd1306_Fill(Black);
				ssd1306_DrawBitmap(30, 0, eye_64x64[i], 64, 64, White);
				ssd1306_SetCursor(10, 45);
				ssd1306_WriteString("MOTION DETECTED !", Font_7x10, White);
				ssd1306_UpdateScreen();
        	}
            break;
        default:
        	break;
    }
}
