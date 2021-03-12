/*Speed_Control.h*/
#ifndef SPEED_CONTROL_H_
#define SPEED_CONTROL_H_

#include "Speed_Control_Config.h"
#define MINMUM 140
#define MEDIUM 90
#define MAXIMUM 10

void            Speed_Control_init(void);
SWITCH_STATE_t Speed_Control_get_Switch_state(void);
void           Angel_update(void);





#endif