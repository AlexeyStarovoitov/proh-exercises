// listing 3_4 - more printf() properties 

#include "stdio.h"

int main(void)
{
	unsigned un = 3000000000; // 32-bit int
	short end = 200; // 16-bit short
	long big = 65537;
	long long verybig = 12345678908642;
	
	printf("un = %u and not %d\n", un, un);
	printf("end = %hd and not %d\n", end, end);
	printf("big = %ld and not %hd\n", big, big);
	printf("verybig = %lld and not %ld\n", verybig, verybig);
	
	return 0;
}