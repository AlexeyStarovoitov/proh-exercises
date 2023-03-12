#include "stdio.h"
#include "exercise_12_3a.h"


void set_mode(int mode, int *rec_mode)
{
	if (mode > US_MODE)
	{
		printf("Invalid mode specified. Mode %d (%s) used\n", *rec_mode, 
				*rec_mode == EU_MODE ? "Europe":"US");
		get_info(*rec_mode);
	}
	else
	{
		*rec_mode = mode;
		get_info(mode);
	}
}

void get_info(int mode)
{
	int distance;
	double fuel;
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
	
	show_info(mode, distance, fuel);
}

void show_info(int mode, int distance, double fuel)
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

