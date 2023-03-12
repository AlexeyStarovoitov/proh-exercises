//listing_4_3
//try %u or %lu specifiers if your implementation
//does not recognize the %zd specifiers

#include "stdio.h"
#include "string.h"

#define PRAISE "You are an extraordinary being."

int main(void)
{
	char name[40];
	
	printf("What's your name? \n");
	scanf("%s", name);
	printf("Hello, %s. %s\n", name, PRAISE);
	printf("Your name of %u letters occupies %u memory cells.\n",
	strlen(name), sizeof name);
	printf("The phrase of praise has %u letter",
	strlen(PRAISE));
	printf("and occupies %u memory cells.\n", sizeof PRAISE);
	
	return 0;
	
}