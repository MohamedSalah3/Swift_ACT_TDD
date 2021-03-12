/*Speed_Control_Config.h*/
#ifndef SPEED_CONTROL_CONFIG_H_
#define SPEED_CONTROL_CONFIG_H_


#include "../Switch/Switch.h"

typedef uint8_t MOTOR_ANGEL_t;



typedef struct speed_Cfg_str
{
  uint8_t Switch_ID[3];
  SWITCH_STATE_t Switch_status[3];
	uint32_t Push_Time;
  uint8_t MOTOR_angel;
}speed_Cfg_str;


extern speed_Cfg_str SpeedSTR;

#endif
