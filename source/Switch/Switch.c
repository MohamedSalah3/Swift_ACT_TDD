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
    Switch_State =(Switch_used -> Switch_status);
    SWITCH_getSwState = SWITCH_getSwState_real;
  }else if((Switch_used -> Programming_Mode)== TESTING)
  {

      Switch_State =(Switch_used -> Switch_status);
      SWITCH_getSwState = SWITCH_getSwState_Fake;

  }else
  {
    Ret=INVALID_PARM
  }
return Ret;
}

/* Switch Real Getter Implementation */
SWITCH_STATE_t  SWITCH_getSwState_real(Switch_Cfg_str* Switch_used)
{/*Go to */
    Switch_State = (Switch_used -> Switch_status);
    return Switch_State;
}

ERROR_STATUS SWITCH_update(Switch_Cfg_str* Switch_used)
{

}
