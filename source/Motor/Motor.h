/*Motor.h*/
#ifndef MOTOR_H_
#define MOTOR_H_
#include "Motor_Config.h"



typedef enum {LED_OFF, LED_ON, LED_FLASH} MOTOR_ANGEL_t;

void            MOTOR_init(void);
MOTOR_ANGEL_t     MOTOR_getAngel(void);
void            MOTOR_update(void);



#endif
