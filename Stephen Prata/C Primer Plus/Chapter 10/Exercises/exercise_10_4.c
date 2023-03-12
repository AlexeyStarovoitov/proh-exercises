#include "stdio.h"
#define SIZE 7

int max_index(double *arr, int n)
{
	double max;
	int i, index;
	for(max = *arr, i = 0; i < n; arr++, i++)
		if(max < *arr)
		{
			max = *arr;
			index = i;;
		}
			
	return index;
}

int main(void)
{
	double rand[] = {1.0, 345.0, 553.0, 22222.0, 565.0, -23424.0, 45434.0};
	
	printf("The rand array: ");
	for(int i = 0; i < SIZE; i++)
		printf("%.3f ", rand[i]);
	printf("\n");
	printf("The index of the maximum value of rand is %d\n", max_index(rand, SIZE));
	
	return 0;
}