/*
 * main.c
 *
 * Created: 1/20/2024 6:28:55 AM
 *  Author: LENOVO
 */ 
#include "APP.h"
extern u16 sw_counter ;
int main(void)
{
	APP_INIT();
    while(1)
    {
			Turn_Red_Led_With_Delay();
			Turn_Yellow_Led_With_Delay();
			Turn_Green_Led_With_Delay();
	}
}