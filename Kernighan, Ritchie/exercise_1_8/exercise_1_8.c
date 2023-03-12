#include "stdio.h"

void main(void)
{
	int ns, nt, nl, c;
	ns = nt = nl = 0;
	printf ("ns nt nl\n");
	while((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
			nt++;
		}
		if (c == '\n')
		{
			nl++;
		}
		if(c == ' ')
		{
			ns++;
		}
		
		printf("%d %d %d\n", ns , nt, nl);
	}
}