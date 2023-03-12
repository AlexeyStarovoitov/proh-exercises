#include "stdio.h"

#define STOP '#'

int main(void)
{
	char ch, prev;
	int ei_cnt = 0;
	
	prev  = '\n';
	
	while((ch = getchar()) != STOP)
	{
		if(ch == 'i' && prev == 'e')
			ei_cnt++;
		prev = ch;
	}
	
	printf("ei occured %d times\n", ei_cnt);
	return 0;
}