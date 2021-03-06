/*
 * Calculator.c
 *
 * Calculator implementation for Reverse Polish notation.
 *
 *      Author: 190012003
 */

#include "Calculator.h"
#include "Stack.h"

static Stack* stack;

void Make_Stack() {
    stack = new_Stack();
}

bool Calculator_Push(float operand) {
    return Stack_Push(stack, operand);
}

bool Calculator_Pop(float* retval) {
    if (Stack_Size(stack) != 1) {
        return false;
    }
    return Stack_Pop(stack, retval);
}

bool Calculator_Calculate(char operator, float* retval) {
    float first;
    float second;
    if (Stack_Pop(stack, &second) == false || Stack_Pop(stack, &first) == false) {
        return false;
    }
    switch(operator) {
        case '+' :
            *retval = first + second;
        case '-' :
            *retval = first - second;
        case '*' :
            *retval = first * second;
        case '/' :
            *retval = first / second;
    }
    return true;
}