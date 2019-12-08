#include "list.h"

//creates new list and assign given values to it

List *L_new(char *key, char *value)
{
	List * newList = (List *)malloc(sizeof(List));
	newList->key = key;
	newList->value = value;
	newList->pNext = NULL;
	return newList;
}

//checks if the list contains given key, 
//adds the key to the list and returns 1, if not, returns 0

char L_append(List **ppHead, char *key, char *value)
{
	List * newList = L_new(key, value);
	if (*ppHead == NULL){
		*ppHead = newList;
		return 1;
	}

	if (L_search(*ppHead, key) == 0){
		List * tmp = *ppHead;
		while (tmp->pNext != NULL)
			tmp	= tmp->pNext;
		tmp->pNext = newList;
		return 1;
	}
	return 0;
}

//if the list contains given key, returns its value
//if not, returns 0;

char *L_search(List *pHead, char *key)
{
	List * tmp = pHead;
	while (tmp != NULL){
		if (strcmp(tmp->key, key) == 0)
			return tmp->value;
		tmp = tmp->pNext;
	}
	return 0;
}

//prints the list

void L_print(List *pHead)
{
	while (pHead != NULL){
		printf("[%s, %s] => ", pHead->key, pHead->value);
		pHead = pHead->pNext;
	}
}

