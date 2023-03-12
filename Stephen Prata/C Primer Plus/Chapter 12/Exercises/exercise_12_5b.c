#include "stdio.h"
#include "time.h"
#include "exercise_12_5a.h"

#define SIZE 100

void bubble_srt(unsigned int ar[], int size);

int main(void)
{
	unsigned int ar[SIZE];
	int i;
	
	srand1((unsigned int)time(0));
	for(i = 0; i < SIZE; i++)
		ar[i] = rand1()%10+1;
	
	bubble_srt(ar, SIZE);
	
	for(i = 0; i < SIZE; i++)
	{
		printf("%u", ar[i]);
		if(i % 10 == 9)
			printf("\n");
	}
	
	printf("\n");
	return 0;
}

void bubble_srt(unsigned int ar[], int size)
{
	int i, j;
	unsigned int tmp;
	
	for(i = 0; i < size - 1; i++)
		for(j = i + 1; j < size; j++)
			if(ar[i] < ar[j])
			{
				tmp = ar[i];
				ar[i] = ar[j];
				ar[j] = tmp;
			}
}