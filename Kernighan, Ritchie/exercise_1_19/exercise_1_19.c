#include "stdio.h"
#include "stdlib.h"

#define STOPCHR 'z'
#define STEP 10

int getline1(char *line, int pos, int maxline);
void copy1(char *to, char *from, int pos);
void reverse(char s[], int len);


void main(void)
{
	char *line, *longest;
	char *inter_arr;
	int maxline = 5;
	int i, len, pos, inter_max;
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
			for(i = 0; i < inter_max-1; i++)
				inter_arr[i] = line[i];
			free(line);
			line = (char *) calloc(maxline, sizeof(char));
			for(i = 0; i < inter_max-1; i++)
				line[i] = inter_arr[i];
			len = getline1(line, pos, maxline);
		}
		
		reverse(line, len);
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

void copy1(char *to, char *from, int pos)
{
	int i;
	i = pos;
	while ((to[i] = from[i]) != '\0')
		i++;
}

void reverse(char s[], int len)
{
	int len1 = len - 1;
	int i;
	char t;
	for (i = 0; i <= (len1 - 1)/2 - 1; i++)
	{
		t = s[i];
		s[i] = s[len1-i];
		s[len1-i] = t;
	}
	printf("%s\n", s);
}