/*Switch.h*/
#ifndef SWITCH_H_
#define SWITCH_H_
#include "Switch_Config.h"
/*************************************************************/
/*This Function is used with Both Testing and Production Code */
/*************************************************************/
extern SWITCH_STATE_t State_Machine[5][3];
extern uint8_t index_SM[3];


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


 /*!
		  * @par Input : Switch_Cfg_str* Switch_used Which is a pointer to struct holds Info needed
		  * @par Input 2: u8Switch_status this is used to mock up all the text reading
		  * @par Output  : void

	*/
void switch_st_Testing_Fail(Switch_Cfg_str* Switch_used,uint8_t u8Switch_status,uint8_t u8Timing,uint8_t u8Program_mode );


 /*!
		  * @par Input : Program_Mode Make the init fun change pointer to testing funs
		  * @par Input 2: Switch_Cfg_str* Switch_used a pointer to struct to holdsevery button info
		  * @par Output  : ERROR_STATUS


	*/
void switch_st_Testing_setter(Switch_Cfg_str* Switch_used,uint8_t u8_Programming_Mode );


    /*!
		  * @par Input : Switch_Cfg_str* Switch_used a pointer to struct to holdsevery button info
		  * @par Output  : ERROR_STATUS
		  * @par Description  : Init Switch Module
	*/
ERROR_STATUS  SWITCH_init(Switch_Cfg_str* Switch_used);

/*!
		  * @par Input : Switch_Cfg_str* Switch_used
		  * @par Output  : Button State (SW_PREPRESSED , SW_PRESSED , SW_RELEASED ,SW_PRERELEASED)
		  * @par Description  : gets the push time data from Switch_used Structure
	*/
SWITCH_STATE_t  SWITCH_getSwState_real(Switch_Cfg_str* Switch_used);


/*!
		  * @par Input : Switch_Cfg_str* Switch_used
		  * @par Output  : Button State (SW_PREPRESSED , SW_PRESSED , SW_RELEASED ,SW_PRERELEASED)
		  * @par Description  : gets the push time data from Switch_used Structure
	*/
SWITCH_STATE_t  SWITCH_getSwState_Fake(Switch_Cfg_str* Switch_used);

/*!
		  * @par Input : Switch_Cfg_str* Switch_used
		  * @par Output  : Push Time
		  * @par Description  : gets the push time data from Switch_used Structure
	*/
uint32_t  SWITCH_getP_time_real(Switch_Cfg_str* Switch_used);
    /*!
		  * @par Input : Switch_Cfg_str* Switch_used
		  * @par Output  : Push Time
		  * @par Description  : gets the push time data from Switch_used Structure
	*/
uint32_t  SWITCH_getP_time_Fake(Switch_Cfg_str* Switch_used);
/**************************************************************
This is a real func used when TESTING only* *
*************************************************************/


    /*!
		  * @par Input : Switch_Cfg_str* Switch_used
		  * @par Output  : test_Cfg_str *Test_data
		  * @par Description  : Updates Switch_used Structure
	*/
ERROR_STATUS SWITCH_update(Switch_Cfg_str* Switch_used,test_Cfg_str *Test_data);
#endif
