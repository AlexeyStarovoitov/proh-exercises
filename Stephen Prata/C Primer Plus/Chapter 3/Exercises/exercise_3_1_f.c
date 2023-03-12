#include "stdio.h"

int main(void) // overflow and underflow
{
	float toobig = 3.4E38 * 100.0f;
	float toosmall = 0.123456E-44;
	
	printf("Overflow: \n");
	printf("%e\n", toobig);
	
	printf("Underflow: \n");
	printf("%e %e\n", toosmall, toosmall/2);
	
	return 0;
}