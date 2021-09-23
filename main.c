#include "game.h"

void game() {
	// 初始化地图
	char mines[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mines, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	// 设置地雷
	SetMines(mines, ROW, COL);
	//DisplayBoard(mines, ROW, COL);
	DisplayBoard(show, ROW, COL);
	// 玩家搜雷  如果踩雷直接游戏结束 返回选择界面
	FindMine(show, mines, ROW, COL);
}

void test() {
	printf_s("**************扫雷***************\n");
	printf_s("**********1   game start*********\n");
	printf_s("**********0   exit***************\n");
	printf_s("*********************************\n");
	int isPlay;
	SELECT_OPTION:printf_s("请输入选项:>");
	scanf_s("%d", &isPlay);
	if (isPlay) {
		game();
		goto SELECT_OPTION;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	test();
	return 0;
}