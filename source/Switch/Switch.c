/*Switch.c*/
#include "switch.h"


/* Globals */

/* Switch State */
static SWITCH_STATE_t Switch_State;
ptr_to_Fun_Ret_uint32t Switch_get_time;
switch_state_Ptr_to_fun SWITCH_getSwState ;

/* Global Functions Implementation */
ERROR_STATUS SWITCH_init(Switch_Cfg_str* Switch_used)
{
  uint8_t Ret = E_OK;
if(Switch_used){
  if(((Switch_used -> GPIO) > GPIOD || (Switch_used -> GPIO) < GPIOA )
  ||((Switch_used -> pins) > PIN7 || (Switch_used -> pins) < PIN0 )
  ||((Switch_used -> Switch_status > SW_RELEASED)||(Switch_used -> Switch_status < SW_PREPRESSED))){Ret=INVALID_PARM;}
else{
  (Switch_used -> u8_Mult_init_detect)++;
  if(Switch_used -> u8_Mult_init_detect > 1){Ret=MULTIPLE_INIT;}
  else{
  (Switch_used -> Switch_status) =SW_RELEASED;
  (Switch_used -> Push_Time) =0;

  if((Switch_used -> Programming_Mode)== PRODUCTION)
  {
    Switch_State =(Switch_used -> Switch_status);
    SWITCH_getSwState = SWITCH_getSwState_real;
      Switch_get_time=SWITCH_getP_time_real;
  }else if((Switch_used -> Programming_Mode)== TESTING)
  {

      Switch_State =(Switch_used -> Switch_status);
      SWITCH_getSwState = SWITCH_getSwState_Fake;
      Switch_get_time=SWITCH_getP_time_Fake;

  }else
  {
    Ret=INVALID_PARM;
  }


}
}

}else
{
  Ret=NULL_PTR;
}
return Ret;
}

void switch_st_Testing_Fail(Switch_Cfg_str* Switch_used,uint8_t u8Switch_status,uint8_t u8Timing,uint8_t u8Program_mode )
{
  (Switch_used -> Programming_Mode) = u8Program_mode;
 (Switch_used -> Switch_status) =  u8Switch_status ;
 (Switch_used -> Push_Time) =  u8Timing ;


}
void switch_st_Testing_setter(Switch_Cfg_str* Switch_used,uint8_t u8_Programming_Mode )
{
(Switch_used -> Programming_Mode) = u8_Programming_Mode;
}
/* Switch Real Getter Implementation */
SWITCH_STATE_t  SWITCH_getSwState_real(Switch_Cfg_str* Switch_used)
{/*Go to */
    Switch_State = (Switch_used -> Switch_status);
    return Switch_State;
}

SWITCH_STATE_t  SWITCH_getSwState_Fake(Switch_Cfg_str* Switch_used)
{/*Go to */
    Switch_State = (Switch_used -> Switch_status);
    return Switch_State;
}
/* Switch Real Getter Implementation */
uint32_t  SWITCH_getP_time_real(Switch_Cfg_str* Switch_used)
{/*Go to */
  uint32_t time=0;
    time= (Switch_used -> Push_Time);
    return time;
}

uint32_t  SWITCH_getP_time_Fake(Switch_Cfg_str* Switch_used)
{/*Go to */
  uint32_t time=0;
    time= (Switch_used -> Push_Time);
    return time;
}



ERROR_STATUS SWITCH_update(Switch_Cfg_str* Switch_used,test_Cfg_str *Test_data)
{
  ERROR_STATUS ret=E_OK;

if((Switch_used -> Switch_ID) == P_SWITCH){
 (Switch_used -> Switch_status)=(Test_data -> Switch_status[P_SWITCH]);
  (Switch_used -> Push_Time)=(Test_data -> Push_Time);
}
 if((Switch_used -> Switch_ID )== DOWNSWITCH)
  (Switch_used -> Switch_status)=(Test_data -> Switch_status[DOWNSWITCH]);
  if(Switch_used -> Switch_ID == UPSWITCH)
   (Switch_used -> Switch_status)=(Test_data -> Switch_status[UPSWITCH]);

  return ret;
}
