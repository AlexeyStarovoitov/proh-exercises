//listing_14_8.c -- uses argument input and return

#include "stdio.h"
#include "string.h"
#define NLEN 30

struct namect
{
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect st);
void showinfo(const struct namect st);
char *s_gets(char *st, int n);

int main(void)
{
	struct namect person;
	
	person = getinfo();
	person = makeinfo(person);
	showinfo(person);
	
	return 0;
}


struct namect getinfo(void)
{
	struct namect st;
	printf("Please enter your first name.\n");
	s_gets(st.fname, NLEN);
	printf("Please enter your last name.\n");
	s_gets(st.lname, NLEN);
	
	return st;
}

struct namect makeinfo(struct namect st)
{
	st.letters = strlen(st.fname)+
	strlen(st.lname);
	
	return st;
}

void showinfo(const struct namect st)
{
	printf("%s %s, your name contains %d letters.\n",
			st.fname, st.lname, st.letters);
}

char *s_gets(char *st, int n)
{
	char *ret_val, *find;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find =strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return ret_val;
}