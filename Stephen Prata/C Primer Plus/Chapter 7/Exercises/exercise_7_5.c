#include "stdio.h"

#define STOP '#'
#define PERIOD '.'
#define EXPCLAM '!'

int main(void)
{
	char ch;
	int num_sub = 0;
	
	printf("Enter your text:\n");
	
	while((ch = getchar()) != STOP)
	{
		switch (ch)
		{
			case PERIOD:
				printf("!");
				num_sub++;
				break;
			
			case EXPCLAM:
				printf("!!");
				num_sub++;
				break;
			default:
				printf("%c", ch);
		}
		
	}
	
	printf("\n number of substitution is %d\n", num_sub);
	
	return 0;
}