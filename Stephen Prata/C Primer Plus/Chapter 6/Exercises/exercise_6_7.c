#include "stdio.h"
#include "string.h"

#define LENGTH 30

int main(void)
{
	char word[LENGTH], ch;
	int last, i;
	
	printf("Enter a word: ");
	scanf("%s", word);
	last = strlen(word);
	
	for(i = 0; i < last; i++)
		printf("%c", word[i]);
	
	printf("\n");
	
	
	for(i = 0; i < (last / 2); i++)
	{
		ch = word[i];
		word[i] = word[last-1-i];
		word[last-1-i] = ch;
	}
	
	for(i = 0; i < last; i++)
		printf("%c", word[i]);
	
	return 0;
}