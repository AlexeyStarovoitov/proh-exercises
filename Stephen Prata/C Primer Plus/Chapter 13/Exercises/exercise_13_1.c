#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SLEN 81

char *s_gets(char *st, int len);
 
int main(void)
{
	int ch;
	char name[SLEN];
	FILE *fp;
	unsigned long count = 0;
	
	printf("Please, enter the file name:\n");

	if(s_gets(name, SLEN) == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	if((fp = fopen(name, "r")) == NULL)
	{
		printf("Can't open %s\n", name);
		exit(EXIT_FAILURE);
	}
	
	while((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("\nFile %s has %lu characters\n", name, count);
	
	return 0;
}

char *s_gets(char *st, int len)
{
	char *status;
	char *find;
	
	status = fgets(st, len, stdin);
	
	if(status)
	{
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return status;
}