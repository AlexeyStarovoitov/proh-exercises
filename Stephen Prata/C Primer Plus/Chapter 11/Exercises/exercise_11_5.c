#include "stdio.h"
#define SIZE 30

const char *str_chr(const char *str, char ch)
{
	while(*str)
	{
		if(*str == ch)
			return str;
		str++;
	}
	
	return NULL;
}

char *s_gets(char *st, int n)
{
	char * ret_val;
	int i = 0;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return ret_val;
}


int main(void)
{
	char str[SIZE];
	char ch;
	const char *res;
	
	printf("Enter your sentence (q to quit):\n");
	
	while(s_gets(str, SIZE) && str[0] != 'q')
	{
		printf("Enter the character to search\n");
		ch = getchar();
		getchar(); //for the newline character
		res = str_chr(str, ch);
		if(res)
			printf("The character next to the position in string is %c\n", *(res+1));
		else
			printf("The character was not found\n");
		
		printf("Enter your sentence (q to quit):\n");
	}
	
	return 0;
	
	
}