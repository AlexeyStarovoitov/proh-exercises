//listing_12_10.c -- tests rand1() and srand1()
//compile with listing_12_9.cabs

#include "stdio.h"
extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
	int count;
	unsigned seed;

	printf("Please enter your choice for seed.\n");
	while(scanf("%u", &seed) == 1)
	{
		srand1(seed);
		for(count = 0; count < 5; count++)
			printf("%d\n", rand1());
		printf("Pleae enter next seed (q to quit):\n");
	}
	
	printf("Done\n");
	
	return 0;
}