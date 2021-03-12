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
  //  RUN_TEST_GROUP(FakeSwitch);
  //  RUN_TEST_GROUP(LedState);
  
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
		ret=SWITCH_update(&UpSwitch);
		ret=SWITCH_update(&DownSwitch);
		ret=SWITCH_update(&P_Switch);
		
		
		
	}
    return 0;

}
