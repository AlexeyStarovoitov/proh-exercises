#include "stdio.h"
#include "stdlib.h"
#include "calc.h"

#define MAXOP 100

void main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	
	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop()+pop());
				break;
			case '*':
				push(pop()*pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				break;
			case '\n':
				printf("%.8f\n", pop());
				break;
			default:
				printf("unknow command \n");
				break;
		}
	}
} 