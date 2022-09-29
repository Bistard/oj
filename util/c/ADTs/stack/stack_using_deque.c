///////////////////////////////////////////////////////////////////////////// 
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: 
 
// None 
//  
// Name: Sihan Li
// login ID: s795li 
///////////////////////////////////////////////////////////////////////////// 

// This program contains all the implementations for stack ADT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

struct stack {
    struct deque *deq;
};

// see more details in "stack.h"
struct stack *stack_create(void) {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->deq = deque_create();
    return s;
}

// see more details in "stack.h"
void stack_destroy(struct stack *s) {
    assert(s);
    deque_destroy(s->deq);
    free(s);
}

// see more details in "stack.h"
bool stack_is_empty(const struct stack *s) {
    assert(s);
    return deque_is_empty(s->deq);
}

// see more details in "stack.h"
void stack_push(int item, struct stack *s) {
    assert(s);
    deque_insert_front(item, s->deq);
}

// see more details in "stack.h"
int stack_top(const struct stack *s) {
    assert(s);
    assert(!stack_is_empty(s));
    return deque_front(s->deq);
}

// see more details in "stack.h"
int stack_pop(struct stack *s) {
    assert(s);
    assert(!stack_is_empty(s));
    int pop = deque_remove_front(s->deq);
    return pop;
}