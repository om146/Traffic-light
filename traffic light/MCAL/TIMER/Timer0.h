/*
 * Timer0.h
 *
 * Created: 1/20/2024 10:58:56 PM
 *  Author: LENOVO
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/* ----------------- Includes -----------------*/
#include "../MCAL_Config/Macrous.h"
#include "../MCAL_Config/MCAL_REGs.h"
#include "../MCAL_GPIO/MCAL_GPIO.h"
#include "../INT/Mcal_internal_INT.h"
#include <avr/interrupt.h>
/* ----------------- Macro Declarations -----------------*/
#define TCCR0_FOC0              7
#define TCCR0_WGM00             6
#define TCCR0_COM01             5
#define TCCR0_COM00             4
#define TCCR0_WGM01             3
#define TCCR0_CS02              2
#define TCCR0_CS01				1
#define TCCR0_CS00				0




/* TIMSK Bits */
#define TIMSK_TOIE0             0
#define TIMSK_OCIE0             1
#define TIMSK_TOIE1             2
#define TIMSK_OCIE1B            3
#define TIMSK_OCIE1A            4
#define TIMSK_TICIE             5

#define compare_match_enable 0
#define pwm_mode_enable       1

#define TMR0_STOP_TIMER() (TCCR0 &= 0xF8)
#define TMR0_SET_PRESCALER(_pre) (TCCR0 |= _pre)
#define TMR0_SET_CMP_OUT_MODE(_mode) (TCCR0 |= (_mode << 4))
#define TMR0_SET_pwm_OUT_MODE(_mode) (TCCR0 |= (_mode << 4))
/* ----------------- Macro Functions Declarations -----------------*/

/* ----------------- Data Type Declarations -----------------*/
typedef enum
{
	TMR0_NO_CLK_SOURCE = 0,
	TMR0_NO_PRESCALING ,
	TMR0_PRESCALER_CLK_8 ,
	TMR0_PRESCALER_CLK_64 ,
	TMR0_PRESCALER_CLK_256 ,
	TMR0_PRESCALER_CLK_1024 ,
	TMR0_EXT_CLK_SRC_T0_FALLING_EDGE ,
	TMR0_EXT_CLK_SRC_T0_RISING_EDGE ,
}timer0_Clock_t;

typedef enum
{ TMR0_NORMAL_MODE = 0,
	TMR0_PHASE_CORRECT_PWM_MODE ,
	TMR0_CTC_MODE ,
	TMR0_FAST_PWM_MODE ,
}timer0_Mode_t;

typedef enum
{
	OC0_DISCONECTED =0 ,
	TOOGLE ,
	SET ,
	CLEAR
}CTC_Mode_t;


typedef enum
{
	POC0_DISCONECTED =0 ,
	preserved ,
	non_inverting,
	inverting
}PWM_Mode_t;


typedef struct {
	void (*TMR0_CompareMatchInterruptHandler)(void);
	timer0_Mode_t timer_mode : 2;
	timer0_Clock_t prescale;
	CTC_Mode_t cmp_out_mode : 2;
	u8 out_compare_value;
}timer0_config_t;
/* ----------------- Software Interfaces Declarations -----------------*/
void Timer0_Init(const timer0_config_t *_timer);
void Timer0_DeInit(const timer0_config_t *_timer);
void Timer0_Write_Value(const timer0_config_t *_timer, u8 _value);
void Timer0_Set_compare_value( u8 _value);
u8  Timer0_GetCounterValue();
void TMR0_delay_ms(u16  delay);
void TMR0_delay_us(u16  delay);
void delay_Isr();


#endif /* TIMER0_H_ */