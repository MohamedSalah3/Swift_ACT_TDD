/*Switch.c*/
#include "switch.h"


/* Globals */

/* Switch State */
static SWITCH_STATE_t Switch_State;



switch_state_Ptr_to_fun SWITCH_getSwState ;



/* Global Functions Implementation */
ERROR_STATUS SWITCH_init(Switch_Cfg_str* Switch_used)
{
  uint8_t Ret = E_OK;
  if((Switch_used -> Programming_Mode)== PRODUCTION)
{
    Real_Switch_State =(Switch_used -> Switch_status);
    SWITCH_getSwState = SWITCH_getSwState_real;
  }else if((Switch_used -> Programming_Mode)== TESTING)
  {
    Switch_State =(Switch_used -> Switch_status);
    SWITCH_getSwState = SWITCH_getSwState_real;

  }else
  {
    Switch_State =(Switch_used -> Switch_status);
    SWITCH_getSwState = SWITCH_getSwState_Fake;

  }
return RET;
}

/* Switch Real Getter Implementation */
SWITCH_STATE_t  SWITCH_getSwState_real(void)
{
    return Switch_State;
}


ERROR_STATUS SWITCH_update(void)
{
    /* Do nothing for now */
}
