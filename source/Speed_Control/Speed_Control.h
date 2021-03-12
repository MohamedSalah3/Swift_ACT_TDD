/*Speed_Control.h*/
#ifndef SPEED_CONTROL_H_
#define SPEED_CONTROL_H_

#include "Speed_Control_Config.h"
#define MINMUM 140
#define MEDIUM 90
#define MAXIMUM 10

ERROR_STATUS Speed_Control_init(void);


speed_Cfg_str* Speed_Control_get_Switch_state(speed_Cfg_str* SpeedSTR_used);

ERROR_STATUS Angel_update(MOTOR_ANGEL_t *Angle);




#endif
