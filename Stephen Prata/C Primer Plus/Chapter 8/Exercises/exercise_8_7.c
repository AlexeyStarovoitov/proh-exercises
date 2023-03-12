#include "stdio.h"
#include "ctype.h"

char get_choice(void);
char get_first(void);
int get_int(void);

#define PAY_BAS_1 (8.75)
#define PAY_BAS_2 (9.33)
#define PAY_BAS_3 (10.0)
#define PAY_BAS_4 (11.20)

#define CHOICES 5

#define PAY_OVER 1.5
#define TAX_1 0.15
#define TAX_2 0.2
#define TAX_3 0.25
#define POINT_1 300.0
#define POINT_2 150.0 
#define BASE_1 (TAX_1*POINT_1)
#define BASE_2 (TAX_2*POINT_2)
#define AVER_WEEK 40

int main(void)
{
	double gross_pay, taxes, net_pay;
	int hours, i, choice;
	double pay_base, pay_over;
	
	
	
	while((choice = get_choice()) != 'q')
	{
		switch(choice)
		{
			case 'a':
				pay_base = PAY_BAS_1;
				break;
			case 'b':
				pay_base = PAY_BAS_2;
				break;
			case 'c':
				pay_base = PAY_BAS_3;
				break;
			case 'd':
				pay_base = PAY_BAS_4;
				break;
			
		}
		
		pay_over = PAY_OVER*pay_base;
		printf("Enter your hours: ");
		hours = get_int();
		
		if (hours > AVER_WEEK)
			gross_pay = (hours - AVER_WEEK)*pay_over + AVER_WEEK*pay_base;
		else
			gross_pay = hours*pay_base;
		
		if(gross_pay <= POINT_1)
			taxes = gross_pay*TAX_1;
		else if(gross_pay > POINT_1 && gross_pay <= POINT_2)
			taxes = BASE_1 + (gross_pay - POINT_1)*TAX_2;
		else
			taxes = BASE_1 + BASE_2 + (gross_pay - POINT_1 - POINT_2)*TAX_3;
		
		net_pay = gross_pay - taxes;
		
		printf("gross pay: %.2f\n", gross_pay);
		printf("taxes: %.2f\n", taxes);
		printf("net pay: %.2f\n", net_pay);
		
	}
	
	
	return 0;
}

char get_choice(void)
{
	int ch;
	printf("*****************************************************************\n");
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("a $8.75/hr		b $9.33/hr\n");
	printf("c $10.00/hr 	d $11.20/hr\n");
	printf("q quit\n");
	printf("*****************************************************************\n");
	
	ch = get_first();
	while((ch < 'a' || ch > 'd') && ch != 'q')
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

int get_int(void)
{
	int input;
	char ch;
	
	while(scanf("%d", &input) != 1)
	{
		while((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an integer.\n Please enter an integer: ");
	}
		
	return input;
}
