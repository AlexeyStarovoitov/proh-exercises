#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define LEN 9
unsigned char binstr_dec(char *str);
char *dec_binstr(unsigned char val, char *st);

int main(int argc, char *argv[])
{
	unsigned char val1, val2;
	char binstr[LEN];
	
	if(argc != 3)
	{
		printf("The number of arguments is incorrect!\n");
		exit(EXIT_FAILURE);
	}
	
	val1 = binstr_dec(argv[1]);
	val2 = binstr_dec(argv[2]);
	
	printf("val1 = %d\n", val1);
	printf("val2 = %d\n", val2);
	
	printf("The ~%s is %s\n", argv[1], dec_binstr(~val1, binstr));
	printf("The ~%s is %s\n", argv[2], dec_binstr(~val2, binstr));
	printf("The %s & %s is %s\n", argv[1], argv[2], dec_binstr(val1 & val2, binstr));
	printf("The %s | %s is %s\n", argv[1], argv[2], dec_binstr(val1 | val2, binstr));
	printf("The %s ^ %s is %s\n", argv[1], argv[2], dec_binstr(val1 ^ val2, binstr));
	
	return 0;
	
}

unsigned char binstr_dec(char *str)
{
	unsigned char i, j, val, pow;
	unsigned char len = strlen(str);
	
	for(i = 0, val = 0; i < len; i++)
	{
		for(j = 1, pow = 1; j <=i; j++)
			pow *= 2;
		val += pow*(str[len-1-i] - '0');
	}
	
	return val;
}

char *dec_binstr(unsigned char val, char *st)
{
	int i;
	
	for(i = 0; i < LEN-1; i++)
		st[i] = '0';
	
	st[LEN-1] = '\0';
	i = strlen(st)-1;
	
	while(val > 1)
	{
		st[i] = '0' + (val % 2);
		val /= 2;
		i--;
	}
	st[i] = '0' + val;
	
	return st;
}

