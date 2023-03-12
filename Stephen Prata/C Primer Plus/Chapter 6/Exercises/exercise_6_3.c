#include "stdio.h"

#define ROWS 6

int main(void)
{
	int i;
	char ch;
	
	for(i = 1; i <= ROWS; i++)
	{
		for (ch = 'F'; ch > 'F'- (char)i; ch--)
			printf("%c", ch);
		
		printf("\n");
	}
	
	return 0;
}