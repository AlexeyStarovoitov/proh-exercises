#include "stdio.h"

int main(void)
{
	const int dunbar_num = 150;
	int week, friends;
	
	friends = 5;
	
	printf("weeks: friends: \n");
	
	for(week = 1; friends <= dunbar_num; week++)
	{
		friends = (friends - week)*2;
		if (friends <= dunbar_num)
			printf("%5d %5d\n", week, friends);
	}
	
	return 0;
}