#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"//z自己做的头文件 要用""
void menu()
{
	printf("10\n");
	printf("**********");
	printf("**********\n");

}
//游戏的整个算法实现
void game()
{
	char ret = 0;
	//数组存放走出的棋盘信息
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

void test()
{
	srand((unsigned int)time(NULL));
	int input=0;
	do
	{
		menu();
		printf("请输入：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game(); break;
		case 2:
			printf(""); break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}
