
#include "stdio.h"
#include "stdbool.h"

int main(void)
{
	unsigned long num;
	unsigned long div, val;
	bool isPrime;
	
	printf("Please enter an integer for analysis; ");
	printf("Enter q to quit. \n");
	while(scanf("%lu", &num) == 1)
	{
		for(val = 2; val <= num; val++)
		{
			for (div = 2, isPrime = true; (div*div) <= val; div++)
			{
				if (val % div == 0)
					isPrime = false;
				
			}
			if (isPrime)
				printf("%lu ", val);
		}
		printf("\n\n");
		printf("Enter another integer for analysis; \n");
	}
	
	return 0;
	
}