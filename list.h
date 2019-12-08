#ifndef LIST
#define LIST
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    char *key;
    char *value;
    struct list *pNext;
};

typedef struct list List;

List *L_new(char *key, char *value);
char L_append(List **ppHead, char *key, char *value); //true/false
char *L_search(List *pHead, char *key);
void L_print(List *pHead);



#endif