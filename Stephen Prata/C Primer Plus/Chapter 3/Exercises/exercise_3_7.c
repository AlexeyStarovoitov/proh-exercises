#include "stdio.h"

int main(void) //converts height to inches
{
	float cen_in_inch = 2.54;
	float height;
	
	printf("Write your height in centimiters: ");
	scanf("%f", &height);
	printf("Your weigth in inches is %f", height/cen_in_inch);
	
	return 0;
	
	
}