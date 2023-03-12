#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SLEN 81

char *s_gets(char *st, int n);

int main(void)
{
	FILE *fp;
	char name[SLEN];
	int ch;
	long pos, cur_pos;
	
	printf("Enter the file name:\n");
	if(s_gets(name, SLEN) == NULL)
		exit(EXIT_FAILURE);
	
	if ((fp = fopen(name, "r")) == NULL)
		exit(EXIT_FAILURE);
	
	printf("Enter the position:\n");
	
	while((scanf("%ld", &pos) == 1) && (pos >=0))
	{
		cur_pos = 0L;
		rewind(fp);
		while((cur_pos < pos) && ((ch = getc(fp)) != EOF))
			cur_pos++;
		
		while((ch != '\n') && (ch != EOF))
		{
			putchar(ch);
			ch = getc(fp);
		}
		
		putchar(ch);
		printf("Enter the position:\n");
	}
	
	fclose(fp);
	
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