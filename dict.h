#ifndef DICT
#define DICT
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

struct dict
{
    List **table;
    int capacity;
    int size;
};

typedef struct dict Dict;

Dict *D_new(int capacity);
int D_hash(Dict *dict, char *key);
char D_put(Dict *dict, char *key, char *value); //true/false
char *D_search(Dict *dict, char *key);
Dict *D_duplicate(Dict * dict);
void D_print(Dict * dict);


#endif