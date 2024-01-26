/*
 * APP.c
 *
 * Created: 1/22/2024 7:12:54 AM
 *  Author: LENOVO
 */ 

#include "APP.h"

timer0_config_t timer = {
	.timer_mode = TMR0_CTC_MODE,
	.cmp_out_mode = OC0_DISCONECTED,
	.out_compare_value =125,
	.prescale = TMR0_NO_PRESCALING,
	.TMR0_CompareMatchInterruptHandler = delay_Isr
};

pin_config_t red_led = {
	.port = GPIO_PORTAID ,
	.pin = GPIO_PIN0 ,
	.direction = GPIO_OUTPUT_DIRECTION ,
	.logic = GPIO_LOW
	
};

pin_config_t yellow_led = {
	.port = GPIO_PORTAID ,
	.pin = GPIO_PIN3 ,
	.direction = GPIO_OUTPUT_DIRECTION ,
	.logic = GPIO_LOW
	
};

pin_config_t green_led = {
	.port = GPIO_PORTAID ,
	.pin = GPIO_PIN6 ,
	.direction = GPIO_OUTPUT_DIRECTION ,
	.logic = GPIO_LOW
	
};
void APP_INIT(void){
	Timer0_Init(&timer);
	gpio_pin_intialization(&red_led);
	gpio_pin_intialization(&yellow_led);
	gpio_pin_intialization(&green_led);
}
void Turn_Red_Led_With_Delay(void){
	gpio_PORT_write_value(GPIO_PORTAID,0);
	while(timer_flag == 0){
		SET_BIT(PORTA,0);
		TMR0_delay_ms(2000);
	}
}
void Turn_Yellow_Led_With_Delay(void){
	gpio_PORT_write_value(GPIO_PORTAID,0);
	while(timer_flag == 1){
		SET_BIT(PORTA,3);
		TMR0_delay_ms(2000);
	}
}
void Turn_Green_Led_With_Delay(void){
	gpio_PORT_write_value(GPIO_PORTAID,0);
	while(timer_flag == 2){
		SET_BIT(PORTA,6);
		TMR0_delay_ms(2000);
	}
	timer_flag=0;
}