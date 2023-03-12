#include "stdio.h"
#include "string.h"
#include "stack.h"

#define SLEN 20

char *s_gets(char *p_s, int n);

int main(void)
{
	char s[SLEN];
	char ch;
	int i;
	Stack st;
	
	printf("Enter your string\n");
	
	while(s_gets(s, SLEN) && s[0] != '\0')
	{
		InitializeStack(&st);
		for(i = 0; i < strlen(s) && !StackIsFull(&st); i++)
			AddItem(&s[i], &st);
		
		printf("String in the reverse order\n");
		
		while(RemoveItem(&ch, &st))
			putchar(ch);
		
		putchar('\n');
		printf("Enter your string\n");
		RemoveAll(&st);
	}
	
	return 0;
}

char *s_gets(char *p_s, int n)
{
	char *ret_val = fgets(p_s, n, stdin);
	char *find;
	
	if(ret_val)
	{
		find = strchr(p_s, '\n');
		
		if(find)
		{
			*find = '\0';
		}
		else
			while(getchar() != '\n')
				;
	}
	
	return ret_val;
}