#include "stdio.h"

void Temperatures(double temp);

int main(void)
{
	double temp;
	
	printf("Enter the temperature in Fahrenheit: ");
	
	while(scanf("%lf", &temp) == 1)
	{
		Temperatures(temp);
		printf("Enter the temperature in Fahrenheit: ");
	}
	
	return 0;
}

void Temperatures(double temp)
{
	const double FACTOR_CEL = 5.0/9.0;
	const double ADJUST_CEL = 32.0;
	const double ADJUST_KEL = 273.16;
	
	double Celsius = FACTOR_CEL*(temp-ADJUST_CEL);
	double Kelvin = Celsius + ADJUST_KEL;
	
	printf("Temperature in Fahrenheit: %.2f\n", temp);
	printf("Temperature in Celsius: %.2f\n", Celsius);
	printf("Temperature in Kelvin: %.2f\n", Kelvin);
	
}