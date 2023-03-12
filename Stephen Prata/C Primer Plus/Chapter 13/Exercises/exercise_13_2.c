#include <stdio.h>
#include "stdlib.h"
#include "string.h"
#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);


int main(int argc, char *argv[])
{
	FILE *fa, *fs; // fa for append file, fs for source file
	int ch;
	
	if((fa = fopen(argv[1], "ab+")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	
	if(strcmp(argv[1], argv[2]) == 0)
		fputs("Can't append file to itself\n", stderr);
	else if((fs = fopen(argv[2], "rb")) == NULL)
		fprintf(stderr, "Can't open %s\n", argv[2]);
	else
	{
		if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
		{
			fputs("Can't create input buffer\n", stderr);
			exit(EXIT_FAILURE);
		}
		append(fs, fa);
		if(ferror(fs) != 0)
			fprintf(stderr, "Error in reading file %s.\n",
						argv[2]);
		if(ferror(fa) != 0)
			fprintf(stderr, "Error in writing file %s.\n",
						argv[1]);
		fclose(fs);
		printf("File %s appended.\n", argv[2]);
	}
	
	
	rewind(fa);
	printf("%s contents:\n", argv[1]);
	while((ch =getc(fa)) != EOF)
		putchar(ch);
	printf("\nDone!");
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

