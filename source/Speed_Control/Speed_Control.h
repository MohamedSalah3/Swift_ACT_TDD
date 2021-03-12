/*Speed_Control.h*/
#ifndef SPEED_CONTROL_H_
#define SPEED_CONTROL_H_

/****************************************************************
* _Includes
/****************************************************************/
#include "Speed_Control_Config.h"

/****************************************************************
* Param [out] : Error_status
*param[in] : void
*
/****************************************************************/
ERROR_STATUS Speed_Control_init(void);

/****************************************************************
*Param [in] : speed_Cfg_str Pointer So You should pass an address to it
*Param [out] : Error_status
*
/****************************************************************/

ERROR_STATUS Speed_Control_get_Switch_state(speed_Cfg_str* SpeedSTR_used);

/****************************************************************
* Param [out] : Error_status
*Param [in] : speed_Cfg_str Pointer So You should pass an address to it

*
*
/****************************************************************/
void speed_Con_Testing_setter(speed_Cfg_str* SpeedSTR_used,uint8_t Program_Mode);


/****************************************************************
Param [in] : speed_Cfg_str Pointer So You should pass an address to it
Param [in] :  Program_Mode this is used to diffrentiate PRODUCTION
from testing
***Not Implemented yet
*
/****************************************************************/
MOTOR_ANGEL_t Angel_update(speed_Cfg_str* SpeedSTR_used);

/****************************************************************
* param [in] :SpeedSTR_used pointer
*Param [out] : Motor_Angle
*This functions updates Structure SpeedSTR_used
/****************************************************************/

void speed_st_Testing_Fail(MOTOR_ANGEL_t Angle);

#endif
