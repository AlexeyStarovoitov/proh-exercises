#include "stdio.h"
#define LINES 2
#define COLS 3

void copy_ptr(double *tar, double *src, int n)
{
	while(n-- > 0)
		*tar++ = *src++;
}

int main(void)
{
	double source[LINES][COLS] = {{1.1, 10.1, 3.2}, {45.1, 44.2, 22.6}};
	double target[LINES][COLS];
	int i, j;
	
	printf("The source array: ");
	for(i = 0; i < LINES; i++)
		for(j = 0; j < COLS; j++)
			printf("%.2f ", *(*(source + i) + j));
	
	printf("\n");
	
	for(i = 0; i < LINES; i++)
		copy_ptr(target[i], source[i], COLS);
	
	printf("The source:");
	for(i = 0; i < LINES; i++)
		for(j = 0; j < COLS; j++)
			printf("%.2f ", *(*(source + i) + j));
	
	printf("\nThe target: ");
	for(i = 0; i < LINES; i++)
		for(j = 0; j < COLS; j++)
			printf("%.2f ", *(*(target + i) + j));
	
	return 0;
}