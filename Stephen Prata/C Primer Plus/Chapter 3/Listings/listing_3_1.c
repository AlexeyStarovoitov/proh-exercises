#include "stdio.h"

int main(void)
{
	float weight;
	float value;
	
	printf("Enter your weight in pounds: ");
	scanf("%f", &weight);
	// platinum is 1700.0 per ounce
	// 1 pound = 14.5833 ounces troy
	
	value = weight * 1700.0 * 14.5833;
	printf("Your weight in platinum is %.2f\n", value);
	
	return 0;
}