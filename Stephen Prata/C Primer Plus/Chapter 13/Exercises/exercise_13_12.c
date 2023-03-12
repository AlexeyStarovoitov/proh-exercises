#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define GRAD 10
#define ROWS 20
#define COLS 30
#define SLEN (2*COLS+1)

void read_file(int mas[][COLS], FILE *fp);

int main(int argc, char *argv[])
{
	int i, j;
	int pict_int[ROWS][COLS];
	char pict_sym[ROWS][COLS+1];
	char syms[GRAD] = {' ', '.', ',', '\'', '~', '*', ':', '=', '%', '#'};
	FILE *fp, *fp_out;
	
	if((fp = fopen(argv[1], "r")) == NULL)
		exit(EXIT_FAILURE);
	
	read_file(pict_int, fp);
	
		
	for(i = 0; i < ROWS; i++)
		for(j = 0; j < COLS; j++)
			pict_sym[i][j] = syms[pict_int[i][j] % GRAD];
	
	for(i = 0, j = COLS; i < ROWS; i++)
		pict_sym[i][j] = '\0';
	
	fp_out = fopen("picture_out.txt", "w");
	for(i = 0; i < ROWS; i++)
	{
		fputs(pict_sym[i], stdout);
		fputs("\n", stdout);
		
		fputs(pict_sym[i], fp_out);
		fputs("\n", fp_out);
	}
	
		
	fclose(fp);
	fclose(fp_out);
	
	return 0;
	
	
}

void read_file(int mas[][COLS], FILE *fp)
{
	char temp[SLEN];
	int i, j;
	
	
	for(i = 0; i < ROWS; i++)
	{
		fgets(temp, SLEN, fp);
		for(j = 0; j < COLS; j++)
			mas[i][j] = (temp[j*2] - '0');
		
	}
		
}