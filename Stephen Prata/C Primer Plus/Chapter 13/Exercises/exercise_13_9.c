#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];
	static long unsigned num = 0UL;
	
	if((fp = fopen("wordy.txt", "a+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy.txt\" file.\n");
		exit(EXIT_FAILURE);
	}
	
	rewind(fp);
	while(fscanf(fp, "%40s", words) == 1)
		num++;
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	
	while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	{
		num++;
		fprintf(fp, "%lu.", num);
		fprintf(fp, "%s\n", words);
		
	}
		
	
	puts("File contents:");
	rewind(fp);
	while(fscanf(fp, "%40s", words) == 1)
		puts(words);
	
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	
	return 0;
}