//listing_6_3.c -- watch your braces
//bad coding creates an infinite loop

#include "stdio.h"

int main(void)
{
	int n = 0;
	
	while(n < 3)
		printf("n is %d\n", n);
		n++;
	printf("That's all this proogram does\n");
	
	return 0;
}