#include "stdio.h"
#include "ctype.h"

int my_atoi(const char *str)
{
	int res = 0;
	int sign = 1;
	
	while(isspace(*str))
		str++;
	if(*str == '-')
		sign = -1;
	else if(*str == '+')
		sign = 1;
	else
	{
		while(*str)
			if(isdigit(*str))
			{
				res *= 10;
				res += *str - '0';
				str++;
			}
			else
				return 0;
	}
	
	return res*sign;
	
}


int main(int argc, char *argv[])
{
	int i;
	
	printf("You entered next digits:\n");
	
	for(i = 1; i < argc; i++)
		printf("%s is %d\n", argv[i], my_atoi(argv[i]));
	
	return 0;
}