#include "stdio.h"

void main(void)
{
	int c, nb;
	//nb = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			c = 't';
			putchar('\\');
		}
		if (c == '\b')
		{
			c = 'b';
			//nb++;
			putchar('\\');
		} 
		
		putchar(c);
	}
}