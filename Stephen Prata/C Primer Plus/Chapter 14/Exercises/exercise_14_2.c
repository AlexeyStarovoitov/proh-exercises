#include "stdio.h"
#include "string.h"

#define MON 12

int main(void)
{
	int days, month, year;
	int mondays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};
	int total, i;
	
	printf("Enter days(-1 to quit)\n");
	
	while(scanf("%d", &days) == 1 && days >= 0)
	{
		getchar();
		printf("Enter the month:\n");
		scanf("%d", &month);
		getchar();
		printf("Enter the year:\n");
		scanf("%d", &year);
		getchar();
		
		for(i = 0, total = 0; i < month; i++)
		{
			if((i == 1) && (year % 100 == 0) && (year % 4 == 0) &&
				(year % 400 != 0))
				{
					total += mondays[i] + 1;
					continue;
				}
			total += mondays[i];
		}
		
		total += days;
		
		printf("The total days are %d\n", total);
		printf("Enter days(-1 to quit)\n");
	}
	
	return 0;
	
}