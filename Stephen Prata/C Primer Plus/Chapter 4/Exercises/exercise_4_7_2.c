#include "stdio.h"
#include "float.h"

int main(void)
{
	double val2;
	
	val2 = 1.0/3.0;
	
	printf("%.4f %.12f %.16f\n", val2);
	
	printf("%d", DBL_DIG);
	
	return 0;
}