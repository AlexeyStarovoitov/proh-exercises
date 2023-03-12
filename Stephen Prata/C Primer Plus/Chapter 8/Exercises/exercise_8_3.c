#include "stdio.h"
#include "ctype.h"

int main(void)
{
	long u_c, l_c, o_c;
	int ch;
	
	u_c = l_c = o_c = 0L;
	
	printf("Enter youe characters:\n");
	while((ch = getchar()) != EOF)
	{
		if(isalpha(ch))
			if(islower(ch))
				l_c++;
			else
				u_c++;
		else
			o_c++;
	}
	
	printf("Upper letters: %ld\n", u_c);
	printf("Lower letters: %ld\n", l_c);
	printf("Others: %ld\n", o_c);
	
	return 0;
	
}