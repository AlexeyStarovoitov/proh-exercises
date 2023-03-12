#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LEN 12
#define SLEN 40

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
};

char menu(void);
void read_in(struct seat pst[], int n, FILE *fp);
void show_empty_num(struct seat pst[], int n);
void show_empty_lst(struct seat pst[], int n);
void seat_assign(struct seat pst[], int n);
void del_assignment(struct seat pst[], int n);
void alpha_srt(struct seat pst[], int n);
char *s_gets(char *st, int n);
void cleanup(void);


int main(int argc, char *argv[])
{
	struct seat seats[LEN];
	int i;
	char answer;
	FILE *fp;
	
	for(i = 0; i < LEN; i++)
	{
		seats[i].assigned = 0;
		seats[i].id = i + 1;
		strcpy(seats[i].names.fname, "");
		strcpy(seats[i].names.lname, "");
	}
	
	if(argc != 2)
		exit(EXIT_FAILURE);
	
	if((fp = fopen(argv[1], "a+b")) == NULL)
		exit(EXIT_FAILURE);
	
	rewind(fp);
	read_in(seats, LEN, fp);
	fclose(fp);
	
	printf("Enter your choice:\n");
	
	while((answer = menu()) != 'f')
	{
		switch(answer)
		{
			case 'a':
				show_empty_num(seats, LEN);
				break;
			case 'b':
				show_empty_lst(seats, LEN);
				break;
			case 'c':
				alpha_srt(seats, LEN);
				break;
			case 'd':
				seat_assign(seats, LEN);
				break;
			case 'e':
				del_assignment(seats, LEN);
				break;
		}
		
		printf("Enter your choice:\n");
	}
	
	fp = fopen(argv[1], "w+b");
	
	for(i = 0; i < LEN; i++)
		if(seats[i].assigned == 1)
			fwrite(&seats[i], sizeof(struct seat), 1, fp);
			
	fclose(fp); 
	
	return 0;
}

char menu(void)
{
	char ans;
	
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphabetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
	
	ans = getchar();
	
	while((ans < 'a') || (ans > 'f'))
	{
		cleanup();
		printf("Try again!\n");
		ans = getchar();
	}
	cleanup();
	
	return ans;
}

void read_in(struct seat pst[], int n, FILE *fp)
{
	struct seat temp;
	
	while(fread(&temp, sizeof(struct seat), 1, fp) == 1)
	{
		pst[temp.id-1].assigned = 1;
		strcpy(pst[temp.id-1].names.fname,temp.names.fname);
		strcpy(pst[temp.id-1].names.lname,temp.names.lname);
	}
	
}

void show_empty_num(struct seat pst[], int n)
{
	int num, i;
	
	for(i = 0, num = 0; i < n; i++)
		if(pst[i].assigned == 0)
			num++;
	printf("Number of empty seats: %d\n", num);
}

void show_empty_lst(struct seat pst[], int n)
{
	int i;
	
	printf("List of empty seats:\n");
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
		for(i = 0; i < assignments; i++)
			printf("id: %d, name: %s, last name: %s\n", srt[i]->id, srt[i]->names.fname, srt[i]->names.lname);
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
		pst[id-1].assigned = 1;
		
		printf("Enter the id:\n");
	}
}

void del_assignment(struct seat pst[], int n)
{
	char temp[SLEN];
	int id;
	
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