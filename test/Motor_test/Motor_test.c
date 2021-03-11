#include <stdio.h>
#include <string.h>
/* Include tested module header file */
#define EXPOSE_LED_INTERNALS
/*#include "../../source/led/led.h"
*/
/*Include FakeSwitch */
#include "../fake_switch/fake_sw.h"

/* Include Unity */
#include "../unity/unity_fixture.h"
static void Motor_TEST_SET_Result_Data(MOTOR_SPEED_t* expected_Motor_Speed)
{
FILE* OUTPUT_File_Ptr2File = fopen("MOTOR.txt","a");
fprintf(OUTPUT_File_Ptr2File, "%i\n", expected_Motor_Speed);
fclose(OUTPUT_File_Ptr2File);
}
