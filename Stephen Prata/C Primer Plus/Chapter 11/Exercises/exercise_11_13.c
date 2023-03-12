#include "stdio.h"

int main(int argc, char *argv[])
{
	int i;
	
	printf("Your arguments in reversed order:\n");
	
	for(i = argc - 1; i >= 1; i--)
		printf("%s ", argv[i]);
	
	return 0;
}