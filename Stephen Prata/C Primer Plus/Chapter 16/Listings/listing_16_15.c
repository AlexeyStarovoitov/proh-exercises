//listing_16.15.c -- defining generic macros

#include "stdio.h"
#include "math.h"
#define RAD_TO_DEG (180/(4*atan(1)))

#define SQRT(X) _Generic((X),\
	long double: sqrtl,\
	default: sqrt,\
	float: sqrtf)(X)
	
#define SIN(X) _Generic((X),\
		long double: sinl((X)/RAD_TO_DEG),\
		default: sin((X)/RAD_TO_DEG),\
		float: sinf((X)/RAD_TO_DEG)\
	)

int main(void)
{
	float x = 45.0f;
	double xx = 45.0;
	long double xxx = 45.0L;
	int i = 45;
	
	double y = SQRT(x);
	double yy = SQRT(xx);
	double yyy = SQRT(xxx);
	printf("%.17f\n", y);
	printf("%.17f\n", yy);
	printf("%.17f\n", yyy);
	
	yy = SQRT(i);
	printf("%.17f\n", yy);
	yyy = SIN(xxx);
	printf("%.17f\n", yyy);
	
	return 0;
}
		