//listing_8_1.c -- repeats input

#include "stdio.h"

int main(void)
{
	char ch;
	
	while((ch = getchar()) != '#')
		putchar(ch);
	
	return 0;
}