#include "stdio.h"
#include "stdlib.h"

#define MAXLINE 10
#define STPCHR 'z'

int getline1(char line[],  int pos, int maxline);
void copy(char to[], char from[]);

void main(void)
{
	int c, len, pos, inter_max;
	char *line;
	char *inter_arr;
	int maxline = MAXLINE;
	line = (char*) calloc(maxline, sizeof(char));
	
	while(len = getline1(line, 0, maxline))
	{
		while(line[len-1] != '\n')
		{
			inter_arr = (char*) calloc(maxline, sizeof(char));
			copy(inter_arr, line);
			inter_max = maxline;
			maxline = maxline + MAXLINE;
			free(line);
			line = (char *) calloc(maxline, sizeof(char));
			copy(line, inter_arr);
			free(inter_arr);
			pos = inter_max;
			len = getline1(line, pos, maxline);
		}
		if (len >= MAXLINE)
		{
			printf("%s\n", line);
		}
		free(line);
		line = (char*) calloc(maxline, sizeof(char));
	}
}

int getline1(char line[], int pos, int maxline)
{
	char c;
	int i;
	for (i = pos; (i < maxline - 1) && ((c = getchar()) != STPCHR) && (c != '\n'); i++)
	{
		line[i] = c;
	}		
	if (c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i = 0;
	while((to[i] = from[i]) != '\0')
		i++;
}