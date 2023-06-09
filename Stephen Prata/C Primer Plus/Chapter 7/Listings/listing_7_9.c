//listing_7_9.c -- uses continue to skip part of loop

#include "stdio.h"

int main(void)
{
	const float MIN = 0.0f;
	const float MAX = 100.0f;
	
	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;
	
	printf("enter the first score (q to quit): ");
	while(scanf("%f", &score) == 1)
	{
		if (score < MIN || score > MAX)
		{
			printf("%0.1f is an invalid value. Try again: ", score);
			continue;
		}
		
		printf("Accepting %0.1f\n", score);
		min = (score < min) ? score:min;
		max = (score > max) ? score:max;
		total += score;
		n++;
		printf("Enter next score: ");
	}
	
	if(n > 0)
	{
		printf("Average of %d scores is %0.1f.\n", n, total / n);
		printf("Low %0.1f, high = %0.1f\n", min, max);
	}
	
	return 0;
}