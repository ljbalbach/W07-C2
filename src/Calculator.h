/*
 * Calculator.h
 *
 * Module interface for Calculator implementation.
 *
 *      Author: 190012003
 */

#ifndef CALCULATOR_H_

#include <stdbool.h>

void Make_stack();

bool Calculator_push(float operand);

bool Calculator_pop(float* retval);

bool Calculator_calculate(char operator);

#endif /* CALCULATOR_H_ */
