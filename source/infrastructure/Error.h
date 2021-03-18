/*
 * Error.h
 *
 * Created: 03/10/2021
 *  Author: Mohamed Ahmed Salah
 */


#ifndef ERROR_H_
#define ERROR_H_
#include "std_types.h"
#define E_NOK        1
#define E_OK         0
#define NULL_PTR    2
#define NOT_INIT    4
#define MULTIPLE_INIT 6
#define INVALID_PARM  8
#define STATE_MACHINE_ERROR  9

typedef uint8_t ERROR_STATUS;


#endif /* ERROR_H_ */
