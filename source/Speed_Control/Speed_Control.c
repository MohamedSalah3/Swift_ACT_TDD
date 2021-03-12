	/*Speed_Control.c*/
	#include "Speed_Control.h"

	switch_state_Ptr_to_fun  Speed_Control_get ;

	ERROR_STATUS Speed_Control_init(void)
	{
		ERROR_STATUS ret=E_OK;
	    SpeedSTR_update.MOTOR_angel = MEDIUM;
			SWITCH_init(&P_Switch);
			SWITCH_init(&UpSwitch);
			SWITCH_init(&DownSwitch);


		return ret;
	}

	void speed_Con_Testing_setter(speed_Cfg_str* SpeedSTR_used,uint8_t Program_Mode)
	{
	SpeedSTR_used -> Programming_Mode = Program_Mode;
	}
	ERROR_STATUS Speed_Control_get_Switch_state(speed_Cfg_str* SpeedSTR_used)
	{
		ERROR_STATUS ret=E_OK;
	ret=SWITCH_update(&UpSwitch,&test_data);
	SpeedSTR_used->Switch_ID[UPSWITCH]=	UpSwitch.Switch_ID;
	SpeedSTR_used->Switch_status[UPSWITCH]= UpSwitch.Switch_status;

	ret+=SWITCH_update(&DownSwitch,&test_data);
	SpeedSTR_used->Switch_ID[DOWNSWITCH]=	DownSwitch.Switch_ID;
	SpeedSTR_used->Switch_status[DOWNSWITCH] = DownSwitch.Switch_status;
	ret+=SWITCH_update(&P_Switch,&test_data);
	SpeedSTR_used->Switch_ID[P_SWITCH]=	P_Switch.Switch_ID;
	SpeedSTR_used->Switch_status[P_SWITCH] = P_Switch.Switch_status;
	SpeedSTR_used->Push_Time =P_Switch.Push_Time;

	return ret;
	}

	MOTOR_ANGEL_t Angel_update(speed_Cfg_str* SpeedSTR_used)
	{
uint32_t time = (SpeedSTR_used -> Push_Time);

if(SpeedSTR_used -> Switch_status[UPSWITCH] == SW_PREPRESSED)
{if(SpeedSTR_used-> MOTOR_angel != MAXIMUM)
	SpeedSTR_used-> MOTOR_angel--;}
if(SpeedSTR_used -> Switch_status[DOWNSWITCH] == SW_PREPRESSED)
{if(SpeedSTR_used-> MOTOR_angel != MINMUM)
	SpeedSTR_used-> MOTOR_angel++;}
if(SpeedSTR_used -> Switch_status[P_SWITCH] == SW_PRESSED)
{
	if(time>30){
	while(time -= 30)
	{	if(SpeedSTR_used-> MOTOR_angel != MINMUM)
		{	SpeedSTR_used-> MOTOR_angel++;}

	}
}
}



	return (SpeedSTR_used -> MOTOR_angel) ;
	}




		/* Arrange */
	  void speed_st_Testing_Fail(MOTOR_ANGEL_t Angle)
		{

	SpeedSTR_update.MOTOR_angel =  Angle;


		}
