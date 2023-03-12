#include "stdio.h"

float fl_val(float a, float b);

int main(void)
{
	float a, b;
	
	printf("Enter two floating-point numbers (q to quit): ");
	
	while(scanf("%f %f", &a,&b) == 2)
	{
		printf("Out value is %f\n", fl_val(a,b));
		printf("Enter two floating-point numbers (q to quit): ");
	}
	
	return 0;
}

float fl_val(float a, float b)
{
	return (a-b)/(a*b);
}