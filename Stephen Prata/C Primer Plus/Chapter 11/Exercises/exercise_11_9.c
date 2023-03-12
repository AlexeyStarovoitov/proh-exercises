#include "stdio.h"

#define SIZE 30

void string_reversed(char *s1)
{
	char temp;
	char *end = s1;
	
	while(*(end + 1))
		end++;
	temp = *s1;
	
	while((end - s1) > sizeof(char))
	{
		temp = *s1;
		*s1 = *end;
		*end = temp;
		s1++;
		end--;
	}
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
	
	printf("Enter your sentence (q to quit):\n");
	
	while(s_gets(str, SIZE) && str[0] != 'q')
	{
		string_reversed(str);
		printf("Your string reversed: %s\n", str);
		printf("Enter your sentence (q to quit):\n");
	}
	
	return 0;
	
	
}