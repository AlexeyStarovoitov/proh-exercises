#include "stdio.h"
#include "limits.h"

unsigned int rotate_l(unsigned int x, unsigned int num_bits);

int main(void)
{
	unsigned int val, num;
	
	printf("Enter a positive value and number of bits to rotate:\n");
	
	while(scanf("%u %u", &val, &num) == 2)
	{
		if(num > sizeof(val)*CHAR_BIT)
		{
			printf("Try again\n");
			continue;
		}
		printf("The result of rotation is %u\n", rotate_l(val, num));
		printf("Enter a positive value and number of bits to rotate:\n");
	}
	
	return 0;
}


unsigned int rotate_l(unsigned int x, unsigned int num_bits)
{
	unsigned int bits;
	
	bits = x >> (sizeof(x)*CHAR_BIT - num_bits);
	x <<= num_bits;
	x |= bits;
	
	return x;
}

