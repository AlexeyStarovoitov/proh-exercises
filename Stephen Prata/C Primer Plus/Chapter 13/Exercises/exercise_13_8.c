#include "stdio.h"
#include "stdlib.h"


int main(int argc, char *argv[])
{
	unsigned long count;
	int ch, i;
	FILE *fp;
	
	if(argc < 2)
	{
		printf("Usage: %s character, filename1, filename2 ... filenamen\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		for(i = 2; i < argc; i++)
		{
			if((fp = fopen(argv[i], "r")) == NULL)
			{
				printf("Can't open the %s file\n", argv[i]);
				continue;
			}
			else
			{
				count = 0UL;
				while((ch = getc(fp)) != EOF)
					if(ch == argv[1][0])
						count++;
				printf("File %s has %lu characters %c\n",
						argv[i], count, argv[1][0]);
			}
		}	
	}
	else
	{
		count = 0UL;
		while((ch = getchar()) != EOF)
			if(ch == argv[1][0])
				count++;
		printf("Input stream has %lu characters %c\n",
						count, argv[1][0]);
	}
	
	return 0;
}