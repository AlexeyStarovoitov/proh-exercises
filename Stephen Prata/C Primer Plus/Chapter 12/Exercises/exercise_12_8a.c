#include "stdio.h"
#include "stdlib.h"

int *make_array(int elem, int val)
{
	int *pa = (int *)malloc(elem*sizeof(int));
	
	int i;
	for(i = 0; i < elem; i++)
		pa[i] = val;
	
	return pa;
}

void show_array(const int ar[], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("%4d ", ar[i]);
		if(i % 8 == 7)
			printf("\n");
	}
	
	if(i % 8 != 0)
		printf("\n");

}