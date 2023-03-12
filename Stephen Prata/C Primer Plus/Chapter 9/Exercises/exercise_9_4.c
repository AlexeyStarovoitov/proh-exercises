#include "stdio.h"

double harmonic_mean(double val1, double val2)
{ 
	return 1.0/(2.0*(1.0/val1 + 1.0/val2)); 
}

int main(void)
{
	double val1, val2;
	
	printf("Enter two double values:\n");
	
	while(scanf("%lf %lf", &val1, &val2) == 2)
	{
		printf("The harmonic mean of %.3f and %.3f is %.3f\n",
				val1, val2, harmonic_mean(val1, val2));
				
	}
	return 0;
}
