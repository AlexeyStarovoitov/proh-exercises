#include "stdio.h"
#define LEN 4

void sum(int *arr1, int *arr2, int *sum_arr, int n)
{
	int i;
	
	for(i = 0; i < n; i++)
		*(sum_arr + i) = *(arr1 + i) + *(arr2 + i);
		
}

int main(void)
{
	int arr1[LEN] = {2, 4, 5, 8};
	int arr2[LEN] = {1, 0, 4, 6};
	int sum_arr[LEN];
	int i;
	
	sum(arr1, arr2, sum_arr, LEN);
	printf("arr1[i], arr[2], [sum_arr[i]\n");
	for(i = 0; i < LEN; i++)
		printf("%5d %5d %5d\n", arr1[i], arr2[i], sum_arr[i]);
	
	return 0;
}