/*Speed_Control.c*/
#include "Speed_Control.h"



static MOTOR_ANGEL_t MOTRO_angel;
static SWITCH_STATE_t Switch_state;

ERROR_STATUS Speed_Control_init(void)
{
	ERROR_STATUS ret=E_OK;
    MOTRO_angel = MINMUM;
	return ret;
}


ERROR_STATUS Speed_Control_get_Switch_state(uint8_t member,SWITCH_STATE_t *Status,uint8_t *time)
{
ERROR_STATUS ret=E_OK;
//ERROR_STATUS SWITCH_update(Switch_Cfg_str* Switch_used)


    return ret;
}

ERROR_STATUS Angel_update(MOTOR_ANGEL_t *Angle)
{
  
  ERROR_STATUS ret=E_OK;
//ERROR_STATUS SWITCH_update(Switch_Cfg_str* Switch_used)


    return ret;
}
