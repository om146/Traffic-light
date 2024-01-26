/*
 * Timer0_Intialize.c
 *
 * Created: 1/21/2024 6:55:18 AM
 *  Author: LENOVO
 */ 
#include "Timer0.h"
extern  u16 sw_delay = 0 ;
extern u8 timer_flag = 0 ;
extern u16 sw_counter =0;
void delay_Isr(){
	sw_counter++;
	if(sw_counter == sw_delay ){
		sw_counter = 0;
		timer_flag++;
		TIMER0_CompareMatchInterruptDisable();
	}
}

