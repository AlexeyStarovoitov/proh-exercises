#include "stdio.h"

unsigned long Fibonacci(unsigned n)
{
	unsigned long fib_n, fib_n_1, temp;
	unsigned i;
	
	if(n == 1 || n == 2)
		fib_n = 1;
	else
	{
		fib_n = fib_n_1 = 1;
		
		for(i = 3; i <= n; i++)
		{
			temp = fib_n;
			fib_n += fib_n_1;
			fib_n_1 = temp;
		}
	}
	
	return fib_n;
}

int main(void)
{
	unsigned n;
	
	printf("Enter the number of Fibonacci:\n");
	
	while(scanf("%u", &n) == 1)
	{
		printf("The Fibonacci with number %u is %lu\n", 
				n, Fibonacci(n));
		printf("Enter the number of Fibonacci:\n");
	}
	
	return 0;
}