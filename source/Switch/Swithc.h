/*Switch.h*/
#ifndef SWITCH_H_
#define SWITCH_H_
#include "Switch_Config.h"
typedef enum {SW_PREPRESSED,SW_PRESSED,SW_PRERELEASED, SW_RELEASED} SWITCH_STATE_t;


void        SWITCH_init(void);
extern      SWITCH_STATE_t   (*SWITCH_getSwState)(void); /* Turned into pointer so we can make it point to another fake function */
void        SWITCH_update(void);

#endif
