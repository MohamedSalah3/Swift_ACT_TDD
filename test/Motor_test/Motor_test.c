#include "Motor_test.h"
TEST_GROUP(Motor_Angle);
#ifndef MAX_TESTS
#define MAX_TESTS 5
#endif
TEST_SETUP(Motor_Angle)
{


}


TEST_TEAR_DOWN(Motor_Angle)
{

}

static void Motor_TEST_SET_Result_Data(MOTOR_ANGEL_t* expected_Motor_Speed)
{
FILE* OUTPUT_File_Ptr2File = fopen("MOTOR.txt","a");
fprintf(OUTPUT_File_Ptr2File, "%i\n", expected_Motor_Speed);
fclose(OUTPUT_File_Ptr2File);
}


TEST(Motor_Angle,complete_output)
{
MOTOR_init();
/* Arrange */
for(uint8_t test_num=0;test_num < MAX_TESTS;test_num++){
SWITCH_init(&P_Switch);
SWITCH_init(&UpSwitch);
SWITCH_init(&DownSwitch);
SWITCH_update(&P_Switch,(Switch_getTestData(&test_data,test_num)));

SWITCH_update(&UpSwitch,(Switch_getTestData(&test_data,test_num)));

SWITCH_update(&DownSwitch,(Switch_getTestData(&test_data,test_num)));

Speed_Control_get_Switch_state(&SpeedSTR_update);
 Angel_update(&SpeedSTR_update);

MOTOR_update();
}

}


TEST_GROUP_RUNNER(Motor_Angle)
{
RUN_TEST_CASE(Motor_Angle,complete_output);
}
