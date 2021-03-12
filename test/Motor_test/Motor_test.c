#include "../Fake_Switch/Switch_Fake.h"

static void Motor_TEST_SET_Result_Data(MOTOR_ANGEL_t* expected_Motor_Speed);
static void Motor_TEST_SET_Result_Data(MOTOR_ANGEL_t* expected_Motor_Speed)
{
FILE* OUTPUT_File_Ptr2File = fopen("MOTOR.txt","a");
fprintf(OUTPUT_File_Ptr2File, "%i\n", expected_Motor_Speed);
fclose(OUTPUT_File_Ptr2File);
}
