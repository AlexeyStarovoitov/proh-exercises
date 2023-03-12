#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char *s_gets(char *st, int n);
int menu(void);

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int deleted;
};

int main(void)
{
	
	struct book library[MAXBKS];
	int count = 0;
	int count_del = 0;
	int index, filecount, answer;
	FILE *pbooks;
	int size = sizeof(struct book);
	
	for(index = 0; index < MAXBKS; index++)
		library[index].deleted = 0;
	
	if((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	
	rewind(pbooks);
	
	while(count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if(count == 0)
			puts("Current contents of book.dat");
		printf("%s by %s: $%.2f\n", library[count].title,
				library[count].author, library[count].value);
		answer = menu();
		
		switch(answer)
		{
			case 1:
				printf("Enter title:\n");
				s_gets(library[count].title, MAXAUTL);
			break;
			case 2:
				printf("Enter author:\n");
				s_gets(library[count].author, MAXAUTL);
			break;
			case 3:
				printf("Enter value:\n");
				scanf("%d", library[count].value);
				while(getchar() != '\n')
					;
			break;
			case 4:
				library[count].deleted = 1;
				count_del++;
			break;
			case 5:
			break;
		}
		count++;
	}
	
	fclose(pbooks);
	count -= count_del;
	
	if(count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
		exit(2);
	}
	
	puts("Please add new book titles.");
	puts("Press enter at the start of a line to stop.");
	while(count < MAXBKS)
	{
		if (count_del != 0)
		{
			index = 0;
			while(library[index].deleted == 0)
				index++;
			if(s_gets(library[index].title, MAXTITL) == NULL || library[index].title[0] == '\0')
				break;
			puts("Now enter the author.");
			s_gets(library[index].author, MAXAUTL);
			puts("Now enter the value.");
			scanf("%f", &library[index].value);
			while(getchar() != '\n')
				continue;
			count_del--;
		}
		else
		{
			if(s_gets(library[count].title, MAXTITL) == NULL || library[count].title[0] == '\0')
				break;
			puts("Now enter the author.");
			s_gets(library[count].author, MAXAUTL);
			puts("Now enter the value.");
			scanf("%f", &library[count].value);
			while(getchar() != '\n')
				continue;
		}
		count++;
		if(count < MAXBKS)
			puts("Enter the next title");
		
	}
	
	pbooks = fopen("book.dat", "w+b");
	
	if (count > 0)
	{
		puts("Here is the list of your books:");
		for(index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title,
					library[index].author, library[index].value);
		fwrite(&library[0], size, count, pbooks);
	}
	else
		puts("No books? Too bad.\n");
	
	fclose(pbooks);
	
	return 0;
}

int menu(void)
{
	int ans;
	
	printf("1)Change title 2)Change author\n");
	printf("3)Change value 4)Delete the record\n");
	printf("5) No changes\n");
	
	while((scanf("%d", &ans) != 1) || ((ans < 1) && (ans > 5)))
		printf("Try again!\n");
	
	while(getchar() != '\n')
		continue;
	
	return ans;
}

char *s_gets(char *st, int n)
{
	char *ret_val, *find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find =strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return ret_val;
}