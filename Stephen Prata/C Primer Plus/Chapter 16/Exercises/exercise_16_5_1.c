#include "time.h"

static unsigned long next;

void srand1(void)
{
	next = (unsigned)(time(0));
}

int rand1(void)
{
	next = next*1103515245 + 12345;
	
	return (unsigned int)(next/65536) % 32768;
}