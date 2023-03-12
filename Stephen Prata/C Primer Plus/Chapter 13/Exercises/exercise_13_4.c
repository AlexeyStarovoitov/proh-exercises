#include "stdio.h"


int main(int argc, char *argv[])
{
	int i;
	
	printf("The list of files mentioned in command lines:\n");
	
	for(i = 1; i <argc; i++)
		printf("%s\n", argv[i]);
	
	return 0;
}