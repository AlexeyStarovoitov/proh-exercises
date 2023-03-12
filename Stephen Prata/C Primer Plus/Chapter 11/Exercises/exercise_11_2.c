#include "stdio.h"
#include "ctype.h"

void s_gets(char arr[], int n)
{
	char ch;
	
	while((n-- > 0) && !isspace((ch = getchar())))
		*arr++ = ch;
	*arr = '\0';
}

int main(void)
{
	int n;
	
	printf("Enter the number of characters you will enter:");
	scanf("%d", &n);
	getchar();
	
	char arr[n+1];
	
	printf("Now enter no more than %d charcters\n", n);
	s_gets(arr, n);
	printf("You entered:\n");
	puts(arr);
	
	return 0;
}