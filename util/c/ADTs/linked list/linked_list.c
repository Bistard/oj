#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct llnode {
	int item;
	struct llnode *next;
};

struct llist {
	struct llnode *front;
};

// list_create() creates a new, empty list
// effects: allocates memory: call list_destroy
// time: O(1)
struct llist *list_create(void) {
	struct llist *lst = malloc(sizeof(struct llist));
	lst->front = NULL;
	return lst;
}

// add_front(i, lst) adds i to the front of lst
// effects: modifies lst
// time: O(1)
void add_front(int i, struct llist *lst) {
	struct llnode *newnode = malloc(sizeof(struct llnode));
	newnode->item = i;
	newnode->next = lst->front;
	lst->front = newnode;
}

// time: O(n)
int list_length(const struct llist *lst) {
	int len = 0;
	const struct llnode *node = lst->front;
	while (node) {
		++len;
		node = node->next;
	}
	return len;
}

// time: O(n)
void list_destroy(struct llist *lst) {
	struct llnode *currnode = lst->front;
	struct llnode *nextnode = NULL;
	while (currnode) {
		nextnode = currnode->next;
		free(currnode);
		currnode = nextnode;
	}
	free(lst);
}

// time: O(n)
struct llist *list_dup(const struct llist *oldlst) {
	struct llist *newlst = list_create();
	if (oldlst->front) {
		add_front(oldlst->front->item, newlst);
		const struct llnode *oldnode = oldlst->front->next;
		struct llnode *newnode = newlst->front;
		while (oldnode) {
			newnode->next = malloc(sizeof(struct llnode));
			newnode = newnode->next;
			newnode->item = oldnode->item;
			newnode->next = NULL;
			oldnode = oldnode->next;
		}
	}
	return newlst;
}

// insert(i, slst) inserts i into sorted list slst
// requires: slst is sorted [not asserted]
// effects: modifies slst
// time: O(n)
void insert(int i, struct llist *slst) {
	if (slst->front == NULL || i < slst->front->item) {
		add_front(i, slst);
		return;
	}
	// find the node that will be "before" our insert
	struct llnode *before = slst->front;
	while (before->next && i > before->next->item) {
		before = before->next;
	}
	// insert i
	struct llnode *newnode = malloc(sizeof(struct llnode));
	newnode->item = i;
	newnode->next = before->next;
	before->next = newnode;
}

// time: O(1)
void remove_front(struct llist *lst) {
	assert(lst->front);
	struct llnode *old_front = lst->front;
	lst->front = lst->front->next;
	free(old_front);
}

// remove_item(i, lst) removes the first occurrence of i in lst
//   returns true if an item is successfully removed
// time: O(n)
void remove_item(int i, struct llist *lst) {
	if (lst->front == NULL) 
		return false;
	if (lst->front->item == i) {
		remove_front(lst);
		return true;
	}
	// find the node that "==" to our remove
	struct llnode *before = lst->front;
	while (lst->front->next && lst->front->next->item != i) {
		before = before->next;
	}
	// remove the node
	if (before->next != NULL) {
		struct llnode *oldnode = before->next;
		before->next = before->next->next;
		free(oldnode);
	}
	// not found
	return false;
}