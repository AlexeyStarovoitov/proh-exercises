#include "stdio.h"
#include "string.h"

#define SIZE_SHIFT 8
#define ALIGN_SHIFT 16
#define TOGGLE_B_SHIFT 18
#define TOGGLE_I_SHIFT 19
#define TOGGLE_U_SHIFT 20

#define FONT_MASK 0xff
#define SIZE_MASK 0x7f00
#define ALIGN_MASK 0x30000
#define LFT_ALGN 0x0
#define CNTR_ALGN 0x1
#define RGHT_ALGN 0x2
#define TOGGLE_B (1 << TOGGLE_B_SHIFT)
#define TOGGLE_I (1 << TOGGLE_I_SHIFT)
#define TOGGLE_U (1 << TOGGLE_U_SHIFT)


void display(const unsigned long *txt_p);
char menu(void);
void cleanup(void);
void change_font(unsigned long *txt_p);
void change_size(unsigned long *txt_p);
void change_align(unsigned long *txt_p);
void toggle_bold(unsigned long *txt_p);
void toggle_italic(unsigned long *txt_p);
void toggle_underline(unsigned long *txt_p);


int main(void)
{
	unsigned long txt = 200 | (120 << SIZE_SHIFT) | (1 << ALIGN_SHIFT) | (1 << TOGGLE_B_SHIFT)| (1 << TOGGLE_I_SHIFT) | (1 << TOGGLE_U_SHIFT);
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

void display(const unsigned long *txt_p)
{
	printf("ID: %u\n", *txt_p & FONT_MASK);
	printf("SIZE: %u\n", (*txt_p & SIZE_MASK) >> SIZE_SHIFT);
	printf("ALIGNMENT: ");
	switch((*txt_p & ALIGN_MASK) >> ALIGN_SHIFT)
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
	printf("B: %s\n", (*txt_p & TOGGLE_B) ? "on":"off");
	printf("I: %s\n", (*txt_p & TOGGLE_I) ? "on":"off");
	printf("U: %s\n", (*txt_p & TOGGLE_U) ? "on":"off");
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

void change_font(unsigned long *txt_p)
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
	*txt_p &= ~FONT_MASK;
	*txt_p |= font;
}

void change_size(unsigned long *txt_p)
{
	unsigned int size;
	
	printf("Enter font ID (0-127): ");
	while(scanf("%u", &size) != 1)
	{
		cleanup();
		printf("Try again!\n");
	}
	cleanup();
	size &= (SIZE_MASK >> SIZE_SHIFT);
	*txt_p &= ~SIZE_MASK;
	*txt_p |= (size << SIZE_SHIFT);	
}

void change_align(unsigned long *txt_p)
{
	char ch;
	
	printf("l)left c)center r)right\n");
	while(strchr("lcr", ch = getchar()) == NULL)
	{
		cleanup();
		printf("Try again!\n");
	}
	cleanup();
	*txt_p &= ~ALIGN_MASK;
	
	switch(ch)
	{
		case 'l':
			*txt_p |= (LFT_ALGN << ALIGN_SHIFT);
			break;
		case 'c':
			*txt_p |= (CNTR_ALGN << ALIGN_SHIFT);
			break;
		case 'r':
			*txt_p |= (RGHT_ALGN << ALIGN_SHIFT);
			break;
	}
}
	
void toggle_bold(unsigned long *txt_p)
{
	*txt_p ^= TOGGLE_B;
}

void toggle_underline(unsigned long *txt_p)
{
	*txt_p ^= TOGGLE_U;
}

void toggle_italic(unsigned long *txt_p)
{
	*txt_p ^= TOGGLE_I;
}
