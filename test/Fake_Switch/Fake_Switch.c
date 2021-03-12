#include "Switch_Fake.h"

TEST_GROUP(Switch_Status);


  static void Switch_getTestData(SWITCH_STATE_t* initial_switch_state,uint8_t test_num);

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


/** Doxygen Test Case Description **/
TEST(Switch_Status, Switchup_Realeased_After_Init)
{
  ERROR_STATUS ret=E_NOK;
    /*!
		  * @par Given : switch is in unknown state
		  * @par When  : SWITCH_init() is called
		  * @par Then  : Switch is in Released state
	*/


    /* Expected led state */
	SWITCH_STATE_t expected_SWITCH_state = SW_RELEASED;

	/* Arrange */
  switch_st_Testing_Fail(&UpSwitch,SW_PREPRESSED,0,TESTING);


    /* Act */
    ret=SWITCH_init(&UpSwitch);

    /* Assert */
    LONGS_EQUAL(expected_SWITCH_state, SWITCH_getSwState(&UpSwitch));
}
TEST(Switch_Status, SwitchDown_Realeased_After_Init)
{
  ERROR_STATUS ret=E_NOK;
    /*!
		  * @par Given : switch is in unknown state
		  * @par When  : SWITCH_init() is called
		  * @par Then  : Switch is in Released state
	*/


    /* Expected led state */
	SWITCH_STATE_t expected_SWITCH_state = SW_RELEASED;

	/* Arrange */
  switch_st_Testing_Fail(&DownSwitch,SW_PREPRESSED,0,TESTING);


    /* Act */
    ret=SWITCH_init(&DownSwitch);

    /* Assert */
    LONGS_EQUAL(expected_SWITCH_state, SWITCH_getSwState(&DownSwitch));
}
TEST(Switch_Status, SwitchP_Realeased_After_Init)
{
  ERROR_STATUS ret=E_NOK;
    /*!
		  * @par Given : switch is in unknown state
		  * @par When  : SWITCH_init() is called
		  * @par Then  : Switch is in Released state
	*/


    /* Expected led state */
	SWITCH_STATE_t expected_SWITCH_state = SW_RELEASED;
  uint8_t u8_EXP_timing = 0;
	/* Arrange */
  switch_st_Testing_Fail(&P_Switch,SW_PREPRESSED,100,TESTING);
  P_Switch.u8_Mult_init_detect = 0;

    /* Act */
    ret=SWITCH_init(&P_Switch);

    /* Assert */
    LONGS_EQUAL(expected_SWITCH_state, SWITCH_getSwState(&P_Switch));


}

TEST(Switch_Status,Multiple_init_detection)
{

    /*!
		  * @par Given : switch init should be called once
		  * @par When  : SWITCH_init() is called Twice
		  * @par Then  : Switch Module should be able to prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = MULTIPLE_INIT;

	/* Arrange */
ERROR_STATUS ret=E_NOK;


    /* Act */
    ret=SWITCH_init(&UpSwitch);
    ret=SWITCH_init(&UpSwitch);
    /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_init(&UpSwitch));

}
TEST(Switch_Status,NULL_PTR_init_detection)
{

    /*!
		  * @par Given : switch init shouldnot take a null ptr
		  * @par When  : SWITCH_init() is called with null ptr
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = NULL_PTR;

	/* Arrange */
ERROR_STATUS ret=E_NOK;


  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_init(NULL));

}
TEST(Switch_Status,INVALID_PARM_init_detection)
{

    /*!
		  * @par Given : switch init shouldnot take an INVALID_PARM
		  * @par When  : SWITCH_init() is called with an INVALID_PARM
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = INVALID_PARM;

	/* Arrange */
ERROR_STATUS ret=E_NOK;

DownSwitch.GPIO = 7;
DownSwitch.pins =10;
DownSwitch.Switch_status = 30;

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_init(&DownSwitch));
SWITCH_init(&DownSwitch);
}

TEST_GROUP_RUNNER(Switch_Status)
{/*Init Func Testing */
    RUN_TEST_CASE(Switch_Status, Switchup_Realeased_After_Init);
    RUN_TEST_CASE(Switch_Status, SwitchDown_Realeased_After_Init);
    RUN_TEST_CASE(Switch_Status, SwitchP_Realeased_After_Init);
    RUN_TEST_CASE(Switch_Status, Multiple_init_detection);
    RUN_TEST_CASE(Switch_Status, NULL_PTR_init_detection);
    RUN_TEST_CASE(Switch_Status, INVALID_PARM_init_detection);
    /* And so on..*/
    /* False transitions & 1-Switch coverage tests should be added */
}


  static void Switch_getTestData(Switch_Cfg_str* Switch_used,uint8_t test_num)
  {
  FILE* Input_File_Ptr2File = fopen("../../switch.txt","r+");
  char* Ptr_to_char;
  char STR_UpSwitch[20];
  char STR_DownSwitch[20];
  char STR_P_Switch[20];
  char timeSTR_P_Switch[5];
  if(Input_File_Ptr2File){
  for(int i=0;i<test_num+2;i++)
  {
  memset(STR_UpSwitch,0,20);
  memset(STR_DownSwitch,0,20);
  memset(STR_P_Switch,0,20);
  /*'-' used To diffentiate between numbers*/
  memset(timeSTR_P_Switch,'-',5);
  fscanf(Input_File_Ptr2File,"%s\n",STR_UpSwitch);
  fscanf(Input_File_Ptr2File,"%s\n",STR_DownSwitch);
  fscanf(Input_File_Ptr2File,"%s\n",STR_P_Switch);
  fscanf(Input_File_Ptr2File,"%s\n",timeSTR_P_Switch);
  }

if(Switch_used == (&UpSwitch)){Ptr_to_char = STR_UpSwitch;}
else if(Switch_used == (&DownSwitch)){Ptr_to_char = STR_DownSwitch;}
else if(Switch_used ==(&P_Switch)){Ptr_to_char = STR_P_Switch;}
else
{

}

  /*Make Your Decisions*/
  if(strcmp(Ptr_to_char,"SW_PREPRESSED") == 0)
  {
      (Switch_used -> Switch_status) = SW_PREPRESSED;
  }
  else if (strcmp(Ptr_to_char,"SW_PRESSED") == 0)
  {
      (Switch_used -> Switch_status) = SW_PRESSED;
  }
  else if(strcmp(Ptr_to_char,"SW_PRERELEASED") == 0)
  {
      (Switch_used -> Switch_status) = SW_PRERELEASED;
  }
  else if(strcmp(Ptr_to_char,"SW_RELEASED") == 0)
  {
      (Switch_used -> Switch_status) = SW_RELEASED;
  }
  else
  {
      printf("Incorrect test data\n");
  }

  fclose(Input_File_Ptr2File);


}else{  printf("Failed To open the file");}
  }
