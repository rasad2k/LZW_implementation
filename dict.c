#include "dict.h"
#include "list.c"

//initializes new dict with given capacity

Dict *D_new(int capacity){
	Dict * newDict = (Dict *)malloc(sizeof(Dict));
	newDict->capacity = capacity;
	newDict->size = 0;
	newDict->table = (List **)malloc(capacity * sizeof(List *));
	return newDict;
}

//for a given key and a dict, returns hash value

int D_hash(Dict *dict, char *key)
{
	if (dict == NULL || dict->capacity <= 0)
        return -1;
    int index;
    for (index = 0; *key != '\0'; key++)
    {
        index = (index * 256 + (int)(*key)) % dict->capacity;
 
    }
    return index;
}

//adds given key and value to given dict

char D_put(Dict *dict, char *key, char *value)
{
	if (dict == NULL || dict->size < 0)
		return 0;
	int index = D_hash(dict, key);
	if (L_append(&(dict->table[index]), key, value)){
		dict->size++;
		return 1;
	}
	return 0;
}

char D_putDup(Dict *dict, char *key, char *value)
{
	if (dict == NULL || dict->size < 0)
		return 0;
	int index = D_hash(dict, value);
	if (L_append(&(dict->table[index]), value, key)){
		dict->size++;
		return 1;
	}
	return 0;
}

//searches for given key in dict,
//returns its value if found, if not 0

char *D_search(Dict *dict, char *key)
{
	return L_search(dict->table[D_hash(dict, key)], key);
}

//prints dict

void D_print(Dict *dict)
{
    int i;
    for (i = 0; i < dict->capacity; i++)
    {
        printf("[%d]:", i);
        L_print(dict->table[i]);
        printf("\n");
    }
}

//duplicates dict

Dict *D_duplicate(Dict * dict)
{
	Dict * newDict = D_new(dict->capacity);
	for (int i = 0; i < dict->capacity;i++)
	{
		List * tmp = dict->table[i];
		while (tmp != NULL){
			D_putDup(newDict, tmp->key, tmp->value);
			tmp = tmp->pNext;
		}
	}
	return newDict;
}