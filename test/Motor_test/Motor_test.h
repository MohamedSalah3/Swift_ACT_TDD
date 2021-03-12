#ifndef MOTOR_TEST_H_
#define MOTOR_TEST_H_

#include <stdio.h>
#include <string.h>
/* Include tested module header file */
#define EXPOSE_LED_INTERNALS
/*#include "../../source/led/led.h"
*/
#include "../../source/Motor/Motor.h"
#include "../Fake_Switch/Switch_Fake.h"
#include <stdlib.h>

static void Motor_TEST_SET_Result_Data(MOTOR_ANGEL_t* expected_Motor_Speed);

#endif
