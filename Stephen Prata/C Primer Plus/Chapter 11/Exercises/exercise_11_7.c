#include "stdio.h"
#include "string.h"
#define SIZE 30

char *mystrncpy(char *s1, const char *s2, int n)
{
	char *ret_val = s1;
	
	while(*s1)
		s1++;
	while(n-- > 0 && *s2)
		*s1++ = *s2++;
	
	if(n>0)
		while(n-- > 0)
			*s1++ = '\0';
	
	return ret_val;
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
	int available;
	
	printf("Enter your first sentence (q to quit):\n");
	
	while(s_gets(str1, SIZE) && str1[0] != 'q')
	{
		printf("Enter your second sentence:\n");
		s_gets(str2, SIZE);
		
		available = SIZE - strlen(str2) - 1;
		if(available > 0)
		{
			mystrncpy(str1, str2, available);
			str1[SIZE-1] = '\0';
			puts(str1);
		}
		
		printf("Enter your first sentence (q to quit):\n");
	}
	
	return 0;
	
	
}
