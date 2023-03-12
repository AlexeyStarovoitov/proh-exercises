#include "stdio.h"
#define LENGTH 6


void reverse(double *arr, int n)
{
	double temp;
	int i;
	
	for (i = 0; i < n/2; i++)
	{
		temp = arr[i];
		arr[i] = arr[n-1-i];
		arr[n-1-i] = temp;
	}
}

int main(void)
{
	double given[LENGTH] = {1.1, 234.1, 2.3455, 45.3, 455.678, 22345.1};
	int i;
	
	printf("The given array: ");
	
	for(i = 0; i < LENGTH; i++)
		printf("%.2f ", given[i]);
	
	printf("\n");
	reverse(given, LENGTH);
	
	printf("The  reversed given array: ");
	for(i = 0; i < LENGTH; i++)
		printf("%.2f ", given[i]);
	
	return 0;
}