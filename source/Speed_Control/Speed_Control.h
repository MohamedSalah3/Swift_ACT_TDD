/*Speed_Control.h*/
#ifndef SPEED_CONTROL_H_
#define SPEED_CONTROL_H_

#include "Speed_Control_Config.h"

ERROR_STATUS Speed_Control_init(void);


ERROR_STATUS Speed_Control_get_Switch_state(speed_Cfg_str* SpeedSTR_used);

void speed_Con_Testing_setter(speed_Cfg_str* SpeedSTR_used,uint8_t Program_Mode);


MOTOR_ANGEL_t Angel_update(speed_Cfg_str* SpeedSTR_used);


void speed_st_Testing_Fail(MOTOR_ANGEL_t Angle);

#endif
