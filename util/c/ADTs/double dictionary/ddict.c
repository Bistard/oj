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

// This program contains all the implementations for double dictionary ADT

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "ddict.h"

struct bstnode {
    char *key;
    char *value;
    struct bstnode *left;
    struct bstnode *right;
};

// see more details in "ddict.h"
struct double_dict {
    struct bstnode *key_dict;
    struct bstnode *value_dict;
};

// see more details in "ddict.h"
struct double_dict *ddict_create(void) {
    struct double_dict *dd = 
        (struct double_dict *)malloc(sizeof(struct double_dict));
    dd->key_dict = NULL;
    dd->value_dict = NULL;
    return dd;
}

// free_bstnode(node) free a bstnode and its subnodes
// effects: node and its subnodes are no longer avaliable
static void free_bstnode(struct bstnode *node) {
    if (node) {
        free_bstnode(node->left);
        free_bstnode(node->right);
        free(node->key);
        free(node->value);
        free(node);
    }
}

// see more details in "ddict.h"
void ddict_destroy(struct double_dict *dd) {
    assert(dd);
    free_bstnode(dd->key_dict);
    free_bstnode(dd->value_dict);
    free(dd);
}

// my_strdup(src) duplicate a new string to src and return it
// requires: src is valid
// effects: allocate memory
// time: O(n)
static char *my_strdup(const char *src) {
  assert(src);
  char *dup = (char *)malloc(strlen(src) * sizeof(char) + 1);
  strcpy(dup, src);
  return dup;
}

// new_node(key, value, is_key) return a new bstnode with given pair key/value
//   or value/key by is_key
// requries: value is valid
// effects: allocate memory
// time: O(n)
static struct bstnode *new_node(const char *key, const char *value, 
                                bool is_key) {
  assert(key);
  assert(value);
  struct bstnode *node = (struct bstnode *)malloc(sizeof(struct bstnode));
  if (is_key) {
      node->key = my_strdup(key);
      node->value = my_strdup(value);
  } else {
      node->key = my_strdup(value);
      node->value = my_strdup(key);
  }
  node->left = NULL;
  node->right = NULL;
  return node;
}

// ddict_insert_key_value(key, value, frontnode, is_key) insert the pair 
//   key/value into the BST
// note: if is_key is true, searching BST is key_dict, vise versa
// requires: key, value, frontnode are valid
//           key/value does not appear in the ddict (not asserted)
// effects: may modify dict
// time: O(h*m)
static void ddict_insert_key_value(const char *key, const char *value,
                                   struct double_dict *dict, bool is_key) {
    assert(key);
    assert(value);
    assert(dict);
    // find which dict is using
    struct bstnode *node = dict->key_dict;
    if (!is_key) {
         node = dict->value_dict;
    }
    struct bstnode *parent = NULL;
    // find the parent of that "insert"
    while (node) {
        int res = 0;
        if (is_key) {
            res = strcmp(key, node->key);
        } else {
            res = strcmp(value, node->key);
        }
        parent = node;
        if (res == 0) {
            return;    
        } else if (res < 0) {
            node = node->left;
        } else if (res > 0) {
            node = node->right;
        }
    }
    // try to insert
    if (node != NULL) {
        return;
    } else if (parent == NULL) {               // empty dict
        if (is_key) {
            dict->key_dict = new_node(key, value, is_key);
        } else {
            dict->value_dict = new_node(key, value, is_key);
        }
    } else {
        int res = 0;
        if (is_key) {
            res = strcmp(key, parent->key);
        } else {
            res = strcmp(value, parent->key);
        }
        if (res < 0) { // key is "small"
            parent->left = new_node(key, value, is_key);
        } else { // key is "large"
            parent->right = new_node(key, value, is_key);
        }
    }
}

// see more details in "ddict.h"
void ddict_insert(const char *key, const char *value, struct double_dict *dd) {
    assert(key);
    assert(value);
    assert(dd);
    // check if any key/value exists
    const char * res_key = ddict_lookup_by_key(key, dd);
    const char * res_value = ddict_lookup_by_value(value, dd);
    if (!(!res_key && !res_value)) {
        return;
    }
    // insert key/value into ddict
    ddict_insert_key_value(key, value, dd, true);
    ddict_insert_key_value(key, value, dd, false);
}

// see more details in "ddict.h"
const char *ddict_lookup_by_key(const char *key, 
                                const struct double_dict *dd) {
    assert(key);
    assert(dd);
    struct bstnode *node = dd->key_dict;
    // try to find by the key
    while (node) {
        int res = strcmp(key, node->key);
        if (res == 0) {
            return node->value;
        } else if (res < 0) {
            node = node->left;
        } else if (res > 0) {
            node = node->right;
        }
    }
    // key is not found
    return NULL;
}

// see more details in "ddict.h"
const char *ddict_lookup_by_value(const char *value,
                                  const struct double_dict *dd) {
    assert(value);
    assert(dd);
    struct bstnode *node = dd->value_dict;
    // try to find by the value
    while (node) {
        int res = strcmp(value, node->key);
        if (res == 0) {
            return node->value;
        } else if (res < 0) {
            node = node->left;
        } else if (res > 0) {
            node = node->right;
        }
    }
    // key is not found
    return NULL;
}

int main() {
    struct double_dict *dict = ddict_create();
    ddict_insert("rtx", "3080", dict);
    ddict_insert("gtx", "1080", dict);
    printf("%s\n", ddict_lookup_by_key("rtx", dict));
    printf("%s\n", ddict_lookup_by_value("3080", dict));
    printf("%s\n", ddict_lookup_by_key("gtx", dict));
    printf("%s\n", ddict_lookup_by_value("1080", dict));

    ddict_insert("rtx", "2090", dict);
    printf("key rtx => %s\n", ddict_lookup_by_key("rtx", dict));
    printf("val 2090 => %s\n", ddict_lookup_by_value("2090", dict));

    ddict_insert("gtx", "1090", dict);
    printf("key gtx => %s\n", ddict_lookup_by_key("gtx", dict));
    printf("val 1090 => %s\n", ddict_lookup_by_value("1090", dict));
}