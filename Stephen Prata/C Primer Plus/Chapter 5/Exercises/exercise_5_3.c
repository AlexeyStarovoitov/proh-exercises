#include "stdio.h"

#define DAYS_IN_WEEK 7

int main(void)
{
	int days, weeks, left;
	
	printf("Enter number of days\n");
	printf("To exit the program, enter 0 or value less than 0\n");
	scanf("%d", &days);
	while(days > 0)
	{
		weeks = days / DAYS_IN_WEEK;
		left = days % DAYS_IN_WEEK;
		printf("%d days are %d weeks, %d days\n", days, weeks, left);
		
		printf("Enter number of days\n");
		printf("To exit the program, enter 0 or value less than 0\n");
		scanf("%d", &days);
	}
	
	return 0;
}