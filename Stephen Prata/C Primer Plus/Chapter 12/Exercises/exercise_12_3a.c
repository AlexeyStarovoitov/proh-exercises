#include "stdio.h"
#include "exercise_12_3a.h"

int main(void)
{
	int mode;
	int rec_mode = 0;
	
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	
	while(mode >= 0)
	{
		set_mode(mode, &rec_mode);
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	
	return 0;
	
}