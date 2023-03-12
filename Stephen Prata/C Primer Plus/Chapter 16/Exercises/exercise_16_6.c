#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define SIZE 4
#define LEN 40

typedef struct
{
	char first[LEN];
	char last[LEN];
	
} names;

void show_array(names ar[], int size);
int my_sort(const void *a1, const void *a2);


int main(void)
{
	names arr[SIZE] = {[0] = {.first = "Alex", .last = "Starovoitov"},
					   [1] = {.first = "Dmitriy", .last = "Vdovichenko"},
					   [2] = {.first = "Andrew", .last = "Raritskih"},
					   [3] = {.first = "Paul", .last = "Tihonov"}};
	
	show_array(arr, SIZE);
	qsort((void *) arr, SIZE, sizeof(names), my_sort);
	
	printf("Sorted: \n");
	show_array(arr, SIZE);
	
	return 0;
}



void show_array(names ar[], int size)
{
	int i;
	
	for(i = 0; i < size; i++)
		printf("Surname: %s\nName: %s\n\n", ar[i].last, ar[i].first);
}

int my_sort(const void *a1, const void *a2)
{
	const names *a1_s = (const names *)a1;
	const names *a2_s = (const names *)a2;
	
	int res;
	
	res = strcmp(a1_s->last, a2_s->last);
	
	if (res != 0)
		return res;
	else
		return strcmp(a1_s->first, a2_s->first);
	
}