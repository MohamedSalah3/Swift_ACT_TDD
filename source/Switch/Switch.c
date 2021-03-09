/*Switch.c*/
#include "switch.h"


/* Globals */

/* Switch State */
static SWITCH_STATE_t real_switch_state;

/* Switch Real Getter Prototype */
SWITCH_STATE_t  SWITCH_getSwState_real(void);

SWITCH_STATE_t   (*SWITCH_getSwState)(void);


/* Global Functions Implementation */
void SWITCH_init(void)
{
    real_switch_state = SW_RELEASED;
    SWITCH_getSwState = SWITCH_getSwState_real;
}

/* Switch Real Getter Implementation */
SWITCH_STATE_t  SWITCH_getSwState_real(void)
{
    return real_switch_state;
}

void SWITCH_update(void)
{
    /* Do nothing for now */
}
