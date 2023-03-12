#include "stdio.h"
#include "stdlib.h"

int main( int argc, char * argv[])
{
	char *end;
	int power;
	double base;
	double power_res = 1.0;
	
	base = strtod(argv[1], &end);
	power = atoi(argv[2]);
	
	if(power < 0)
	{
		power = - power;
		
		while(power-- > 0)
		{
			power_res /= base;
		}
	}
	else
		while(power-- > 0)
			power_res *= base;
	
	printf("The result is %.3f\n", power_res);
	
	return 0;
}