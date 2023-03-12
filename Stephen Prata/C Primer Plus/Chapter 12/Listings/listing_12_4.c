//listing_12_4.c -- uses an external variable

#include "stdio.h"

int units = 0;

void critic(void);

int main(void)
{
	extern int units;
	
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	while(units != 56)
		critic();
	printf("You must have looked it up!\n");
	
	return 0;
}

void critic(void)
{
	printf("No luck, my firend. Try again.\n");
	scanf("%d", &units);
}