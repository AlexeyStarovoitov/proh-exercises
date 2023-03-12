#include "stdio.h"

#define A_PRICE 2.05
#define B_PRICE 1.15
#define C_PRICE 1.09

#define SUM_DISC 100.00
#define DISCOUNT 0.05

#define A_CH 'a'
#define B_CH 'b'
#define C_CH 'c'
#define STOP 'q'

#define SHIP_1 6.50
#define SHIP_2 14.00
#define SHIP_POUND 0.50

#define POUND_1 5
#define POUND_2 20

int main(void)
{
	char response;
	int pounds, a_pounds, b_pounds, c_pounds, sum_pounds;
	double sum, sum_disc, charges;
	
	a_pounds = b_pounds = c_pounds = 0;
	
	printf("Enter your response:\n");
	
	
	while(scanf("%c%*c", &response) == 1)
	{
		switch(response)
		{
			case 'a':
				printf("Enter pounds: ");
				scanf("%d%*c", &pounds);
				a_pounds += pounds;
				break;
			case 'b':
				printf("Enter pounds: ");
				scanf("%d%*c", &pounds);
				b_pounds += pounds;
				break;
			case 'c':
				printf("Enter pounds: ");
				scanf("%d%*c", &pounds);
				c_pounds += pounds;
				break;
			case 'q':
				goto exit;
				break;
			default:
				printf("Enter a, b,c or q to quit only! Try again\n");
				continue;
		}
		
		printf("Enter your response:\n");
	}
	
	exit:
	sum = a_pounds*A_PRICE + b_pounds*B_PRICE + c_pounds*C_PRICE;
	sum_pounds = a_pounds + b_pounds + c_pounds;
	sum_disc = (sum >= SUM_DISC) ? (sum*(1-DISCOUNT)):sum;
	
	if(sum_pounds <= POUND_1)
		charges = SHIP_1;
	else if(sum_pounds > POUND_1 && sum_pounds < POUND_2)
		charges = SHIP_2;
	else
		charges = SHIP_2 + sum_pounds * SHIP_POUND;
	
	printf("Prices:\n");
	printf("Artichokes: %.2f per pound\n", A_PRICE);
	printf("Beets: %.2f per pound\n", B_PRICE);
	printf("Carrot: %.2f per pound\n", C_PRICE);
	
	printf("Ordered pounds: %d\n", sum_pounds);
	printf("Cost for each vegetables:\n");
	printf("Artichokes: %.2f \n", A_PRICE*(double)a_pounds);
	printf("Beets: %.2f\n", B_PRICE*(double)b_pounds);
	printf("Carrot: %.2f\n", C_PRICE*(double)c_pounds);
	printf("The total cost:.2f\n", sum_disc);
	
	printf("Discount: %.2f\n", (sum > sum_disc) ? (sum-sum_disc): 0.0);
	printf("Shipping charge: %.2f\n", charges);
	printf("Grand total:%.2f\n", sum_disc + charges);
	
	
	
	
	
}






