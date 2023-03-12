#include "stdio.h"

#define NAME_LEN 30
#define SURNAME_LEN 30

int main(void)
{
	char name[NAME_LEN];
	char surname[SURNAME_LEN];
	
	printf("Please, enter your name\n");
	scanf("%s", name);
	printf("Please, enter your lastname\n");
	scanf("%s", surname);
	printf("Your last and first names are: %s, %s\n", surname, name);
	
	return 0;
}