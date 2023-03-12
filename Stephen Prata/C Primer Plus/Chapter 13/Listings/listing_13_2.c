//listing_13_2.c -- reduces your file by two-thirds

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LEN 50

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	int count = 0;
	int length;
	char *orig;
	char *pos;
	
	if(argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	if((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file %s\n",
				argv[1]);
		exit(EXIT_FAILURE);
	}
	pos = strchr(argv[1], '.');
	orig = (char *)malloc(sizeof(char)*((int)(pos - argv[1])+1));
	strncpy(orig, argv[1], (int)(pos - argv[1]));
	*(orig + (int)(pos - argv[1])) = '\0';
	length = LEN - 1 - strlen("_red.txt");
	strncpy(name, orig, length);
	name[length] = '\0';
	strcat(name, "_red.txt");
	free(orig);
	if((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can't crete output file.\n");
		exit(3);
	}
	
	while((ch = getc(in)) != EOF)
		if(count++ % 3 == 0)
			putc(ch, out);
	
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");
	
	return 0;
	
}