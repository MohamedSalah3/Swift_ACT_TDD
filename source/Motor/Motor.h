/*Motor.h*/
#ifndef MOTOR_H_
#define MOTOR_H_
/*********************************************************************/
/*                  _Includes                                       */
/*******************************************************************/
#include "../Speed_Control/Speed_Control.h"
/*******************************************************************/
/*                Definitions                                        */
/*******************************************************************/
#define MINMUM 140
#define MEDIUM 90
#define MAXIMUM 10

/****************************************************************/
/*typedef used here to make the code readable*/
/****************************************************************/
typedef uint8_t MOTOR_ANGEL_t ;
/*****************************************************************/
/*@parm ERROR_STATUS
This param is used to make sure that the structure of the function is
working fine by building whitebox tests */
/*****************************************************************/
ERROR_STATUS MOTOR_init(void);
/*****************************************************************/
/*@Parm [in] This function gets the angle of the motor */
/*****************************************************************/
MOTOR_ANGEL_t MOTOR_getAngel(speed_Cfg_str* SpeedSTR_used);
/*****************************************************************/
/*This Functions Takes the angle form MOTOR_get_Angel and
Update it to the Motor text file*/
/*****************************************************************/
void MOTOR_update(void);



#endif
