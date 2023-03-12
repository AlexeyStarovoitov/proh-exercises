#include "stdio.h"

void critic(int *unp);

int main(void)
{
	int units;
	
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", &units);
	
	while(units != 56)
	{
		critic(&units);
		
	}
	
	printf("You must have looked up!\n");
	
	return 0;
}

void critic(int *unp)
{
	printf("No luck, my friend. Try again.\n");
	scanf("%d", unp);
}