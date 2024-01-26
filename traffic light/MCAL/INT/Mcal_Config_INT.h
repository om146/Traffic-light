/*
 * Mcal_Config_INT.h
 *
 * Created: 1/20/2024 10:57:41 PM
 *  Author: LENOVO
 */ 


#ifndef MCAL_CONFIG_INT_H_
#define MCAL_CONFIG_INT_H_

/* ----------------- Includes -----------------*/
#include "../MCAL_GPIO/MCAL_GPIO.h"
#include "mcal_interrupt_gen_cfg.h"

/* ----------------- Macro Declarations -----------------*/
#define INTERRUPT_ENABLE    1
#define INTERRUPT_DISABLE   0
#define INTERRUPT_OCCUR     1
#define INTERRUPT_NOT_OCCUR 0


/* ----------------- Macro Functions Declarations -----------------*/


/* This macro will enable global interrupts. */
#define INTERRUPT_GlobalInterruptEnable()  sei()
/* This macro will disable global interrupts. */
#define INTERRUPT_GlobalInterruptDisable() cli()





#endif /* MCAL_CONFIG_INT_H_ */