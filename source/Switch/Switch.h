/*Switch.h*/
#ifndef SWITCH_H_
#define SWITCH_H_
#include "Switch_Config.h"
/*************************************************************/
/*This Function is used with Both Testing and Production Code */
/*************************************************************/


/**********************************************************************************/
/*        Switch state definition                                                 */
/**********************************************************************************/

/*************************************************************/
/*with this typedef we made it more readable and related to the used scinario
this defination will be used with SWITCH_getSwState */
/*************************************************************/
typedef ptr_to_Fun_Ret_uint8t switch_state_Ptr_to_fun;

extern  switch_state_Ptr_to_fun SWITCH_getSwState ; /* Turned into pointer so we can make it point to another fake function */


void switch_st_Testing_Fail(Switch_Cfg_str* Switch_used,uint8_t u8Switch_status,uint8_t u8Timing,uint8_t u8Program_mode );

void switch_st_Testing_setter(Switch_Cfg_str* Switch_used,uint8_t u8_Programming_Mode );

ERROR_STATUS  SWITCH_init(Switch_Cfg_str* Switch_used);
/* Switch Real Getter Prototype */
SWITCH_STATE_t  SWITCH_getSwState_real(Switch_Cfg_str* Switch_used);


SWITCH_STATE_t  SWITCH_getSwState_Fake(Switch_Cfg_str* Switch_used);


ERROR_STATUS SWITCH_update(Switch_Cfg_str* Switch_used);
#endif
