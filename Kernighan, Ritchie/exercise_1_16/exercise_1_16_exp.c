#include "stdio.h"
#include "stdlib.h"

#define STOPCHR 'z'
#define STEP 10

int getline1(char *line, int pos, int maxline);
void copy1(char *to, char *from, int pos);


void main(void)
{
	char *line, *longest;
	char *inter_arr;
	int maxline = 5;
	int i, len, max, pos, inter_max;
	line = (char *) calloc(maxline, sizeof(char));
	longest = (char *) calloc(maxline, sizeof(char));
	inter_arr = (char *) calloc(maxline, sizeof(char));
	max = 0;
	while((len = getline1(line, 0, maxline)) > 0)
	{
		while(line[len-1] != '\n')
		{
			inter_max = maxline;
			pos = len;
			maxline = maxline + STEP;
			free(inter_arr);
			inter_arr = (char *) calloc(maxline, sizeof(char));
			for(i = 0; i < inter_max-1; i++)
				inter_arr[i] = line[i];
			free(line);
			line = (char *) calloc(maxline, sizeof(char));
			for(i = 0; i < inter_max-1; i++)
				line[i] = inter_arr[i];
			len = getline1(line, pos, maxline);
		}
		if (len > max)
		{
			max = len;
			free(longest);
			longest = (char *) calloc(maxline, sizeof(char));
			for(i = 0; i <= len; i++)
				longest[i] = line[i];
		}
		free(line);
		line = (char *) calloc(maxline, sizeof(char));
	}
	printf("%s", longest);
	
}

int getline1(char *line, int pos, int maxline)
{
	int i, c;
	for (i = pos; i< maxline - 1 && (c = getchar()) !=  STOPCHR && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		i++;
	}
	line[i] = '\0';
	return i;
}

void copy1(char *to, char *from, int pos)
{
	int i;
	i = pos;
	while ((to[i] = from[i]) != '\0')
		i++;
}