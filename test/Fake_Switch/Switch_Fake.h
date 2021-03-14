#ifndef SWITCH_FAKE_H_
#define SWITCH_FAKE_H_

#include <stdio.h>
#include <string.h>
/* Include tested module header file */
#define EXPOSE_LED_INTERNALS
/*#include "../../source/led/led.h"
*/
#include "../../source/Motor/Motor.h"
/***********************************************************
test_Cfg_str* Switch_getTestData(test_Cfg_str* Data_Return,uint8_t test_num);
Param [in] : uint8_t test_num
Param [in/OUT] :test_Cfg_str* Data_Return
*
test_Cfg_str* Switch_getTestData(test_Cfg_str* Data_Return,uint8_t test_num);
This is a helper function to read data from input.txt
************************************************************/

test_Cfg_str* Switch_getTestData(test_Cfg_str* Data_Return,uint8_t test_num)

#endif
