#include "stdio.h"

int main(void)
{
	int val;
	int sum_even, sum_odd;
	int ev_cnt, odd_cnt;
	float ev_aver, odd_aver;
	sum_even = sum_odd = ev_cnt = odd_cnt = 0;
	
	printf("Enter your integers:\n");
	while(scanf("%d", &val) == 1 && val != 0)
	{
		if(val % 2 == 0)
		{
			sum_even += val;
			ev_cnt++;
		}
		else
		{
			sum_odd += val;
			odd_cnt++;
		}
	}		
	
	if(ev_cnt != 0)
	{
		ev_aver = (float)sum_even/ev_cnt;
		printf("The total number of even integers " 
				"are %d, average is %.3f\n", ev_cnt, ev_aver);
		
	}
	else
		printf("The total number of even integers is 0\n");
		
	if(odd_cnt != 0)
	{
		odd_aver = (float)sum_odd/odd_cnt;
		printf("The total number of odd integers " 
				"are %d, average is %.3f\n", odd_cnt, odd_aver);
		
	}
	else
		printf("The total number of odd integers is 0\n");
	
	return 0;
		
}