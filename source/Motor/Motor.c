/*Motor.c*/
#include "Motor.h"

static MOTOR_ANGEL_t MOTRO_angel;

void MOTOR_init(void)
{
    MOTRO_angel = MINMUM;
}


MOTOR_ANGEL_t MOTOR_getAngel(void)
{
    return MOTRO_angel;
}

void MOTOR_update(void)
{
  /*Write on output text*/
}
