#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* #define GRAD 10
#define ROWS 20
#define COLS 30
#define SLEN (2*COLS+1) */

void read_file(int rows, int cols, int mas[rows][cols], FILE *fp);

int main(int argc, char *argv[])
{
	int i, j;
	int rows = 20;
	int cols = 30;
	int grad = 10;

	int pict_int[rows][cols];
	char pict_sym[rows][cols+1];
	char syms[] = {' ', '.', ',', '\'', '~', '*', ':', '=', '%', '#'};
	FILE *fp, *fp_out;
	
	if((fp = fopen(argv[1], "r")) == NULL)
		exit(EXIT_FAILURE);
	
	read_file(rows, cols, pict_int, fp);
	
		
	for(i = 0; i < rows; i++)
		for(j = 0; j < cols; j++)
			pict_sym[i][j] = syms[pict_int[i][j] % grad];
	
	for(i = 0, j = cols; i < rows; i++)
		pict_sym[i][j] = '\0';
	
	fp_out = fopen("picture_out.txt", "w");
	for(i = 0; i < rows; i++)
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

void read_file(int rows, int cols, int mas[rows][cols], FILE *fp)
{
	int slen = 2*cols+1;
	char temp[slen];
	int i, j;
	
	
	for(i = 0; i < rows; i++)
	{
		fgets(temp, slen, fp);
		for(j = 0; j < cols; j++)
			mas[i][j] = (temp[j*2] - '0');
		
	}
		
}