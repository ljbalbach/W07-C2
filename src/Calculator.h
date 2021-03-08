/*
 * Calculator.h
 *
 * Module interface for Calculator implementation.
 *
 *      Author: 190012003
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <stdbool.h>

/*
 * Creates/initialises a Stack using the Stack.c file.
 */
void Make_stack();


/*
 * pushes a float to the Stack.
 * param operand is the float to be pushed.
 * returns if the push worked or not.
 */
bool Calculator_push(float operand);

/*
 * pops a float from the Stack, after ensuring that there is only one element left(the result),
 *  otherwise the expression is incompatible.
 * param retval is the pointer to where the popped float should be stored.
 * returns if the pop worked or not.
 */
bool Calculator_pop(float* retval);

/*
 * performs a calculation on the top floats in the Stack with the correct operator,
 *  pushing the result back onto the stack.
 * param operator is the char operator that is used to combine the top values.
 * returns if the calculation worked or not.
 */
bool Calculator_calculate(char operator);

#endif /* CALCULATOR_H_ */
