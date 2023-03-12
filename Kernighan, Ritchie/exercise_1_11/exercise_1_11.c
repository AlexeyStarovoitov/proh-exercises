#include "stdio.h"

void main(void)
{
	#define IN 1
	#define OUT 0
	int nl, nc, nw, c, state;
	
	state = OUT;
	nl = nw = nc = 0;
	printf("nc nw nl\n");
	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
		{
			nl++;
			nc--;
		}
		if ((c == '\n') || (c == '\t') || (c == ' '))
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			nw++;
		}
		
		printf("%d %d %d\n", nc, nw, nl);
	}
	
}