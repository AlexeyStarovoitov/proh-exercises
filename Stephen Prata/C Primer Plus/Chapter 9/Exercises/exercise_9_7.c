#include "stdio.h"
#include "ctype.h"

#define ALPH_BEGIN 'a'
#define NOT_ALPHA -1

int letter_chk(int ch)
{
	if(isalpha(ch))
	{
		ch = tolower(ch);
		return ch - ALPH_BEGIN + 1;
	}
	else
		return NOT_ALPHA;
}

int main(void)
{
	int ch, pos;
	
	printf("Please, enter your text:\n");
	
	while((ch = getchar()) != EOF)
	{
		pos = letter_chk(ch);
		if  (pos > 0)
			printf("%c - %d\n", ch, pos);
		else
			printf("%c is not a letter\n", ch);
	}
	
	return 0;
}