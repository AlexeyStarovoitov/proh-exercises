//tree.h -- binary search tree
//			no duplicate items are allowed in this tree

#ifndef TREE_H_
#define TREE_H_

#include "stdbool.h"
#define SLEN 20
#define MAXITEMS 20

typedef struct item 
{
	char word[SLEN];
	int count;
}Item;


typedef struct trnode
{
	Item item;
	struct trnode *left;
	struct trnode *right;
} Trnode;

typedef struct tree
{
	Trnode *root;
	int size;
} Tree;


/*
operation: initialize a tree to empty
preconditions: ptree points to a tree
postconditions: the tree is initialized to empty
*/
void InitializeTree(Tree *ptree);

/*
operation: determine if tree is empty
preconditions: ptree points to a tree
postconditions: function returns true if tree is
				empty and returns false otherwise
*/
bool TreeIsEmpty(const Tree *ptree);

/*
operation: determine if tree is full
preconditions: ptree points to a tree
postconditions: function returns true if tree is
				full and returns false otherwise
*/
bool TreeIsFull(const Tree *ptree);

/*
operation: determine number of items in tree
preconditions: ptree points to a tree
postconditions: function returns number of items in tree
*/

int TreeItemCount(const Tree *ptree);

 /*
operation: 		add an item to a tree
preconditions: 	pi is address of item to be added
				ptree points to an initialized tree
postconditions: if possible function adds item to
				tree and returns true; otherwise,
				the function returns false
*/

bool AddItem(const Item *pi, Tree *ptree);

/*
operation: 		find an item in a tree
preconditions: 	pi points to an item
				ptree points to an initialized tree
postconditions: function returns true if item is in tree
				and returns false otherwise
*/
bool InTree(const Item *pi, const Tree *ptree);

/*
operation: 		delete an item in a tree
preconditions: 	pi points to an item to be deleted
				ptree points to an initialized tree
postconditions: function deletes item from tree
				and returns true otherwise
				function returns false
*/
bool DeleteItem(const Item *pi, Tree *ptree);

/*
operation: 		apply a function to each item in a tree
preconditions: 	pfun points to a function that
				takes an Item argument and has no return value
				ptree points to an initialized tree
postconditions: the function pointed to by pfun is
				is executed once for each item in tree
*/
void Traverse(const Tree *ptree, void (*pfun)(Item item));

/*
operation: 		delete everything from a tree
preconditions: 	ptree points to an initialized tree
postconditions: tree is empty
*/

void DeleteAll(Tree *ptree);

bool FindItem(Item *pi, const Tree *ptree);

#endif




