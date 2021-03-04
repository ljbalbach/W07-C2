/*
 * TestStack.c
 *
 * Very simple unit test file for Stack functionality.
 *
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
 * The number of tests that succeeded
 */
static int success_count = 0;

/*
 * The total number of tests run
 */
static int total_count = 0;


/*
 * Setup function to run prior to each test
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
 * Teardown function to run after each test
 */
void teardown(){
    Stack_destroy(stack);
}

/*
 * This function is called multiple times from main for each user-defined test function
 */
void runTest(int (*testFunction)()) {
    total_count++;
    setup();

    if (testFunction()) success_count++;

    teardown();
}


/*
 * Two sample user-defined tests included below.
 * You will have to write many more tests.
 *
 * Each test function should return TEST_SUCCESS at the end.
 * Test functions can contain more than one assertion.
 *
 * If any assertion fails, the function name and line number
 * will be printed and the test will return a failure value.
 *
 * You will have to call runTest on your test functions in main below.
 */


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
 * Main function for the Stack tests which will run each user-defined test in turn.
 */

int main() {
    // Un-comment the next two lines to test your new_Stack and Stack_size functions once, you've written them.
    // runTest(newStackIsNotNull);
    // runTest(newStackSizeZero);

    /*
     * Write more of your own test functions below (such as pushOneElement, pushAndPopOneElement, ...)
     * to help you verify correctness of your Stack
     * you will have to call runTest on all your test functions as shown
     *
     * runTest(pushOneElement);
     * runTest(pushAndPopOneElement);
     *
     */

    printf("Stack Tests complete: %d / %d tests successful.\n----------------\n", success_count, total_count);

}
