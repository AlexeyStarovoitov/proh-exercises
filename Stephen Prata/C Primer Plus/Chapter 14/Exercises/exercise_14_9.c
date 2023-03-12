#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LEN 12
#define FLIGHTS 4
#define SLEN 40

int flights[FLIGHTS] = {102, 311, 444, 519};

struct name
{
	char fname[SLEN];
	char lname[SLEN];
};

struct seat
{
	int id;
	int assigned;
	struct name names;
	int flight;
};

char top_menu(void);
char menu(void);
void read_in(struct seat pst[][LEN], int n, FILE *fp);
void show_empty_num(struct seat pst[], int n);
void show_empty_lst(struct seat pst[], int n);
void seat_assign(struct seat pst[], int n);
void del_assignment(struct seat pst[], int n);
void alpha_srt(struct seat pst[], int n);
void assign_conf(struct seat pst[], int n);
char *s_gets(char *st, int n);
void cleanup(void);


int main(int argc, char *argv[])
{
	struct seat seats[FLIGHTS][LEN];
	int i, j;
	char answer;
	FILE *fp;
	
	for(i = 0; i < FLIGHTS; i++)
		for(j = 0; j < LEN; j++)
		{
			seats[i][j].assigned = 0;
			seats[i][j].id = j + 1;
			seats[i][j].flight = flights[i];
			strcpy(seats[i][j].names.fname, "");
			strcpy(seats[i][j].names.lname, "");
		}
	
	if(argc != 2)
		exit(EXIT_FAILURE);
	
	if((fp = fopen(argv[1], "a+b")) == NULL)
		exit(EXIT_FAILURE);
	
	rewind(fp);
	read_in(seats, FLIGHTS, fp);
	fclose(fp);
	
	printf("Enter your flight:\n");
	
	while((answer = top_menu()) != 'e')
	{
		switch(answer)
		{
			case 'a':
				i = 0;
				break;
			case 'b':
				i = 1;
				break;
			case 'c':
				i = 2;
				break;
			case 'd':
				i = 3;
				break;
		}
		
		while((answer = menu()) != 'g')
		{
			printf("Flight %d\n", flights[i]);
			switch(answer)
			{
				case 'a':
					show_empty_num(seats[i], LEN);
					break;
				case 'b':
					show_empty_lst(seats[i], LEN);
					break;
				case 'c':
					alpha_srt(seats[i], LEN);
					break;
				case 'd':
					seat_assign(seats[i], LEN);
					break;
				case 'e':
					del_assignment(seats[i], LEN);
					break;
				case 'f':
					assign_conf(seats[i], LEN);
					break;
			}
			
			printf("Enter your choice:\n");
		}
		printf("Enter your flight:\n");
	}
	
	fp = fopen(argv[1], "w+b");
	
	for(i = 0; i < FLIGHTS; i++)
		for(j = 0; j < LEN; j++)
			if(seats[i][j].assigned == 1)
				fwrite(&seats[i][j], sizeof(struct seat), 1, fp);
			
	fclose(fp); 
	
	return 0;
}

char top_menu(void)
{
	char ans;
	
	printf("a) Flight 102\n");
	printf("b) Flight 311\n");
	printf("c) Flight 444\n");
	printf("d) Flight 519\n");
	printf("e) Quit\n");
	
	ans = getchar();
	
	while((ans < 'a') || (ans > 'e'))
	{
		cleanup();
		printf("Try again!\n");
		ans = getchar();
	}
	cleanup();
	
	return ans;
	
	
}

char menu(void)
{
	char ans;
	
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Seat assigmnent\n");
	printf("g) Quit\n");
	
	ans = getchar();
	
	while((ans < 'a') || (ans > 'g'))
	{
		cleanup();
		printf("Try again!\n");
		ans = getchar();
	}
	cleanup();
	
	return ans;
}

void read_in(struct seat pst[][LEN], int n, FILE *fp)
{
	struct seat temp;
	int i;
	
	while(fread(&temp, sizeof(struct seat), 1, fp) == 1)
	{
		for(i = 0; i < FLIGHTS; i++)
			if(flights[i] == temp.flight)
				break;
		pst[i][temp.id-1].assigned = 1;
		strcpy(pst[i][temp.id-1].names.fname,temp.names.fname);
		strcpy(pst[i][temp.id-1].names.lname,temp.names.lname);
	}
	
}

void show_empty_num(struct seat pst[], int n)
{
	int num, i;
	
	for(i = 0, num = 0; i < n; i++)
		if(pst[i].assigned == 0)
			num++;
	printf("Number of empty seats for flight %d: %d\n", pst[0].flight, num);
}

void show_empty_lst(struct seat pst[], int n)
{
	int i;
	
	printf("List of empty seats for flight %d:\n", pst[0].flight);
	for(i = 0; i < n; i++)
		if(pst[i].assigned == 0)
			printf("%d ", pst[i].id);
	printf("\n");
}

void alpha_srt(struct seat pst[], int n)
{
	int i, j;
	int assignments = 0;
	
	struct seat *srt[n];
	struct seat *temp; 
	
	for(i = 0; i < n; i++)
		if(pst[i].assigned == 1)
			srt[assignments++] = &pst[i];
		
	if(assignments > 1)
	{
		
		for(i = 0; i < assignments - 1; i++)
			for(j = i + 1; j < assignments; j++)
				if(strcmp(srt[i]->names.fname, srt[j]->names.fname) > 0)
				{
					temp = srt[i];
					srt[i] = srt[j];
					srt[j] = temp;
				}
	}
	
	if(assignments > 0)
	{
		printf("Flight %d:\n", pst[0].flight);
		for(i = 0; i < assignments; i++)
			printf("id: %d, name: %s, last name: %s\n", srt[i]->id, srt[i]->names.fname, srt[i]->names.lname);
	}	
}

void seat_assign(struct seat pst[], int n)
{
	char temp[SLEN];
	int id;
	
	printf("Enter the id:\n");
	while(s_gets(temp, SLEN) != NULL && temp[0] != '\0')
	{
		id = atoi(temp);
		printf("%d\n", id);
		if(id < 1 || id > n || pst[id-1].assigned == 1)
		{
			printf("Try again!\n");
			continue;
		}
			
		
		printf("Enter name:\n");
		if(s_gets(temp, SLEN) != NULL && temp[0] != '\0')
			strcpy(pst[id-1].names.fname, temp);
		else
			break;
		
		printf("Enter last name:\n");
		if(s_gets(temp, SLEN) != NULL && temp[0] != '\0')
			strcpy(pst[id-1].names.lname, temp);
		else
			break;
		
		printf("Enter the id:\n");
	}
}

void del_assignment(struct seat pst[], int n)
{
	char temp[SLEN];
	int id;
	
	printf("Flight %d:\n", pst[0].flight);
	printf("Enter the id of the assignment you want to delete:\n");
	while(s_gets(temp, SLEN) != NULL && temp[0] != '\0')
	{
		id = atoi(temp);
		if(id < 1 || id > n)
		{
			printf("Try again!\n");
			continue;
		}
		pst[id-1].assigned = 0;
		printf("Enter the id of the assignment you want to delete:\n");
		
	}
}

void assign_conf(struct seat pst[], int n)
{
	char temp[SLEN];
	int id;
	
	printf("Flight %d:\n", pst[0].flight);
	printf("Enter the id of the assignment you want to confirm:\n");
	while(s_gets(temp, SLEN) != NULL && temp[0] != '\0')
	{
		id = atoi(temp);
		if(id < 1 || id > n)
		{
			printf("Try again!\n");
			continue;
		}
		if((strlen(pst[id-1].names.fname) == 0) || (strlen(pst[id-1].names.lname) == 0))
		{
			printf("There was no registration for this id!\n");
			printf("Try again!\n");
			continue;
		}
		pst[id-1].assigned = 1;
		printf("Enter the id of the assignment you want to confirm:\n");
		
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


void cleanup(void)
{
	while(getchar() != '\n')
		;
}