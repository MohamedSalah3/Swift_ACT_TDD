/*Speed_Control_Config.h*/
#ifndef SPEED_CONTROL_CONFIG_H_
#define SPEED_CONTROL_CONFIG_H_

#include "../../test/unity/unity_fixture.h"
#include "../infrastructure/Error.h"
#include "../infrastructure/std_types.h"

#include "../Switch/Switch.h"

typedef uint8_t MOTOR_ANGEL_t;
#define MINMUM 140
#define MEDIUM 90
#define MAXIMUM 10

/****************************************************************
* Defining a structure makes the code More Object orieted
*So This Structure speed_Cfg_str is used to carry all information
needed to the motor Module which makes Life easier :)
/****************************************************************/

typedef struct speed_Cfg_str
{
  uint8_t Switch_ID[3];
  SWITCH_STATE_t Switch_status[3];
	uint32_t Push_Time;
  MOTOR_ANGEL_t MOTOR_angel;
  uint8_t Programming_Mode;
}speed_Cfg_str;


extern speed_Cfg_str SpeedSTR_update;

#endif
