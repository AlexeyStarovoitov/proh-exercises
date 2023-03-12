//listing_11_14.c -- prints a string without adding \n
#include "stdio.h"
void put1(const char *string)
{
	while(*string)
		putchar(*string++);
}