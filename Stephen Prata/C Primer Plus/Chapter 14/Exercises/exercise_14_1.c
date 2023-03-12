#include "string.h"
#include "stdio.h"

#define MON 12
#define MONAME 10
#define ABBR 3

struct mondate
{
	char name[MONAME];
	char abbr[ABBR];
	int days;
	int num;
};

char *s_gets(char *st, int n);
int month_cnt(const char * p_mon);

struct mondate months[MON] = 
{
	{"January", "Jan", 31, 1},
	{"February", "Feb", 28, 2},
	{"March", "Mar", 31, 3},
	{"April", "Apr", 30, 4},
	{"May", "May", 31, 5},
	{"June", "Jun", 30, 6},
	{"July", "Jul", 31, 7},
	{"August", "Aug", 31, 8},
	{"September", "Sep", 30, 9},
	{"October", "Oct", 31, 10},
	{"November", "Nov", 30, 11},
	{"December", "Dec", 31, 12}
};


int main(void)
{
	char temp[MONAME];
	
	printf("Enter a month name:\n");
	
	while(s_gets(temp, MONAME) != NULL && temp[0] !='\0')
	{
		printf("The total days are %d\n", month_cnt(temp));
		printf("Enter a month name:\n");
	}
		
	return 0;
	
}

int month_cnt(const char * p_mon)
{
	int mon_num, i, total;
	
	for(i = 0; i < MON; i++)
		if(strcmp(p_mon, months[i].name) == 0)
		{
			mon_num = i;
			break;
		}
	if(i == 12)
		return -1;
	else
	{
		for(i = 0, total = 0; i <= mon_num; i++)
			total += months[i].days;
		
		return total; 
	}
}

char *s_gets(char *st, int n)
{
	char *find, *ret_val;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return ret_val;
}

