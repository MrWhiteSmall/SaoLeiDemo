#include "game.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char set) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	for (int i = 0; i <= col; ++i) {
		if (i > 0)printf_s(" %d  ",i);
		else printf_s("   ");
	}
	printf_s("\n");
	for (int j = 0; j < col; ++j) {
		if (j == 0)printf_s("  ");
		printf_s("----");
		if (j + 1 == col)printf_s("\n");
	}
	for (int i = 0; i < row; ++i) {
		printf_s("%d |",i + 1);
		for (int j = 0; j < col; ++j) {
			printf_s(" %c |",board[i + 1][j + 1]);
		}
		printf_s("\n");
		for (int j = 0; j < col; ++j) {
			if (j == 0)printf_s("  ");
			printf_s("----");
			if (j + 1 == col)printf_s("\n");
		}
	}
}

void SetMines(char mines[ROWS][COLS], int row, int col) {
	int count = EASY_MODE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mines[x][y] == '0') {
			mines[x][y] = '1';
			--count;
		}
	}
}

int direction[3] = {-1,0,1};
void CountMines(char show[ROWS][COLS],char mines[ROWS][COLS], 
										int row, int col, int x, int y,int *count) {
	if (x <= 0 || x > row || y <= 0 || y > col
		|| show[x][y] != '*' || mines[x][y] == '1') {
		return;
	}
	int countMines = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (mines[x + direction[i]][y + direction[j]] == '1')++countMines;
		}
	}
	//printf_s("count = %d\n", count);
	if (countMines != 0) {
		show[x][y] = '0'+countMines;
		--*count;
	}
	else {
		show[x][y] = ' ';
		--*count;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				CountMines(show, mines, row, col, x + direction[i], y + direction[j],count);
			}
		}
	}
}
void FindMine(char show[ROWS][COLS], char mines[ROWS][COLS], int row, int col) {
	int count = row*col-EASY_MODE;
	while (1)
	{
		printf_s("������ɨ������:>");
		int x, y;
		char p;
		scanf_s("%d %d %c", &x, &y ,&p ,1 );
		if (p == 'P' || p == 'p') {
			show[x][y] = 'P';
			DisplayBoard(show, ROW, COL);
			continue;
		}
		if (x > 0 && x <= row && y > 0 && y <= col && show[x][y] == '*') {
			if (mines[x][y] == '1') {
				printf_s("�ڵ����ˣ����ź�����Ϸʧ��\n");
				break;
			}
			CountMines(show, mines, row, col, x, y,&count);
			printf_s("ʣ��%d��������\n", count);
			//DisplayBoard(mines, ROW, COL);
			DisplayBoard(show, ROW, COL);
		}
		else {
			printf_s("�������������/���������ڹ�������������\n");
		}
		if (count == 0) {
			printf_s("��ȷ��ȫ���׵�λ�ã���Ϸʤ����\n");
			break;
		}
	}
	
}