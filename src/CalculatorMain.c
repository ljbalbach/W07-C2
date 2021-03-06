/*
 * CalculatorMain.c
 *
 * Main file for running the Calculator.
 *
 *      Author: 190012003
 */

#include <stdio.h>
#include "Calculator.h"

static void clean() {
    printf("Bad expression");
    exit(0);
}

/*
 * Main function for taking inputs and using the calculator to carry out the operations
 */
int main() {
    Make_Stack();
    float input;
    char operator = NULL;
    while(scanf("%f%c", &input, &operator) != EOF) {
        if (operator != NULL) {
            if(!Calculator_Calculate(operator, &input)) {
                goto error;
            }
            operator = NULL;
        }
        if (!Calculator_Push(input)) {
            goto error;
        }
    }
    float output;
    if (!Calculator_Pop(&output)) {
        goto error;
    }
    printf("%.2f", output);

    error:
        clean();
}