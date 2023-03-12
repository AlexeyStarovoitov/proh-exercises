#include "stdio.h"

void larger_of(double *x, double *y)
{ 
	 *x = *y = (*x > *y ? *x:*y);
}

int main(void)
{
	double val1, val2;
	
	printf("Enter two double values:\n");
	
	while(scanf("%lf %lf", &val1, &val2) == 2)
	{
		larger_of(&val1, &val2);
		printf("Now the first is %.3f and the second is %.3f\n", val1, val2);
				
	}
	return 0;
}
