#include "stdio.h"

void main(void)
{
	#define IN 1
	#define OUT 0
	#define MAX_WORD 1000
	#define END_CHAR 'z'
	
	int length_array[MAX_WORD]; // массив гистограммы
	int c, state, i, j, cur_lgth, max_lgth, max_cnt;
	state = OUT;
	cur_lgth = 0;
	max_lgth = 0;
	max_cnt = 0;
	
	for (i = 0; i < MAX_WORD; i++)
	{
		length_array[i] = 0;
	}
	
	while ((c = getchar()) !=  END_CHAR)
	{
		if ((c == '\n') || (c == '\t') || (c == ' '))
		{
			state = OUT;
			length_array[cur_lgth-1]++;
			if (cur_lgth > max_lgth)
				max_lgth = cur_lgth;
			if(length_array[cur_lgth-1] > max_cnt)
				max_cnt = length_array[cur_lgth-1];
			
			cur_lgth = 0;
		}
		else if (state == OUT)
		{
			state = IN;
		}
		
		if (state == IN)
		{
			cur_lgth++;
		}
	}
	printf("\n");
	for(i = max_cnt; i > 0; i--)
	{
		for (j = 0; j < max_lgth; j++)
		{
			if (i <= length_array[j])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
	for(i = 0; i < max_lgth; i++)
		printf("%d", i+1);
	
}