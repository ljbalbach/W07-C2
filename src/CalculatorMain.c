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
    //Make_stack();
    float operand;
    char operator;
    char temp;
    while(1) {
        printf("hello1");
        temp = getchar();
        printf("hello2");
        if (temp == EOF) {
            break;
        }
        ungetc(temp, stdin);
        while (true) {
            if ((temp = getchar()) != ' ') {
                ungetc(temp, stdin);
            }
        }

        temp = getchar();
        if (isdigit(temp)) {
            printf("is a digit\n");
            ungetc(temp, stdin);
            scanf("%f\n", &operand);

            printf("operand: %.2f", operand);
            if (!Calculator_push(operand)) {
                goto error;
            }
        } else if (temp != ' ') {
            printf("is a symbol\n");
            ungetc(temp, stdin);
            scanf("%c", &operator);
            
            printf("operator: %c\n", operator);
            if(!Calculator_calculate(operator, &operand)) {
                goto error;
            }
            printf("after calculate\n");
        }
    }
    float output;
    if (!Calculator_pop(&output)) {
        goto error;
    }
    printf("Final: %.2f", output);
    return 0;

    error:
        clean();


/*
    while(scan >= 0 && scan2 >= 0) {
        scan = scanf("%f", &operand);
        printf("scan: %d", scan);
        scan2 = scanf("%c", &operator);
        printf("scan2: %d", scan2);
        printf("\nop1: %.2f", operand);
        printf("op2:%cend\n", operator);
        if (operator != ' ') {
            printf("here1");
            if(!Calculator_calculate(operator, &operand)) {
                goto error;
            }
            operator = ' ';
        } else if (!Calculator_push(operand)) {
            goto error;
        }
    }
    printf("here2");
    float output;
    if (!Calculator_pop(&output)) {
        goto error;
    }
    printf("Final: %.2f", output);
    return 0;

    error:
        clean();*/
}