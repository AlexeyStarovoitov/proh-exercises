#include "math.h"
#include "stdio.h"

#define DELTA 0.001

double power(double n, int p);

int main(void)
{
	double num, pow;
	int p;
	
	printf("Enter the base and the power:\n");
	
	while(scanf("%lf %d", &num, &p) == 2)
	{
		pow = power(num, p);
		printf("%.3f to %d is %.3f\n", num, p , pow);
		printf("Enter the base and the power:\n");
	}
	
	return 0;
}


double power(double n, int p)
{
	double pow;
	
	if(fabs(n) < DELTA)
	{
		if(p == 0)
		{
			printf("0 to the 0 is undefined. The used value is 1.\n");
			pow = 1.0;
		}
		else
			pow = 0.0;		
	}
	else
	{
		if(p >= 0)
		{
			if(p > 0)
				pow = n *power(n, p-1);
			else
				pow = 1.0;
		}
		else
		{
			if(p < 0)
				pow = power(n, p+1)/n;
			else
				pow = 1.0;
		}
	}
	
	return pow;
}

