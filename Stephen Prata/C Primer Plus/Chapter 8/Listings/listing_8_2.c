//listing_8_1.c -- repeats input to end of file

#include "stdio.h"

int main(void)
{
	char ch;
	
	while((ch = getchar()) != EOF)
		putchar(ch);
	
	return 0;
}