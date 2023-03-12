#include "stdio.h"

#define SIZE 8

int main(void)
{
	int i, temp, arr_int[SIZE];
	
	printf("Enter 8 integers: ");
	
	for(i = 0; i < SIZE; i++)
		scanf("%d", &arr_int[i]);
	
	for(i = 0; i < SIZE/2; i++)
	{
		temp = arr_int[i];
		arr_int[i] = arr_int[SIZE-1-i];
		arr_int[SIZE-1-i] = temp;
	}
	
	for(i = 0; i < SIZE; i++)
		printf("%d ", arr_int[i]);
	
	return 0;
}