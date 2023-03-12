#include "stdio.h"
#include "stdlib.h"

#define STOPCHR 'z'
#define STEP 10
#define TAB 1

int getline1(char *line, int pos, int maxline);
void copy(char *to, char *from);
void entab(int len, int n);

void main(void)
{
	char *line, *inter_arr;
	int maxline = 5;
	int len, pos, i, inter_max, nwhites;
	
	line = (char *) calloc(maxline, sizeof(char));
	inter_arr = (char *) calloc(maxline, sizeof(char));
	
	while((len = getline1(line, 0, maxline)) > 0)
	{
		while(line[len-1] != '\n')
		{
			inter_max = maxline;
			pos = len;
			maxline = maxline + STEP;
			free(inter_arr);
			inter_arr = (char *) calloc(maxline, sizeof(char));
			copy(inter_arr, line);
			free(line);
			line = (char *) calloc(maxline, sizeof(char));
			copy(line, inter_arr);
			len = getline1(line, pos, maxline);
		}
		nwhites = 0;
		for(i = 0; i < len - 1; i++)
			if(line[i] == ' ')
				nwhites++;
		if(nwhites == len - 1)
			entab(len, TAB);
		else
			printf("%s\n", line);
		free(line);
		line = (char *) calloc(maxline, sizeof(char));
	}
	
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

void copy(char *to, char *from)
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
}

void entab(int len, int n)
{
	int i, j;
	char c;
	char *line2;
	int ntabs, nwhites;
	ntabs = (len-1) / n;
	nwhites = (len-1) % n;
	line2 = (char*) calloc(ntabs+nwhites+2, sizeof(char));
	for(i = 0; i < ntabs; i++)
	{
		line2[i] = '\t';
	}
	for(;i<ntabs+nwhites;i++)
	{
		line2[i] = ' ';
	}
	line2[i] = '\n';
	i++;
	line2[i] = '\0';
	printf("%s\n", line2);
}