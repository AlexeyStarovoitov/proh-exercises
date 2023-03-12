#include "stdio.h"

#define SIZE 30
#define SPACE ' '

void remove_space(char *s1)
{
	char *space;
	
	while(*s1)
	{
		if(*s1 == SPACE)
		{
			space = s1;
			while(*(space+1))
			{
				*space = *(space+1);
				space++;
			}
			
			*space = '\0';
		}
		s1++;
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
		remove_space(str);
		printf("Your string without spaces: %s\n", str);
		printf("Enter your sentence (q to quit):\n");
	}
	
	return 0;
	
	
}
