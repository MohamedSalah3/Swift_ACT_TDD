#ifndef MOTOR_TEST_H_
#define MOTOR_TEST_H_

#include <stdio.h>
#include <string.h>
/* Include tested module header file */
#define EXPOSE_LED_INTERNALS
/*#include "../../source/led/led.h"
*/
#include "../../source/Motor/Motor.h"

#include <stdlib.h>
extern speed_Cfg_str SpeedSTR_update;
static void Motor_TEST_SET_Result_Data(MOTOR_ANGEL_t* expected_Motor_Speed);

test_Cfg_str* Switch_getTestData(test_Cfg_str* Data_Return,uint8_t test_num);

#endif
