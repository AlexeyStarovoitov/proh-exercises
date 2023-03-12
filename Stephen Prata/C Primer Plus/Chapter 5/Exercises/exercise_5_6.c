#include "stdio.h"

int main(void)
{
	int count, sum, fin;
	
	printf("Enter the final value\n");
	scanf("%d", &fin);
	
	while (fin > 0)
	{
		count = 0;
		sum = 0;
		
		while (count++ < fin)
			sum = sum + count*count;
		
		printf("sum = %d\n", sum);
		
		printf("Enter the final value\n");
		scanf("%d", &fin);
	}
	
	return 0;
}