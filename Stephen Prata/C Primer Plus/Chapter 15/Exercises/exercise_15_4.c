#include "stdio.h"
#include "limits.h"
#include "stdbool.h"

bool bit_val(int val, int bit_pos);

int main(void)
{
	int value, pos;
	
	printf("Enter a value and the bit position you want to check:\n");
	
	while(scanf("%d %d", &value, &pos) == 2)
	{
		
		if(pos > (sizeof(int)*CHAR_BIT - 1))
			printf("Try again!\n");
		else
			printf("The bit is %u\n", bit_val(value, pos));
		
		printf("Enter a value and the bit position you want to check:\n");
	}
	return 0;
}

bool bit_val(int val, int bit_pos)
{
	int mask = 1 << bit_pos;
	
	if(val & mask)
		return true;
	else
		return false;
}