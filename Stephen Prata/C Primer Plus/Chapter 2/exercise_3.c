#include "stdio.h"

int main(void)
{
	int age_in_years = 21;
	int days_in_year = 365;
	
	printf("My age in years: %d\n", age_in_years);
	printf("My age in days: %d", age_in_years*days_in_year);
	
	return 0;
}