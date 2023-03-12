#include "stdio.h"
#include "stdlib.h"

int on_bits(int val);

int main(int argc, char *argv[])
{
	int val;
	
	if(argc != 2)
		exit(EXIT_FAILURE);
	
	val = atoi(argv[1]);
	printf("val = %d\n", val);
	printf("The number of on-bits is %d\n", on_bits(val));
	
	return 0;
	
}

int on_bits(int val)
{
	int count = 0;
	unsigned int val1;
	
	if(val < 0)
	{	
		val1 = val;
		while(val1 > 1)
		{
			count += (val1 % 2 == 1) ? 1:0;
			val1 /= 2;
		}
		count += val1;
	}
	else
	{
		while(val > 1)
		{
			count += ((val % 2) == 1) ? 1:0;
			val /= 2;
		}
		count += val;
	}
	
	return count;
}
