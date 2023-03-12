#include "stdio.h"

#define SPACE ' '
#define NEWLINE '\n'
#define END '#'

int main(void)
{
	unsigned long sp_c, l_c, o_c;
	char ch;
	
	sp_c = l_c = o_c = 0LU;
	
	printf("Please, enter your text\n");
	while((ch = getchar()) != END)
	{
		if(ch == SPACE)
			sp_c++;
		else if(ch == NEWLINE)
			l_c++;
		else
			o_c++;
	}
	
	printf("spaces = %lu, newlines = %lu, others = %lu", sp_c, l_c, o_c);
	
	return 0;
}