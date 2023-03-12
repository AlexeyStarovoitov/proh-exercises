#include "stdio.h"

void main(void)
{
	#define ARR_LGTH 256
	#define END_CHAR 'z'
	
	int freq_arr[ARR_LGTH];
	int i, j, c, max_cnt, max_chr;
	
	max_cnt = 0; // максимальное вхождение символа в потоке
	max_chr = 0; // наибольший номер символа, который вошел в поток
	
	for(i = 0; i < ARR_LGTH; i++)
		freq_arr[i] = 0;
	
	while((c = getchar()) != END_CHAR)
	{
		freq_arr[c]++;
		if (c > max_chr)
			max_chr = c;
		if (freq_arr[c] > max_cnt)
			max_cnt = freq_arr[c];
	}
	printf("\n");
	printf("№ - num\n");
	for(i = 0; i <= max_chr; i++)
		if(freq_arr[i] != 0)
			printf("%d - %d\n", i, freq_arr[i]);
	for(i = max_cnt; i > 0; i--)
	{
		for (j = 0; j <= max_chr; j++)
		{
			if(i <= freq_arr[j])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

}