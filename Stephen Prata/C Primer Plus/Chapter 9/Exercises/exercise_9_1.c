#include "stdio.h"

double min(double x, double y)
{ return x < y ? x:y; }

int main(void)
{
	double a, b;
	
	printf("Enter two double values:\n");
	
	while(scanf("%lf %lf", &a, &b) == 2)
		printf("The minimal of %.3f and %.3f is %.3f\n",
				a, b , min(a,b));
	return 0;
}