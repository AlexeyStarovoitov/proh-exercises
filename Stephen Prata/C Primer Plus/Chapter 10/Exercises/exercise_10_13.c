#include "stdio.h"
#define ROWS 3
#define COLS 5

void initilize(double arr[][COLS], int rows)
{
	int i, j;
	
	printf("Enter 3 sets of double values\n");
	for(i = 0; i < rows; i++)
	{
		printf("Enter the %d set of 5 double elements:\n", i + 1);
		for(j = 0; j < COLS; j++)
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

double aver(double arr[][COLS], int rows)
{
	int i, j;
	double sum = 0.0;
	
	for(i = 0; i < rows; i++)
		for(j = 0; j < COLS; j++)
			sum += *(*(arr + i) + j);
	
	return sum/(double)(rows*COLS);
}

double max(double arr[][COLS], int rows)
{
	double maximum = **arr;
	int i,j;
	
	for(i = 0; i < rows; i++)
		for(j = 0; j < COLS; j++)
			if(maximum < arr[i][j])
				maximum = arr[i][j];
	
	return maximum;
	
}

void results(double arr[][COLS], int rows)
{
	int i;
	
	initilize(arr, rows);
	for(i = 0; i< rows; i++)
	{
		printf("The %d set:\n", i+1);
		aver_line(arr[i], COLS);
	}
	printf("The average of arr is %.3f\n", aver(arr, rows));
	printf("The max of arr is %.3f\n", max(arr, rows));
}

int main(void)
{
	double arr[ROWS][COLS];
	
	results(arr, ROWS);
	
	return 0;
}