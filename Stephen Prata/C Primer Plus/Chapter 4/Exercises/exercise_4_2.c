#include "stdio.h"
#include "string.h"

#define NAME_LEN 30

int main(void)
{
	char name[NAME_LEN];
	
	printf("Enter your first name:\n");
	scanf("%s", name);
	
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);
	printf("%*s\n", strlen(name)+3, name);
	
	return 0;
}