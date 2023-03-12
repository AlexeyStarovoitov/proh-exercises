#include "stdio.h"
#define SIZE1 7
#define SIZE2 3 

void copy_ptr(double *tar, double *src, int n)
{
	while(n-- > 0)
		*tar++ = *src++;
}

int main(void)
{
	double arr[SIZE1] = {1.2, 33.3, 45.1, 34.2, 44.3, 22.1, 2.3};
	double sub_arr[SIZE2];
	int i;
	
	printf("The array: ");
	for(i = 0; i < SIZE1; i++)
		printf("%.2f ", arr[i]);
	printf("\n");
	
	copy_ptr(sub_arr, arr+2, SIZE2);
	printf("The subarray: ");
	for(i = 0; i < SIZE2; i++)
		printf("%.2f ", sub_arr[i]);
	printf("\n");
	
	return 0;
	
}