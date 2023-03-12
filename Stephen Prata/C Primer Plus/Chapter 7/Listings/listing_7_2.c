//listing_7_2.c -- alters input, preversing spaces

#include "stdio.h"
#define SPACE ' '

int main(void)
{
	char ch;
	ch = getchar();
	while(ch != '\n')
	{
		if(ch == SPACE)
			putchar(ch);
		else
			putchar(ch+1);
		ch = getchar();
	}
	
	putchar(ch);
	return 0;
}