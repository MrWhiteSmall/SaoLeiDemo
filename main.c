#include "game.h"

void game() {
	// ��ʼ����ͼ
	char mines[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mines, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	// ���õ���
	SetMines(mines, ROW, COL);
	//DisplayBoard(mines, ROW, COL);
	DisplayBoard(show, ROW, COL);
	// �������  �������ֱ����Ϸ���� ����ѡ�����
	FindMine(show, mines, ROW, COL);
}

void test() {
	printf_s("**************ɨ��***************\n");
	printf_s("**********1   game start*********\n");
	printf_s("**********0   exit***************\n");
	printf_s("*********************************\n");
	int isPlay;
	SELECT_OPTION:printf_s("������ѡ��:>");
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