//listing_14_11.c -- compound literals

#include "stdio.h"
#define MAXTITL 41
#define MAXAUTL 31

struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book readfirst;
	int score;
	
	printf("Enter test score: ");
	scanf("%d", &score);
	
	if(score >= 84)
		readfirst = (struct book){.title = "Crime and Punishment",
									"Fyodor Dostoevsky",
									11.25};
	else
		readfirst = (struct book) {"Mr. Bouncy's Nice Hat",
									.author = "Fred Winsome",
									11.25};
	
	printf("Your assigned reading:\n");
	printf("%s by %s: $%.2f\n", readfirst.title,
			readfirst.author, readfirst.value);
	
	return 0;
}
