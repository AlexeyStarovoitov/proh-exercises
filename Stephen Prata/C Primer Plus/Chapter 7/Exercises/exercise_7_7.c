#include "stdio.h"

#define PAY_BAS (10.0)
#define PAY_OVER 15.0
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
	int hours;
	
	printf("Enter your hours: ");
	scanf("%d", &hours);
	
	if (hours > AVER_WEEK)
		gross_pay = (hours - AVER_WEEK)*PAY_OVER + AVER_WEEK*PAY_BAS;
	else
		gross_pay = hours*PAY_BAS;
	
	if(gross_pay <= POINT_1)
		taxes = gross_pay*TAX_1;
	else if(gross_pay > POINT_1 && gross_pay <= POINT_2)
		taxes = BASE_1 + (gross_pay - POINT_1)*TAX_2;
	else
		taxes = BASE_1 + BASE_2 + (gross_pay - POINT_1 - POINT_2)*TAX_3;
	
	net_pay = gross_pay - taxes;
	
	printf("gross pay: %.2f\n", gross_pay);
	printf("taxes: %.2f\n", taxes);
	printf("net pay: %.2f", net_pay);
	
	return 0;
}
