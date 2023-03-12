#include "stdio.h"
#include "string.h"

#define SLEN 50
#define LEN 5

struct names
{
	
	char lname[SLEN];
	char fname[SLEN];
	char mname[SLEN];
	
};

struct person
{
	unsigned long soc_num;
	struct names name;
};


void per_print(const struct person *per_p, int n);

int main(void)
{
	struct person persons[LEN] = 
	{
		{1222342, {"Vdovichenko", "Dmitriy", "Serggevich"}},
		{12535492, {"Starovoitov", "Alexey", "Yurievich"}},
		{18789342, {"Rakistkih", "Andrey", ""}},
		{1255555, {"Tichonov", "Pavel", "Alexeevich"}},
		{1266442, {"Andreev", "Yiriy", "Olegovich"}}
	};
	
	per_print(persons, LEN);
	
	return 0;
}


void per_print(const struct person *per_p, int n)
{
	int i;
	char init[3];
	
	for(i = 0; i < n; i++)
	{
		if(strlen((per_p+i)->name.mname) != 0)
		{
			init[0] = (per_p+i)->name.mname[0];
			init[1] = '.';
			init[2] = '\0';
		}
		else
			strcpy(init, "  ");
		
		printf("%s, %s %s --- %lu\n", (per_p+i)->name.lname,
			(per_p+i)->name.fname, init, (per_p+i)->soc_num);
	}
	
}

