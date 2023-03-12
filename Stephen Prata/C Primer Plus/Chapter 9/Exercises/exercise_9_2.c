#include "stdio.h"

void chline(char ch, int col1, int col2);

int main(void)
{
	int i, j;
	char ch;
	
	printf("Enter a character and column numbers:\n");
	
	while(scanf("%c %d %d", &ch, &i, &j) == 3)
	{
		chline(ch, i, j);
		scanf("%c", &ch);
	}
	return 0;
}

void chline(char ch, int col1, int col2)
{
	int i;
	
	for(i = 1; i < col1; i++)
		putchar(' ');
	
	for(i = col1; i <= col2; i++)
		putchar(ch);
	
	putchar('\n');
	
}