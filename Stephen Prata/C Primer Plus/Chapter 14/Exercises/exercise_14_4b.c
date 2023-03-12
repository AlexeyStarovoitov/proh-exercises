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


void per_print(struct person per);

int main(void)
{
	int i;
	struct person persons[LEN] = 
	{
		{1222342, {"Vdovichenko", "Dmitriy", "Serggevich"}},
		{12535492, {"Starovoitov", "Alexey", "Yurievich"}},
		{18789342, {"Rakistkih", "Andrey", ""}},
		{1255555, {"Tichonov", "Pavel", "Alexeevich"}},
		{1266442, {"Andreev", "Yiriy", "Olegovich"}}
	};
	
	for(i = 0; i < LEN; i++)
		per_print(persons[i]);
	
	return 0;
}


void per_print(struct person per)
{
	char init[3];
	
	if(strlen(per.name.mname) != 0)
	{
		init[0] = per.name.mname[0];
		init[1] = '.';
		init[2] = '\0';
	}
	else
		strcpy(init, "  ");
		
	printf("%s, %s %s --- %lu\n", per.name.lname,
			per.name.fname, init, per.soc_num);
	
	
}

