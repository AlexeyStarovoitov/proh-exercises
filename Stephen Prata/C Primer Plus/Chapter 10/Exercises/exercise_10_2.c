#include "stdio.h"

#define SIZE 5

void copy_arr(double *tar, double *src, int n)
{
	int i;
	
	for(i = 0; i < n; i++)
		tar[i] = src[i];
}

void copy_ptr(double *tar, double *src, int n)
{
	while(n-- > 0)
		*tar++ = *src++;
	
		
}

void copy_ptrs(double *tar, double *src1, double *src2)
{
	while(src1 < src2)
		*tar++ = *src1++;
		
}

int main(void)
{
	double source[SIZE] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double target1[SIZE], target2[SIZE], target3[SIZE];
	
	copy_arr(target1, source, SIZE);
	copy_ptr(target2, source, SIZE);
	
	copy_ptrs(target3, source, source + SIZE);
	
	printf("target1[i], target2[i], target3[i]\n");
	
	for(int i = 0; i < SIZE; i++)
		printf("%5f %5f %5f\n", 
				target1[i], target2[i], target3[i]);
	
	return 0;
}
