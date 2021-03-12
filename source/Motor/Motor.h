/*Motor.h*/
#ifndef MOTOR_H_
#define MOTOR_H_

#include "Motor_Config.h"
#define MINMUM 140
#define MEDIUM 90
#define MAXIMUM 10

typedef uint8_t MOTOR_ANGEL_t ;

ERROR_STATUS  MOTOR_init(void);
ERROR_STATUS  MOTOR_getAngel(MOTOR_ANGEL_t *);
ERROR_STATUS  MOTOR_update(void);



#endif
