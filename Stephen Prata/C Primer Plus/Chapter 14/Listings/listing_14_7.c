//listing_14_5.c -- passing a structure

#include "stdio.h"
#define FUNDLEN 50

struct funds
{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};

double sum(const struct funds moolah);

int main(void)
{
	struct funds stan =
	{
		.bank = "Galic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};
	
	printf("Stan has a total of $%.2f\n",
		sum(stan));
	
	return 0;
}

double sum(const struct funds moolah)
{
	return moolah.bankfund + moolah.savefund;
}