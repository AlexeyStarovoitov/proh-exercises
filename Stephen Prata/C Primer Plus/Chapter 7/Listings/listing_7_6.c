//listing_7_6.c -- use the logical AND operator

#include "stdio.h"
#include "iso646.h"
#define PERIOD '.'

int main(void)
{
	char ch;
	int charcount = 0;
	
	while((ch = getchar()) != PERIOD)
	{
		if (ch != '"' and ch != '\'')
			charcount++;
	}
	
	printf("There are %d non-quote characters.\n", charcount);
	
	return 0;
	
}