//listing_17_9.c -- use the Queue interface

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "queue.h"

#define MIN_PER_HR 60.0

bool newcustomer(double x); // is there is a new customer
Item customertime(long when); // set customer parameters

int main(void)
{
	Queue line, line2;
	Item temp;
	int hours, hours2; //hours of simulation
	int perhour, perhour2; // average number of arrivals per hour
	long cycle, cycle2, cyclelimit, cyclelimit2;
	long turnaways = 0;
	long turnaways2 = 0;
	long customers = 0;
	long customers2 = 0;
	long served = 0;
	long served2 = 0;
	long sum_line = 0; // cumulative line length
	long sum_line2 = 0; // cumulative line length
	int wait_time = 0; // time until Sigmund is free
	int wait_time2 = 0; // time until Sigmund is free
	double min_per_cust; // average time between arrivals
	double min_per_cust2; // average time between arrivals
	long line_wait = 0; // cumulative time in line
	long line_wait2 = 0; // cumulative time in line
	
	
	InitializeQueue(&line);
	InitializeQueue(&line2);
	srand((unsigned int)time(0));
	
	puts("Case study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours for first queue:");
	scanf("%d", &hours);
	puts("Enter the number of simulation hours for second queue:");
	scanf("%d", &hours2);
	cyclelimit = MIN_PER_HR * hours;
	cyclelimit2 = MIN_PER_HR * hours2;
	puts("Enter the average number of customers per hour for first queue: ");
	scanf("%d", &perhour);
	puts("Enter the average number of customers per hour for second queue: ");
	scanf("%d", &perhour2);
	min_per_cust = MIN_PER_HR / perhour;
	min_per_cust2 = MIN_PER_HR / perhour2;
	
	for(cycle = 0, cycle2 = 0; (cycle < cyclelimit) || (cycle2 < cyclelimit2); cycle++, cycle2++)
	{
		if (cycle < cyclelimit)
		{
			
			if(newcustomer(min_per_cust))
			{
				if(QueueIsFull(&line))
					turnaways++;
				else
				{
					customers++;
					temp = customertime(cycle);
					EnQueue(temp, &line);
				}
			}
			
			if(wait_time <= 0 && !QueueIsEmpty(&line))
			{
				DeQueue(&temp, &line);
				wait_time = temp.processtime;
				line_wait += cycle - temp.arrive;
				served++;
			}
			
			if(wait_time > 0)
				wait_time--;
			sum_line += QueueItemCount(&line);
		}
		
		if (cycle2 < cyclelimit2)
		{
			
			if(newcustomer(min_per_cust2))
			{
				if(QueueIsFull(&line2))
					turnaways2++;
				else
				{
					customers2++;
					temp = customertime(cycle2);
					EnQueue(temp, &line2);
				}
			}
			
			if(wait_time2 <= 0 && !QueueIsEmpty(&line2))
			{
				DeQueue(&temp, &line2);
				wait_time2 = temp.processtime;
				line_wait2 += cycle2 - temp.arrive;
				served2++;
			}
			
			if(wait_time2 > 0)
				wait_time2--;
			sum_line2 += QueueItemCount(&line2);
		}
		
	}
	
	if(customers > 0)
	{
		printf ("First queue:\n");
		printf("customers accepted: %ld\n", customers);
		printf("customers served: %ld\n", served);
		printf("turnaways: %ld\n", turnaways);
		printf("average queue size: %.2f\n", (double)sum_line/cyclelimit);
		printf("average wait time: %.2f minutes\n", (double) line_wait/served);
	}
	else
		puts("No customers!");
	
	if(customers2 > 0)
	{
		printf ("Second queue:\n");
		printf("customers accepted: %ld\n", customers2);
		printf("customers served: %ld\n", served2);
		printf("turnaways: %ld\n", turnaways2);
		printf("average queue size: %.2f\n", (double)sum_line2/cyclelimit2);
		printf("average wait time: %.2f minutes\n", (double) line_wait2/served2);
	}
	else
		puts("No customers!");
	
	EmptyTheQueue(&line);
	EmptyTheQueue(&line2);
	
	return 0;
	
}


/*
x = average time, in minutes, between customers
return value if true if customer shows up this minute
*/

bool newcustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else 
		return false;
		
}

/*
when is the time at which the customer arrives
function returns an Item structure with the arrival time set to when 
and the processing time set to a random value from 1 to 3 
*/

Item customertime(long when)
{
	Item cust;
	
	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;
	
	return cust;
}