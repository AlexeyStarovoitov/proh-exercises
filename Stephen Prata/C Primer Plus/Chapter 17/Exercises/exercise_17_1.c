//exercise_17_2.c -- using a linked list of structures

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TSIZE 45

struct film
{
	char title[TSIZE];
	int rating;
	struct film *prv;
	struct film *next;
};

char *s_gets(char *st, int n);

int main(void)
{
	struct film *head = NULL;
	struct film *prev, *current, *temp, *tail;
	char input[TSIZE];
	
	prev = NULL;
	puts("Enter first movie title:");
	
	while(s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film *)malloc(sizeof(struct film));
		if(head == NULL)
			head = current;
		else
			prev->next = current;
		
		current->next = NULL;
		current->prv = prev; 
		strcpy(current->title, input);
		puts("Enter your rating 0-10:");
		scanf("%d", &current->rating);
		while(getchar() != '\n')
			;
		puts("Enter next movie title:");
		
		prev = current;
	}
	
	if(head == NULL)
		printf("No data entered. ");
	else
	{
		
		printf("Here is the movie list in the original order:\n");
	
		current = head;
	
		while(current != NULL)
		{
			printf("Movie: %s Rating: %d\n",
					current->title, current->rating);
			if(current->next == NULL)
				tail = current;
			current = current->next;
		}	
		putchar('\n');
		printf("Here is the movie list in the reverse order:\n");
		current = tail;
		
		while(current != NULL)
		{
			printf("Movie: %s Rating: %d\n",
					current->title, current->rating);
			current = current->prv;
		}	
		
		
	}
	
	current = head;
		
	while(current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
		
	return 0;
		
}


char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				;
	}
	
	return ret_val;
}