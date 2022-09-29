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

// This program contains all the implementations for dueue ADT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "deque.h"

/////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THIS STRUCTURE
/////////////////////////////////////////////////////////////////////////////
struct llnode {
  int item;
  struct llnode *prev;
  struct llnode *next;
};

struct deque {
  struct llnode *front;
  struct llnode *back;
};
/////////////////////////////////////////////////////////////////////////////

// see more details in "deque.h"
struct deque *deque_create(void) {
  struct deque *deq = (struct deque *)malloc(sizeof(struct deque));
  deq->front = NULL;
  deq->back = NULL;
  return deq;
}

// see more details in "deque.h"
void deque_destroy(struct deque *deq) {
  assert(deq);
  struct llnode *currnode = deq->front;
	struct llnode *nextnode = NULL;
	while (currnode) {
		nextnode = currnode->next;
		free(currnode);
		currnode = nextnode;
	}
	free(deq);
}

// see more details in "deque.h"
bool deque_is_empty(const struct deque *deq) {
  assert(deq);
  if (deq->front != NULL) {
    return false;
  }
  return true;
}

// see more details in "deque.h"
void deque_insert_front(int item, struct deque *deq) {
  assert(deq);
  struct llnode *newnode = (struct llnode *)malloc(sizeof(struct llnode));
  newnode->item = item;
  newnode->prev = NULL;
  newnode->next = deq->front;
  if (deq->front) {
    deq->front->prev = newnode;
  }
  deq->front = newnode;
  // it was an empty deque
  if (deq->back == NULL) {
    deq->back = newnode;
  }
}

// see more details in "deque.h"
int deque_front(const struct deque *deq) {
  assert(deq);
  assert(!deque_is_empty(deq));
  return deq->front->item;
}

// see more details in "deque.h"
int deque_remove_front(struct deque *deq) {
  assert(deq);
  assert(!deque_is_empty(deq));
  struct llnode *oldnode = deq->front;
  struct llnode *afternode = deq->front->next;
  if (afternode) {
    afternode->prev = NULL;
  }  else {
    deq->back = NULL;
  }
  int item = deque_front(deq);
  deq->front = afternode;
  free(oldnode);
  return item;
}

// see more details in "deque.h"
void deque_insert_back(int item, struct deque *deq) {
  assert(deq);
  struct llnode *newnode = (struct llnode *)malloc(sizeof(struct llnode));
  newnode->item = item;
  newnode->next = NULL;
  newnode->prev = deq->back;
  if (deq->back) {
      deq->back->next = newnode;
  }
  deq->back = newnode;
  // it was an empty deque
  if (deq->front == NULL) {
    deq->front = newnode;
  }
}

// see more details in "deque.h"
int deque_back(const struct deque *deq) {
  assert(deq);
  assert(!deque_is_empty(deq));
  return deq->back->item;
}

// see more details in "deque.h"
int deque_remove_back(struct deque *deq) {
  assert(deq);
  assert(!deque_is_empty(deq));
  struct llnode *oldnode = deq->back;
  struct llnode *beforenode = deq->back->prev;
  if (beforenode) {
    beforenode->next = NULL;
  } else {
    deq->front = NULL;
  }
  int item = deque_back(deq);
  deq->back = beforenode;
  free(oldnode);
  return item;
}

// see more details in "deque.h"
void deque_print(const struct deque *deq) {
  assert(deq);
  // empty
  if (deq->front == NULL) {
    printf("[empty]\n");
    return;
  }
  // single item
  if (deq->front == deq->back) {
    printf("[%d]\n", deq->front->item);
    return;
  }
  // else
  printf("[");
  struct llnode *node = deq->front;
  int i = 0;
  while (node) {
    if ((!i && node->next) || (i && node->next)) {
      printf("%d,", node->item);
    } else {
      printf("%d", node->item);
    }
    node = node->next;
    i++;
  }
  printf("]\n");
}

// see more details in "deque.h"
void deque_print_reverse(const struct deque *deq){
  assert(deq);
  // empty
  if (deq->front == NULL) {
    printf("[empty]\n");
    return;
  }
  // single item
  if (deq->front == deq->back) {
    printf("[%d]\n", deq->front->item);
    return;
  }
  // else
  printf("[");
  struct llnode *node = deq->back;
  int i = 0;
  while (node) {
    if ((!i && node->prev) || (i && node->prev)) {
      printf("%d,", node->item);
    } else {
      printf("%d", node->item);
    }
    node = node->prev;
    i++;
  }
  printf("]\n");
}

