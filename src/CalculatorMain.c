/*
 * CalculatorMain.c
 *
 * Main file for running the Calculator.
 *
 *      Author: 190012003
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Calculator.h"

/*
 * private method for handling exceptions.
 */
static void clean() {
    printf("\nBad expression\n");
    exit(0);
}

/*
 * private method to scan a float or char and push or calculate them depending.
 * param operand is the float operand that needs to be pushed to the stack.
 * param operand is the char operator that needs to be used to calculate an output.
 * param isFloat is the bool of if the next char in the stream is an operator or operand.
 */
static void perform(float operand, char operator, bool isFloat) {
    if (isFloat) {
        scanf("%f\n", &operand);
        if (!Calculator_push(operand)) {
            goto error;
        }
        return;
    } else {
        scanf("%c", &operator);
        if(!Calculator_calculate(operator)) {
            goto error;
        }
        return;
    }

    error:
        clean();
}

/*
 * private method to loop through the standard input and check whether the next char is an operator or operand,
 *  it then passes that information onto the perform method.
 */
static void looper() {
    float operand = 0;
    char operator = ' ';
    int temp;
    int second;
    bool neg;

    while((temp = getchar()) != EOF) {
        if (isdigit(temp)) {
            ungetc(temp, stdin);
            perform(operand, operator, true);
        } else if (temp != 32 && temp != 10) {
            neg = isdigit(second = getchar());
            ungetc(second, stdin);
            ungetc(temp, stdin);
            perform(operand, operator, neg);
        }
    }
}

/*
 * private method to get the output from the Calculator and print it out
 */
static void getOut() {
    float output;
    if (!Calculator_pop(&output)) {
        goto error;
    }
    printf("\n%.2f\n", output);
    return;

    error:
        clean();
}

/*
 * Main function for controlling the calculator.
 */
int main() {
    Make_stack();
    looper();
    getOut();
    return 0;
}