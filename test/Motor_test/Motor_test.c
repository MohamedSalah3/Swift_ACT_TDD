
TEST_GROUP(Switch_Status);



TEST_SETUP(Switch_Status)
{
   switch_st_Testing_setter(&DownSwitch,TESTING);
   switch_st_Testing_setter(&UpSwitch,TESTING);
   switch_st_Testing_setter(&P_Switch,TESTING);

}


TEST_TEAR_DOWN(Switch_Status)
{
  switch_st_Testing_setter(&DownSwitch,PRODUCTION);
  switch_st_Testing_setter(&UpSwitch,PRODUCTION);
  switch_st_Testing_setter(&P_Switch,PRODUCTION);

}

static void Motor_TEST_SET_Result_Data(MOTOR_ANGEL_t* expected_Motor_Speed)
{
FILE* OUTPUT_File_Ptr2File = fopen("MOTOR.txt","a");
fprintf(OUTPUT_File_Ptr2File, "%i\n", expected_Motor_Speed);
fclose(OUTPUT_File_Ptr2File);
}
