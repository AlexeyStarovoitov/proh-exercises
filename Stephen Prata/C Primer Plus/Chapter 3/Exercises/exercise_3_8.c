#include "stdio.h"

int main(void)
{
	float cups_in_pint = 2.0;
	float ounces_in_cup = 8.0;
	float tablespoons_in_ounce = 2.0;
	float teaspoons_in_tablespoon = 3.0;
	
	int cups;
	
	printf("Write volume in cups: ");
	scanf("%d", &cups);
	
	printf("Volume in pints: %f\n", cups/cups_in_pint);
	printf("Volume in ounces: %f\n", cups*ounces_in_cup);
	printf("Volume in tablespoons: %f\n", cups*ounces_in_cup*tablespoons_in_ounce);
	printf("Volume in teaspoons: %f\n", cups*ounces_in_cup*tablespoons_in_ounce*teaspoons_in_tablespoon);
	
	return 0;	
}