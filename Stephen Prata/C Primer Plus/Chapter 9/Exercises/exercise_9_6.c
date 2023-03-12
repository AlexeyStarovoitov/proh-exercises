#include "stdio.h"

void swap(double *x, double *y)
{
	double temp;
	
	temp = *x;
	*x = *y;
	*y = temp;
}

void order(double *first, double *second, double *third)
{
	if (*second < *first)
		swap(first, second);
	if (*third < *second)
		swap(third, second);
	if (*second < *first)
		swap(first, second);
}

int main(void)
{
	double val1, val2, val3;
	
	printf("Enter three double values:\n");
	
	while(scanf("%lf %lf %lf", &val1, &val2, &val3) == 3)
	{
		order(&val1, &val2, &val3);
		printf("Now the first is %.3f and the second is %.3f"
				" and the third is %.3f\n", val1, val2, val3);			
	}
	return 0;
}