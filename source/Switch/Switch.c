/*Switch.c*/
#include "switch.h"


/* Globals */

/* Switch State */
SWITCH_STATE_t State_Machine[5][3];
uint8_t index_SM[3]={0,0,0};
static SWITCH_STATE_t Switch_State;
ptr_to_Fun_Ret_uint32t Switch_get_time;
switch_state_Ptr_to_fun SWITCH_getSwState ;

/* Global Functions Implementation */
ERROR_STATUS SWITCH_init(Switch_Cfg_str* Switch_used)
{
  uint8_t Ret = E_OK;

  for(uint8_t i=0; i<3; i++)
  {index_SM[i] = 0;}

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


/******************************************************************************************
First Lets Check Invalid Inputs , first lets check null ptr detection
Using Testing Technique EP and BVA
*****************************************************************************************/

ERROR_STATUS SWITCH_update(Switch_Cfg_str* Switch_used,test_Cfg_str *Test_data)
{
  ERROR_STATUS ret=E_OK;
uint8_t arr_check_SM [5]={SW_RELEASED,SW_PREPRESSED,SW_PRESSED,SW_PRERELEASED,SW_RELEASED};

if((Switch_used == NULL) || (Test_data == NULL)){
ret = NULL_PTR;}else{
  if(Switch_used -> Switch_ID > P_SWITCH ||Switch_used -> Switch_ID < UPSWITCH )
{
  ret = INVALID_PARM;
}else{

if((Switch_used -> Switch_ID) == P_SWITCH){
  if((Test_data -> Switch_status[P_SWITCH]>SW_RELEASED) || (Test_data -> Switch_status[P_SWITCH]<SW_PREPRESSED))
  {
    ret = INVALID_PARM;
  }else{
       (Switch_used -> Switch_status)=(Test_data -> Switch_status[P_SWITCH]);

       State_Machine[index_SM[P_SWITCH]][P_SWITCH]= (Switch_used -> Switch_status);
       if(State_Machine[index_SM[P_SWITCH]][P_SWITCH] == arr_check_SM [index_SM[P_SWITCH] ]){
       if(index_SM[P_SWITCH] < 5)
       { index_SM[P_SWITCH]+=1;}else{index_SM[P_SWITCH]=0;}
     }else{ret = STATE_MACHINE_ERROR;}

if(Test_data -> Push_Time >= 0 &&Test_data -> Push_Time <= 5070 )
  {(Switch_used -> Push_Time)=(Test_data -> Push_Time);
}else{  ret = INVALID_PARM;}
}
}

 if((Switch_used -> Switch_ID )== DOWNSWITCH)
 {
   if((Test_data -> Switch_status[DOWNSWITCH]>SW_RELEASED) || (Test_data -> Switch_status[DOWNSWITCH]<SW_PREPRESSED))
   {
     ret = INVALID_PARM;
   }else{

     (Switch_used -> Switch_status)=(Test_data -> Switch_status[DOWNSWITCH]);

     State_Machine[index_SM[DOWNSWITCH]][DOWNSWITCH]= (Switch_used -> Switch_status);
     if(State_Machine[index_SM[DOWNSWITCH]][DOWNSWITCH] == arr_check_SM [index_SM[DOWNSWITCH] ]){
     if(index_SM[DOWNSWITCH] < 5)
     { index_SM[DOWNSWITCH]+=1;}else{index_SM[DOWNSWITCH]=0;}
     }else{ret = STATE_MACHINE_ERROR;}

}
}



if(Switch_used -> Switch_ID == UPSWITCH){
  if((Test_data -> Switch_status[UPSWITCH]>SW_RELEASED) || (Test_data -> Switch_status[UPSWITCH]<SW_PREPRESSED))
  {
    ret = INVALID_PARM;
  }else{
    (Switch_used -> Switch_status)=(Test_data -> Switch_status[DOWNSWITCH]);

    State_Machine[index_SM[UPSWITCH]][UPSWITCH]= (Switch_used -> Switch_status);
    if(State_Machine[index_SM[UPSWITCH]][UPSWITCH] == arr_check_SM [index_SM[UPSWITCH] ]){
    if(index_SM[UPSWITCH] < 5)
    { index_SM[UPSWITCH]+=1;}else{index_SM[UPSWITCH]=0;}
    }else{ret = STATE_MACHINE_ERROR;}
}
}




}

}


  return ret;
}
