#ifndef SWITCH_FAKE_H_
#define SWITCH_FAKE_H_

#include <stdio.h>
#include <string.h>
/* Include tested module header file */
#define EXPOSE_LED_INTERNALS
/*#include "../../source/led/led.h"
*/
#include "../../source/Motor/Motor.h"

static void Switch_getTestData(Switch_Cfg_str* Switch_used,uint8_t test_num);

#endif
