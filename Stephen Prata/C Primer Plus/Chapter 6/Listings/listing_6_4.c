//listing_6_4.c -- watch your semicolons

#include "stdio.h"

int main(void)
{
	int n = 0;
	
	while(n++ < 3);
		printf("n is %d\n", n);
	printf("That's all this program does.\n");
	
	return 0;
}