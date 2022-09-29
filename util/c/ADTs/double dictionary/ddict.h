// This is a module that provides a "double dictionary" ADT 
// (also known as a "reverse dictionary" ADT) with string keys/values

// SEASHELL_READONLY

struct double_dict;

// The following applies to all functions
// requires: all double_dict parameters must be valid (non-null)
//           all string parameters must be valid (non-null)
// time: (n) is the number of entries in the double dictionary
//       (h) is the height of the internal tree in the double dictionary
//           [or the max of the height of the two trees]
//       (m) is the length of the string
//           [or the max of the length of the two strings]

// note: in practice, we wouldn't use height (h) here, but we are using
//       it to ensure that you are implementing the functions correctly


// ddict_create() creates and returns a new empty double dictionary
// effects: allocates memory (must call ddict_destroy)
// time: O(1)
struct double_dict *ddict_create(void);

// ddict_insert(key, value, dd) adds a new key/value pair into the dd
// note: if either key exists or value exists, insert is ignored
//       and there is no effect
// effects: may modify dd
// time: O(h*m)
void ddict_insert(const char *key, const char *value, struct double_dict *dd);

// ddict_lookup_by_key(key, dd) finds the corresponding value for the given key
//   in dd or returns NULL if key does not appear in dd
// time: O(h*m)
const char *ddict_lookup_by_key(const char *key, 
                                const struct double_dict *dd);

// ddict_lookup_by_value(value, dd) finds the corresponding key for the 
//   given value in dd or returns NULL if value does not appear in dd
// time: O(h*m)
const char *ddict_lookup_by_value(const char *value,
                                  const struct double_dict *dd);

// ddict_destroy(dd) frees all memory associated with dd
// effects: dd is no longer valid
// time: O(n)
void ddict_destroy(struct double_dict *dd);
