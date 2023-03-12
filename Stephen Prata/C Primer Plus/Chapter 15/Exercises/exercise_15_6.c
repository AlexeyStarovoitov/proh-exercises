#include "stdio.h"
#include "string.h"

#define FONT_MASK 0xff
#define SIZE_MASK 0x7f
#define LFT_ALGN 0x0
#define CNTR_ALGN 0x1
#define RGHT_ALGN 0x2
#define TOGGLE 0x1

struct txt_info
{
	unsigned int font_id: 8;
	unsigned int font_size: 7;
	unsigned int: 1;
	unsigned int align: 2;
	unsigned int bold: 1;
	unsigned int italic: 1;
	unsigned int underline: 1;
};

void display(struct txt_info *txt_p);
char menu(void);
void cleanup(void);
void change_font(struct txt_info *txt_p);
void change_size(struct txt_info *txt_p);
void change_align(struct txt_info *txt_p);
void toggle_bold(struct txt_info *txt_p);
void toggle_italic(struct txt_info *txt_p);
void toggle_underline(struct txt_info *txt_p);


int main(void)
{
	struct txt_info txt = {200, 120, 1, 1, 1, 1};
	char ch;
	
	display(&txt);
	while((ch = menu()) != 'q')
	{
		switch(ch)
		{
			case 'f':
				change_font(&txt);
				break;
			case 's':
				change_size(&txt);
				break;
			case 'a':
				change_align(&txt);
				break;
			case 'b':
				toggle_bold(&txt);
				break;
			case 'i':
				toggle_italic(&txt);
				break;
			case 'u':
				toggle_underline(&txt);
				break;
		}
		
		display(&txt);
	}
	
	return 0;
}

void display(struct txt_info *txt_p)
{
	printf("ID: %u\n", txt_p->font_id);
	printf("SIZE: %u\n", txt_p->font_size);
	printf("ALIGNMENT: ");
	switch(txt_p->align)
	{
		case LFT_ALGN:
			printf("left\n");
			break;
		case CNTR_ALGN:
			printf("center\n");
			break;
		case RGHT_ALGN:
			printf("right\n");
			break;
	}
	printf("B: %s\n", (txt_p->bold == 1) ? "on":"off");
	printf("I: %s\n", (txt_p->italic == 1) ? "on":"off");
	printf("U: %s\n", (txt_p->underline == 1) ? "on":"off");
}

char menu(void)
{
	char ch;
	
	printf("f)change font s)change size a)change alignment\n");
	printf("b)toggle bold i)toggle italic u)toggle underline\n");
	printf("q)quit\n");
	
	printf("Do your choice: ");
	
	while(strchr("abfisuq", ch = getchar()) == NULL)
	{
		cleanup();
		printf("Try again!\n");
	}
	cleanup();
	return ch;
}

void cleanup(void)
{
	while(getchar() != '\n')
		;
}

void change_font(struct txt_info *txt_p)
{
	unsigned int font;
	
	printf("Enter font ID (0-255): ");
	while(scanf("%u", &font) != 1)
	{
		cleanup();
		printf("Try again!\n");
	}
	cleanup();
	font &= FONT_MASK;
	txt_p->font_id = font;
}

void change_size(struct txt_info *txt_p)
{
	unsigned int size;
	
	printf("Enter font ID (0-127): ");
	while(scanf("%u", &size) != 1)
	{
		cleanup();
		printf("Try again!\n");
	}
	cleanup();
	size &= SIZE_MASK;
	txt_p->font_size = size;	
}

void change_align(struct txt_info *txt_p)
{
	char ch;
	
	printf("l)left c)center r)right\n");
	while(strchr("lcr", ch = getchar()) == NULL)
	{
		cleanup();
		printf("Try again!\n");
	}
	cleanup();
	
	switch(ch)
	{
		case 'l':
			txt_p->align = LFT_ALGN;
			break;
		case 'c':
			txt_p->align = CNTR_ALGN;
			break;
		case 'r':
			txt_p->align = RGHT_ALGN;
			break;
	}
}
	
void toggle_bold(struct txt_info *txt_p)
{
	txt_p->bold ^= TOGGLE;
}

void toggle_underline(struct txt_info *txt_p)
{
	txt_p->underline ^= TOGGLE;
}

void toggle_italic(struct txt_info *txt_p)
{
	txt_p->italic ^= TOGGLE;
}

