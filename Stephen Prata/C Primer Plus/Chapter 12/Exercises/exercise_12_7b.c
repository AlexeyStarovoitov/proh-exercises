#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int roll_n_dice(int dice, int sides);

int main(void)
{
	int dice, roll, sets, i;
	int sides, status;
	
	srand((unsigned int) time(0));
	printf("Enter the number sets; enter q to stop.\n");
	while(scanf("%d", &sets) == 1 && sets > 0)
	{
		printf("How many sides and how many dice? ");
		if((status = scanf("%d %d", &sides, &dice)) != 2)
		{
			if(status == EOF)
				break;
			else
			{
				printf("You should have entered an integer.");
				printf("Let's begin again.\n");
				while(getchar() != '\n')
					continue;
				printf("\nEnter the number sets; enter q to stop.");
				continue;
			}
		}
		
		printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
		
		for(i = 1; i <= sets; i++)
			printf(" %3d", roll_n_dice(dice, sides));
		printf("\nEnter the number sets; enter q to stop. ");
	}
	
	
	return 0;
}