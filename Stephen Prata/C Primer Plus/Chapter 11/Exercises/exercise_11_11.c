#include "stdio.h"
#include "string.h"
#include "ctype.h"

#define LIM 10
#define SIZE 30

void print_str(char arr[][SIZE], int n);
void ascii(char arr[][SIZE], int n);
void str_sort(char arr[][SIZE], int n);
void str_frst_wrd_sort(char arr[][SIZE], int n);
void menu(void);
char *s_gets(char *st, int n);

int main(void)
{
	int choice;
	int num = 0;
	char str[LIM][SIZE];
	
	printf("Enter your strings\n");
	
	while(num < LIM && s_gets(str[num], SIZE))
		num++;
	
	menu();
	
	while(scanf("%d", &choice) == 1)
	{
		switch(choice)
		{
			case 1:
			print_str(str, num+1);
			break;
			case 2:
			ascii(str, num+1);
			break;
			case 3:
			str_sort(str, num + 1);
			break;
			case 4:
			str_frst_wrd_sort(str, num + 1);
			break;
			case 5:
			goto cyc_exit;
			default:
			printf("Try again!\n");
		}
		
		menu();
	}
	
	cyc_exit:
	return 0;
}

void print_str(char arr[][SIZE], int n)
{
	int i;
	
	for(i = 0; i < n; i++)
		printf("%s\n", arr[i]);
	
}

void ascii(char arr[][SIZE], int n)
{
	int i,j;
	
	for(i = 0; i < n; i++)
	{
		for(j = 0; arr[i][j]; j++)
			printf("%d", arr[i][j]);
		printf("\n");
	}
}

void str_sort(char arr[][SIZE], int n)
{
	char *str;
	char *str_p[LIM];
	int i,j;
	
	for(i = 0; i < n; i++)
		str_p[i] = arr[i];
	
	for(i = 0; i < n-1; i++)
		for(j = i + 1; j < n; j++)
			if(strlen(str_p[i]) > strlen(str_p[j]))
			{
				str = str_p[i];
				str_p[i] = str_p[j];
				str_p[j] = str;
			}
	for(i = 0; i < n; i++)
		printf("%s\n", str_p[i]);
}


void str_frst_wrd_sort(char arr[][SIZE], int n)
{
	char *str, *end1, *end2;
	char *str_p[LIM];
	int i,j;
	
	for(i = 0; i < n; i++)
		str_p[i] = arr[i];
	
	for(i = 0; i < n-1; i++)
		for(j = i + 1; j < n; j++)
		{
			end1 = str_p[i];
			end2 = str_p[j];
			while(!isspace(*end1))
				end1++;
			while(!isspace(*end2))
				end2++;
			
			if((end1 - str_p[i]) > (end2 - str_p[j]))
			{
				str = str_p[i];
				str_p[i] = str_p[j];
				str_p[j] = str;
			}
		}
		
	for(i = 0; i < n; i++)
		printf("%s\n", str_p[i]);
	
}

void menu(void)
{
	printf("1) print the original list of strings\n");
	printf("2) print the strings in ASCII collating sequence\n");
	printf("3) print the strings in order of increasing length\n");
	printf("4) print the strings in order of the length of the first word in the string\n");
	printf("5) quit\n");
}

char *s_gets(char *st, int n)
{
	char * ret_val;
	int i = 0;
	
	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		while(st[i] != '\n' && st[i] != '\0')
			i++;
		if(st[i] == '\n')
			st[i] = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	
	return ret_val;
}
