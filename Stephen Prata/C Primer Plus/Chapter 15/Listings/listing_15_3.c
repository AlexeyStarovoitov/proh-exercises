//listing_15_3.c -- define and use fields

#include "stdio.h"
#include "stdbool.h"


#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define BLUE 4
#define GREEN 2
#define RED 1

#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char *colours[8] = {"black", "red", "green", "yellow",
							"blue", "magenta", "cyan", "white"};


struct box_props
{
	bool opaque : 1;
	unsigned int fill_colour : 3;
	unsigned int : 4;
	bool show_border : 1;
	unsigned int border_colour : 3;
	unsigned int border_style: 2;
	unsigned int : 2;
};

void show_settings(const struct box_props *pb);

int main(void)
{
	struct box_props box = {true, YELLOW, true, GREEN, DASHED};
	
	printf("Original box settings:\n");
	show_settings(&box);
	
	box.opaque = false;
	box.fill_colour = WHITE;
	box.border_colour = MAGENTA;
	box.border_style = SOLID;
	printf("\nModified box settings:\n");
	show_settings(&box);

	return 0;
}

void show_settings(const struct box_props * pb)
{
	printf("Box is %s.\n",
			pb->opaque == true ? "opaque":"transparent");
	printf("The fill colour is %s.\n", colours[pb->fill_colour]);
	printf("Border is %s\n",
			pb->show_border == true ? "shown" : "not shown");
	printf("The border colour is %s.\n", colours[pb->border_colour]);
	printf("The border style is ");
	switch(pb->border_style)
	{
		case SOLID: printf("solid.\n"); break;
		case DOTTED: printf("dotted.\n"); break;
		case DASHED: printf("dashed.\n"); break;
		default: printf("Unkbown type.\n");
	}
}