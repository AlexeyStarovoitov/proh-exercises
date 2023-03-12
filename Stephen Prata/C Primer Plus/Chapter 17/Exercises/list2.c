//list.c -- functions supporting list operations

#include "stdio.h"
#include "stdlib.h"
#include "list2.h"


void InitializeList(List *plist)
{
	plist->items = 0;
}

bool ListIsEmpty(const List *plist)
{
	return plist->items == 0;
}

bool ListIsFull(List *plist)
{
	return plist->items == MAXSIZE;
		
}

unsigned int ListItemCount(const List *plist)
{
	return plist->items;
}

bool AddItem(Item item, List *plist)
{
	
	if(plist->items == MAXSIZE)
		return false;
	
	plist->entries[plist->items] = item;
	plist->items++;
	
	return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
	int i;
	
	for(i = 0; i < plist->items; i++)
		(*pfun)(plist->entries[i]);
	
}

void EmptyTheList(List *plist)
{
	plist->items = 0;
}
