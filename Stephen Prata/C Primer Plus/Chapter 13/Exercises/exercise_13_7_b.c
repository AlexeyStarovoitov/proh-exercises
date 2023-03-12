#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SLEN 10
#define EOL 1 // EOL - end of line
#define NO_EOL -1 // no EOL occurred
#define EOF_ 0 // EOF occurred

int s_gets(char *st, int len, FILE *fp);

int main(int argc, char *argv[])
{
	char buf1[SLEN], buf2[SLEN];
	int f_st1, f_st2;
	FILE *fp1, *fp2;
	char *pos;
	
	if(((fp1 = fopen(argv[1],"r")) == NULL) || ((fp2 = fopen(argv[2],"r")) == NULL))
		exit(EXIT_FAILURE);
	
	f_st1 = s_gets(buf1, SLEN, fp1);
	f_st2 = s_gets(buf2, SLEN, fp2);
	
	while(f_st1 || f_st2)
	{
		if(f_st1)
		{
			while(f_st1 && (f_st1 != EOL))
			{
				fputs(buf1, stdout);
				f_st1 = s_gets(buf1, SLEN, fp1);
			}
			if(f_st1)
			{
				pos = strchr(buf1, '\n');
				*pos = '\0';
				fputs(buf1, stdout);	
				fputs("\t", stdout);
			}
			else
				fputs("\t", stdout);
		}
		
		
		if(f_st2)
		{
			while(f_st2 && (f_st2 != EOL))
			{
				fputs(buf2, stdout);
				f_st2 = s_gets(buf2, SLEN, fp2);
			}
			if(f_st2)
				fputs(buf2, stdout);
			else
				fputs("\n", stdout);
		}
		else
			fputs("\n", stdout);
		
		f_st1 = s_gets(buf1, SLEN, fp1);
		f_st2 = s_gets(buf2, SLEN, fp2);
	}
	
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}

int s_gets(char *st, int len, FILE *fp)
{
	char *status, *find;
	
	status = fgets(st, len, fp);
	
	if(status)
	{
		find = strchr(st, '\n');
		if(find)
			return EOL;
		else
			return NO_EOL;
	}
	else
		return EOF_;
}