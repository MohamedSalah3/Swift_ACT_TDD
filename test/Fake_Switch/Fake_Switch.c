#include "Switch_Fake.h"
#include <math.h>
#include <stdlib.h>
TEST_GROUP(Switch_Status);

TEST_GROUP(Speed_Control);



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
TEST(Switch_Status,NULL_PTR_update_detection1)
{

    /*!
		  * @par Given : switch update shouldnot take a null ptr
		  * @par When  : SWITCH_update() is called with null ptr for Switch_used and
      real ptr for Test_data then reverse it
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = NULL_PTR;

	/* Arrange */
test_Cfg_str test_valid={
{SW_PRESSED,SW_RELEASED,SW_PREPRESSED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  DOWNSWITCH,
  SW_RELEASED,
  TESTING,
  0,
  0
};

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_update(0,&test_valid));

}

TEST(Switch_Status,NULL_PTR_update_detection2)
{

    /*!
		  * @par Given : switch update shouldnot take a null ptr
		  * @par When  : SWITCH_update() is called with null ptr for Switch_used and
      real ptr for Test_data then reverse it
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = NULL_PTR;

	/* Arrange */
test_Cfg_str test_valid={
{SW_PRESSED,SW_RELEASED,SW_PREPRESSED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  DOWNSWITCH,
  SW_RELEASED,
  TESTING,
  0,
  0
};

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_update(&switch_used_test,0));

}
/*Perform EP and BVA testing Techniques*/
TEST(Switch_Status,EquivelP_and_BVA_testing0)
{

    /*!
		  * @par Given : switch update should not take a invalid switch id
		  * @par When  : SWITCH_update() is called with invalid switch id
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = INVALID_PARM;

	/* Arrange */
test_Cfg_str test_valid={
{SW_PRESSED,SW_RELEASED,SW_PREPRESSED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  -1,     /**Invalid Switch id */
  SW_RELEASED,
  TESTING,
  0,
  0
};

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_update(&switch_used_test,&test_valid));

}
/*Perform EP and BVA testing Techniques*/
TEST(Switch_Status,EquivelP_and_BVA_testing1)
{

    /*!
		  * @par Given : switch update should not take a invalid switch id
		  * @par When  : SWITCH_update() is called with invalid switch id
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = INVALID_PARM;

	/* Arrange */
test_Cfg_str test_valid={
{SW_PRESSED,SW_RELEASED,SW_PREPRESSED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  P_SWITCH+1,     /**Invalid Switch id */
  SW_RELEASED,
  TESTING,
  0,
  0
};

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_update(&switch_used_test,&test_valid));

}

/*Perform EP and BVA testing Techniques*/
TEST(Switch_Status,EquivelP_and_BVA_testing2)
{

    /*!
		  * @par Given : switch update should not take a invalid switch id
		  * @par When  : SWITCH_update() is called with invalid switch id
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = INVALID_PARM;

	/* Arrange */
test_Cfg_str test_valid={
{SW_PRESSED,SW_RELEASED,SW_PREPRESSED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  UPSWITCH-1,     /**Invalid Switch id */
  SW_RELEASED,
  TESTING,
  0,
  0
};

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_update(&switch_used_test,&test_valid));

}
/*Perform EP and BVA testing Techniques*/
TEST(Switch_Status,EquivelP_and_BVA_testing3)
{

    /*!
		  * @par Given : switch update should not take a invalid switch id
		  * @par When  : SWITCH_update() is called with invalid switch id
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = E_OK;

	/* Arrange */
test_Cfg_str test_valid={
{SW_PRESSED,SW_RELEASED,SW_PREPRESSED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  DOWNSWITCH,     /**Invalid Switch id */
  SW_RELEASED,
  TESTING,
  0,
  0
};

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_update(&switch_used_test,&test_valid));

}
TEST(Switch_Status,EquivelP_and_BVA_testing4)
{

    /*!
		  * @par Given : switch update should not take a invalid switch Status
		  * @par When  : SWITCH_update() is called with invalid switch status
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = INVALID_PARM;

	/* Arrange */
test_Cfg_str test_valid={
{SW_PRESSED,-1,SW_PREPRESSED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  DOWNSWITCH,     /**Invalid Switch id */
  SW_RELEASED,
  TESTING,
  0,
  0
};

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_update(&switch_used_test,&test_valid));

}
TEST(Switch_Status,EquivelP_and_BVA_testing5)
{

    /*!
		  * @par Given : switch update should not take a invalid switch Status
		  * @par When  : SWITCH_update() is called with invalid switch status
		  * @par Then  : Switch Module should be able to Report and Prevent it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = INVALID_PARM;

	/* Arrange */
test_Cfg_str test_valid={
{SW_PRESSED,SW_RELEASED+1,SW_PREPRESSED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  DOWNSWITCH,     /**Invalid Switch id */
  SW_RELEASED,
  TESTING,
  0,
  0
};

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_update(&switch_used_test,&test_valid));

}
TEST(Switch_Status,EquivelP_and_BVA_testing6)
{

    /*!
		  * @par Given : switch update should not take a valid switch Status
		  * @par When  : SWITCH_update() is called with valid switch status
		  * @par Then  : Switch Module should be able to Process it
	*/


    /* Expected  state */
	ERROR_STATUS expected_ERROR_STATUS = E_OK;

	/* Arrange */

test_Cfg_str test_valid={
{SW_PRESSED,SW_PREPRESSED,SW_PREPRESSED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  DOWNSWITCH,
  SW_RELEASED,
  TESTING,
  0,
  0
};
SWITCH_init(&switch_used_test);

  /* Assert */
    LONGS_EQUAL(expected_ERROR_STATUS, SWITCH_update(&switch_used_test,&test_valid));

}
TEST(Switch_Status,stateMachine_Mechanism)
{

    /*!
		  * @par Given : switch update is used to update objects
		  * @par When  : SWITCH_update() is called
		  * @par Then  : Switch objects should change
	*/



	/* Arrange */
  SWITCH_init(&P_Switch);



test_Cfg_str test_valid={
{SW_RELEASED,SW_RELEASED,SW_RELEASED},
10
};

test_Cfg_str test_valid2={
{SW_PREPRESSED,SW_PREPRESSED,SW_PREPRESSED},
10
};

test_Cfg_str test_valid3={
{SW_PRESSED,SW_PRESSED,SW_PRESSED},
10
};

test_Cfg_str test_valid4={
{SW_PRERELEASED,SW_PRERELEASED,SW_PRERELEASED},
10
};

test_Cfg_str test_valid5={
{SW_RELEASED,SW_RELEASED,SW_RELEASED},
10
};
Switch_Cfg_str switch_used_test={

  GPIOD ,
  PIN1,
  P_SWITCH,
  SW_RELEASED,
  TESTING,
  0,
  0
};




SWITCH_update(&switch_used_test,&test_valid);
SWITCH_update(&switch_used_test,&test_valid2);
SWITCH_update(&switch_used_test,&test_valid3);
SWITCH_update(&switch_used_test,&test_valid4);
SWITCH_update(&switch_used_test,&test_valid5);


  /* Assert */
    LONGS_EQUAL(E_OK,SWITCH_update(&switch_used_test,&test_valid5));
}



TEST(Switch_Status,stateMachine_Mechanism1)
{

    /*!
		  * @par Given : switch update is used to update objects
		  * @par When  : SWITCH_update() is called
		  * @par Then  : Switch objects should change
	*/



	/* Arrange */

    SWITCH_init(&UpSwitch);
  /* Arrange */
test_Cfg_str test_valid={
{SW_RELEASED,SW_RELEASED,SW_RELEASED},
10
};

test_Cfg_str test_valid2={
{SW_PREPRESSED,SW_PREPRESSED,SW_PREPRESSED},
10
};

test_Cfg_str test_valid3={
{SW_PRESSED,SW_PRESSED,SW_PREPRESSED},
10
};

test_Cfg_str test_valid4={
{SW_PRERELEASED,SW_PRERELEASED,SW_PRERELEASED},
10
};

test_Cfg_str test_valid5={
{SW_RELEASED,SW_RELEASED,SW_RELEASED},
10
};


Switch_Cfg_str switch_used_test2={

  GPIOD ,
  PIN1,
  UPSWITCH,
  SW_RELEASED,
  TESTING,
  0,
  0
};


SWITCH_update(&switch_used_test2,&test_valid);
SWITCH_update(&switch_used_test2,&test_valid2);
SWITCH_update(&switch_used_test2,&test_valid3);
SWITCH_update(&switch_used_test2,&test_valid4);
SWITCH_update(&switch_used_test2,&test_valid5);



  /* Assert */
    LONGS_EQUAL(STATE_MACHINE_ERROR,SWITCH_update(&switch_used_test2,&test_valid5));
}


TEST(Switch_Status,Update_fun_is_updating)
{

    /*!
		  * @par Given : switch update is used to update objects
		  * @par When  : SWITCH_update() is called
		  * @par Then  : Switch objects should change
	*/


    /* Expected  state */
uint8_t UpSwitch_Switch_status = SW_PREPRESSED           ;
uint8_t Down_Switch_Switch_status =SW_RELEASED             ;
uint8_t P_SWITCH_Switch_status=SW_PRESSED       ;
uint32_t P_SWITCH_push_time=15;

	/* Arrange */
  SWITCH_init(&P_Switch);

SWITCH_update(&P_Switch,(Switch_getTestData(&test_data,0)));



  /* Assert */
    LONGS_EQUAL(P_SWITCH_push_time, Switch_get_time(&P_Switch));
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
    RUN_TEST_CASE(Switch_Status, Update_fun_is_updating);
    RUN_TEST_CASE(Switch_Status,NULL_PTR_update_detection1);
  RUN_TEST_CASE(Switch_Status,NULL_PTR_update_detection2);
  RUN_TEST_CASE(Switch_Status,EquivelP_and_BVA_testing0);
  RUN_TEST_CASE(Switch_Status,EquivelP_and_BVA_testing1);
  RUN_TEST_CASE(Switch_Status,EquivelP_and_BVA_testing2);
RUN_TEST_CASE(Switch_Status,EquivelP_and_BVA_testing3);
RUN_TEST_CASE(Switch_Status,EquivelP_and_BVA_testing4);
RUN_TEST_CASE(Switch_Status,EquivelP_and_BVA_testing5);
RUN_TEST_CASE(Switch_Status,EquivelP_and_BVA_testing6);
RUN_TEST_CASE(Switch_Status,stateMachine_Mechanism);
RUN_TEST_CASE(Switch_Status,stateMachine_Mechanism1);
}


test_Cfg_str* Switch_getTestData(test_Cfg_str* Data_Return,uint8_t test_num)
 {
  FILE* Input_File_Ptr2File;
  Input_File_Ptr2File= fopen("Input.txt","r+");


  char STR_UpSwitch[20];
  char STR_DownSwitch[20];
  char STR_P_Switch[20];
  char timeSTR_P_Switch[5];

  for(int i=0;i<test_num+2;i++)
  {
  memset(STR_UpSwitch,0,20);
  memset(STR_DownSwitch,0,20);
  memset(STR_P_Switch,0,20);
  /*'-' used To diffentiate between numbers*/
  memset(timeSTR_P_Switch,0,5);
  fscanf(Input_File_Ptr2File,"%s\n",STR_UpSwitch);
  fscanf(Input_File_Ptr2File,"%s\n",STR_DownSwitch);
  fscanf(Input_File_Ptr2File,"%s\n",STR_P_Switch);
  fscanf(Input_File_Ptr2File,"%s\n",timeSTR_P_Switch);
  }
if(Input_File_Ptr2File){
  /*Make Your Decisions*/
  if(strcmp(STR_UpSwitch,"SW_PREPRESSED") == 0)
  {
      (Data_Return -> Switch_status[UPSWITCH]) = SW_PREPRESSED;
  }
  else if (strcmp(STR_UpSwitch,"SW_PRESSED") == 0)
  {
      (Data_Return -> Switch_status[UPSWITCH]) = SW_PRESSED;
  }
  else if(strcmp(STR_UpSwitch,"SW_PRERELEASED") == 0)
  {
      (Data_Return -> Switch_status[UPSWITCH]) = SW_PRERELEASED;
  }
  else if(strcmp(STR_UpSwitch,"SW_RELEASED") == 0)
  {
      (Data_Return -> Switch_status[UPSWITCH]) =SW_RELEASED;
  }
  else
  {
      printf("Incorrect test data STR_UpSwitch\n");
  }

  if(strcmp(STR_DownSwitch,"SW_PREPRESSED") == 0)
  {
      (Data_Return -> Switch_status[DOWNSWITCH]) = SW_PREPRESSED;
  }
  else if (strcmp(STR_DownSwitch,"SW_PRESSED") == 0)
  {
      (Data_Return -> Switch_status[DOWNSWITCH]) = SW_PRESSED;
  }
  else if(strcmp(STR_DownSwitch,"SW_PRERELEASED") == 0)
  {
      (Data_Return -> Switch_status[DOWNSWITCH]) = SW_PRERELEASED;
  }
  else if(strcmp(STR_DownSwitch,"SW_RELEASED") == 0)
  {
      (Data_Return -> Switch_status[DOWNSWITCH]) =SW_RELEASED;
  }
  else
  {
      printf("Incorrect test data  STR_DownSwitch\n");
  }

  if(strcmp(STR_P_Switch,"SW_PREPRESSED") == 0)
  {
      (Data_Return -> Switch_status[P_SWITCH]) = SW_PREPRESSED;
  }
  else if (strcmp(STR_P_Switch,"SW_PRESSED") == 0)
  {
      (Data_Return -> Switch_status[P_SWITCH]) = SW_PRESSED;
  }
  else if(strcmp(STR_P_Switch,"SW_PRERELEASED") == 0)
  {
      (Data_Return -> Switch_status[P_SWITCH]) = SW_PRERELEASED;
  }
  else if(strcmp(STR_P_Switch,"SW_RELEASED") == 0)
  {
      (Data_Return -> Switch_status[P_SWITCH]) =SW_RELEASED;
  }
  else
  {
      printf("Incorrect test data STR_P_Switch\n");
  }
  (Data_Return -> Push_Time)=atoi(timeSTR_P_Switch);
  fclose(Input_File_Ptr2File);

 }else{
  printf("Failed To open the file");
  }
return Data_Return;
  }
