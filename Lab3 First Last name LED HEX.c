#include "address_map_nios2.h"
#include <stdio.h>

int main(void) {
	volatile int * HEX3_HEX0_ptr	= (int *) 0xFF200020; //HEX3-0 LED address
	volatile int * HEX5_HEX4_ptr	= (int *) 0xFF200030; //HEX5-4 LED address
	volatile int * red_LED_ptr 	= (int *) 0xFF200000;   // red LED address
	volatile int * switch_ptr	= (int *) 0xFF200040; //SW slider switch address
	int SW_value = 0;
	*(HEX3_HEX0_ptr) = 0;
	*(HEX5_HEX4_ptr) = 0;
	
	while (1) {
		SW_value = *switch_ptr;
		*red_LED_ptr = SW_value;
		
		if (SW_value == 512) {
			*HEX5_HEX4_ptr = 0x1E77;
			*HEX3_HEX0_ptr = 0x37063779;
		}
		else if (SW_value == 1) {
			*HEX5_HEX4_ptr = 0x7876;
			*HEX3_HEX0_ptr = 0x3F37776D;
		}
		else {
			*(HEX3_HEX0_ptr) = 0;
			*(HEX5_HEX4_ptr) = 0;
		}
		
	}
}