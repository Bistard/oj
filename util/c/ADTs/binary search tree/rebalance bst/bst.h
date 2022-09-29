// TODO: you must complete this interface file
//       for the bst data structure

#include <stdbool.h>

///////////////////////////////////////
// DO NOT MODIFY THESE STRUCTURES
///////////////////////////////////////
struct bstnode {
  int item;
  struct bstnode *left;
  struct bstnode *right;
  int count;               // <-- new!
};

struct bst {
  struct bstnode *root;
};
///////////////////////////////////////

// time: (n) is the number of entries in the BST
//       (h) is the height of the internal tree in the BST
//           [or the max of the height of the two trees]

// bst_create_empty() creates and returns a new empty BST
// effects: allocate memory (bst_destroy must be called)
// time: O(1)
struct bst *bst_create_empty(void);

// bst_contains(i, tree) determine whether the node with value i is
//   in the tree
// requires: tree is valid
// time: O(h)
bool bst_contains(int i, const struct bst *tree);

// bst_insert(i, tree) add a new node to the BST with given value i
// requires: tree is valid
// effects: might modify tree
//          might allocate memory
// time: O(h)
void bst_insert(int i, struct bst *tree);

// bst_remove(i, tree) remove the node with value i in the BST 
// requires: tree is valid
// effects: might modify tree
//          might allocate memory
// time: O(h)
void bst_remove(int i, struct bst *tree);

// bst_select(k, tree) selects the kth smallest node in the BSt
// requires: tree is valid
// time: O(h)
int bst_select(int k, struct bst *tree);

// free_bstnode(node) frees a Binary Search Tree
// requires: tree is valid
// effects: free tree
//          tree is invalid after
// time: O(n)
void bst_destroy(struct bst *tree);

// bst_to_sorted_array(tree, len) creates and returns a new array that 
//   contains all the items in the tree and modifies the len to the correct
//   size
// note: if tree is empty, then len is set to 0 and NULL is returned
// requires: tree, len are valid
// effects: modifies *len to store the length of the array
//          allocates memory (caller must free)
// time: O(n)
int *bst_to_sorted_array(const struct bst *tree, int *len);

// bst_create_balanced(a, len) creates and returns a new balanced BST from a 
//   sorted array
// note: if a is NULL then len == 0 (and vice versa) and an empty tree is
//       returned
// requires: a is either NULL or an ascending sorted array 
//             without duplicates [not asserted]
//           len >= 0
// effects: allocate memory (caller must free)
// time: O(n)
struct bst *bst_create_balanced(const int a[], int len);

// bst_insert_rebalance(i, tree) inserts the value i into the tree and 
//   automatically rebalanced the tree
// requires: tree is valid
// effects: might allocate memory
//          might modify tree
// time: O(n) [O(log n) when no re-balance occurs]
void bst_insert_rebalance(int i, struct bst *tree);

// bst_compact(tree) rearranges the tree to a complete tree
// requires: tree is valid
// effects: might modify tree
// time: O(n)
void bst_compact(struct bst *tree);
