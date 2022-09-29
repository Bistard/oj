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

// This program contains all the implementations for bst ADT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "bst.h"
#include "pow2.h"

struct bstnode {
  void *item;
  struct bstnode *left;
  struct bstnode *right;
  int count;
};

struct bst {
  struct bstnode *root;
};

// see more details in "bst.h"
struct bst *bst_create_empty(void) {
  struct bst *tree = (struct bst *)malloc(sizeof(struct bst));
  tree->root = NULL;
  return tree;
}

// new_leaf(i) creates and returns a new bstnode with value i
// effects: allocate memory
// time: O(1)
static struct bstnode *new_leaf(int i) {
  struct bstnode *leaf = (struct bstnode *)malloc(sizeof(struct bstnode));
  leaf->item = i;
  leaf->left = NULL;
  leaf->right = NULL;
  leaf->count = 1;
  return leaf;
}

// see more details in "bst.h"
bool bst_contains(int i, const struct bst *tree) {
  assert(tree);
  struct bstnode *node = tree->root;
  while (node) {
    if (node->item == i) {
      return true;
    }
    if (i < node->item) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return false;
}

// see more details in "bst.h"
void bst_insert(int i, struct bst *tree) {
  assert(tree);
  // if the node exists
  if (bst_contains(i, tree)) {
    return;
  }
  // then the new node must be added and we can update count to 
  //   each parent through the iteration
  struct bstnode *node = tree->root;
  struct bstnode *parent = NULL;
  while (node) {
    node->count += 1;
    parent = node;
    if (i < node->item) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  if (parent == NULL) {  // tree was empty
    tree->root = new_leaf(i);
  } else if (i < parent->item) {
    parent->left = new_leaf(i);
  } else {
    parent->right = new_leaf(i);
  }
}

// see more details in "bst.h"
void bst_remove(int i, struct bst *tree) {
  assert(tree);
  // if the node doest not exist
  if (!bst_contains(i, tree)) {
    return;
  }
  // find the target (and its parent)
  struct bstnode *target = tree->root;
  struct bstnode *target_parent = NULL;
  while (target && target->item != i) {
    target->count -= 1;
    target_parent = target;
    if (i < target->item) {
      target = target->left;
    } else {
      target = target->right;
    }
  }
  if (target == NULL) {
    return; // key not found
  }
  // find the node to "replace" the target
  struct bstnode *replacement = NULL;
  if (target->left == NULL) {
    replacement = target->right;
  } else if (target->right == NULL) {
    replacement = target->left;
  } else {
    // neither child is NULL:
    // find the replacement node and its parent
    replacement = target->right;
    struct bstnode *replacement_parent = target;
    while (replacement->left) {
      replacement_parent = replacement;
      replacement_parent->count -= 1;
      replacement = replacement->left;
    }
    // update the child links for the replacement and its parent
    replacement->left = target->left;
    if (replacement_parent != target) {
      replacement_parent->left = replacement->right;
      replacement->right = target->right;
    }
    replacement->count = 1;
    if (replacement->left) {
      replacement->count += replacement->left->count;
    }
    if (replacement->right) {
      replacement->count += replacement->right->count;
    }
  }
  // free the target, and update the target's parent
  free(target);
  if (target_parent == NULL) {
    tree->root = replacement;
  } else if (i > target_parent->item) {
    target_parent->right = replacement;
  } else {
    target_parent->left = replacement;
  }
}

// select_node(k, node) selects the kth smallest node in the root node
// requires: node is valid
//           0 <= k < total # of nodes
// time: O(h)
static int select_node(int k, struct bstnode *node) {
  assert(node && 0 <= k && k < node->count);
  int left_count = 0;
  if (node->left) {
    left_count = node->left->count;
  }
  if (k < left_count) {
    return select_node(k, node->left);
  }
  if (k == left_count) {
    return node->item;
  }
  return select_node(k - left_count - 1, node->right);
}

// see more details in "bst.h"
int bst_select(int k, struct bst *tree) {
  assert(tree);
  return select_node(k, tree->root);
}

// free_bstnode(node) frees a bstnode node
// requires: node is valid
// effects: free node
// time: O(n)
static void free_bstnode(struct bstnode *node) {
  if (node) {
    free_bstnode(node->left);
    free_bstnode(node->right);
    free(node);
  }
}

// see more details in "bst.h"
void bst_destroy(struct bst *tree) {
  assert(tree);
  free_bstnode(tree->root);
  free(tree);
}

///////////////////////////////////////////////////////////////////////////// 
// The following functions are for you to implement:
// (only PARTIAL documentation shown for CRITICAL information)
///////////////////////////////////////////////////////////////////////////// 

// bst_to_sorted_array_by_pos(node, pos, arr) converts a BST into a 
//   sorted array
// requires: node, pos, arr are valid
// effects: modify arr, pos
// time: O(n)
static void bst_to_sorted_array_by_pos(const struct bstnode *node, 
                                       int *pos, int *arr) {
  assert(node);
  assert(arr);
  assert(pos);
  if (node->left) {
    bst_to_sorted_array_by_pos(node->left, pos, arr);
  }
  arr[*pos] = node->item;
  *pos += 1;
  if (node->right) {
    bst_to_sorted_array_by_pos(node->right, pos, arr);
  }
}

// see more details in "bst.h"
int *bst_to_sorted_array(const struct bst *tree, int *len) {
  assert(tree);
  assert(len);
  if (tree->root) {
    *len = tree->root->count;
  } else {
    *len = 0;
    return NULL;
  }
  int *arr = (int *)malloc(sizeof(int) * *len);
  int pos = 0;
  bst_to_sorted_array_by_pos(tree->root, &pos, arr);
  return arr;
}

// bst_create_balanced_middle(a, start, end) creates and returns
//   a new bstnode from a sorted array given a index from start to end
// requires: a is valid
//           a is sorted ascending
//             without duplicates [not asserted]
// effects: allocate memory
// time: O(n)
static struct bstnode *bst_create_balanced_middle(const int a[], 
                                                  int start, int end) {
  assert(a);
  // legal element in the array
  if (start <= end) {
    int mid = (start + end) / 2;
    if ((start + end + 1) % 2 == 0) {
      mid++;
    }
    struct bstnode *node = new_leaf(a[mid]);
    node->count = (end - start) + 1;
    node->left = bst_create_balanced_middle(a, start, mid - 1);
    node->right = bst_create_balanced_middle(a, mid + 1, end);
    return node;
  }
  // reaches the end of the leaf
  return NULL;
}

// see more details in "bst.h"
struct bst *bst_create_balanced(const int a[], int len) {
  assert(len >= 0);
  struct bst *tree = bst_create_empty();
  // empty array
  if (!len) {
    return tree;
  }
  tree->root = bst_create_balanced_middle(a, 0, len - 1);
  return tree;
}

///////////////////////////////////////////////////////////////////////////// 
// The following functions are BONUS functions you may implement:
// (only PARTIAL documentation shown for CRITICAL information)
///////////////////////////////////////////////////////////////////////////// 

// see more details in "bst.h"
void bst_insert_rebalance(int i, struct bst *tree) {
  assert(tree);
  // if the node exists, no rebalance or either insertion
  if (bst_contains(i, tree)) {
    return;
  }
  // find the minimum height (smallest possible of maximum of the depth)
  int minimum_height = 0;
  if (tree->root) {
    int nodes = tree->root->count;
    minimum_height = log2floor(nodes) + 1;
  }
  // then the new node must be added and we can update count to 
  //   each parent through the iteration
  int depth = 1;
  struct bstnode *node = tree->root;
  struct bstnode *parent = NULL;
  while (node) {
    depth++;
    node->count += 1;
    parent = node;
    if (i < node->item) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  // insert the node first
  if (parent == NULL) {  // tree was empty
    tree->root = new_leaf(i);
  } else if (i < parent->item) {
    parent->left = new_leaf(i);
  } else {
    parent->right = new_leaf(i);
  }
  // rebalance
  if (depth > minimum_height * 2 && tree->root) {
    int len = 0;
    int *arr = bst_to_sorted_array(tree, &len);
    struct bstnode *oldroot = tree->root;
    free_bstnode(oldroot);
    struct bst *newtree = bst_create_balanced(arr, len);
    tree->root = newtree->root;
    free(newtree);
    free(arr);
  }
}

// bst_create_balanced_completed(a, start, end) creates and returns
//   a new completed bstnode from a sorted array given a index from start to end
// requires: a is valid
//           a is sorted ascending
//             without duplicates [not asserted]
// effects: allocate memory
// time: O(n)
static struct bstnode *bst_create_balanced_completed(const int *a, 
                                                     int start, int end) {
  assert(a);
  if (start <= end) {
    // reaches the bottom
    if (start == end) {
      struct bstnode *node = new_leaf(a[start]);
      node->count = 1;
      return node;
    }
    // calculate the extra nodes at the bottom
    int len = end - start + 1;
    int extra = len - pow2(log2floor(len)) + 1;
    // find the index'th element as the root
    int extra_left_bottom = pow2(log2floor(len)) / 2;
    int subtree_without_bottom = (len - extra - 1) / 2;
    int index = start + subtree_without_bottom + extra;
    if (extra > extra_left_bottom) {
      index = start + subtree_without_bottom + extra_left_bottom;
    }
    struct bstnode *node = new_leaf(a[index]);
    node->count = (end - start) + 1;
    node->left = bst_create_balanced_completed(a, start, index - 1);
    node->right = bst_create_balanced_completed(a, index + 1, end);
    return node;
  }
  return NULL;
}

// see more details in "bst.h"
void bst_compact(struct bst *tree) {
  assert(tree);
  // empty BST
  if (tree->root == NULL) {
    return;
  }
  int len = 0;
  int *arr = bst_to_sorted_array(tree, &len);
  struct bst *complete_tree = bst_create_empty();
  complete_tree->root = bst_create_balanced_completed(arr, 0, len - 1);
  free_bstnode(tree->root);
  tree->root = complete_tree->root;
  free(complete_tree);
  free(arr);
}
