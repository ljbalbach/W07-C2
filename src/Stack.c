/*
 * Stack.c
 *
 * Array-based Stack implementation.
 *
 *      Author: 190012003
 */

#include "Stack.h"
#include <stdlib.h>

#ifdef DYNAMIC

Stack *new_Stack() {
    Stack* this = (Stack *) malloc(sizeof(Stack));
    this->current_size = 0;
    return this;
}

#else

Stack new_Stack() {
    Stack this;
    return this;
}

#endif


bool Stack_push(Stack* this, float element) {
    if (this->current_size >= MAX_VALUE) {
        return false;
    }
    this->stck[this->current_size] = element;
    this->current_size++;
    return true;
}

bool Stack_pop(Stack* this, float* retval) {
    if (Stack_isEmpty(this)) {
        return false;
    }
    *retval = this->stck[this->current_size - 1];
    this->current_size--;
    return true;
}

int Stack_size(Stack* this) {
    return this->current_size;
}

bool Stack_isEmpty(Stack* this) {
    return (this->current_size <= 0);
	
}

void Stack_clear(Stack* this) {
    for( int i = 0; !Stack_isEmpty(this); i++) {
        this->stck[i] = 0;
        this->current_size--;
    }
}

void Stack_destroy(Stack* this) {
    Stack_clear(this);
    free(this);
}
