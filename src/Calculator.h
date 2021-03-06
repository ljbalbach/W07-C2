/*
 * Calculator.h
 *
 * Module interface for Calculator implementation.
 *
 *      Author: 190012003
 */

#ifndef CALCULATOR_H_

#include <stdbool.h>
#include <stddef.h>

void Make_Stack();

bool Calculator_Push(float operand);

bool Calculator_Pop(float* retval);

bool Calculator_Calculate(char operator, float* retval);

#endif /* CALCULATOR_H_ */
