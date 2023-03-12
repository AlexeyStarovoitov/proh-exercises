#include "stdio.h"

int main(void) // receives an ASCII code value and returns the char which has this code
{
	char ch;
	printf("Please, enter the ASCII code: ");
	scanf("%d", &ch);
	printf("Your character is: %c", ch);
	
	return 0;
	
}