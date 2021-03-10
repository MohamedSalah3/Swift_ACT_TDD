/*Switch_Config.h*/
#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

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
/*        Switch state definition                                                 */
/**********************************************************************************/
extern     switch_state_Ptr_to_fun SWITCH_getSwState ; /* Turned into pointer so we can make it point to another fake function */

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

typedef struct Switch_Cfg_str
{
	uint8_t GPIO;
	uint8_t pins;
  SWITCH_STATE_t Switch_status;
  uint8_t Programming_Mode;
}Switch_Cfg_str;

/**********************************************************************************/
/*        extern Switches                                                       */
/**********************************************************************************/
extern Switch_Cfg_str UpSwitch;
extern Switch_Cfg_str DownSwitch;
extern Switch_Cfg_str P_Switch;

#endif
