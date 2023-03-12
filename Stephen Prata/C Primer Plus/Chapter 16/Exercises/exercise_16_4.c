#include "stdio.h"
#include "time.h"


void delay_func(double delay)
{
	double start = (double)(clock()/CLOCKS_PER_SEC);
	double cur_del = (double)(clock()/CLOCKS_PER_SEC) - start;
	
	while(cur_del < delay)
		cur_del = (double)(clock()/CLOCKS_PER_SEC) - start;
}

int main(void)
{
	double t1, del_main;
	double delay;
	
	printf("Enter the desired delay in sec:\n");
	
	while(scanf("%lf", &delay) == 1)
	{
		t1 = (double)(clock()/CLOCKS_PER_SEC);
		delay_func(delay);
		del_main = (double)(clock()/CLOCKS_PER_SEC) - t1;
		printf("The actual delay: %.3f\n", del_main);
		
		printf("Enter the desired delay in sec:\n");
	}
	
	return 0;
}