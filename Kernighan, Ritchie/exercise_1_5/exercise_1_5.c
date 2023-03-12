#include "stdio.h"

void main(void)
{
	#define LOWER 0
	#define UPPER 300
	#define STEP 20
	
	int fahr;
	printf("Программа перевода температур из Фаренгейта в Цельсий\n");
	for (fahr = UPPER; fahr >=LOWER; fahr = fahr - STEP)
	{
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr - 32.0));
	}
}