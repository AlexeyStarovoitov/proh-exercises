#include "stdio.h"

void main(void)
{
	// �� �믮������ ������ �ணࠬ�� �㦭� ������� �� ������ ��ப� �� ����⨨ enter ��⮬���᪨ ��⠢����� ᨬ��� ���� ��ப�, �.� ��ॢ��
	// �� ����� ��ப�
	int c, proof, ns;
	ns = 0;
	printf("char proof ns\n");
	while(proof = ((c = getchar()) != EOF))
	{
		if (c == '\n')
		{
			ns++;
		}
		putchar(c);
		printf(" ");
		printf("%d ", proof);
		printf("%d\n", ns);
		
	}
}