// This is a module that provides a queue of void pointers

// SEASHELL_READONLY

// The following applies to all functions
// requires: all vqueue parameters (e.g., vq) must be valid (non-null)

#include <stdbool.h>

struct vqueue;

// vqueue_create() create a new empty vqueue
// effects: allocates memory (caller must call vqueue_destroy)
// time: O(1)
struct vqueue *vqueue_create(void);

// vqueue_destroy(vq) destroys vq and frees all memory
// requires: vq is empty
// effects: vq is no longer valid
// time: O(1)
void vqueue_destroy(struct vqueue *vq);

// vqueue_is_empty(vq) determines if vq is empty
// time: O(1)
bool vqueue_is_empty(const struct vqueue *vq);

// vqueue_add_back(item, vq) adds item to the back of vq
// effects: modifies vq
// time: O(1)
void vqueue_add_back(void *item, struct vqueue *vq);

// vqueue_front(vq) returns the item at the front of vq
// requires: vq is not empty
// time: O(1)
const void *vqueue_front(const struct vqueue *vq);

// vqueue_remove_front(vq) removes and returns the front of vq
// requires: vq is not empty
// effects: modifies vq
// time: O(1)
void *vqueue_remove_front(struct vqueue *vq);
