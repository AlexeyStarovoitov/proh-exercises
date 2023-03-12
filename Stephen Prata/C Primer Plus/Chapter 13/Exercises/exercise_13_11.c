#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define SLEN 256

int main(int argc, char *argv[])
{
	FILE *fp;
	char st[SLEN];
	
	if(argc != 3)
	{
		printf("Usage: %s arg1: string, arg2: filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("Can't open the %s file\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	while(fgets(st, SLEN, fp))
		if(strstr(st, argv[1]))
			fputs(st, stdout);
	
	fclose(fp);
	return 0;
}