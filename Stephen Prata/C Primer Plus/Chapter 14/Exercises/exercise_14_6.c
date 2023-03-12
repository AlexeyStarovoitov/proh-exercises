#include "stdio.h"
#include "stdlib.h"

#define SLEN 40
#define SIZE 4

struct name
{
	char lname[SLEN];
	char fname[SLEN];	
}; 

struct player
{
	struct name names;
	int bats;
	int hits;
	int walks;
	int rbi;
	float bat_aver;
};

void read_in(struct player pl[], int n, FILE *fp);
void bat_Aver(struct player pl[], int n);
void inf_print(struct player pl[], int n);


int main(int argc, char *argv[])
{
	struct player players[SIZE];
	int i;
	FILE *fp;
	
	if(argc != 2)
		exit(EXIT_FAILURE);
	if((fp = fopen(argv[1], "r")) == NULL)
		exit(EXIT_FAILURE);
	
	for(i = 0; i < SIZE; i++)
	{
		players[i].bats = players[i].hits = players[i].walks = players[i].rbi = 0;
		players[i].bat_aver = 0.0f;
	}
	
	read_in(players, SIZE, fp);
	bat_Aver(players, SIZE);
	inf_print(players, SIZE);
	
	fclose(fp);
	return 0;
	
}


void read_in(struct player pl[], int n, FILE *fp)
{
	int bats, hits, walks, rbi;
	int index;
	
	while((fscanf(fp, "%d", &index) == 1) && (index < n))
	{
		fscanf(fp, "%s", pl[index].names.fname);
		fscanf(fp, "%s", pl[index].names.lname);
		fscanf(fp, "%d %d %d %d", &bats, &hits, &walks, &rbi);
		
		pl[index].bats += bats;
		pl[index].hits += hits;
		pl[index].walks += walks;
		pl[index].rbi += rbi;
	}
}

void bat_Aver(struct player pl[], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
		if(pl[i].bats != 0)
			pl[i].bat_aver = (float)pl[i].hits/pl[i].bats; 
}

void inf_print(struct player pl[], int n)
{
	int i;
	
	int bats_tot = 0;
	int hits_tot = 0;
	int walks_tot = 0;
	int rbi_tot = 0;
	float bat_aver_tot = 0.0f;
	
	printf("N name surname bats hits walks rbi bat_aver\n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d %s %s %d %d %d %d %.2f\n", i, pl[i].names.fname, pl[i].names.lname,
				pl[i].bats, pl[i].hits, pl[i].walks, pl[i].rbi, pl[i].bat_aver);
		
		bats_tot += pl[i].bats;
		hits_tot += pl[i].hits;
		walks_tot += pl[i].walks;
		rbi_tot += pl[i].rbi;
		bat_aver_tot += pl[i].bat_aver;
	}
	
	printf("Total:\n");
	printf("Bats: %d\n", bats_tot);
	printf("Hits: %d\n", hits_tot);
	printf("Walks: %d\n", walks_tot);
	printf("RBI: %d\n", rbi_tot);
	printf("Bat aver: %.2f\n", bat_aver_tot);
		
	
}