/*Speed_Control.h*/
#ifndef SPEED_CONTROL_H_
#define SPEED_CONTROL_H_

#include "Speed_Control_Config.h"
#define MINMUM 140
#define MEDIUM 90
#define MAXIMUM 10

ERROR_STATUS Speed_Control_init(void);

ERROR_STATUS Speed_Control_get_Switch_state(uint8_t member,SWITCH_STATE_t *Status,uint8_t *time);

ERROR_STATUS Angel_update(MOTOR_ANGEL_t *Angle);




#endif