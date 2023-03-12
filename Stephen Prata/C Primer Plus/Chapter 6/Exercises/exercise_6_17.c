#include "stdio.h"

int main(void)
{
	const float percent = 0.08f;
	const float withdraw = 1e5f;
	
	float sum = 1e6f;
	int years = 0;
	
	while(sum > 0.0f)
	{
		sum *= (1.0f + percent);
		sum -= withdraw;
		
		years++;
		
	}
	
	printf("years for Chuckie Lucky: %d\n", years);
	
	return 0;
}