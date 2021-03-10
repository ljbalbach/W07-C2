/*
 * Calculator.c
 *
 * Calculator implementation for Reverse Polish notation.
 *
 *      Author: 190012003
 */

#include "Calculator.h"
#include "Stack.h"

/*
 * the Stack to use during calculations
 */
static Stack* stack;

void Make_stack() {
    stack = new_Stack();
}

bool Calculator_push(float operand) {
    return Stack_push(stack, operand);
}

bool Calculator_pop(float* retval) {
    if (Stack_size(stack) != 1) {
        return false;
    }
    return Stack_pop(stack, retval);
}

bool Calculator_calculate(char operator) {
    float first;
    float second;
    float out;

    if (Stack_pop(stack, &second) == false || Stack_pop(stack, &first) == false) {
        return false;
    }
    if (operator == '/' && second == 0.0) {     //division by 0
        return false;
    }
    switch(operator) {
        case '+' :
            out = first + second;
            break;
        case '-' :
            out = first - second;
            break;
        case '*' :
            out = first * second;
            break;
        case '/' :
            out = first / second;
            break;
        default:
            return false;
    }
    return Calculator_push(out);;
}