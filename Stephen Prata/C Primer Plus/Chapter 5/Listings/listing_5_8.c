//listing_5_8 -- uses sizeof operator

#include "stdio.h"

int main(void)
{
	int n = 0;
	size_t intsize;
	
	intsize = sizeof(int);
	printf("n = %d, n has %lu bytes; all ints have %lu bytes.\n",
	n, sizeof n, intsize);
	
	return 0;
}