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

static void clean() {
    printf("\nBad expression\n");
    exit(0);
}

/*
 * Main function for taking inputs and using the calculator to carry out the operations.
 */
int main() {
    Make_stack();
    float operand;
    char operator;
    int temp;
    int second;

    while((temp = getchar()) != EOF) {
        printf("loop\n");
        if (isdigit(temp)) {
            ungetc(temp, stdin);
            scanf("%f\n", &operand);

            if (!Calculator_push(operand)) {
                goto error;
            }
        } else if (temp != 32 && (isdigit(second = getchar()))) {
            ungetc(second, stdin);
            ungetc(temp, stdin);

            scanf("%f\n", &operand);

            if (!Calculator_push(operand)) {
                goto error;
            }
        } else if (temp != 32) {
            ungetc(second, stdin);
            ungetc(temp, stdin);
            scanf("%c", &operator);

            if(!Calculator_calculate(operator)) {
                goto error;
            }
        }
        printf("loopEnd\n");
    }
    printf("loopFinished\n");
    float output;
    if (!Calculator_pop(&output)) {
        goto error;
    }
    printf("\nFinal: %.2f\n", output);
    return 0;

    error:
        clean();
}