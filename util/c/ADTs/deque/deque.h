// This is a module that provides a deque of integers ADT

// SEASHELL_READONLY

#include <stdbool.h>

struct deque;

// The following applies to all functions
// requires: all deque parameters must be valid (non-null)
// time: (n) is the number of items in the deque

// deque_create() returns a pointer to a new (empty) deque
// effects: allocates memory (caller must call deque_destroy)
// time: O(1)
struct deque *deque_create(void);

// deque_destroy(deq) destroys the deq
// effects: deq is no longer valid (freed)
// time: O(n)
void deque_destroy(struct deque *deq);

// deque_is_empty(deq) determines if deq is empty
// time: O(1)
bool deque_is_empty(const struct deque *deq);

// deque_insert_front(item, deq) inserts item into the front of deq
// effects: modifies deq
// time: O(1)
void deque_insert_front(int item, struct deque *deq);

// deque_front(deq) returns the front of deq
// requires: deq is not empty
// time: O(1)
int deque_front(const struct deque *deq);

// deque_remove_front(deq) removes and returns the front of deq
// requires: deq is not empty
// effects: modifies deq
// time: O(1)
int deque_remove_front(struct deque *deq);

// deque_insert_back(item, deq) inserts item into the back of deq
// effects: modifies deq
// time: O(1)
void deque_insert_back(int item, struct deque *deq);

// deque_back(deq) returns the back of deq
// requires: deq is not empty
// time: O(1)
int deque_back(const struct deque *deq);

// deque_remove_back(deq) removes and returns the back of deq
// requires: deq is not empty
// effects: modifies deq
// time: O(1)
int deque_remove_back(struct deque *deq);

// deque_print(deq) prints out the items in deq
// notes: prints "[empty]\n" if deq is empty
//        prints "[%d]\n" if deq has a single item
//        prints "[%d,%d,...,%d]\n" otherwise 
//               so if the deq from front->back is 8,6,7,5,3,0,9
//               prints "[8,6,7,5,3,0,9]\n"
// effects: produces output
// time: O(n)
void deque_print(const struct deque *deq);

// deque_print_reverse(deq) prints out the items in deq in reverse
// notes: prints "[empty]\n" if deq is empty
//        prints "[%d]\n" if deq has a single item
//        prints "[%d,%d,...,%d]\n" otherwise 
//               so if the deq from front->back is 8,6,7,5,3,0,9
//               prints "[9,0,3,5,7,6,8]\n"
// effects: produces output
// time: O(n)
void deque_print_reverse(const struct deque *deq);
