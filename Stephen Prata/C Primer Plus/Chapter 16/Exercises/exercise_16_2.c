#include "stdio.h"
#include "math.h"

#define HARM_MEAN(X,Y) (2.0/(1.0/(X) + 1.0/(Y)))
#define DELTA 0.002

int main(void)
{
	double x, y;
	
	printf("Enter two nonzero numbers:\n");
	
	while((scanf("%lf %lf", &x, &y) == 2) && ((fabs(x) > DELTA) || (fabs(y) > DELTA)))
	{
		printf("The harmonic mean of %.3f and %.3f is %.3f\n", x, y, HARM_MEAN(x,y));
		printf("Enter two nonzero numbers:\n");
	}
	
	return 0;
}