//stack.c -- the implementation of the stack interface

#include "stdio.h"
#include "stdlib.h"
#include "stack.h"

static Node *MakeNode(Item *pi);

bool InitializeStack(Stack * ps)
{
	ps->head = ps->end = NULL;
	ps->counts = 0;
	
	return true;
}

bool StackIsFull(Stack *ps)
{
	return ps->counts == STACKSIZE;
}

bool StackIsEmpty(Stack *ps)
{
	return ps->counts == 0;
}

unsigned int CountItems(Stack *ps)
{
	return ps->counts;
}

bool AddItem(Item *pi, Stack *ps)
{
	if(StackIsFull(ps))
		return false;
	
	Node *new_node = MakeNode(pi);
	
	if(new_node == NULL)
	{
		fprintf(stderr, "Error in the AddItem function");
		exit(EXIT_FAILURE);
	}
	
	if(ps->counts == 0)
	{
		ps->head = ps->end = new_node;
	}
	else
	{
		new_node->prev = ps->end;
		ps->end = new_node;
	}
	ps->counts++;
	return true;
}

bool RemoveItem(Item *pi, Stack *ps)
{
	if(StackIsEmpty(ps))
		return false;
	
	Node *temp;
	
	if(ps->counts == 1)
	{
		*pi = ps->end->item;
		free(ps->end);
		ps->head = ps->end = NULL;
	}
	else
	{
		temp = ps->end;
		*pi = ps->end->item;
		ps->end = ps->end->prev;
		free(temp);
	}
	
	ps->counts--;
	
	return true;
}

bool RemoveAll(Stack *ps)
{
	if(StackIsEmpty(ps))
		return false;
	
	Node *temp;
	
	while(ps->counts != 0)
	{
		if(ps->counts == 1)
		{
			free(ps->end);
			ps->head = ps->end = NULL;
		}
		else
		{
			temp = ps->end;
			ps->end = ps->end->prev;
			free(temp);
		}
		
		ps->counts--;
	}
	
	return true;
}

static Node *MakeNode(Item *pi)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	
	if(new_node)
	{
		new_node->prev = NULL;
		new_node->item = *pi;
	}
	
	return new_node;
}