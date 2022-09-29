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

// This program contains all the implementations for queue ADT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

struct queue {
    struct deque *deq;
};

// see more details in "queue.h"
struct queue *queue_create(void) {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->deq = deque_create();
    return q;
}

// see more details in "queue.h"
void queue_destroy(struct queue *q) {
    assert(q);
    deque_destroy(q->deq);
    free(q);
}

// see more details in "queue.h"
bool queue_is_empty(const struct queue *q) {
    assert(q);
    return deque_is_empty(q->deq);
}

// see more details in "queue.h"
void queue_add_back(int item, struct queue *q) {
    assert(q);
    deque_insert_back(item, q->deq);
}

// see more details in "queue.h"
int queue_front(const struct queue *q) {
    assert(q);
    assert(!queue_is_empty(q));
    return deque_front(q->deq);
}

// see more details in "queue.h"
int queue_remove_front(struct queue *q) {
    assert(q);
    assert(!queue_is_empty(q));
    int pop = deque_remove_front(q->deq);
    return pop;
}