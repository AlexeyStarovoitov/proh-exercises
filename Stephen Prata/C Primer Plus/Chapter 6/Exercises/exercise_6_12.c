#include "stdio.h"

int main(void)
{
	float sum_1, sum_2;
	int i_lim;
	
	printf("Enter the limit of items: ");
	
	while((scanf("%d", &i_lim) == 1) && (i_lim > 0))
	{
		sum_1 = sum_2 = 0.0f;
		
		for(int i = 1; i <= i_lim; i++)
		{
			sum_1 += 1.0/(float)i;
			
			if (i % 2)
				sum_2 -= 1.0/(float)i;
			else
				sum_2 += 1.0/(float)i;
		}
		
		printf("seq 1: %f, seg 2: %f\n", sum_1, sum_2);
		printf("Enter the limit of items: ");
	}
	
	return 0;
}