#include "stdio.h"

#define GRADES 3
#define SLEN 40
#define SIZE 4


struct name
{
	char lname[SLEN];
	char fname[SLEN];	
}; 

struct student
{
	struct name names;
	float grade[GRADES];
	float average;
};

void scores(struct student st[], int n);
void av_score(struct student st[], int n);
void inf_print(struct student st[], int n);
void class_av(struct student st[], int n);
void cleanup(void);

int main(void)
{
	struct student students[SIZE] = 
	{
		{{"Vdovichenko", "Dmitriy"}, {0.0f, 0.0f, 0.0f}, 0.0f},
		{{"Starovoitov", "Alexey"}, {0.0f, 0.0f, 0.0f}, 0.0f},
		{{"Rakistkih", "Andrey"}, {0.0f, 0.0f, 0.0f}, 0.0f},
		{{"Tichonov", "Pavel"}, {0.0f, 0.0f, 0.0f}, 0.0f}
	};
	
	scores(students, SIZE);
	av_score(students, SIZE);
	inf_print(students, SIZE);
	class_av(students, SIZE);
	
	return 0;
}

void scores(struct student st[], int n)
{
	int i, j;
	
	for(i = 0; i < n; i++)
	{
		printf("%s %s\n", st[i].names.fname, st[i].names.lname);
		for(j = 0; j < GRADES; j++)
		{
			printf("Enter grade %d:\n", j+1);
			scanf("%f", &st[i].grade[j]);
			cleanup();
		}
	}
}

void av_score(struct student st[], int n)
{
	int i, j;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < GRADES; j++)
			st[i].average += st[i].grade[j];
		
		st[i].average /= GRADES;
	}
}

void inf_print(struct student st[], int n)
{
	int i, j;
	
	for(i = 0; i < n; i++)
	{
		printf("Name: %s\nSecond name: %s\n",
				st[i].names.fname, st[i].names.lname);
		printf("Grades:\n");
		for(j = 0; j < GRADES; j++)
			printf("Grade %d: %.2f\n", j+1, st[i].grade[j]);
		printf("Average score: %.2f\n", st[i].average);
	}
}
void class_av(struct student st[], int n)
{
	int i, j;
	float aver;
	
	for(j = 0; j < GRADES; j++)
	{
		aver  = 0.0f;
		for(i = 0; i < n; i++)
			aver += st[i].grade[j];
		
		printf("Class average %d: %.2f\n",
				j+1, aver/n);
		
	}
	
}
void cleanup(void)
{
	while(getchar() != '\n')
		;
}

