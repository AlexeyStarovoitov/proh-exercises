#include "stdio.h"
#define SIZE 30

int is_within(const char *str, char ch)
{
	while(*str)
	{
		if(*str == ch)
			return 1;
		str++;
	}
	
	return 0;
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
	int res;
	
	printf("Enter your sentence (q to quit):\n");
	
	while(s_gets(str, SIZE) && str[0] != 'q')
	{
		printf("Enter the character to search\n");
		ch = getchar();
		getchar();
		res = is_within(str, ch);
		if(res)
			printf("The character was found\n");
		else
			printf("The character was not found\n");
		
		printf("Enter your sentence (q to quit):\n");
	}
	
	return 0;
	
	
}