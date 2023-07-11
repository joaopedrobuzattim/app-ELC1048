/**
 * \file
 *
 * \brief SAM EEPROM Emulator Service Quick Start
 *
 * Copyright (c) 2012-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>
#include <stdio.h>
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

typedef struct Node {
	int data;
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

void createSensorsLists(Node** list, int n) {
	for(int i = 0; i < 3; i++) {
		list[i] = createCircularList(n);
	}
}

}
//! [setup]

int main(void)
{
	//eeprom_emulator_erase_memory();
	system_init();

//! [setup_init]
	configure_eeprom();
//! [setup_init]

//! [setup_bod]
	configure_bod();
//! [setup_bod]

//! [main]
//! [read_page]
	float temp_sensor_page[EEPROM_PAGE_SIZE];
	float light_sensor_page[EEPROM_PAGE_SIZE];
	float movement_sensor_page[EEPROM_PAGE_SIZE];
	
	eeprom_emulator_read_page(0, temp_sensor_page);
	eeprom_emulator_read_page(1, light_sensor_page);
	eeprom_emulator_read_page(2, movement_sensor_page);
//! [read_page]

//! [write_page]
	eeprom_emulator_write_page(0, temp_sensor_page);
	eeprom_emulator_commit_page_buffer();
	eeprom_emulator_write_page(1, light_sensor_page);
	eeprom_emulator_commit_page_buffer();
	eeprom_emulator_write_page(2, movement_sensor_page);
	eeprom_emulator_commit_page_buffer();
//! [write_page]

	int 

	int temp_sensor, light_sensor, movement_sensor;
	Node* sensorLists[3];
	createSensorsLists(sensorLists, 10);
	Node* currentNodes[3] = {sensorLists[0], sensorLists[1], sensorLists[2]};

	while(true) {
		// Assume data is read into temp_sensor, light_sensor, and movement_sensor
		currentNodes[0]->data = temp_sensor;
		currentNodes[1]->data = light_sensor;
		currentNodes[2]->data = movement_sensor;

		// Move to next node in each circular list
		currentNodes[0] = currentNodes[0]->next;
		currentNodes[1] = currentNodes[1]->next;
		currentNodes[2] = currentNodes[2]->next;

		//if aperto o botão do sensor:
		//Printa currentNodes[index_da_lista_do_sensor]->data
		//Escreve o dado na pagina na eeprom
		//currentNodes[index_da_lista_do_sensor] = currentNodes[index_da_lista_do_sensor]->next
	}
	
//! [main]
}
