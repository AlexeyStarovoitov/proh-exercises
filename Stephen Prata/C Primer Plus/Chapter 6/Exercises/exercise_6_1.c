#include "stdio.h"

#define SIZE 26

int main(void)
{
	char ch, alph[SIZE];
	int i;
	for(i = 0, ch = 'a'; ch < 'a'+ SIZE; i++,ch++)
	{
		alph[i] = ch;
		printf("%c ", alph[i]);
	}
	
	return 0;
	
}