//listing_6_9.c -- using a _Bool variable

#include "stdio.h"
#include "stdbool.h"

int main(void)
{
	long sum = 0L;
	long num;
	bool input_is_good;
	
	printf("Please enter an integer to be summed ");
	printf("(q to quit): ");
	input_is_good = scanf("%ld", &num);
	while(input_is_good)
	{
		sum += num;
		printf("Please enter the next integer(q to quit): ");
		input_is_good = scanf("%ld", &num);
	}
	printf("Those integers sum to %ld\n", sum);
	
	return 0;
}