#include "stdio.h"
#define ROWS 3
#define COLS 5

void display(int arr[][COLS], int rows)
{
	int i, j;
	
	for(i = 0; i < rows; i++)
		for(j = 0; j < COLS; j++)
			printf("%d ", arr[i][j]);
	
	printf("\n");
}

void double_arr(int arr[][COLS], int rows)
{
	int i, j;
	
	for(i = 0; i < rows; i++)
		for(j = 0; j < COLS; j++)
			*(*(arr + i) + j) *= 2;
}

int main(void)
{
	int arr[ROWS][COLS] = 
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15}
	};
	
	printf("The original arr: ");
	display(arr, ROWS);
	double_arr(arr, ROWS);
	printf("The doubled arr: ");
	display(arr, ROWS);
	
	return 0;
}