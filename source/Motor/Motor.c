/*Motor.c*/
#include "Motor.h"

static MOTOR_ANGEL_t MOTOR_angel;

ERROR_STATUS MOTOR_init(void)
{
	ERROR_STATUS ret=E_OK;
    MOTOR_angel = MEDIUM;
				Speed_Control_init();
	return ret;
}


MOTOR_ANGEL_t MOTOR_getAngel(speed_Cfg_str* SpeedSTR_used)
{
	MOTOR_ANGEL_t Angle=MEDIUM;
Angle=(SpeedSTR_used->MOTOR_angel);
return Angle;
}

void MOTOR_update(void)
{
	FILE* OUTPUT_File_Ptr2File = fopen("MOTOR.txt","a");
	fprintf(OUTPUT_File_Ptr2File, "%u\n",MOTOR_getAngel(&SpeedSTR_update));
	fclose(OUTPUT_File_Ptr2File);
 /*Write on output text*/
 
}
