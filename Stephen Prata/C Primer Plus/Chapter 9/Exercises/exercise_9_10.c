#include "stdio.h"

void to_base_n(unsigned long n, unsigned base);

int main(void)
{
	unsigned long number;
	unsigned base;
	
	printf("Enter an integer and a base (q to quit):\n");
	while(scanf("%lu %u", &number, &base) == 2)
	{
		printf("Base equivalent: ");
		to_base_n(number, base);
		putchar('\n');
		printf("Enter an integer and a base (q to quit):\n");
	}
	
	return 0;
}

void to_base_n(unsigned long n, unsigned base)
{
	int r;
	
	r = n % base;
	if (n >= base)
		to_base_n(n/base, base);
	printf("%d", r);
}