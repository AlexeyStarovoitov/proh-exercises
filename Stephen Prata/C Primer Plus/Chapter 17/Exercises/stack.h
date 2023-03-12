// stack.h -- header file for ADT stack
#ifndef STACK_H_

#define STACK_H_

#include "stdbool.h"

#define STACKSIZE 10

typedef char Item;

typedef struct node
{
	Item item;
	struct node *prev;
} Node;

typedef struct stack
{
	Node *head;
	Node *end;
	
	unsigned int counts;
} Stack;

/*
Operation: Initializes stack variable;
Input: pointer to the Stack variable;
Output: returns true if the stack variable is initialized false otherwise
*/
bool InitializeStack(Stack * ps);

/*
Operation: checks whether the stack is full
Input: pointer to the Stack variable;
Output: returns true if the stack is full false otherwise
*/
bool StackIsFull(Stack *ps);

/*
Operation: checks whether the stack is empty
Input: pointer to the Stack variable;
Output: returns true if the stack is empty false otherwise
*/
bool StackIsEmpty(Stack *ps);


/*
Operation: returns the number of items in the stack
Input: pointer to the Stack variable;
Output: returns the number of items in the stack
*/
unsigned int CountItems(Stack *ps);

/*
Operation: adds item on the top of the stack
Input: pointer to the Stack variable;
	   pi points to the added item
Output: returns true if the item is added false otherwise 
*/
bool AddItem(Item *pi, Stack *ps);

/*
Operation: removes an item from the top of the stack
Input: pointer to the Stack variable;
	   pi points to the deleted item
Output: returns true if the item is deleted false otherwise 
*/
bool RemoveItem(Item *pi, Stack *ps);

/*
Operation: removes all items;
Input: pointer to the Stack variable;
Output: all items are removed
*/
bool RemoveAll(Stack *ps);

#endif