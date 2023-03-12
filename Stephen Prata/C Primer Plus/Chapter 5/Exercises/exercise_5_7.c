#include "stdio.h"

void cube(double val);

int main(void)
{
	double val;
	
	printf("Enter your value\n");
	scanf("%lf", &val);
	
	while (val > 0)
	{
		cube(val);
		printf("Enter your value\n");
		scanf("%lf", &val);
	}
	
	
	return 0;
}

void cube(double val)
{
	printf("Your cubed value is %.1f\n", val*val*val);
}