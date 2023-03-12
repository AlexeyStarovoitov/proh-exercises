#include "stdio.h"
#include "string.h"

#define LEN 30

int str2bin(char *str);
char *s_gets(char *str, int n);

int main(void)
{
	char strval[LEN];
	
	printf("Please, enter the binaty representation of your value:\n");
	while(s_gets(strval, LEN) && strval[0] != '\0')
	{
		printf("The value of your number in the decimal system: %d\n",
				str2bin(strval));
		printf("Please, enter the binaty representation of your value:\n");
	}	
	return 0;
}

int str2bin(char *st)
{
	int i, j, val, pow;
	int len = strlen(st);
	
	for(i=0, val = 0; i < len; i++)
	{
		for(j = 1, pow = 1; j <= i; j++)
			pow *= 2;
		
		val += pow*(st[len-1-i] - '0');
	}
		
	
	return val;
}

char *s_gets(char *st, int n)
{
	char *ret_val, *res;
	
	ret_val = fgets(st, n, stdin);
	
	if(ret_val)
	{
		res = strchr(st, '\n');
		if(res)
			*res = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return ret_val;
}