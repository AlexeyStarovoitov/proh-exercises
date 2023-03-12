//listing_11_4.c -- array of pointers, array of strings

#include "stdio.h"
#define SLEN 40
#define LIM 5

int main(void)
{
	const char *mytalents[LIM] = 
	{
		"Adding numbers swiftly",
		"Multiplying accurantly",
		"Stashing data",
		"Following instructions to the letter",
		"Understanding the C language"
	};
	
	char yourtalents[LIM][SLEN] =
	{
		"Walking in a straight line",
		"Sleeping",
		"Watching television",
		"Mailing letters",
		"Reading email"
	};
	
	int i;
	
	puts("Let's compare talents.");
	printf("%-36s %-25s\n", "My Talents", "Your talents");
	for(i = 0; i < LIM; i++)
		printf("%-36s %-25s\n", mytalents[i], yourtalents[i]);
	printf("\nsizeof mytalents: %lu, sizeof yourtalents: %lu\n",
			sizeof(mytalents), sizeof(yourtalents));
	
	return 0;
}