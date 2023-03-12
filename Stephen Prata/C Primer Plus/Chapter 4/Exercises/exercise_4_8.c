#include "stdio.h"

#define GALLONS_TO_LTRS 3.785
#define MILES_TO_KLM 1.609

int main(void)
{
	float miles, gallons;
	float miles_per_gal, liters_per_100km;
	
	printf("Enter the number of milles and the number of gallons\n");
	scanf("%f %f", &miles, &gallons);
	
	miles_per_gal = miles/gallons;
	liters_per_100km = 100/(miles_per_gal * MILES_TO_KLM / GALLONS_TO_LTRS);
	
	printf("Miles-per-gallon: %.1f\n", miles_per_gal);
	printf("Litter_per_100km: %.1f", liters_per_100km);
	
	return 0;
	
}