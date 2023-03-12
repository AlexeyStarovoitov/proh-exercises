#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "tree.h"
#include "string.h"

char menu(void);
void lowercase(char *s);
void ShowCount(Item *pi, Tree *pt);
void ShowWord(Item i);

int main(int argc, char *argv[])
{
	Tree tr;
	FILE *in;
	char ch;
	Item words;
	
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Couldn't open the file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	InitializeTree(&tr);
	
	while(fscanf(in, "%20s", words.word) != EOF)
	{
		lowercase(words.word);
		AddItem(&words, &tr);
	}
	
	while((ch = menu()) != 'q')
	{
		switch(ch)
		{
			case 'l': Traverse(&tr, ShowWord);
					 break;
			case 'e': ShowCount(&words, &tr);
					break;
		}
	}
	DeleteAll(&tr);
	fclose(in);
	
	return 0;
}


char menu(void)
{
	int ch;
	
	printf("l) show all words with counts\ne) enter word to show how many times it occured\nq) quit\n");
	
	while((ch = getchar()) != EOF)
	{
		while(getchar() != '\n')
			continue;
		if(strchr("leq", ch) == NULL)
			printf("Try again!\n");
		else
			break;
	}
	
	if(ch == EOF)
		ch = 'q';
	
	return ch;
}

void lowercase(char *s)
{
	while(*s != '\0')
	{
		*s = tolower(*s);
		s++;
	}
}

void ShowCount(Item *pi, Tree *pt)
{
	printf("Enter the word:\n");
	scanf("%20s", pi->word);
	while(getchar() != '\n')
		continue;
	if (FindItem(pi, pt))
		printf("Word %s occured %d times\n", pi->word, pi->count);
}

void ShowWord(Item i)
{
	printf("Word %s occured %d times\n", i.word, i.count);
}
