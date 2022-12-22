#include "bsp_lcd.h"
#include "tftlcd.h"

void Prepare_LCD(void)
{
	LCD_Init();
	LCD_Clear(BLACK); 		//«Â∆¡	
	BACK_COLOR=BLACK;
	POINT_COLOR=CYAN;	
	LCD_ShowString(0, 0, 200, 12, 32, "CUHK ERB106");
	LCD_ShowString(0, 35, 160, 12, 12, "Version 0.3 Arthor TF&LW");
}
