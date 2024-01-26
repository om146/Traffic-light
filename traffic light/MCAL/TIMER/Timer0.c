/*
 * Timer0.c
 *
 * Created: 1/20/2024 10:59:09 PM
 *  Author: LENOVO
 */ 
/* ----------------- Includes -----------------*/
#include "Timer0.h"
/* ----------------- Software Interfaces Declarations -----------------*/
static void (*TMR0_CompareMatchInterruptHandler)(void);
static void Timer0_set_mode(const timer0_config_t*_timer);
static void Timer0_set_oc0_pin(const timer0_config_t*_timer); 
extern u16 sw_delay;
void Timer0_Init(const timer0_config_t *_timer){
	
	Timer0_set_mode(_timer);
	TMR0_SET_PRESCALER(_timer->prescale);
	TMR0_SET_CMP_OUT_MODE(_timer->cmp_out_mode);
	OCR0 = _timer->out_compare_value;
	 sei();
	TIMER0_CompareMatchInterruptEnable();
	 TMR0_CompareMatchInterruptHandler =
	 _timer->TMR0_CompareMatchInterruptHandler;
}
void Timer0_DeInit(const timer0_config_t *_timer){
	TMR0_STOP_TIMER();
	TIMER0_CompareMatchInterruptDisable();
	TIMER0_OverflowInterruptDisable();
}

void Timer0_Set_compare_value(u8 _value){
	OCR0 = _value;
}


static void Timer0_set_mode(const timer0_config_t *_timer) {
	switch (_timer->timer_mode) {
		case TMR0_NORMAL_MODE:
		CLEAR_BIT(TCCR0, TCCR0_WGM00);
		CLEAR_BIT(TCCR0, TCCR0_WGM01);
		break;
		case TMR0_PHASE_CORRECT_PWM_MODE:
		SET_BIT(TCCR0, TCCR0_WGM00);
		CLEAR_BIT(TCCR0, TCCR0_WGM01);
		break;
		case TMR0_CTC_MODE:
		CLEAR_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
		break;
		case TMR0_FAST_PWM_MODE:
		SET_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
		break;
		default:
		break;
	}
}
static void Timer0_set_oc0_pin(const timer0_config_t *_timer) {
	if (_timer->timer_mode != TMR0_NORMAL_MODE) {
		SET_BIT(_PTRDDRB,3);
		} 
}
void TMR0_delay_ms(u16  delay){
	TIMER0_CompareMatchInterruptEnable();
		TMR0_SET_PRESCALER(TMR0_PRESCALER_CLK_64);
		sw_delay=delay;
		Timer0_Set_compare_value(125);
}
void TMR0_delay_us(u16  delay){
	TIMER0_CompareMatchInterruptEnable();
	TMR0_SET_PRESCALER(TMR0_PRESCALER_CLK_8);
	sw_delay=delay;
	Timer0_Set_compare_value(8);
}


ISR(TIMER0_COMP_vect) {
	TMR0_CompareMatchInterruptHandler();
}