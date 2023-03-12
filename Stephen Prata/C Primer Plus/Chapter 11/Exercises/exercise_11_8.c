#include "stdio.h"

#define SIZE 30

char * string_in(char *s1, char *s2)
{
	char *first = NULL;
	
	while(*s1)
	{
		if(*s1 == *s2)
		{
			first = s1;
			while ((*s1 == *s2) && *s1 && *s2)
			{
				s1++;
				s2++;
			}
			if(*s2 == '\0')
				return first;
			else 
				first = NULL;
		}
		
		s1++;
	}
	
	return first;
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
	char str1[SIZE], str2[SIZE];
	char *ch;
	
	printf("Enter your first sentence (q to quit):\n");
	
	while(s_gets(str1, SIZE) && str1[0] != 'q')
	{
		printf("Enter your second sentence:\n");
		s_gets(str2, SIZE);
		
		ch = string_in(str1, str2);
		if(ch)
			printf("The second string begins at the address %p\n", ch);
		else
			printf("There is no second string in the first string!\n");
		
		printf("Enter your first sentence (q to quit):\n");
	}
	
	return 0;
	
	
}