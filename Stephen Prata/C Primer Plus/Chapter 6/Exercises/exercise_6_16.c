#include "stdio.h"

int main(void)
{
	const float INIT = 100.0f;
	const float PER_SIM = 0.1f;
	const float PER_COM = 0.05f;
	
	float sum_sim = INIT;
	float sum_com = sum_sim;
	int years = 0;
	
	do
	{
		years++;
		sum_sim += INIT*PER_SIM;
		sum_com *= (1.0f + PER_COM);
		
	}while(sum_sim >= sum_com);
	
	printf("years: %d\n", years);
	printf("Daphne: %.2f, Deirde: %.2f", sum_sim, sum_com);
	
	return 0;
}