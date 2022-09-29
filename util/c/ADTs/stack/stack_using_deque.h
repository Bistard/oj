// This is a module that provides a stack of integers ADT

// SEASHELL_READONLY

// The following applies to all functions
// requires: all stack parameters must be valid (non-null)
// time: (n) is the number of items in the stack

#include <stdbool.h>

struct stack;

// stack_create() create a new empty stack
// effects: allocates memory (caller must call stack_destroy)
// time: O(1)
struct stack *stack_create(void);

// stack_destroy(s) destroys the stack s and frees all memory
// effects: s is no longer valid
// time: O(n)
void stack_destroy(struct stack *s);

// stack_is_empty(s) determines if s is empty
// time: O(1)
bool stack_is_empty(const struct stack *s);

// stack_push(item, s) pushes item on to the stack s
// effects: modifies s
// time: O(1)
void stack_push(int item, struct stack *s);

// stack_top(s) returns the top of the stack s
// requires: s is not empty
// time: O(1)
int stack_top(const struct stack *s);

// stack_pop(s) removes and returns the top of stack s
// requires: s is not empty
// effects: modifies s
// time: O(1)
int stack_pop(struct stack *s);
