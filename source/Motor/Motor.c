/*Motor.c*/
#include "Motor.h"

static MOTOR_ANGEL_t MOTOR_angel;

ERROR_STATUS MOTOR_init(void)
{
	ERROR_STATUS ret=E_OK;
    MOTOR_angel = MINMUM;
	return ret;
}


ERROR_STATUS MOTOR_getAngel(MOTOR_ANGEL_t *angle_of_the_motor)
{ERROR_STATUS ret=E_OK;

	return ret;
}

ERROR_STATUS MOTOR_update(void)
{
	ERROR_STATUS ret=E_OK;

	return ret;
  /*Write on output text*/
}
