#include "stdio.h"

float fahr2celsius(int fahr);

void main(void)
{
	#define LOWER 0
	#define UPPER 300
	#define STEP 20
	int fahr;
	printf("fahr - celsius\n");
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	{
		printf("%3d - %6.2f\n", fahr, fahr2celsius(fahr));
	}
		
}

float fahr2celsius(int fahr)
{
	return (5.0/9.0)*(fahr - 32.0);
}