#include "stdio.h"
#include "ctype.h"

int main(void)
{
	int nw, nu, nl, np, nd;
	int ch;
	
	nw = nu = nl = np = nd = 0;
	
	printf("Enter your text\n");
	
	while((ch = getchar()) != EOF)
	{
		if(isspace(ch))
			nw++;
		if(isalpha(ch))
		{
			if(isupper(ch))
				nu++;
			else
				nl++;
		}
		
		if(ispunct(ch))
			np++;
		if(isdigit(ch))
			nd++;
		
	}
	
	printf("Number of words: %d\n", nw);
	printf("Number of uppercase: %d\n", nu);
	printf("Number of lowercase: %d\n", nl);
	printf("Number of punctuation %d\n", np);
	printf("Number of digits %d\n", nd);
	
	return 0;
}