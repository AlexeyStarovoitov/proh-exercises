#include "stdio.h"
#define ROWS 3
#define COLS 5

void initilize(int rows, int cols, double arr[rows][cols])
{
	int i, j;
	
	printf("Enter 3 sets of double values\n");
	for(i = 0; i < rows; i++)
	{
		printf("Enter the %d set of 5 double elements:\n", i + 1);
		for(j = 0; j < cols; j++)
			scanf("%lf", *(arr+i) + j);
	}
}

void aver_line(double *arr, int n)
{
	int i;
	double sum = 0.0;
	
	for(i = 0; i < n; i++)
		sum += *(arr + i);
	
	printf("The average of %d values is %.3f\n", n, sum/(double)n);
}

double aver(int rows, int cols, double arr[rows][cols])
{
	int i, j;
	double sum = 0.0;
	
	for(i = 0; i < rows; i++)
		for(j = 0; j < cols; j++)
			sum += *(*(arr + i) + j);
	
	return sum/(double)(rows*cols);
}

double max(int rows, int cols, double arr[rows][cols])
{
	double maximum = **arr;
	int i,j;
	
	for(i = 0; i < rows; i++)
		for(j = 0; j < cols; j++)
			if(maximum < arr[i][j])
				maximum = arr[i][j];
	
	return maximum;
	
}

void results(int rows, int cols, double arr[rows][cols])
{
	int i;
	
	initilize(rows, cols, arr);
	for(i = 0; i< rows; i++)
	{
		printf("The %d set:\n", i+1);
		aver_line(arr[i], cols);
	}
	printf("The average of arr is %.3f\n", aver(rows, cols, arr));
	printf("The max of arr is %.3f\n", max(rows, cols, arr));
}

int main(void)
{
	double arr[ROWS][COLS];
	
	results(ROWS, COLS, arr);
	
	return 0;
}