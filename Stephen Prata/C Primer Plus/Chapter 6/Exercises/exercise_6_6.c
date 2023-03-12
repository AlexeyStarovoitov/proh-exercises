#include "stdio.h"

int main(void)
{
	int min, max, i;
	
	printf("Enter maximum: ");
	scanf("%d", &max);
	printf("Now minimum: ");
	scanf("%d", &min);
	
	printf("  int square  cube\n");
	for(i = min; i<=max; i++)
	{
		printf("%5d %5d %5d\n", i, i*i, i*i*i);
	}
	
}