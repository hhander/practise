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
		printf("����win\n");
	}
	if (ret == 'q')
	{
		printf("ƽ��\n");
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
		printf("��ѡ��");
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
			printf("�˳���Ϸ");
			break;
		}
		default:
		{
			printf("�������");
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