#include "stdio.h"
#include "math.h"

#define LEN 10
#define FUN 4

double my_sqr(double x)
{
	return x*x;
}

double my_cube(double x)
{
	return x*x*x;
}

void transform(double source[], double target[], int n, double (*fp)(double));
char menu(void);
void cleanup(void);

int main(void)
{
	double (*fp[FUN])(double) = {sin, cos, my_sqr, my_cube};
	
	int i;
	char answer;
	double source[LEN], target[LEN];
	
	for(i = 0; i < LEN; i++)
		source[i] = (double)i;
	
	printf("Enter your choice:\n");
	
	while((answer = menu()) != 'e')
	{
		transform(source, target, LEN, fp[answer - 'a']);
		printf("i Source[i], Target[i]\n");
		for(i = 0; i < LEN; i++)
			printf("%d %5.1f %10.1f\n", i, source[i], target[i]);
	}
	
	return 0;
}

char menu(void)
{
	char ans;
	
	printf("a) Sin\n");
	printf("b) Cos\n");
	printf("c) Square\n");
	printf("d) Cube\n");
	printf("e) Quit\n");
	
	ans = getchar();
	
	while((ans < 'a') || (ans > 'e'))
	{
		cleanup();
		printf("Try again!\n");
		ans = getchar();
	}
	cleanup();
	
	return ans;
}

void transform(double source[], double target[], int n, double (*fp)(double))
{
	int i;
	for(i = 0; i < n; i++)
		target[i] = (*fp)(source[i]);
}

void cleanup(void)
{
	while(getchar() != '\n')
		;
}