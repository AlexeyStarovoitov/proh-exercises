#include "stdio.h"

#define ROWS 6

int main(void)
{
	int i;
	char ch, ch_st;
	
	ch_st = 'A';
	
	for(i = 0; i < ROWS; i++)
	{
		ch_st += (char)i;
		for (ch = ch_st; ch <= ch_st + (char)i; ch++)
			printf("%c", ch);
		
		printf("\n");
	}
	
	return 0;
}