#include <atmel_start.h>
#include <hal_gpio.h>
#include <stdio.h>
#include "gfx_mono_main.h"
#include "gfx_mono_font_basic_6x7.h"
#include <asf.h>
#include <stdlib.h>

void configure_eeprom(void);

//! [setup]
void configure_eeprom(void)
{
	/* Setup EEPROM emulator service */
//! [init_eeprom_service]
	enum status_code error_code = eeprom_emulator_init();
//! [init_eeprom_service]

//! [check_init_ok]
	if (error_code == STATUS_ERR_NO_MEMORY) {
		while (true) {
			/* No EEPROM section has been set in the device's fuses */
		}
	}
//! [check_init_ok]
//! [check_re-init]
	else if (error_code != STATUS_OK) {
		/* Erase the emulated EEPROM memory (assume it is unformatted or
		 * irrecoverably corrupt) */
		eeprom_emulator_erase_memory();
		eeprom_emulator_init();
	}
//! [check_re-init]
}

#if (SAMD || SAMR21)
void SYSCTRL_Handler(void)
{
	if (SYSCTRL->INTFLAG.reg & SYSCTRL_INTFLAG_BOD33DET) {
		SYSCTRL->INTFLAG.reg = SYSCTRL_INTFLAG_BOD33DET;
		eeprom_emulator_commit_page_buffer();
	}
}
#endif
static void configure_bod(void)
{
#if (SAMD || SAMR21)
	struct bod_config config_bod33;
	bod_get_config_defaults(&config_bod33);
	config_bod33.action = BOD_ACTION_INTERRUPT;
	/* BOD33 threshold level is about 3.2V */
	config_bod33.level = 48;
	bod_set_config(BOD_BOD33, &config_bod33);
	bod_enable(BOD_BOD33);

	SYSCTRL->INTENSET.reg = SYSCTRL_INTENCLR_BOD33DET;
	system_interrupt_enable(SYSTEM_INTERRUPT_MODULE_SYSCTRL);
#endif


}
//! [setup]
//Memory stuff
typedef struct Node {
	uint8_t data;
	int index;
	struct Node* next;
} Node;

Node* createNode(int data, int index) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(newNode == NULL) {
		exit(0);
	}
	newNode->data = data;
	newNode->index = index;
	newNode->next = NULL;
	return newNode;
}

Node* createCircularList(int n) {
	Node* head = NULL;
	Node* temp = NULL;
	Node* tail = NULL;

	for(int i = 0; i < n; i++) {
		temp = createNode(i, i);
		if(head == NULL) {
			head = temp;
		} else {
			tail->next = temp;
		}
		tail = temp;
	}
	tail->next = head;
	return head;
}

void clearCircularList(Node* head) {
	Node* ptr = head;
	Node* next;

	do {
		next = ptr->next;
		free(ptr);
		ptr = next;
	} while (ptr != head);
}

//Cria três listas circulares
void createSensorsLists(Node** list, int n) {
	for(int i = 0; i < 3; i++) {
		list[i] = createCircularList(n);
	}
}

int main(void)
{
	//eeprom_emulator_erase_memory();  //Serve para apagar a memória caso algo de errado
	system_init();
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	//! [setup_init]
	configure_eeprom();
	//! [setup_init]

	//! [setup_bod]
	configure_bod();
	//! [setup_bod]

	uint8_t temp_sensor_page[EEPROM_PAGE_SIZE];
	uint8_t light_sensor_page[EEPROM_PAGE_SIZE];
	uint8_t movement_sensor_page[EEPROM_PAGE_SIZE];
	
	eeprom_emulator_read_page(0, temp_sensor_page);
	eeprom_emulator_read_page(1, light_sensor_page);
	eeprom_emulator_read_page(2, movement_sensor_page);

	int temp_index = 0, light_index = 0, movm_index = 0;

	int temp_sensor = 1, light_sensor = 2, movement_sensor = 3;
	Node* sensorLists[3];
	//Cria as listas com 10 nodos cada
	createSensorsLists(sensorLists, 10);
	Node* currentNodes[3] = {sensorLists[0], sensorLists[1], sensorLists[2]};
	// Display Message
	const uint8_t msg_hello[] =       "Seja bem vindo!     ";
	const uint8_t msg_temperatura[] = "Sensor 1!          ";
	const uint8_t msg_luz[] =         "Sensor 2!          ";
	const uint8_t msg_orient[] =      "Sensor 3!          ";

	// Enable SPI and OLED
	spi_m_sync_enable(&DISPLAY_SPI);
	gfx_mono_init();
	
	// Draw a Rectangle
	gfx_mono_draw_rect(&MONOCHROME_GRAPHICS_desc, 0, 0, UG2832HSWEG04_LCD_WIDTH, UG2832HSWEG04_LCD_HEIGHT, GFX_PIXEL_SET);
	gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, msg_hello, 20, 12, &basic_6x7);	

	/* Replace with your application code */
	while(1) {
		currentNodes[0]->data = temp_sensor;
		currentNodes[1]->data = light_sensor;
		currentNodes[2]->data = movement_sensor;

		currentNodes[0] = currentNodes[0]->next;
		currentNodes[1] = currentNodes[1]->next;
		currentNodes[2] = currentNodes[2]->next;

		bool botao_1 = gpio_get_pin_level(PA22);
		bool botao_2 = gpio_get_pin_level(PA06);
		bool botao_3 = gpio_get_pin_level(PA07);
		
		if(!botao_1){
			temp_sensor_page[temp_index] = currentNodes[0]->data;
			currentNodes[0] = currentNodes[0]->next;
			temp_index++;
			if(temp_index >= 60) {temp_index = 0;}

			eeprom_emulator_write_page(0, temp_sensor_page);
			eeprom_emulator_commit_page_buffer();

			sprintf(msg_temperatura, "Temp = %d graus", currentNodes[0]->data);
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, "                 ", 20, 12, &basic_6x7);
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, msg_temperatura, 20, 12, &basic_6x7);
		}
		if(!botao_2){
			light_sensor_page[light_index] = currentNodes[1]->data;
			currentNodes[1] = currentNodes[1]->next;
			light_index++;
			if(light_index >= 60) {light_index = 0;}

			eeprom_emulator_write_page(1, light_sensor_page);
			eeprom_emulator_commit_page_buffer();

			sprintf(msg_luz, "Luz = %d", currentNodes[1]->data);
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, "                 ", 20, 12, &basic_6x7);
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, msg_luz, 20, 12, &basic_6x7);
		}
		if(!botao_3){
			movement_sensor_page[movm_index] = currentNodes[2]->data;
			currentNodes[2] = currentNodes[2]->next;
			movm_index++;
			if(movm_index >= 60) {movm_index = 0;}

			eeprom_emulator_write_page(2, movement_sensor_page);
			eeprom_emulator_commit_page_buffer();

			sprintf(msg_orient, "Orient = %d graus", currentNodes[2]->data);
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, "                 ", 20, 12, &basic_6x7);
			gfx_mono_text_draw_string(&MONOCHROME_TEXT_desc, msg_orient, 20, 12, &basic_6x7);
		}
	}
}