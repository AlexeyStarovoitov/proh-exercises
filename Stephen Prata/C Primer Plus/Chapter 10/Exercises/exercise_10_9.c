#include "stdio.h"

#define LIN 3
#define COL 5

void copy(int n, int m, double source[n][m], double target[n][m])
{
	int i, j;
	
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			*(*(target + i)+j) = *(*(source + i) + j);
}

void display(int n, int m, double arr[n][m])
{
	int i, j;
	
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			printf("%.1f ", arr[i][j]);
	
	printf("\n");
}

int main(void)
{
	int rows = LIN;
	int cols = COL;
	
	double arr_1[LIN][COL] = {
								{2, 3, 45, 56, 44},
								{34, 445.3, 433.1, 55, 345},
								{345, 333, 5433, 344, 22}
								};
	double arr_2[LIN][COL];
	
	copy(rows, cols, arr_1, arr_2);
	printf("The arr_1 array: ");
	display(rows, cols, arr_1);
	printf("The arr_2 array: ");
	display(rows, cols, arr_2);
	
	return 0;
	
}