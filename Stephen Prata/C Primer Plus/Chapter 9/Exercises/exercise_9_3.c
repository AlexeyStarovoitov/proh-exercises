#include "stdio.h"

void chlines(char ch, int cols, int lines);

int main(void)
{
	int cols, lines;
	char ch;
	
	printf("Enter a character and the number of columns and lines:\n");
	
	while(scanf("%c %d %d", &ch, &cols, &lines) == 3)
	{
		chlines(ch, cols, lines);
		scanf("%c", &ch);
	}
	return 0;
}

void chlines(char ch, int cols, int lines)
{
	int i, j;
	
	for(i = 0; i < lines; i++)
	{
		for(j = 0; j < cols; j++)
			putchar(ch);
			
		putchar('\n');
	}
		
}