#include "stdio.h"


int main(void)
{
	int lower = 0;
	int upper = 100;
	int guess = 50;
	char response;
	
	printf("Pick an integer from 1 to 100. I will try to guess ");
	printf("it.\n Respond with a c if my guess is correct,\n with");
	printf("l, if guess is low and with h if my guess is high.\n");
	printf("Uh.. is your number %d?\n", guess);
	while((response = getchar()) != 'c')
	{
		if (response == 'l')
		{
			lower = guess;
			guess = (upper + lower)/2;
			printf("Well, is it %d?\n", guess);
		}
		else if(response == 'h')
		{
			upper = guess;
			guess = (upper + lower)/2;
			printf("Well, is it %d?\n", guess);
		}
		else
			printf("Sorry, but try again!\n");
		while(getchar() != '\n')
			continue;
		
	}
	printf("I knew I could do it!\n");
	
	return 0;
}