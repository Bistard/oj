// This is a module that provides a queue of integers ADT

// SEASHELL_READONLY

// The following applies to all functions
// requires: all queue parameters must be valid (non-null)
// time: (n) is the number of items in the queue

#include <stdbool.h>

struct queue;

// queue_create() create a new empty queue
// effects: allocates memory (caller must call queue_destroy)
// time: O(1)
struct queue *queue_create(void);

// queue_destroy(q) destroys q and frees all memory
// effects: q is no longer valid
// time: O(n)
void queue_destroy(struct queue *q);

// queue_is_empty(q) determines if q is empty
// time: O(1)
bool queue_is_empty(const struct queue *q);

// queue_add_back(item, q) adds item to the back of q
// effects: modifies q
// time: O(1)
void queue_add_back(int item, struct queue *q);

// queue_front(q) returns the item at the front of q
// requires: q is not empty
// time: O(1)
int queue_front(const struct queue *q);

// queue_remove_front(q) removes and returns the front of q
// requires: q is not empty
// effects: modifies q
// time: O(1)
int queue_remove_front(struct queue *q);
