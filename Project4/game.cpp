#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "game.h"
//判断输赢
char checkWin(char arr[ROW][COL], int row, int col) {
	char who = ' ';
	for (int i = 0; i < row; i++) {
		int count = 1;
		who=' ';
		for (int j = 0; j < col-1; j++) {
			//行赢
			if (arr[i][j] == arr[i][j + 1]) {
				who = arr[i][j];
				count++;
			}
		}
		if (count == COL) return who;
	}

	for (int i = 0; i < col; i++) {
		int count = 1;
		who = ' ';
		for (int j = 0; j < row - 1; j++) {
			//列赢
			if (arr[j][i] == arr[j+1][i]) {
				who = arr[i][j];
				count++;
			}
		}
		if (count == COL) return who;
	}
	int count = 1;
	for (int i = 0; i < row-1; i++) {
		who = ' ';
		if (arr[i][i] == arr[i + 1][i + 1]) {
			//对角线
			count++;
			who = arr[i][i];
		}
		if (count == COL) return who;
	}
	count = 1;
	for (int i = 0; i < row - 1; i++) {
		who = ' ';
		if (arr[i][row-i-1] == arr[i+1][row-i-2]) {
			//副对角线
			count++;
			who = arr[i][row - i - 1];
		}
		if (count == COL) return who;
	}
	return ' ';
}
//下棋
int pressChess(char arr[ROW][COL], int row, int col,char who) {
	int rowT = row - 1;
	int colT = col - 1;
	if (rowT > ROW || colT > COL) {
		//棋子坐标有误
		return 0;
	}
	if (arr[rowT][colT] != ' ') {
		//棋子位子被占
		return 1;
	}
	//下棋
	arr[rowT][colT] = who;
	return 2;
}
int initGameBoard(char arr[ROW][COL], int row, int col) {
	//健壮性判断
	if (!(arr != NULL && row > 0 && col > 0)) {
		return 0;
	}
	//全部置空
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = ' ';
		}
	}
	return 1;
}

void printGameBoard(char arr[ROW][COL],int row,int col) {
	printf("\n");
	for (int k = 0; k < col; k++) {
		printf("————");
	}
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ", arr[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		for (int k = 0; k < col; k++) {
			printf("————");
		}
		printf("\n");
	}
	printf("\n");
}