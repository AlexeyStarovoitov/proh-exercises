#include "stdio.h"

#define LINE_CH 8
#define LENGTH 256
#define STOP '#'

int main(void)
{
	char arr_ch[LENGTH], ch;
	int num, i;
	
	num = 0;
	
	printf("Please, enter your text:\n");
	
	while((ch = getchar()) != STOP)
	{
		arr_ch[num] = ch;
		num++;
	}
	
	for(i = 0; i < num; i++)
	{
		if((i+1) % LINE_CH == 0)
			printf("%c %d\n", arr_ch[i], arr_ch[i]);
		else
			printf("%c %d ", arr_ch[i], arr_ch[i]);
			
	}
	
	return 0;
}