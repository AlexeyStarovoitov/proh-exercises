#include "stdio.h"

void main(void)
{
	int lower, upper, step;
	float fahr, celsius;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	celsius = lower;
	printf("Таблица перевода температур из Цельсия в Фаренгейнт\n");
	
	while (celsius <= upper)
	{
		fahr = (9.0/5.0)*celsius + 32.0;
		printf ("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}