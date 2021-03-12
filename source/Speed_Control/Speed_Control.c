/*Speed_Control.c*/
#include "Speed_Control.h"



static MOTOR_ANGEL_t MOTRO_angel;
static SWITCH_STATE_t Switch_state;

void Speed_Control_init(void)
{
    MOTRO_angel = MINMUM;
}


SWITCH_STATE_t Speed_Control_get_Switch_state(void)
{



    return Switch_state;
}

void Angel_update(void)
{
  /**/
}
