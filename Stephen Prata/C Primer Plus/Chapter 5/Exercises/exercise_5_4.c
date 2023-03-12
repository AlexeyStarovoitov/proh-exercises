#include "stdio.h"

#define CEN_IN_FEET 30.48
#define CEN_IN_INCH 2.54

int main(void)
{
	float height_cen, inches;
	int feet;
	
	printf("Enter a height in centimeters\n");
	printf("Enter zero or negative value to exit\n");
	scanf("%f", &height_cen);
	
	while(height_cen > 0.0)
	{
		feet = (int)(height_cen / CEN_IN_FEET);
		inches = (float)((height_cen - feet*CEN_IN_FEET)/CEN_IN_INCH);
		
		printf("%.1f cm = %d feet, %.1f inches\n", height_cen, feet, inches);
		
		printf("Enter a height in centimeters\n");
		printf("Enter zero or negative value to exit\n");
		scanf("%f", &height_cen);
	}
	
	printf("bye\n");
	return 0;
}
