//listing_12_7_c -- produces random numbers uses
//					ANSI C portable algorithm

static unsigned long next = 1;

int rand0(void)
{
	//magic formula to generate pseudorandom number
	next = next*1103515245 + 12345;
	
	return (unsigned int)(next/65536) % 32768;
}