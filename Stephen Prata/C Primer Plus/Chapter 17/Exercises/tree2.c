//tree.c -- tree support functions

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "tree2.h"


typedef struct pair
{
	Trnode *parent;
	Trnode *child;
} Pair;

// prototypes for local functions
static Trnode * MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Trnode *new_node, Trnode *root);
static void InOrder(Trnode *root, void (*pfun)(Trnode *pn));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Trnode **ptr);
static void DeleteAllNodes(Trnode *ptr);
static bool ModifyNode(Trnode *pn, const Item *pi);
static void ItemCount(Trnode *pn, int *pnum);

void InitializeTree(Tree *ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
	if(ptree->root == NULL)
		return true;
	else
		return false;
}

bool TreeIsFull(const Tree *ptree)
{
	if(ptree->size == MAXITEMS)
		return true;
	else 
		return false;
}

int TreeItemCount(const Tree *ptree)
{
	int count = 0;
	if (TreeIsEmpty(ptree))
		return 0;
	else
	{
		ItemCount(ptree->root, &count);
		return count;
	}
}

bool AddItem(const Item *pi, Tree *ptree)
{
	Trnode *new_node;
	Pair look;
	
	if(TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	
	look = SeekItem(pi, ptree);
	if(look.child == NULL)
	{
		new_node = MakeNode(pi);
		if(new_node == NULL)
		{
			fprintf(stderr, "Couldn't create node\n");
			return false;
		}
	
		ptree->size++;
	
		if(ptree->root == NULL)
			ptree->root = new_node;
		else
			AddNode(new_node, ptree->root);
	}
	else
		return ModifyNode(look.child, pi);
	
	return true;
}

bool InTree(const Item *pi, const Tree *ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false:true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
	Pair look;
	int del_i, i;
	look = SeekItem(pi, ptree);
	if(look.child == NULL)
		return false;
	
	for(i = 0; (i < look.child->numkind) && (strcmp(look.child->kinds[i], pi->petkind) != 0); i++)
		continue;
	if(i == look.child->numkind)
		return false;
	else
	{
		if(i == 0)
		{
			if(look.parent == NULL)
				DeleteNode(&ptree->root);
			else if(look.parent->left == look.child)
				DeleteNode(&look.parent->left);
			else
				DeleteNode(&look.parent->right);
			ptree->size--;
		}
		else
		{
			del_i = i;
			for(i = del_i; i < (look.child->numkind-1); i++)
				strcpy(look.child->kinds[i], look.child->kinds[i+1]);
			
			look.child->numkind--;	
		}
	}
	
	return true;
}

void Traverse(const Tree *ptree, void (*pfun)(Trnode *pn))
{
	if(ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree *ptree)
{
	if(ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}

static void InOrder(Trnode *root, void (*pfun)(Trnode *pn))
{
	if(root != NULL)
	{
		if(root->left != NULL)
			InOrder(root->left, pfun);
		(*pfun)(root);
		if(root->right != NULL)
			InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Trnode *root)
{
	Trnode *pright;
	
	if(root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

static void AddNode(Trnode *new_node, Trnode * root)
{
	if(ToLeft(&new_node->item, &root->item))
	{
		if(root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if(ToRight(&new_node->item, &root->item))
	{
		if(root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node, root->right);
	}
	else{
		fprintf(stderr, "location error in AddNode()\n");
		exit(EXIT_FAILURE);
	}
}

static bool ToLeft(const Item *i1, const Item *i2)
{
	int compl;
	
	if((compl = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	else
		return false;

}

static bool ToRight(const Item *i1, const Item *i2)
{
	int compl;
	
	if((compl = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else
		return false;

}

static Trnode *MakeNode(const Item *pi)
{
	Trnode *new_node;
	
	new_node = (Trnode *)malloc(sizeof(Trnode));
	if(new_node != NULL)
	{
		new_node->item = *pi;
		new_node->numkind = 1;
		strcpy(new_node->kinds[0], pi->petkind);
		new_node->left = NULL;
		new_node->right = NULL;
	}
	
	return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	
	if(look.child == NULL)
		return look;
	
	while(look.child != NULL)
	{
		if(ToLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	
	return look;
}

static void DeleteNode(Trnode **ptr)
{
	Trnode *temp;
	
	if((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else
	{
		for(temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

static bool ModifyNode(Trnode *pn, const Item *pi)
{
	if(pn->numkind < KIND)
	{
		strcpy(pn->kinds[pn->numkind], pi->petkind);
		pn->numkind++;
	}
	else
		printf("The list is full!\n");
}

static void ItemCount(Trnode *pn, int *pnum)
{
	*pnum += pn->numkind;
	if(pn->left != NULL)
		ItemCount(pn->left, pnum);
	if(pn->right != NULL)
		ItemCount(pn->right, pnum);
		
}