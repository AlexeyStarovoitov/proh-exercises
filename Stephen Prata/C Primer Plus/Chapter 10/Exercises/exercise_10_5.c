#include "stdio.h"
#define SIZE 7

double max_min_diff(double *arr, int n)
{
	double max, min;
	
	
	for(max = *arr, min = *arr; n > 0; arr++, n--)
	{
		if(max < *arr)
			max = *arr;
		if (min > *arr)
			min = *arr;
	}		
	return max-min;
}

int main(void)
{
	double rand[] = {1.0, 345.0, 553.0, 22222.0, 565.0, -23424.0, 45434.0};
	
	printf("The rand array: ");
	for(int i = 0; i < SIZE; i++)
		printf("%.3f ", rand[i]);
	printf("\n");
	printf("The difference between the maximum  and minimum value of rand is %.3f\n", max_min_diff(rand, SIZE));
	
	return 0;
}