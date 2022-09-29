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

// This program contains implementation for priority queue using array of queue

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "vqueue.h"
#include "pri-queue.h"

struct pri_queue {
  struct vqueue **arr;
  int count;
  int largest_priority;
};

// see more details in "pri-queue.h"
// time: O(1)
struct pri_queue *pri_queue_create(void) {
  struct pri_queue *pq = (struct pri_queue *)malloc(sizeof(struct pri_queue));
  pq->arr = (struct vqueue **)malloc(sizeof(struct vqueue *));
  pq->arr[0] = vqueue_create();
  pq->count = 0;
  pq->largest_priority = 0;
  return pq;
}

// see more details in "pri-queue.h"
// time: O(1) [O(m) when realloc occurs]
void pri_queue_add(void *item, int priority, struct pri_queue *pq) {
  assert(pq);
  assert(priority >= 0);
  // reallocate the whole array
  if (priority > pq->largest_priority) {
    pq->arr = (struct vqueue **)
                realloc(pq->arr, sizeof(struct vqueue *) * (priority + 1));
    // create new empty vqueue for the new slot
    for (int i = pq->largest_priority + 1; i <= priority; i++) {
      pq->arr[i] = vqueue_create();
    }
    pq->largest_priority = priority;
  }
  // add item
  vqueue_add_back(item, pq->arr[priority]);
  pq->count += 1;
}

// see more details in "pri-queue.h"
// time: O(1)
bool pri_queue_is_empty(const struct pri_queue *pq) {
  assert(pq);
  if (pq->count == 0) {
    return true;
  }
  return false;
}

// see more details in "pri-queue.h"
// time: O(m)
void *pri_queue_remove(struct pri_queue *pq) {
  assert(pq);
  assert(!pri_queue_is_empty(pq));
  // find the highest priority
  int highest_priority = 0;
  for (int i = 0; i < pq->largest_priority + 1; i++) {
    if (!vqueue_is_empty(pq->arr[i])) {
      break;
    }
    highest_priority++;
  }
  // remove the item
  pq->count -= 1;
  void *remove = vqueue_remove_front(pq->arr[highest_priority]);
  return remove;
}

// see more details in "pri-queue.h"
// time: O(m)
const void *pri_queue_front(const struct pri_queue *pq, int *priority) {
  assert(pq);
  assert(priority);
  assert(!pri_queue_is_empty(pq));
  // find the highest priority
  int highest_priority = 0;
  for (int i = 0; i < pq->largest_priority + 1; i++) {
    if (!vqueue_is_empty(pq->arr[i])) {
      break;
    }
    highest_priority++;
  }
  // find the item
  const void *front = vqueue_front(pq->arr[highest_priority]);
  *priority = highest_priority;
  return front;
}

// see more details in "pri-queue.h"
// time: O(m)
void pri_queue_destroy(struct pri_queue *pq) {
  assert(pq);
  assert(pri_queue_is_empty(pq));
  // free each vqueue in the array
  for (int i = 0; i < pq->largest_priority + 1; i++) {
    vqueue_destroy(pq->arr[i]);
  }
  free(pq->arr);
  free(pq);
}
