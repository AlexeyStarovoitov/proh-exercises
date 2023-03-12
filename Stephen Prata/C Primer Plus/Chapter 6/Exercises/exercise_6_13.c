#include "stdio.h"

#define SIZE 8

int main(void)
{
	int pow_2[SIZE], i, j;
	
	for(i = 0; i < SIZE; i++)
	{
		pow_2[i] = 1;
		for(j = 1; j <= (i+1); j++)
			pow_2[i] *= 2;
	}
	
	i = 0;
	
	do
	{
		printf("%4d", pow_2[i]);
		i++;
	}while(i < SIZE);
	
	return 0;
}