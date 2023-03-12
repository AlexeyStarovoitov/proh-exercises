#include "stdio.h"

#define MIN_IN_HR 60

int main(void)
{
	int min, hours, left;
	
	printf("Enter time in minutes\n");
	printf("To exit the program, enter 0 or value less than 0\n");
	scanf("%d", &min);
	while(min > 0)
	{
		hours = min / MIN_IN_HR;
		left = min % MIN_IN_HR;
		printf("Your time is %d hours, %d minutes\n", hours, left);
		
		printf("Enter time in minutes\n");
		printf("To exit the program, enter 0 or value less than 0\n");
		scanf("%d", &min);
	}
	
	return 0;
}