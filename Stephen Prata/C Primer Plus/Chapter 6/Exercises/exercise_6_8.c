#include "stdio.h"

int main(void)
{
	float a, b, val;
	
	printf("Enter two floating-point numbers (q to quit): ");
	
	while(scanf("%f %f", &a,&b) == 2)
	{
		val = (a-b)/(a*b);
		printf("Out value is %f\n", val);
		printf("Enter two floating-point numbers (q to quit): ");
	}
	
	return 0;
}