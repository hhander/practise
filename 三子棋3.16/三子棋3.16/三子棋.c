#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board,ROW,COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		char ret = IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		system("cls");
		DisplayBoard(board, ROW, COL);
		char ret = IsWin(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("you win\n");
	}
	if (ret == '#')
	{
		printf("电脑win\n");
	}
	if (ret == 'q')
	{
		printf("平局\n");
	}
}




void menu()
{
	printf("**************************\n");
	printf("***** 1. play 0. quit*****\n");
	printf("**************************\n");
}

void test()
{
	int input = 0;
	do
	{	
		srand((unsigned int)time(NULL));
		menu();
		printf("请选择");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("退出游戏");
			break;
		}
		default:
		{
			printf("输入错误");
			break;
		}
		}		
	} while (input);
}






int main()
{
	test();
	return 0;
}