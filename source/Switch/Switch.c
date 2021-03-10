/*Switch.c*/
#include "switch.h"


/* Globals */

/* Switch State */
static SWITCH_STATE_t Real_Switch_State;



switch_state_Ptr_to_fun SWITCH_getSwState ;



/* Global Functions Implementation */
ERROR_STATUS SWITCH_init(void)
{
    Real_Switch_State = SW_RELEASED;
    SWITCH_getSwState = SWITCH_getSwState_real;
}

/* Switch Real Getter Implementation */
SWITCH_STATE_t  SWITCH_getSwState_real(void)
{
    return Real_Switch_State;
}


void SWITCH_update(void)
{
    /* Do nothing for now */
}
