#include "stdio.h"
#include "stdlib.h"
#include "exercise_16_5_1.h"

#define SIZE 40
void rand_print(int ar[], int size, int picks);

int main(void)
{
	int arr[SIZE];
	int i;
	int picks = 30;
	srand1();
	
	for(i = 0; i < SIZE; i++)
		arr[i] = rand1();
	
	rand_print(arr, SIZE, picks);

	return 0;
}

void rand_print(int ar[], int size, int picks)
{
	int *pti = (int *)malloc(picks*sizeof(int));
	int pick_cur = 0;
	int index, j;
	int i = 0;
	
	srand1();
	
	while(i < picks)
	{
		index = rand1() % size;
		
		if(pick_cur == 0)
		{
			pti[0] = ar[index];
			pick_cur++;
			i++;
		}
		else
		{
			for(j = 0; j < pick_cur; j++)
				if(pti[j] == ar[index])
					break;
			if(j == pick_cur)
			{
				pti[j] = ar[index];
				pick_cur++;
				i++;
			}
		}
	}
	
	for (i = 0; i < picks; i++)
	{
		printf("%d ", pti[i]);
		if(i % 7 == 6)
			printf("\n");
	}
	if(i % 7 != 6)
			printf("\n");
	free(pti);
}