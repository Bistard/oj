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

// This program contains implementation for priority queue using heap

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "pri-queue.h"

struct bstnode {
  void *item;
  int priority;
  int time_stamp;
};

struct pri_queue {
  struct bstnode **heap;
  int count;
  int maxlen;
};

// newnode(item, priority) creates and returns a new bstnode with given item,
//   priority
// requires: priority >= 0
// effects: allocate memory
// time: O(1)
static struct bstnode *newnode(void *item, int priority) {
  assert(priority >= 0);
  struct bstnode *node = (struct bstnode *)malloc(sizeof(struct bstnode));
  node->item = item;
  node->priority = priority;
  node->time_stamp = 0;
  return node;
}

// update_time_stamp(pq, priority, time_stamp) count how many nodes with the 
//   same priority and update time_stamp
// requires: pq, time_stamp are valid
//           priority >= 0
// effects: modify time_stamp
// time: O(n)
static void update_time_stamp(struct pri_queue *pq, 
                              int               priority, 
                              int *             time_stamp) {
  assert(pq);
  assert(time_stamp);
  assert(priority >= 0);
  // count how many nodes with the same priority
  int count = 0;
  for (int i = 0; i < pq->count; i++) {
    if (pq->heap[i]->priority == priority) {
      count++;
    }
  }
  *time_stamp = count;
}

// swap_node(arr, idx1, idx2) swap the given two nodes with index idx1 and idx2
//   in the arr
// requires: arr is valid
//           0 <= idx1, idx2 < len(arr) [not asserted]
// effects: arr
// time: O(1)
static void swap_node(struct bstnode **arr, int idx1, int idx2) {
  assert(arr);
  struct bstnode *temp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = temp;
}

// see more details in "pri-queue.h"
// time: O(1)
struct pri_queue *pri_queue_create(void) {
  struct pri_queue *pq = (struct pri_queue *)malloc(sizeof(struct pri_queue));
  pq->heap = (struct bstnode **)malloc(sizeof(struct bstnode *));
  pq->heap[0] = NULL;
  pq->count = 0;
  pq->maxlen = 1;
  return pq;
}

// see more details in "pri-queue.h"
// time: O(1)
bool pri_queue_is_empty(const struct pri_queue *pq) {
  if (pq->count == 0) {
    return true;
  }
  return false;
}

// see more details in "pri-queue.h"
// time: O(n)
void pri_queue_add(void *            item, 
                   int               priority, 
                   struct pri_queue *pq) {
  assert(pq);
  assert(priority >= 0);
  // reallocate the whole array if reaches maxlen
  if (pq->count == pq->maxlen) {
    pq->heap = (struct bstnode **)realloc(pq->heap, sizeof(struct bstnode *) *
                                                    (2 * pq->maxlen + 1));
    pq->maxlen = 2 * pq->maxlen + 1;
  }
  // create the newnode
  struct bstnode *node = newnode(item, priority);
  update_time_stamp(pq, node->priority, &(node->time_stamp));
  // place the newnode in the furthest left bottom
  int index = pq->count;
  pq->heap[index] = node;
  // heapify
  struct bstnode *parent = pq->heap[(index - 1) / 2];
  while (parent->priority > node->priority) {
    swap_node(pq->heap, index, (index - 1) / 2);
    index = (index - 1) / 2;
    parent = pq->heap[(index - 1) / 2];
  }
  pq->count += 1;
}

// see more details in "pri-queue.h"
// time: O(logn)
void *pri_queue_remove(struct pri_queue *pq) {
  assert(pq);
  assert(!pri_queue_is_empty(pq));
  // backup the info of the topmost node
  void *remove = pq->heap[0]->item;
  // swap the topnode with the "out-of-place" node and remove it
  swap_node(pq->heap, 0, pq->count - 1);
  free(pq->heap[pq->count - 1]);
  pq->heap[pq->count - 1] = NULL;
  pq->count -= 1;
  // heapify
  int index = 0;
  int swap_index = 0;
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  while (left < pq->count || right < pq->count) {
    // info
    int curr_priority = pq->heap[index]->priority;
    int curr_time_stamp = pq->heap[index]->time_stamp;
    int left_priority = -1;
    int left_time_stamp = -1;
    int right_priority = -1;
    int right_time_stamp = -1;
    if (pq->heap[left]) {
      left_priority = pq->heap[left]->priority;
      left_time_stamp = pq->heap[left]->time_stamp;
    }
    if (pq->heap[right]) {
      right_priority = pq->heap[right]->priority;
      right_time_stamp = pq->heap[right]->time_stamp;
    }
    if (right >= pq->count) { 
      // right has no child
      if (curr_priority >= left_priority) {
        if (curr_priority == left_priority && 
            curr_time_stamp > left_time_stamp) {
          swap_index = left;
        } else if (curr_priority > left_priority) {
          swap_index = left;
        }
      }
    } else if (left >= pq->count) { 
      // left has no child
      if (curr_priority >= right_priority) {
        if (curr_priority == right_priority && 
            curr_time_stamp > right_time_stamp) {
          swap_index = right;
        } else if (curr_priority > right_priority) {
          swap_index = right;
        }
      }
    } else if (left_priority != right_priority) { 
      // both are different priority
      int minimum_priority = left_priority;
      if (right_priority < left_priority) {
        minimum_priority = right_priority;
      }
      // left side has smaller or equal priority
      if (curr_priority >= left_priority &&
          minimum_priority == left_priority) {
        if (curr_priority == left_priority && 
            curr_time_stamp > left_time_stamp) {
          swap_index = left;
        } else if (curr_priority > left_priority) {
          swap_index = left;
        }
      }
      // right side has smaller or equal priority
      if (curr_priority >= right_priority &&
          minimum_priority == right_priority) {
        if (curr_priority == right_priority && 
            curr_time_stamp > right_time_stamp) {
          swap_index = right;
        } else if (curr_priority > right_priority) {
          swap_index = right;
        }
      }
    } else if (left_priority == right_priority) { 
      // both have the same priority
      if (curr_priority >= left_priority) {
        if (left_time_stamp < right_time_stamp) {
          swap_index = left;
        } else {
          swap_index = right;
        }
      }
    }
    // check whether there is a swap occurs
    if (index != swap_index) {
      swap_node(pq->heap, index, swap_index);
      index = swap_index;
      left = index * 2 + 1;
      right = index * 2 + 2;
      continue;
    }
    break;
  }
  return remove;
}

// see more details in "pri-queue.h"
// time: O(1)
const void *pri_queue_front(const struct pri_queue *pq, int *priority) {
  assert(pq);
  assert(priority);
  assert(!pri_queue_is_empty(pq));
  *priority = pq->heap[0]->priority;
  return pq->heap[0]->item;
}

// see more details in "pri-queue.h"
// time: O(1)
void pri_queue_destroy(struct pri_queue *pq) {
  assert(pq);
  assert(pri_queue_is_empty(pq));
  free(pq->heap);
  free(pq);
}

// test client #1
/* int main() {
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
} */

// test client #2   
/* 
int main() {
  struct pri_queue *pq = pri_queue_create();

  char str1[] = "strong";
  void *to_str1 = str1;
  pri_queue_add(to_str1, 9, pq);
  char str2[] = "to";
  void *to_str2 = str2;
  pri_queue_add(to_str2, 6, pq);

  char str3[] = "be";
  void *to_str3 = str3;
  pri_queue_add(to_str3, 6, pq);

  char str4[] = "needs";
  void *to_str4 = str4;
  pri_queue_add(to_str4, 5, pq);

  char str5[] = "Chris";
  void *to_str5 = str5;
  pri_queue_add(to_str5, 0, pq);

  char *remove = (char *)pri_queue_remove(pq);
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  printf("removed: %s\n", remove);

  pri_queue_destroy(pq);
}
 */

int main() {
  struct pri_queue *pq = pri_queue_create();

  char *remove = NULL;

  pri_queue_add((void *)"i", 4, pq);
  pri_queue_add((void *)"j", 1, pq);
  pri_queue_add((void *)"k", 3, pq);
  pri_queue_add((void *)"l", 2, pq);
  pri_queue_add((void *)"m", 4, pq);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "j"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "l"));
  printf("removed: %s\n", remove);

  pri_queue_add((void *)"n", 4, pq);
  pri_queue_add((void *)"o", 4, pq);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "k"));
  printf("removed: %s\n", remove);

  pri_queue_add((void *)"p", 2, pq);
  pri_queue_add((void *)"q", 3, pq);
  pri_queue_add((void *)"r", 5, pq);
  pri_queue_add((void *)"w", 5, pq);
  pri_queue_add((void *)"x", 5, pq);
  pri_queue_add((void *)"y", 3, pq);
  pri_queue_add((void *)"z", 3, pq);

    remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "p"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "q"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "y"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "z"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "i"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "m"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "n"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "o"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "r"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "w"));
  printf("removed: %s\n", remove);

  remove = (char *)pri_queue_remove(pq);
  assert(!strcmp(remove, "x"));
  printf("removed: %s\n", remove);

  pri_queue_destroy(pq);
}

