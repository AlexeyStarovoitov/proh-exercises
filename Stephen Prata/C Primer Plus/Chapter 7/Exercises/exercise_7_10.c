#include "stdio.h"

#define INCOME_1 17850.0
#define INCOME_2 23900.0
#define INCOME_3 29750.0
#define INCOME_4 14875.0

#define PERCENT 0.15
#define EXCESS 0.28

int main(void)
{
	int category;
	double income, tax;
	
	printf("Enter your category:\n");
	
	while(scanf("%d", &category) == 1)
	{
		printf("Enter your income:\n");
		scanf("%lf", &income);
		
		switch(category)
		{
			case 1:
				if(income > INCOME_1)
					tax = INCOME_1*PERCENT+(income - INCOME_1)*EXCESS;
				else
					tax = income*PERCENT;
				break;
			case 2:
				if(income > INCOME_2)
					tax = INCOME_2*PERCENT+(income - INCOME_2)*EXCESS;
				else
					tax = income*PERCENT;
				break;
			case 3:
				if(income > INCOME_3)
					tax = INCOME_3*PERCENT+(income - INCOME_3)*EXCESS;
				else
					tax = income*PERCENT;
				break;
			case 4:
				if(income > INCOME_4)
					tax = INCOME_4*PERCENT+(income - INCOME_4)*EXCESS;
				else
					tax = income*PERCENT;
				break;
			default:
				printf("Enter numbers from 1 to 4!\n");
				break;
		}
		
		printf("Your taxes %.2f\n", tax);
		printf("Enter your category:\n");
		
	}
	
	return 0;
	
}
