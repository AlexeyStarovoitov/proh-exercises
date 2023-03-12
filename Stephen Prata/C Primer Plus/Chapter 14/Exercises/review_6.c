//review_6.c -- the answer to the review question 6

#include "stdio.h"
#include "string.h"

typedef struct 
{
	float foclen;
	float fstop;
	char brand[30];
}
LENS;

int main(void)
{
	LENS lens_arr[10] = {[2] = {.brand = "Remarkater", .foclen = 500.0, .fstop = 250.0}};
	
	strcpy(lens_arr[2].brand, "Remarkatar2");
	
}