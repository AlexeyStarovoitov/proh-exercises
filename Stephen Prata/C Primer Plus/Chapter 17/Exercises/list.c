//list.c -- functions supporting list operations

#include "stdio.h"
#include "stdlib.h"
#include "list.h"

static void CopyToNode(Item item, Node *pnode);

void InitializeList(List *plist)
{
	plist->head = plist->end = NULL;
}

bool ListIsEmpty(const List *plist)
{
	if (plist->head == NULL)
		return true;
	else
		return false;
}

bool ListIsFull(List *plist)
{
	Node *temp = (Node *)malloc(sizeof(Node));

	if (temp == NULL)
	{
		free(temp);
		return true;
	}
	else
	{
		free(temp);
		return false;
	}
		
}

unsigned int ListItemCount(const List *plist)
{
	unsigned int count = 0;
	
	Node *pnode = plist->head;
	
	while(pnode != plist->end)
	{
		count++;
		pnode = pnode->next;
	}
	count++;
	return count;
}

bool AddItem(Item item, List *plist)
{
	Node *pnew;
	Node *scan = plist->head;
	
	pnew = (Node *)malloc(sizeof(Node));
	
	if(pnew == NULL)
		return false;
	
	CopyToNode(item, pnew);
	
	pnew->next = NULL;
	
	if(scan == NULL)
		plist->head = pnew;
	else
	{
		while(scan->next != NULL)
			scan = scan->next;
		scan->next = pnew;
	}
	plist->end = pnew;
	
	return true;
}

void Traverse(const List *plist, void (*pfun)(Item item))
{
	Node * pnode = plist->head;
	
	while(pnode != NULL)
	{
		(*pfun)(pnode->item);
		pnode = pnode->next;
	}
}

void EmptyTheList(List *plist)
{
	Node *psave, *current;
	
	current = plist->head;
	
	while(current != NULL)
	{
		psave = current->next;
		free(current);
		current = psave;
	}
}

static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}