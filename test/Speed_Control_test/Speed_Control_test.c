
#include <stdio.h>
#include <string.h>
/* Include tested module header file */
#define EXPOSE_LED_INTERNALS
#include "../../source/Speed_Control/Speed_Control.h"

/*Include FakeSwitch */
#include "../Fake_Switch/Switch_Fake.h"

/* Include Unity */
#include "../unity/unity_fixture.h"
/*speed control test.c*/
#include "Speed_Control_test.h"

/* Include Unity */
#include "../unity/unity_fixture.h"


TEST_GROUP(Speed_Control);



TEST_SETUP(Speed_Control)
{
  /* switch_st_Testing_setter(&DownSwitch,TESTING);
   switch_st_Testing_setter(&UpSwitch,TESTING);
   switch_st_Testing_setter(&P_Switch,TESTING);
*/
}


TEST_TEAR_DOWN(Speed_Control)
{/*
  switch_st_Testing_setter(&DownSwitch,PRODUCTION);
  switch_st_Testing_setter(&UpSwitch,PRODUCTION);
  switch_st_Testing_setter(&P_Switch,PRODUCTION);
*/
}

/***********************************************************************/
/*                                */
/***********************************************************************/
TEST(Speed_Control,Angle_after_init)
{
  /*!
    * @par Given : MOTOR_angel is in unknown state
    * @par When  : Speed_Control_init() is called
    * @par Then  : MOTOR is in MEDIUM state
*/

MOTOR_ANGEL_t expected_Angle = MEDIUM;

speed_st_Testing_Fail(MAXIMUM);

/* Act */
Speed_Control_init();
LONGS_EQUAL(expected_Angle, SpeedSTR_update.MOTOR_angel);


}






TEST(Speed_Control,Update_Boundries)
{
  /*!
    * @par Given : MOTOR_angel is in unknown state
    * @par When  : Speed_Control_init() is called
    * @par Then  : MOTOR is in MEDIUM state
*/

MOTOR_ANGEL_t expected_Angle = 93;


//speed_st_Testing_Fail(MAXIMUM);
/* Act */
/* Arrange */
SWITCH_init(&P_Switch);
SWITCH_init(&UpSwitch);
SWITCH_init(&DownSwitch);
Speed_Control_init();

SWITCH_update(&P_Switch,(Switch_getTestData(&test_data,0)));
SWITCH_update(&UpSwitch,(Switch_getTestData(&test_data,0)));
SWITCH_update(&DownSwitch,(Switch_getTestData(&test_data,0)));

/* Assert */

Speed_Control_get_Switch_state(&SpeedSTR_update);



LONGS_EQUAL(expected_Angle,Angel_update(&SpeedSTR_update));



}
TEST_GROUP_RUNNER(Speed_Control)
{
  RUN_TEST_CASE(Speed_Control, Angle_after_init);
  RUN_TEST_CASE(Speed_Control, Update_Boundries);


}
