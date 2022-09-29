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

// This program contains implementation for priority queue using linked list

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "pri-queue.h"

struct llnode {
  void *item;
  int priority;
  struct llnode *next;
};

struct pri_queue {
  int len;
  struct llnode *front;
};

// see more details in "pri-queue.h"
// time: O(1)
struct pri_queue *pri_queue_create(void) {
  struct pri_queue *pq = (struct pri_queue *)malloc(sizeof(struct pri_queue));
  pq->front = NULL;
  pq->len = 0;
  return pq;
}

// newnode(item, priority) creates and return a new llnode with given item and
//   priority
// requires: priority >= 0
// effects: allocates memory
// time: O(1)
static struct llnode *newnode(void *item, int priority) {
  assert(priority >= 0);
  struct llnode *node = (struct llnode *)malloc(sizeof(struct llnode));
  node->item = item;
  node->priority = priority;
  node->next = NULL;
  return node;
}

// see more details in "pri-queue.h"
// time: O(n)
void pri_queue_add(void *            item, 
                   int               priority, 
                   struct pri_queue *pq) {
  assert(pq);
  assert(priority >= 0);
  // find the before of the "insert" position
  struct llnode *before = NULL;
  struct llnode *currnode = pq->front;
  while (currnode && priority >= currnode->priority) {
    before = currnode;
    currnode = currnode->next;
  }
  // insertion
  struct llnode *node = newnode(item, priority);
  if (currnode == NULL && before == NULL) { // empty priority queue
    pq->front = node;
  } else if (before == NULL) { // insert in the first
    node->next = pq->front;
    pq->front = node;
  } else {
    node->next = before->next;
    before->next = node;
  }
  pq->len += 1;
}

// see more details in "pri-queue.h"
// time: O(1)
bool pri_queue_is_empty(const struct pri_queue *pq) {
  assert(pq);
  if (pq->len == 0) {
    return true;
  }
  return false;
}

// see more details in "pri-queue.h"
// time: O(1)
void *pri_queue_remove(struct pri_queue *pq) {
  assert(pq);
  assert(!pri_queue_is_empty(pq));
  struct llnode *oldnode = pq->front;
  void *remove = oldnode->item;
  pq->front = pq->front->next;
  pq->len -= 1;
  free(oldnode);
  return remove;
}

// see more details in "pri-queue.h"
// time: O(1)
const void *pri_queue_front(const struct pri_queue *pq, int *priority) {
  assert(pq);
  assert(priority);
  assert(!pri_queue_is_empty(pq));
  struct llnode *topmost_node = pq->front;
  const void *topmost_item = topmost_node->item;
  *priority = topmost_node->priority;
  return topmost_item;
}

// see more details in "pri-queue.h"
// time: O(1)
void pri_queue_destroy(struct pri_queue *pq) {
  assert(pq);
  assert(pri_queue_is_empty(pq));
  free(pq->front);
  free(pq);
}

// test client
int main() {
  struct pri_queue *pq = pri_queue_create();
  char str1[] = "great";
  void *to_str1 = str1;
  pri_queue_add(to_str1, 5, pq);
  char str2[] = "have";
  void *to_str2 = str2;
  pri_queue_add(to_str2, 0, pq);

  char str3[] = "a";
  void *to_str3 = str3;
  pri_queue_add(to_str3, 3, pq);

  char str4[] = "summer";
  void *to_str4 = str4;
  pri_queue_add(to_str4, 5, pq);

  char *remove = (char *)pri_queue_remove(pq);
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  printf("removed: %s\n", remove);
  
  int priority = 5;
  char *front = (char *)pri_queue_front(pq, &priority);
  printf("front: %s\n", front);

  remove = (char *)pri_queue_remove(pq);
  printf("removed: %s\n", remove);

  pri_queue_destroy(pq);
}