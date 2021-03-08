/*
 * TestStack.c
 *
 * Very simple unit test file for Stack functionality.
 *
 *      Author: 190012003
 */

#include <stdio.h>
#include "Stack.h"
#include "myassert.h"



/*
 * The stack to use during tests
 */
static Stack* stack;

#ifndef DYNAMIC // if we're not using dynamic memory allocation in our stack implementation, we need an actual stack struct in addition to the pointer to the stack
static Stack stack_s;
#endif


/*
 * The number of tests that succeeded.
 */
static int success_count = 0;

/*
 * The total number of tests run.
 */
static int total_count = 0;


/*
 * Setup function to run prior to each test.
 */
#ifdef DYNAMIC // if we are using dynamic memory allocation in our Stack implementation

void setup() {
    stack = new_Stack();
}

#else // we are not using dynamic memory allocation so initialise "Stack* stack" to contain the pointer to the stack struct

void setup() {
    stack_s = new_Stack();
    stack = &stack_s;
}

#endif


/*
 * Teardown function to run after each test.
 */
void teardown(){
    Stack_destroy(stack);
}

/*
 * This function is called multiple times from main for each user-defined test function.
 */
void runTest(int (*testFunction)()) {
    total_count++;
    setup();

    if (testFunction()) success_count++;

    teardown();
}


/*
 * Checks that the Stack constructor returns a non-NULL pointer.
 */
int newStackIsNotNull() {
    assert(stack != NULL);
    return TEST_SUCCESS;
}


/*
 * Checks that the size of an empty stack is 0.
 */
int newStackSizeZero() {
    assert(Stack_size(stack) == 0);
    return TEST_SUCCESS;
}

/*
 * Checks that one element is successfully pushed to the stack.
 */
int pushOneElement() {
    assert(Stack_push(stack, 4.0) == true);
    assert(Stack_size(stack) == 1);
    return TEST_SUCCESS;
}

/*
 * Checks that one element can be pushed and popped from the stack.
 */
int pushAndPopOneElement() {
    float j = 4.0;
    float i = 2.0;
    float *ip = &i;
    Stack_push(stack, j);
    assert(Stack_size(stack) == 1);
    assert(Stack_pop(stack, ip) == true);
    assert(Stack_size(stack) == 0);
    assert(*ip == j);
    return TEST_SUCCESS;
}

/*
 * Checks that two elements can be pushed and popped from the stack.
 */
int pushAndPopTwoElements() {
    float j = 4.0;
    float i = 2.0;
    float Jout = 1;
    float Iout = 1;
    float *jp = &Jout;
    float *ip = &Iout;

    Stack_push(stack, j);
    Stack_push(stack, i);
    assert(Stack_pop(stack, ip) == true);
    assert(Stack_pop(stack, jp) == true);
    assert(*ip == i);
    assert(*jp == j);
    return TEST_SUCCESS;
}

/*
 * Checks that the iaEmpty returns the correct results.
 */
int stackIsntAndIsEmpty() {
    assert(Stack_isEmpty(stack) == true);
    Stack_push(stack, 4.0);
    assert(Stack_isEmpty(stack) == false);
    return TEST_SUCCESS;
}

/*
 * Checks that the Stack is properly cleared.
 */
int stackIsCleared() {
    Stack_push(stack, 4.0);
    Stack_push(stack, 7.0);
    Stack_push(stack, 1.0);
    assert(Stack_size(stack) == 3);
    Stack_clear(stack);
    assert(Stack_size(stack) == 0);
    return TEST_SUCCESS;
}

/*
 * Checks that popping from an empty list returns false.
 */
int popFail() {
    float i = 1.5;
    assert(Stack_pop(stack, &i) == false);
    return TEST_SUCCESS;
}

/*
 * Checks that pushing to a full list returns false.
 */
int pushFail() {
    float j = 1.5;
    for (int i = 0; i < MAX_VALUE - 1; i++) {
        Stack_push(stack, j);
    }
    assert(Stack_push(stack, j) == true);
    assert(Stack_push(stack, j) == false);
    return TEST_SUCCESS;
}



/*
 * Main function for the Stack tests which will run each user-defined test in turn.
 */
int main() {
    runTest(newStackSizeZero);
    runTest(newStackIsNotNull);
    runTest(pushOneElement);
    runTest(pushAndPopOneElement);
    runTest(pushAndPopTwoElements);
    runTest(stackIsntAndIsEmpty);
    runTest(stackIsCleared);
    runTest(pushFail);
    runTest(popFail);

    printf("Stack Tests complete: %d / %d tests successful.\n----------------\n", success_count, total_count);
}
