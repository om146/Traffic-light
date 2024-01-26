/*
 * APP.h
 *
 * Created: 1/21/2024 6:56:54 AM
 *  Author: LENOVO
 */ 


#ifndef APP_H_
#define APP_H_

#include "../MCAL/TIMER/Timer0.h"
#include "../MCAL/MCAL_GPIO/MCAL_GPIO.h"
extern u8 timer_flag ;



/***********************API'S DEFINATION ********************************/
void APP_INIT(void);
void Turn_Red_Led_With_Delay(void);
void Turn_Yellow_Led_With_Delay(void);
void Turn_Green_Led_With_Delay(void);
#endif /* APP_H_ */