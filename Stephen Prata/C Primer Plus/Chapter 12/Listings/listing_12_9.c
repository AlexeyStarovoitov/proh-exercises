//listing_12_9.c -- file for rand1() and srand1()
//					uses ANSI C portable algorithm

static unsigned long next = 1;

int rand1(void)
{
	//magic formula to generate pseudorandom number
	next = next*1103515245 + 12345;
	
	return (unsigned int)(next/65536) % 32768;
}

void srand1(unsigned int seed)
{
	next = seed;
}