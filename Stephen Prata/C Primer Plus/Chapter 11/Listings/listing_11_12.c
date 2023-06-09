//listing_11_12.c -- using puts()

#include "stdio.h"

#define DEF "I am a #defined string"

int main(void)
{
	char str1[80] = "An array was initilized to me.";
	const char *str2 = "A pointer was initilized to me.";
	
	puts("I am an argument to puts().");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[5]);
	puts(str2 + 4);
	
	return 0;
}