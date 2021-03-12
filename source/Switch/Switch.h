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
extern ptr_to_Fun_Ret_uint32t Switch_get_time;
/*************************************************************/
/*void switch_st_Testing_Fail(Switch_Cfg_str* Switch_used,uint8_t u8Switch_status,uint8_t u8Timing,uint8_t u8Program_mode );
param [in] : Switch_Cfg_str* Switch_used Which is a pointer to struct holds Info needed
param [in] : u8Switch_status this is used to mock up all the text reading
*/
/*************************************************************/
void switch_st_Testing_Fail(Switch_Cfg_str* Switch_used,uint8_t u8Switch_status,uint8_t u8Timing,uint8_t u8Program_mode );
/*************************************************************/
/*void switch_st_Testing_setter(Switch_Cfg_str* Switch_used,uint8_t u8_Programming_Mode )
param[in]:Program_Mode Make the init fun change pointer to testing funs
/*************************************************************/
void switch_st_Testing_setter(Switch_Cfg_str* Switch_used,uint8_t u8_Programming_Mode );
/*************************************************************
*Init Switch Module
@Param [in] Switch_Cfg_str* Switch_used a pointer to struct to holds
every button info
*************************************************************/
ERROR_STATUS  SWITCH_init(Switch_Cfg_str* Switch_used);
/* Switch Real Getter Prototype */
SWITCH_STATE_t  SWITCH_getSwState_real(Switch_Cfg_str* Switch_used);

/*************************************************************
*
This is a fake func used when testing only*
*************************************************************/
SWITCH_STATE_t  SWITCH_getSwState_Fake(Switch_Cfg_str* Switch_used);
/*************************************************************
*
This is a real func used when PRODUCTION only* *
*************************************************************/
uint32_t  SWITCH_getP_time_real(Switch_Cfg_str* Switch_used);
/*************************************************************/
/*with this typedef we made it more readable and related to the used scinario
this defination will be used with SWITCH_getSwState */
/*************************************************************/
uint32_t  SWITCH_getP_time_Fake(Switch_Cfg_str* Switch_used);
/**************************************************************
This is a real func used when TESTING only* *
*************************************************************/
ERROR_STATUS SWITCH_update(Switch_Cfg_str* Switch_used,test_Cfg_str *Test_data);

/**************************************************************

ERROR_STATUS SWITCH_update(Switch_Cfg_str* Switch_used,test_Cfg_str *Test_data);
@param [in] : Switch_Cfg_str* Switch_used
@Param [in/out] :test_Cfg_str *Test_data




*************************************************************/
#endif
