#pragma once
#include<stdio.h>
#define ROW 3
#define COL 3
#define USER '*'
#define PC '#'
//初始化棋盘---数组空
int initGameBoard(char arr[ROW][COL],int row,int col);
//输出棋盘
void printGameBoard(char arr[ROW][COL], int row, int col);
//下棋
int pressChess(char arr[ROW][COL], int row, int col,char who);
//判断输赢
char checkWin(char arr[ROW][COL], int row, int col);
