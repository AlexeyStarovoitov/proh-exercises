//listing_14_15.c -- uses enumeratied values

#include "stdio.h"
#include "string.h"
#include "stdbool.h"

char *s_gets(char *st, int n);

enum spectrum {red, orange, yellow, green, blue, violet};
const char *colours[] = {"red", "orange", "yellow", 
						"green", "blue", "viloet"};
				
#define LEN 30

int main(void)
{
	char choice[LEN];
	enum spectrum colour;
	
	bool colour_is_found = false;
	
	puts("Enter a colour(empty line to quit): ");
	while(s_gets(choice, LEN) != NULL && choice[0] != '\0')
	{
		for(colour = red; colour <= violet; colour++)
		{
			if(strcmp(choice, colours[colour]) == 0)
			{
				colour_is_found = true;
				break;
			}
		}
		
		if(colour_is_found)
			switch(colour)
			{
				case red: puts("Roses are red.");
				break;
				case orange: puts("Poppies are orange.");
				break;
				case yellow: puts("Sunflowers are yellow");
				break;
				case green: puts("Grass is green.");
				break;
				case blue: puts("Bluebells are blue.");
				break;
				case violet: puts("Violets are violet");
				break;
			}
		else
			printf("I don't know the colour %s.\n", choice);
		colour_is_found = false;
		puts("Next colour, please: ");
	}		
	
	return 0;
}

char *s_gets(char *st, int n)
{
	char *find, *ret_val;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return ret_val;
}