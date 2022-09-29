// This module provides a generic priority queue ADT
// * the items are any type (void pointers, which could be NULL)
// * priorities are non-negative ints
//   0 is the "topmost" or most urgent priority level
//   1 is the next most urgent level, etc.

// Formally, the item with the "topmost" priority is:
// * the item with the smallest priority value that was added the earliest

// items with the same priority behave like a FIFO queue (first in, first out)

// SEASHELL_READONLY

// The following applies to all functions:
// requires: all pri_queue parameters must be valid (non-null) pri_queues
// time: n is the number of entries in the pri-queue
//       m is the "bottommost" priority (highest value) seen by the pri-queue

#include <stdbool.h>

struct pri_queue;

// pri_queue_create() creates a new priority queue 
// effects: allocates memory (client must call pri_queue_destroy)
// time: to be completed in pri-queue-X.c (where X is a, b or c)
struct pri_queue *pri_queue_create(void);

// pri_queue_add(item, priority, pq) adds item to pq with the given
//   priority
// requires: 0 <= priority
// effects: modifies pq
// time: to be completed in pri-queue-X.c (where X is a, b or c)
void pri_queue_add(void *item, int priority, struct pri_queue *pq);

// pri_queue_remove(pq) removes and returns the topmost item
// requires: pq is not empty
// effects: modifies pq
// time: to be completed in pri-queue-X.c (where X is a, b or c)
void *pri_queue_remove(struct pri_queue *pq);

// pri_queue_front(pq, priority) returns a pointer to the topmost item in pq
//   and updates priority to store the priority of that item
// requires: pq is not empty
//           priority is not NULL
// time: to be completed in pri-queue-X.c (where X is a, b or c)
const void *pri_queue_front(const struct pri_queue *pq, int *priority);

// pri_queue_is_empty(pq) determines if pq is empty
// time: to be completed in pri-queue-X.c (where X is a, b or c)
bool pri_queue_is_empty(const struct pri_queue *pq);

// pri_queue_destroy(pq) frees all memory for pq
// requires: pq is empty
// effects: pq is no longer valid
// time: to be completed in pri-queue-X.c (where X is a, b or c)
void pri_queue_destroy(struct pri_queue *pq);
