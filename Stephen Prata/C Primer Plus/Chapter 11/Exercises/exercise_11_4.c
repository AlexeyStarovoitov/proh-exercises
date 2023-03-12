#include "stdio.h"
#include "ctype.h"

void get_word(char arr[], int n)
{
	char ch;
	
	while(isspace(ch = getchar()))
		continue;
	*arr++ = ch;
	n--;
	while(n-- > 0 && !isspace(ch = getchar()))
		*arr++ = ch;
	*arr = '\0';
	while (getchar() != '\n')
		continue;
}

int main(void)
{
	int n;
	
	printf("Enter the length of the word: ");
	scanf("%d", &n);
	getchar();
	
	char arr[n+1];
	
	printf("Now enter your sentence\n", n);
	get_word(arr, n);
	printf("You entered:\n");
	puts(arr);
	
	return 0;
}