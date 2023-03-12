#include "stdio.h"

#define BITS_IN_BYTES 8

int main(void)
{
	float speed, size;
	
	printf("Enter download speed in megabits and " 
	"size of a file in megabytes\n");
	scanf("%f %f", &speed, &size);
	
	printf("At %.2f megabits per second, a file of %.2f megabytes\n"
	"downloads in %.2f seconds.\n", speed, size, size*BITS_IN_BYTES/speed);
	
	return 0;
	
}