//listing_6_1.c -- sums integers entered interactively

#include "stdio.h"

int main(void)
{
	long sum = 0L;
	long num;
	int status;
	
	printf("Please enter an integer to be summed ");
	printf("(q to quit): ");
	status = scanf("%ld", &num);
	while(status == 1)
	{
		sum += num;
		printf("Please enter the next integer(q to quit): ");
		status = scanf("%ld", &num);
	}
	printf("Those integers sum to %ld\n", sum);
	
	return 0;
} 