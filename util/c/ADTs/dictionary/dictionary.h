// this is the dictionary module from the course notes

// the documentation is conspicuously absent
// see the course notes for more details

// You may want to modify this .h file, or you can ignore it
// (see dictionary.c for more options)

struct dictionary;

struct dictionary *dict_create(void);

void dict_insert(int key, const char *val, struct dictionary *d);

const char *dict_lookup(int key, const struct dictionary *d);

void dict_destroy(struct dictionary *d);


