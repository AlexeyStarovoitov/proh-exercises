#include "stdio.h"

int main(void)
{
	float number;
	
	printf("Enter a floating-point number:\n");
	scanf("%f", &number);
	
	printf("The input is %.1f or %.1e\n", number, number);
	printf("The input is %+.3f or %.3e\n", number, number);
	
	return 0;
	
}