/*Switch.h*/
#ifndef SWITCH_H_
#define SWITCH_H_
#include "Switch_Config.h"
/*************************************************************/
/*with this typedef we made it more readable and related to the used scinario
this defination will be used with SWITCH_getSwState */
/*************************************************************/
typedef ptr_to_Fun_Ret_uint8t switch_state_Ptr_to_fun;

/*************************************************************/
/*This Function is used with Both Testing and Production Code */
/*************************************************************/
ERROR_STATUS  SWITCH_init(Switch_Cfg_str* Switch_used);
/* Switch Real Getter Prototype */
SWITCH_STATE_t  SWITCH_getSwState_real(Switch_Cfg_str* Switch_used);

void SWITCH_update(Switch_Cfg_str* Switch_used);
#endif
