#define CALLS 100

#include "stdio.h"

unsigned long num_tms(void)
{
	static unsigned long times = 0;
	
	times++;
	
	return times;
}

int main(void)
{
	int i;
	
	for(i = 0; i < CALLS; i++)
		printf("Function num_tms called %lu times\n",
				num_tms());
	
	return 0;
}