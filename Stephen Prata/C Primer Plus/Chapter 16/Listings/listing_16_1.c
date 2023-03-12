//listing_16_1.c -- simple preproccessor examples

#include "stdio.h"
#define TWO 2
#define OW "Consistency is the last refuge of the unimagina\
tive. - Oscar Wilde"

#define FOUR TWO*TWO
#define FMT "X is %d\n"
#define PX printf("X is %d\n", x)

int main(void)
{
	int x = TWO;
	
	PX;
	x = FOUR;
	printf(FMT, x);
	printf("%s\n", OW);
	printf("TWO: OW\n");
	
	return 0;
}
