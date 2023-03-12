#include "stdio.h"

void main(void)
{
	int c, c_prev;
	c = c_prev = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (c != c_prev)
			{
				putchar(c);
			}
		}
		else
		{
			putchar(c);
		}
		c_prev = c;
	}
}