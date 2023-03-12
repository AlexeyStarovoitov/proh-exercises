#include "stdio.h"
#include "exercise_12_2a.h"

static int mode = 0; 
static int distance;
static double fuel;

void set_mode(int in_mode)
{
	if (in_mode > US_MODE)
		printf("Invalid mode specified. Mode %d (%s) used\n", mode, 
				mode == EU_MODE ? "Europe":"US");	
	else
		mode = in_mode;
	
}

void get_info(void)
{
	switch(mode)
	{
		case EU_MODE:
			printf("Enter distance traveled in kilometers: ");
			scanf("%d", &distance);
			printf("Enter fuel consumed in liters: ");
			scanf("%lf", &fuel);
			break;
		case US_MODE:
			printf("Enter distance traveled in miles: ");
			scanf("%d", &distance);
			printf("Enter fuel consumed in gallons: ");
			scanf("%lf", &fuel);
			break;
	}
}

void show_info(void)
{
	switch(mode)
	{
		case EU_MODE:
			printf("Fuel consumption is %.2f per 100 km.\n",
					fuel/distance*100.0);
			break;
		case US_MODE:
			printf("Fuel consumption is %.1f miles per gallon.\n",
					distance/fuel);
			break;
	}
}

