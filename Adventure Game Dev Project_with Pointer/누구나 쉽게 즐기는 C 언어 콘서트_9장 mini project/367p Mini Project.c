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

	origin_map[index1][index2] = '#';	//사용자
	origin_map[9][9] = 'G';				//목표

	printf("왼쪽 이동: a, 우측 이동: d, 위쪽 이동: w, 아래쪽 이동: s\n");
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

		if (getinputt == 'a')	//좌측으로 이동
		{
				tmp = origin_map[index1][index2];
				origin_map[index1][index2] = origin_map[index1][index2 - 1];
				origin_map[index1][index2 - 1] = tmp;
				index2--;
		}
		else if (getinputt == 'd')	//우측으로 이동
		{
				tmp = origin_map[index1][index2];
				origin_map[index1][index2] = origin_map[index1][index2 + 1];
				origin_map[index1][index2 + 1] = tmp;
				index2++;

				if (index1 == 9 && index2 == 9)
				{
					printf("승리를 축하합니다!\n");
					break;
				}
		}
		else if (getinputt == 's')    //아래쪽으로 이동
		{
				tmp = origin_map[index1][index2];
				origin_map[index1][index2] = origin_map[index1 + 1][index2];
				origin_map[index1 + 1][index2] = tmp;
				index1++;

				if (index1 == 9 && index2 == 9)
				{
					printf("승리를 축하합니다!\n");
					break;
				}
		}
		else    //위쪽으로 이동
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
			printf("게임 실패");
			break;
		}

		printf("\n===== 이동 결과 =====\n");
		for (int i = 0; i < 10; i++)
		{
			for (int k = 0; k < 10; k++)
			{
				printf("%c ", origin_map[i][k]);
			}
			printf("\n");
		}
		printf("왼쪽 이동: a, 우측 이동: d, 위쪽 이동: w, 아래쪽 이동: s\n");

		origin_map[M1][M2] = '0';
		origin_map[M3][M4] = '0';
	}

	return 0;
}