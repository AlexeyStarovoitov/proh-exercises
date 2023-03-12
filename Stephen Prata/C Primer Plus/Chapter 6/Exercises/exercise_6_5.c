#include "stdio.h"

#define ROWS 5

int main(void)
{
	int i,j;
	char ch, ch_in;
	
	printf("Enter the character: ");
	scanf("%c", &ch_in);
	
	ch_in -= (char)(ROWS-1);
	
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < (ROWS - 1 - i); j++)
			printf(" ");
		
		for(ch = ch_in - (char)i; ch < ch_in; ch++)
			printf("%c", ch);
		
		for(ch = ch_in; ch >= ch_in -(char)i; ch--)
			printf("%c", ch);
		
		for(j = 0; j < (ROWS - 1 - i); j++)
			printf(" ");
		
		printf("\n");
		ch_in++;
	}
	
	return 0;
}