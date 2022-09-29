#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct bstnode {
	int item;
    char *value;
	struct bstnode *left;
	struct bstnode *right;
};

struct dict {
	struct bstnode *root;
};

struct dict *dict_create(void) {
    struct dict *dict = malloc(sizeof(struct dict));
    dict->root = NULL;
    return dict;
}

void free_bstnode(struct bstnode *node) {
    if (node) {
        free_bstnode(node->left);
        free_bstnode(node->right);
        free(node->value);
        free(node);
    }
}

void dict_destroy(struct dict *dict) {
    free_bstnode(dict->root);
    free(dict);
}

const char *dict_lookup(int key, struct dict *dict) {
    const struct bstnode *node = dict->root;
    while (node) {
        if (key == node->item) {
            return node->value;
        } else if (key < node->item) {
            return dict_lookup(key, node->left);
        } else {
            return dict_lookup(key, node->right);
        }
    }
    // not found such key
    return NULL;
}

struct bstnode *new_leaf(int key, const char *val) {
    struct bstnode *leaf = malloc(sizeof(struct bstnode));
    leaf->item = key;
    char *new_val = malloc(sizeof(char) * (strlen(val) + 1));
    strcpy(new_val, val);
    leaf->value = new_val;
    leaf->left = NULL;
    leaf->right = NULL;
    return leaf;
}

void dict_insert_iterative(int key, const char *val, struct dict *dict) {
    struct bstnode *node = dict->root;
    struct bstnode *parent = NULL;
    // find where to insert the node
    while (node && node->item != key) {
        parent = node;
        if (key < node->item) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    // insert the node 
    if (node != NULL) { // node already exists, replace it
        free(node->value);
        char *new_val = malloc(sizeof(char) * (strlen(val) + 1));
        strcpy(new_val, val);
        node->value = new_val;
    } else if (node == NULL) { // empty tree
        dict->root = new_leaf(key, val);
    } else if (key < parent->item) {
        parent->left = new_leaf(key, val); // reaches the bottom of the tree
    } else {
        parent->right = new_leaf(key, val);
    }
}


// dict_remove(item, dict) remove the node with item
// note: similar to bst_remove() from bst.c
void dict_remove(int item, struct dict *dict) {
    struct bstnode *target = dict->root;
    struct bstnode *target_parent = NULL;
    // find target (and its parent)
    while (target && target->item != item) {
        target_parent = target;
        if (item < target->item) {
            target = target->left;
        } else {
            target = target->right;
        }
    }
    if (target == NULL) {
        return; // item not found
    }
    // find the node to "replace" the target
    struct bstnode *replacement = NULL;
    if (target->left == NULL) {
        replacement = target->right;
    } else if (target->right == NULL) {
        replacement = target->left;
    } else { 
        // neither child is NULL
        // find the replacement node and its parent
        replacement = target->right;
        struct bstnode *replacement_parent = target;
        while (replacement->left) {
            replacement_parent = replacement;
            replacement = replacement->left;
        }
        // replace the target
        replacement->left = target->left;
        if (replacement_parent != target) {
            replacement_parent->left = replacement->left;
            replacement->right = target->right;
        }
    }
    // free the target
    free(target);
    free(target->value);
    if (target_parent == NULL) {
        dict->root = replacement;
    } else if (item < target_parent->item) {
        target_parent->left = replacement;
    } else {
        target_parent->right = replacement;
    }
}

