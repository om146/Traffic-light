/*
 * Mcal_internal_INT.h
 *
 * Created: 1/20/2024 10:56:13 PM
 *  Author: LENOVO
 */ 


#ifndef MCAL_INTERNAL_INT_H_
#define MCAL_INTERNAL_INT_H_

#include "Mcal_Config_INT.h"
#if TIMER0_INTERRUPT_FEATURE_ENABLE==INTERRUPT_FEATURE_ENABLE
/* This routine clears the interrupt enable for the timer0 module overflow */
#define TIMER0_OverflowInterruptDisable()         (CLEAR_BIT(TIMSK,TOIE0))
/* This routine sets the interrupt enable for the timer0 module overflow */
#define TIMER0_OverflowInterruptEnable()          (SET_BIT(TIMSK,TOIE0))
/* This routine clears the interrupt flag for the timer0 Module overflow */
#define TIMER0_OverflowInterruptFlagClear()       (SET_BIT(TIFR,TOV0))

/* This routine clears the interrupt enable for the timer0 module compare match */
#define TIMER0_CompareMatchInterruptDisable()         (CLEAR_BIT(TIMSK,OCIE0))
/* This routine sets the interrupt enable for the timer0 module compare match */
#define TIMER0_CompareMatchInterruptEnable()          (SET_BIT(TIMSK,OCIE0))
/* This routine clears the interrupt flag for the timer0 Module compare match */
#define TIMER0_CompareMatchInterruptFlagClear()       (SET_BIT(TIFR,OCF0))
#endif



#endif /* MCAL_INTERNAL_INT_H_ */