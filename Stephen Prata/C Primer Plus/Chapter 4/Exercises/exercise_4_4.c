#include "stdio.h"

#define NAME_LEN 30 

int main(void)
{
	float height_cen;
	char name[NAME_LEN];
	
	printf("Please, enter your height in centimeters and your name\n");
	scanf("%f %s", &height_cen, name);
	printf("%s, you are %.3f meeters tall", name, height_cen/100);
	
	return 0;
	
}