#include <stdio.h>
#include <stdlib.h>

char getinputt;

void getinputt_init(char* b)
{
	*b = '0';
}

int main()
{
	char origin_map[10][10] = { {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
		{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'} };

	int index1 = 1;
	int index2 = 1;
	char tmp;

	origin_map[index1][index2] = '#';	//�����
	origin_map[9][9] = 'G';				//��ǥ

	printf("���� �̵�: a, ���� �̵�: d, ���� �̵�: w, �Ʒ��� �̵�: s\n");
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			printf("%c ", origin_map[i][k]);
		}
		printf("\n");
	}

	while (1)
	{
		tmp = 0;
		getinputt_init(&getinputt);
		int M1, M2, M3, M4;

		getinputt = (char)getch();

		if (getinputt == 'a')	//�������� �̵�
		{
				tmp = origin_map[index1][index2];
				origin_map[index1][index2] = origin_map[index1][index2 - 1];
				origin_map[index1][index2 - 1] = tmp;
				index2--;
		}
		else if (getinputt == 'd')	//�������� �̵�
		{
				tmp = origin_map[index1][index2];
				origin_map[index1][index2] = origin_map[index1][index2 + 1];
				origin_map[index1][index2 + 1] = tmp;
				index2++;

				if (index1 == 9 && index2 == 9)
				{
					printf("�¸��� �����մϴ�!\n");
					break;
				}
		}
		else if (getinputt == 's')    //�Ʒ������� �̵�
		{
				tmp = origin_map[index1][index2];
				origin_map[index1][index2] = origin_map[index1 + 1][index2];
				origin_map[index1 + 1][index2] = tmp;
				index1++;

				if (index1 == 9 && index2 == 9)
				{
					printf("�¸��� �����մϴ�!\n");
					break;
				}
		}
		else    //�������� �̵�
		{
				tmp = origin_map[index1][index2];
				origin_map[index1][index2] = origin_map[index1 - 1][index2];
				origin_map[index1 - 1][index2] = tmp;
				index1--;
		}

		srand(time(NULL));
		M1 = rand() % 10;
		M2 = rand() % 10;
		M3 = rand() % 10;
		M4 = rand() % 10;

		if (M1 != M3 || M4 != M2)
		{
			if (M1 != 9 && M2 != 9)
			{
				origin_map[M1][M2] = 'M';
			}
			if (M3 != 9 && M4 != 9)
			{
				origin_map[M3][M4] = 'M';
			}
		}

		if ((M1 == index1 && M2 == index2)||(M4 == index2 && M3 == index1))
		{
			printf("���� ����");
			break;
		}

		printf("\n===== �̵� ��� =====\n");
		for (int i = 0; i < 10; i++)
		{
			for (int k = 0; k < 10; k++)
			{
				printf("%c ", origin_map[i][k]);
			}
			printf("\n");
		}
		printf("���� �̵�: a, ���� �̵�: d, ���� �̵�: w, �Ʒ��� �̵�: s\n");

		origin_map[M1][M2] = '0';
		origin_map[M3][M4] = '0';
	}

	return 0;
}