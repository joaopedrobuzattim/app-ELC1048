#include <atmel_start.h>
#include <hal_gpio.h>
#include <stdio.h>
#include "gfx_mono_main.h"
#include "gfx_mono_font_basic_6x7.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	// Display Message
	const uint8_t msg_temperatura[] = "Temperatura!";
	const uint8_t msg_luz[] = "Luz!";
	const uint8_t msg_orient[] = "Orientacao!";

	// Enable SPI and OLED
	spi_m_sync_enable(&DISPLAY_SPI);
	gfx_mono_init();
	
	// Draw a Rectangle
	gfx_mono_draw_rect(&MONOCHROME_GRAPHICS_desc, 0, 0, UG2832HSWEG04_LCD_WIDTH, UG2832HSWEG04_LCD_HEIGHT, GFX_PIXEL_SET);
	

	/* Replace with your application code */
	while (1) {
		bool botao_1 = gpio_get_pin_level(PA22);
		bool botao_2 = gpio_get_pin_level(PA06);
		bool botao_3 = gpio_get_pin_level(PA07);
		
		if(!botao_1){
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, "              ", 20, 12, &basic_6x7);
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, msg_temperatura, 20, 12, &basic_6x7);
		}
		if(!botao_2){
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, "              ", 20, 12, &basic_6x7);
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, msg_luz, 20, 12, &basic_6x7);
		}
		if(!botao_3){
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, "              ", 20, 12, &basic_6x7);
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, msg_orient, 20, 12, &basic_6x7);
		}

	}
}