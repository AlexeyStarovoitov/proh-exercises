#include "stdio.h"
#define SIZE 7

int max_int(int *arr, int n)
{
	int max;
	for(max = *arr; n > 0; arr++, n--)
		if(max < *arr)
			max = *arr;
	return max;
}

int main(void)
{
	int rand[] = {1, 345, 553, 22222, 565, -23424, 45434};
	
	printf("The rand array: ");
	for(int i = 0; i < SIZE; i++)
		printf("%d ", rand[i]);
	printf("\n");
	printf("the maximum of rand is %d\n", max_int(rand, SIZE));
	
	return 0;
}