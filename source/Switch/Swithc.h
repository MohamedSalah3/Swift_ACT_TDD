/*Switch.h*/
#ifndef SWITCH_H_
#define SWITCH_H_
#include "Switch_Config.h"
typedef ptr_to_Fun_Ret_uint8t switch_state_Ptr_to_fun;



void        SWITCH_init(void);
/* Switch Real Getter Prototype */
SWITCH_STATE_t  SWITCH_getSwState_real(void);

void        SWITCH_update(void);

#endif
