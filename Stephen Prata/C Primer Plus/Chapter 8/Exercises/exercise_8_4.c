#include "stdio.h"
#include "ctype.h"
#include "stdbool.h"

int main(void)
{
	bool inword = false;
	long sum_let, word_c;
	int ch;
	
	sum_let = word_c = 0L;
	
	printf("Enter your words\n");
	
	while((ch = getchar()) != EOF)
	{
		if(isalnum(ch) && inword == false)
		{
			inword = true;
			word_c++;
		}
		else if(!isalnum(ch) && inword == true)
			inword = false;
		if(isalpha(ch))
			sum_let++;
	}
	
	printf("Number of words: %ld, the sum of letters %ld\n", word_c, sum_let);
	printf("Average number of letters per word is %ld\n",
			sum_let/word_c);
	return 0;
}