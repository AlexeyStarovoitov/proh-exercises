//listing_13_2.c -- reduces your file by two-thirds

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LEN 50

char *s_gets(char *st, int len);

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	char name_out[LEN];
	int count = 0;
	int length;
	char *orig;
	char *pos;
	
	printf("Please, enter the input filename:\n");
	if(s_gets(name, LEN) == NULL)
		exit(EXIT_FAILURE);
	
	if((in = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file %s\n",
				name);
		exit(EXIT_FAILURE);
	}
	pos = strchr(name, '.');
	orig = (char *)malloc(sizeof(char)*((int)(pos - name)+1));
	strncpy(orig, name, (int)(pos - name));
	*(orig + (int)(pos - name)) = '\0';
	length = LEN - 1 - strlen("_red.txt");
	strncpy(name_out, orig, length);
	name_out[length] = '\0';
	strcat(name_out, "_red.txt");
	free(orig);
	if((out = fopen(name_out, "w")) == NULL)
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

char *s_gets(char *st, int len)
{
	char *find;
	char *status;

	status = fgets(st, len, stdin);
	
	if(status)
	{
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return status;
}