#include "stdio.h"

void s_gets(char arr[], int n)
{
	while(n-- > 0)
		*arr++ = getchar();
	*arr = '\0';
}

int main(void)
{
	int n;
	
	printf("Enter the number of characters you will enter:");
	scanf("%d", &n);
	getchar();
	
	
	char arr[n+2];
	
	printf("Now enter no more than %d charcters\n", n);
	s_gets(arr, n);
	printf("You entered:\n");
	puts(arr);
	
	return 0;
}