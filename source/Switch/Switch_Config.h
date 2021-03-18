/*Switch_Config.h*/
#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#include "../../test/unity/unity_fixture.h"
#include "../infrastructure/Error.h"
#include "../infrastructure/std_types.h"
/**********************************************************************************/
/*        Switch state definition                                                 */
/**********************************************************************************/
typedef uint8_t SWITCH_STATE_t ;
#define SW_PREPRESSED 0
#define SW_PRESSED 1
#define SW_PRERELEASED 2
#define SW_RELEASED 3


/**********************************************************************************/
/*        Switch Structure   definition                                       */
/**********************************************************************************/

#define PIN0	0x01
#define PIN1	0x02
#define PIN2	0x04
#define PIN3	0x08
#define PIN4	0x10
#define PIN5	0x20
#define PIN6	0x40
#define PIN7	0x80


#define GPIOA			0
#define GPIOB			1
#define GPIOC			2
#define GPIOD			3

#define PRODUCTION 0
#define TESTING    1

#define UPSWITCH   0
#define DOWNSWITCH 1
#define P_SWITCH   2

typedef struct Switch_Cfg_str
{
	uint8_t GPIO;
	uint8_t pins;
	uint8_t Switch_ID;
  SWITCH_STATE_t Switch_status;
  uint8_t Programming_Mode;
	uint32_t Push_Time;
	uint8_t u8_Mult_init_detect;
}Switch_Cfg_str;

typedef struct test_Cfg_str
{
  SWITCH_STATE_t Switch_status[3];
	uint32_t Push_Time;
}test_Cfg_str;


extern test_Cfg_str test_data;
/**********************************************************************************/
/*        extern Switches                                                       */
/**********************************************************************************/
extern Switch_Cfg_str UpSwitch;
extern Switch_Cfg_str DownSwitch;
extern Switch_Cfg_str P_Switch;

/************************************************************************/
/*						 Pointer To Funcrion  definetion                          */
/************************************************************************/
typedef void (*ptr_to_Fun)(void);
typedef SWITCH_STATE_t (*ptr_to_Fun_Ret_uint8t)(Switch_Cfg_str *);
typedef uint32_t (*ptr_to_Fun_Ret_uint32t)(Switch_Cfg_str *);


#endif
