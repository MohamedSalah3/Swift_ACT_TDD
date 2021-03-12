
TEST_GROUP(Motor_Angle);



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


TEST(Motor_Angle,output)
{



}


TEST_GROUP_RUNNER(Speed_Control)
{
RUN_TEST_CASE(Motor_Angle,output);
}
