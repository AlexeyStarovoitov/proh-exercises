#include "stdio.h"

int main(void)
{
	#define SIZE 8
	
	double arr[SIZE], arr_sum[SIZE];
	
	printf("Enter 8 double: ");
	
	for(int i = 0; i < SIZE; i++)
		scanf("%lf", &arr[i]);
	
	
	arr_sum[0] = arr[0];
	
	for(int i = 1; i < SIZE; i++)
		arr_sum[i] = arr_sum[i-1] + arr[i];
	
	for(int i = 0; i < SIZE; i++)
		printf("%5.1f", arr[i]);
	
	printf("\n");
	
	for(int i = 0; i < SIZE; i++)
		printf("%5.1f", arr_sum[i]);
	
	return 0;
}