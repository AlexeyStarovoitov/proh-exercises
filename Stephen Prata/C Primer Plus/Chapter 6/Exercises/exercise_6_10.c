#include "stdio.h"

int main(void)
{
	int lower, upper, item, sum_sq;
	
	printf("Enter lower and upper integer limits: ");
	
	while((scanf("%d %d", &lower, &upper) == 2) && (lower < upper))
	{
		sum_sq = 0;
		for(item = lower; item <= upper; item++)
			sum_sq += item*item;
		
		printf("The sums of the squares from %d to %d is %d\n", 
		lower, upper, sum_sq);
		printf("Enter next set of limits: ");
	}
	
	return 0;
}