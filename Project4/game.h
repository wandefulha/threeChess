#pragma once
#include<stdio.h>
#define ROW 3
#define COL 3
#define USER '*'
#define PC '#'
//��ʼ������---�����
int initGameBoard(char arr[ROW][COL],int row,int col);
//�������
void printGameBoard(char arr[ROW][COL], int row, int col);
//����
int pressChess(char arr[ROW][COL], int row, int col,char who);
//�ж���Ӯ
char checkWin(char arr[ROW][COL], int row, int col);
