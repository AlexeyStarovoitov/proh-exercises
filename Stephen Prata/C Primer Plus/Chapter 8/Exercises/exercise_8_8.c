#include "stdio.h"
#include "ctype.h"
#include "math.h"

char get_choice(void);
char get_first(void);
int get_float(void);

int main(void)
{
	int choice;
	float num1, num2;
	
	while((choice = get_choice()) != 'q')
	{
		printf("Enter first number: ");
		num1 = get_float();
		printf("Enter second number: ");
		num2 = get_float();
		
		switch (choice)
		{
			case 'a':
				printf("%.1f + %.1f = %.1f\n", num1, num2, num1+num2);
				break;
				
			case 's':
				printf("%.1f - %.1f = %.1f\n", num1, num2, num1-num2);
				break;
					  
			case 'm':
				printf("%.1f * %.1f = %.1f\n", num1, num2, num1*num2);
				break;
					  
			case 'd': 
				if (fabs(num2) <= 0.001f)
				{
					printf("Enter a number other than 0: ");
					while(fabs(num2 = get_float())<= 0.001f)
						printf("Enter a number other than 0: ");
				}
				printf("%.1f / %.1f = %.1f\n", num1, num2, num1/num2);
				break;
					
					
		}
	}
	
	printf("Bye.\n");
	
	return 0;
}



char get_choice(void)
{
	int ch;
	
	printf("Enter the operation of your choice:\n");
	printf("a. add s. subtract\n");
	printf("m. multiply d. divide\n");
	printf("q. quit\n");
	ch = get_first();
	while(ch != 'a'&& ch != 's'&& ch != 'm'&& ch != 'd'&& ch != 'q')
	{
		printf("Try again!\n");
		ch = get_first();
	}
	return ch;
}

char get_first(void)
{
	int ch;
	while(isspace(ch = getchar()))
		continue;
	while(getchar() != '\n')
		continue;
	
	return ch;
}

int get_float(void)
{
	float input;
	char ch;
	
	while(scanf("%f", &input) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not float.\nPlease enter a float: ");
	}
		
	return input;
}