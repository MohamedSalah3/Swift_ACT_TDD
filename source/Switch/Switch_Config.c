/*Switch_Config.c*/
#include "Switch_Config.h"

/***********************************************************************/
/*                Switchs decleration                                    */
/***********************************************************************/
/***********************************************************************/
/*UPSwitch decleration This Switch used To increase the speed of the motor
unless the speed is maximum                                             */
/***********************************************************************/

Switch_Cfg_str UpSwitch =
{
GPIOD ,
PIN0,
UPSWITCH,
SW_PREPRESSED,  /// Intial State
TESTING,
0,
0
};
/***********************************************************************/
/*DownSwitch decleration This Switch used To decrease the speed of the motor
unless the speed is minmum                                             */
/***********************************************************************/
Switch_Cfg_str DownSwitch =
{
GPIOD ,
PIN1,
DOWNSWITCH,
SW_RELEASED,
TESTING,
0,
0
};
/***********************************************************************/
/*P_Switch decleration This Switch used To decrease the speed of the motor
by one step per 30s unless the speed is minmum                         */
/***********************************************************************/
Switch_Cfg_str P_Switch =
{
GPIOD ,
PIN2,
P_SWITCH,
SW_PRESSED,
TESTING,
60,
0
};


test_Cfg_str test_data =
{

{SW_PRESSED,SW_RELEASED,SW_PREPRESSED},
10

};
