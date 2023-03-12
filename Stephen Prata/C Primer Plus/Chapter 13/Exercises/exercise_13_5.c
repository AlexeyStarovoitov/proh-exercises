//listing_13_5.c -- appends files to a file
#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);


int main(int argc, char *argv[])
{
	FILE *fa, *fs; // fa for append file, fs for source file
	int files = 0; // number of files
	int ch, i;
	

	if((fa = fopen(argv[0], "a+")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	for(i = 2; i < argc; i++)
	{
		if(strcmp(argv[i], argv[0]) == 0)
			fputs("Can't append file to itself\n", stderr);
		else if((fs = fopen(argv[i], "r")) == NULL)
			fprintf(stderr, "Can't open %s\n", argv[i]);
		else
		{
			if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if(ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n",
						argv[i]);
			if(ferror(fa) != 0)
				fprintf(stderr, "Error in writing file %s.\n",
						argv[0]);
			fclose(fs);
			files++;
			printf("File %s appended.\n", argv[i]);
		}
	}
	
	printf("Done appending. %d file appended.\n", files);
	rewind(fa);
	printf("%s contents:\n", argv[0]);
	while((ch =getc(fa)) != EOF)
		putchar(ch);
	puts("Done!");
	fclose(fa);
	
	return 0;
}

void append(FILE *source, FILE *dest)
{
	long unsigned bytes;
	static char temp[BUFSIZE];
	
	while((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}
