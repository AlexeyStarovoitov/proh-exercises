#include "stdio.h"

int main(void)
{
	long count = 0L;
	
	while(getchar() != EOF)
		count++;
	
	printf("You entered %ld characters", count);
	
	return 0;
	
}