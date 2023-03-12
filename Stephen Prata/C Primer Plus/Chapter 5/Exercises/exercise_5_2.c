#include "stdio.h"

#define PER 10

int main(void)
{
	int val, i;
	
	printf("Enter value\n");
	scanf("%d", &val);
	i = val-1;
	
	while(i++ < (val + PER))
		printf("%d\t", i);
	
	return 0;
}