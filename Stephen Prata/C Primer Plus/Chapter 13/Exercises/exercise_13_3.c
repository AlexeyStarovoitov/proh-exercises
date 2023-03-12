#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"
#define SLEN 81

void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);


int main(void)
{
	FILE *fa, *fs; // fa for append file, fs for source file
	char file_app[SLEN]; // name of append file
	char file_src[SLEN]; // name of source file
	int ch;
	
	puts("Enter name of destination file.");
	s_gets(file_app, SLEN);
	if((fa = fopen(file_app, "a+")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", file_app);
		exit(EXIT_FAILURE);
	}
	puts("Enter name of the source file:");
	if(s_gets(file_src, SLEN) && file_src[0] != '\0')
	{
		if(strcmp(file_src, file_app) == 0)
			fputs("Can't append file to itself\n", stderr);
		else if((fs = fopen(file_src, "r")) == NULL)
			fprintf(stderr, "Can't open %s\n", file_src);
		else
		{
			append(fs, fa);
			if(ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s.\n",
						file_src);
			if(ferror(fa) != 0)
				fprintf(stderr, "Error in writing file %s.\n",
						file_app);
			fclose(fs);
			printf("File %s appended.\n", file_src);
		}
	}
	
	rewind(fa);
	printf("%s contents:\n", file_app);
	while((ch =getc(fa)) != EOF)
		putchar(ch);
	puts("Done!");
	fclose(fa);
	
	return 0;
}

void append(FILE *source, FILE *dest)
{
	static char temp[SLEN];
	int i;
	
	while(fgets(temp, SLEN, source))
		for(i = 0; temp[i] != '\0'; i++)
			putc(toupper(temp[i]), dest);
}

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}