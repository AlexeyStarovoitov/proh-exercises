//exercise_17_6.c -- binary search

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

#define LEN 20

int mycomp(const void *a1, const void *a2);
bool binary_search(int ar[], int n, int a);

int main(void)
{
	int arr[LEN];
	int a, i;
	
	srand((unsigned int) time(0));
	
	for(i = 0; i < LEN; i++)
		arr[i] = rand();
	
	qsort(arr, LEN, sizeof(int), mycomp);
	
	printf("Here is your array:\n");
	
	for(i = 0; i < LEN; i++)
	{
		printf("%d ", arr[i]);
		if(i % 5 == 4)
			putchar('\n');
	}
	
	if(i % 5 != 0)
		putchar('\n');
	
	printf("Enter the value you want ot find in the array:\n");
	
	while(scanf("%d", &a) == 1)
	{
		if(binary_search(arr, LEN, a))
			printf("The value is in the array\n");
		else
			printf("The value is not in the array\n");
		
		printf("Enter the value you want ot find in the array:\n");
	}
	
	return 0;
}

bool binary_search(int ar[], int n, int a)
{
	if(a == ar[n/2])
		return true;
	else if(a != ar[n/2] && n == 1)
		return false;
	else if (a < ar[n/2])
		return binary_search(ar, n/2, a);
	else
	{
		if(n%2 == 0)
			return binary_search(ar+n/2+1, n/2-1, a);
		else
			return binary_search(ar+n/2+1, n/2, a);
	}
}

int mycomp(const void *a1, const void *a2)
{
	const int *ai1 = (const int *)a1;
	const int *ai2 = (const int *)a2;
	
	if (*ai1 < *ai2)
		return -1;
	else if(*ai1 > *ai2)
		return 1;
	else
		return 0;
}