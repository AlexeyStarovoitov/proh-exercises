#include "stdio.h"

int main(void) // receives age in years and returns age in seconds
{
	double sec_in_yr = 3.156E7;
	double age;
	
	printf("Print your age in years:");
	scanf("%lf", &age);
	printf("Your age in seconds is: %lf", age*sec_in_yr);
	
	return 0;
	
}

