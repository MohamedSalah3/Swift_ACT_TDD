#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Motor/Motor.h"

/* Include Unity */
#include "../test/unity/unity_fixture.h"
#define MAKE_UNITY_VERBOSE	argc = 2; argv[1] = "-v"


/* Test Groups Runner */
void RunAllTests(void)
{
RUN_TEST_GROUP(Switch_Status);
 RUN_TEST_GROUP(Speed_Control);
RUN_TEST_GROUP(Motor_Angle);
}


int main(int argc, char const *argv[])
{
ERROR_STATUS ret=E_OK;
/* Manipulate argc & argv to make unity verbose*/
  /* You can use CodeBlocks Command Line inputs to do the same */
  MAKE_UNITY_VERBOSE;

  /* Call Unity Main */
  UnityMain(argc, argv, RunAllTests);


  printf("App is running..");
ret=SWITCH_init(&UpSwitch);
ret=SWITCH_init(&DownSwitch);
ret=SWITCH_init(&P_Switch);
ret=Speed_Control_init();
ret=MOTOR_init();

while(1)
{


}
return 0;

}
