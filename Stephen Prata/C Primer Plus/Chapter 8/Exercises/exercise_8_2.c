#include "stdio.h"

#define PERIOD 10
#define STEP 64
#define SP 32

int main(void)
{
	int ch;
	int count = 0;
	printf("Enter your characters:\n");
	while((ch = getchar()) != EOF)
	{
		if (ch < SP)
		{
			if (ch == '\n')
				count = 0;
			else if(ch != '\t')
				ch += STEP;
		}
		printf("%c - %d ", ch, ch);
		if(++count == PERIOD)
		{
			printf("\n");
			count = 0;
		}
	}
	
	printf("Done!\n");
	
	return 0;
	
}