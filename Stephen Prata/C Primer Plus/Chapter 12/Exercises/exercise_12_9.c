#include "stdlib.h"
#include "stdio.h"
#include "ctype.h"

#define SIZE 50

int main(void)
{
	int words, len;
	int i, j;
	char temp_arr[SIZE];
	char **pc;
	char ch;
	
	printf("How many words do you wish to enter? ");
	
	while(scanf("%d", &words) == 1 && words > 0)
	{
		
		scanf("%d", &words);
		pc = (char **)malloc(words * sizeof(char *));
		
		while(isspace(ch = getchar()))
			continue;
		
		for(i = 0; i < words; i++)
		{
			for(j = 0; !isspace(ch); j++)
			{
				temp_arr[j] = ch;
				ch = getchar();
			}
			
			temp_arr[j] = '\0';
			if(i != (words - 1))
				while(isspace(ch))
					ch = getchar();
			else
				while(ch != '\n')
					ch = getchar();
				
			len = j+1;
			*(pc+i) = (char *)malloc(len*sizeof(char));
			
			for(j = 0; j < len; j++)
			{
				*(*(pc+i)+j) = temp_arr[j];
			}

				
		}
			
		for(i = 0; i < words; i++)
		{
			j = 0;
			while(pc[i][j] != '\0')
			{
				putchar(pc[i][j]);
				j++;
			}
			putchar('\n');
			free(*(pc+i));
		}
		free(pc);
	
		printf("How many words do you wish to enter? ");
	}
	
	return 0;
}