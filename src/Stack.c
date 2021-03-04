/*
 * Stack.c
 *
 * Array-based Stack implementation.
 *
 */

#include "Stack.h"
#include <stdlib.h>

#ifdef DYNAMIC

Stack *new_Stack() {
    Stack* this = NULL;
    return this;
}

#else

Stack new_Stack() {
    Stack this;
    return this;
}

#endif


bool Stack_push(Stack* this, float element) {
    return false;
}

bool Stack_pop(Stack* this, float* retval) {
    return false;
}

int Stack_size(Stack* this) {
    return -1;
}

bool Stack_isEmpty(Stack* this) {
	return false;
}

void Stack_clear(Stack* this) {
}

void Stack_destroy(Stack* this) {
}
