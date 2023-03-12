#include "stdio.h"
#include "string.h"

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

char *s_gets(char *st, int n);
void title_srt(struct book **pbook, int n);
void val_srt(struct book **pbook, int n);

int main(void)
{
	struct book library[MAXBKS];
	struct book *ptr[MAXBKS];
	int count = 0;
	int index;
	
	printf("Please enter the book title.\n");
	printf("Press enter at the start of a line to stop\n");
	while(count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value\n");
		scanf("%f", &library[count++].value);
		while(getchar() != '\n')
			continue;
		if(count < MAXBKS)
			printf("Enter the next title.\n");
				
	}
	
	if(count > 0)
	{
		for(index = 0; index < count; index++)
			ptr[index] = &library[index];
		printf("Here is the list of your books:\n");
		for(index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title, 
					library[index].author, library[index].value);
		
		title_srt(ptr, count);
		printf("Here is the list of your books alphabetized by title:\n");
		for(index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", ptr[index]->title, 
					ptr[index]->author, ptr[index]->value);
		
		val_srt(ptr, count);
		printf("Here is the list of your books in order of increased value:\n");
		for(index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", ptr[index]->title, 
					ptr[index]->author, ptr[index]->value);
		
	}
	else
		printf("No books? Too bad!\n");
	
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
				continue;
	}
	
	return ret_val;
}

void title_srt(struct book **pbook, int n)
{
	int i, j;
	struct book *temp;
	
	for(i = 0; i < n -1; i++)
		for(j = i+1; j < n; j++)
			if(strcmp(pbook[i]->title, pbook[j]->title) > 0)
			{
				temp = pbook[i];
				pbook[i] = pbook[j];
				pbook[j] = temp;
			}
}

void val_srt(struct book **pbook, int n)
{
	int i, j;
	struct book *temp;
	
	for(i = 0; i < n -1; i++)
		for(j = i+1; j < n; j++)
			if(pbook[i]->value > pbook[j]->value)
			{
				temp = pbook[i];
				pbook[i] = pbook[j];
				pbook[j] = temp;
			}
}

