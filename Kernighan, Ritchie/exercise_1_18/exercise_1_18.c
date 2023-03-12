#include "stdio.h"
#include "stdlib.h"

#define MAXLINE 10
#define STPCHR 'z'

int getline1(char line[], int pos, int maxline);
void copy(char to[], char from[]);

void main(void)
{
	int len, pos, i, j, inter_max, maxline, flag;
	maxline = MAXLINE;
	char *line, *inter_arr, *inter_arr2;
	line = (char*) calloc(maxline, sizeof(char));
	while((len = getline1(line, 0, maxline)) > 0)
	{
		while(line[len-1] != '\n')
		{
			inter_max = maxline;
			inter_arr = (char*) calloc(maxline, sizeof(char));
			copy(inter_arr, line);
			maxline += MAXLINE;
			free(line);
			pos = inter_max;
			line = (char*) calloc(maxline, sizeof(char));
			copy(line, inter_arr);
			free(inter_arr);
			len = getline1(line, pos, maxline);
		}
		
		inter_arr2 = (char*) calloc(maxline, sizeof(char));
		flag = 0;
		for (i = len-2; ((line[i] != ' ') || (line[i] != '\t')) && (i >= 1); i--)
			if (((line[i] == ' ') && (line[i-1] == ' ')) || ((line[i] == ' ') && (line[i-1] == '\t')) || ((line[i] == '\t') && (line[i-1] == ' ')) || ((line[i] == '\t') && (line[i-1] == '\t')))
			{
				flag = 1;
				inter_max = i+1;
				free(inter_arr2);
				inter_arr2 = (char*) calloc(inter_max, sizeof(char));
				for(j = 0; j < inter_max - 1; j++)
					inter_arr2[j] = line[j];
				inter_arr2[inter_max - 1] = '\n';
				inter_arr2[inter_max] = '\0';
			}
		
		if (flag == 0)
			printf("%s\n", line);
		else
			printf("%s\n", inter_arr2);
	}
}

int getline1(char line[], int pos, int maxline)
{
	int i, c;
	for(i = pos; (i < maxline - 1) && ((c = getchar()) != STPCHR) && (c != '\n'); i++)
		line[i] = c;
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