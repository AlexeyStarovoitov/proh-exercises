#include "stdio.h"
#include "string.h"

#define NAME_LEN 30
#define SURNAME_LEN 30

int main(void)
{
	char name[NAME_LEN];
	char surname[SURNAME_LEN];
	
	printf("Enter your first and last names\n");
	scanf("%s %s", name, surname);
	
	printf("%s %s\n", name, surname);
	printf("%*d %*d\n", strlen(name), strlen(name), strlen(surname), strlen(surname));
	
	printf("%s %s\n", name, surname);
	printf("%-*d %-*d", strlen(name), strlen(name), strlen(surname), strlen(surname));

	return 0;
}