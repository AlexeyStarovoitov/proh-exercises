#define SEEDS 10
#define TIMES 1000
#define WIDTH 44
#define NUMBERS 10

#include "stdio.h"
#include "exercise_12_6a.h"
//#include "stdlib.h"
#include "time.h"
#include "string.h"

int main(void)
{
	int i, j, k;
	unsigned int arr[NUMBERS], temp;
	
	for(i = 0; i < NUMBERS; i++)
		arr[i] = 0;
	
	for(i = 1; i <= WIDTH/2; i++)
		printf("*");
	printf("NUMBERS");
	for(i = WIDTH/2 +strlen("NUMBERS"); i <= WIDTH; i++)
		printf("*");
	printf("\n");
	
	printf("%4s", "No");
	for(i = 1; i <= NUMBERS; i++)
		printf("%4d", i);
	printf("\n");
	
	for(i = 1; i <= SEEDS; i++)
	{
		for (k = 0; k < 100000000; k++)
			continue;
		srand1(time(0));
		//srand(time(0));
		for(j = 1; j <= TIMES; j++)
		{
			temp = (unsigned int)(rand1()%NUMBERS+1);
			//temp = (unsigned int)(rand()%NUMBERS+1);
			arr[temp-1]++;
		}
		printf("%4d", i);
		
		for(j = 0; j < NUMBERS; j++)
		{
			printf("%4u", arr[j]);
			arr[j] = 0;
		}
		
		printf("\n");
	}
	
	return 0;

}