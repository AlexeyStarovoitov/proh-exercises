#include "stdio.h"
#include "float.h"

int main(void)
{
	
	float val1 = 1.0/3.0;
	
	printf("%.4f %.12f %.16f\n", val1);
	
	printf("%d", FLT_DIG);
	
	return 0;
}