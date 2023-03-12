#include "stdio.h"
#include "string.h"

#define SIZE 255

int main(void)
{
	char line[SIZE], ch;
	int i, last;
	
	printf("Please, enter your line: \n");
	for(i = 0, scanf("%c", &ch); ch != '\n'; i++, scanf("%c", &ch))
		line[i] = ch;
	
	last = strlen(line);
	
	for(i = 0; i < last/2; i++)
	{
		ch = line[i];
		line[i] = line[last-1-i];
		line[last-1-i] = ch;
	}
	
	for(i = 0; i < last; i++)
		printf("%c", line[i]);
	
	return 0;
}