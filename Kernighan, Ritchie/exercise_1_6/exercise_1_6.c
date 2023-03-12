#include "stdio.h"

void main(void)
{
	// при выполнении данной программы нужно помнить что помимо строки при нажатии enter автоматически вставляется символ конца строки, т.е перевод
	// на новую строку
	int c, proof, ns;
	ns = 0;
	printf("char proof ns\n");
	while(proof = ((c = getchar()) != EOF))
	{
		if (c == '\n')
		{
			ns++;
		}
		putchar(c);
		printf(" ");
		printf("%d ", proof);
		printf("%d\n", ns);
		
	}
}