#include "stdio.h"

void main(void)
{
	#define IN 1
	#define OUT 0
	int c, c_prev, state;
	c = c_prev = 0;
	state = OUT;
	
	while ((c = getchar()) != EOF)
	{
		if ((c == '\n') || (c == '\t') || (c == ' '))
		{
			if (c != c_prev)
				printf("\n");
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
		}
		if (state == IN)
		{
			putchar(c);
		}
	
		c_prev = c;
	}
	
}