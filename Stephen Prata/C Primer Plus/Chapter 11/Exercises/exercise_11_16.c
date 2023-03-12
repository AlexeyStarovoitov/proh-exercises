#include "string.h"
#include "stdio.h"
#include "ctype.h"


int main(int argc, char *argv[])
{
	int ch, p, u, l, i;
	
	p = u = l = 0;
	
	for(i = 1; i < argc; i++)
		if(strcmp(argv[i], "-p") == 0)
			p = 1;
		else if (strcmp(argv[i], "-u") == 0)
			u = 1;
		else if (strcmp(argv[i], "-l") == 0)
			l = 1;
	
	if(argc == 1)
		p = 1;
	
	while((ch = getchar()) != EOF)
		if(p)
			putchar(ch);
		else if(u)
			putchar(toupper(ch));
		else if(l)
			putchar(tolower(ch));
	
	return 0;
}