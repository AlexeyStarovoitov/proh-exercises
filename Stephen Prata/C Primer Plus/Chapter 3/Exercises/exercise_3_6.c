#include "stdio.h"

int main(void)
{
	long double mol_in_grams = 3.45e-23;
	long double grams_in_quart = 950.0;
	long double amount = 3.4;
	
	printf("Write amount of water in quarts:\n");
	//scanf("%Lf", &amount);
	__mingw_printf("Molecules in the amount is %Lf", (grams_in_quart*amount));
	
	return 0;
}