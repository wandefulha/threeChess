#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//����Ϸ���߼�
void play(char board[ROW][COL], int row, int col) {
	char who = USER;
	while (1) {
		int rowT;
		int colT;
		int ret;
		//�������
		printf("���%c���壬����������:",who);
		scanf("%d %d", &rowT, &colT);
		ret=pressChess(board, rowT, colT,who);
		who = who==USER?PC:USER;
		if (ret == 0) {
			who = who == USER ? PC : USER;
			printf("������������\n");
			continue;
		}
		if (ret == 1) {
			who = who == USER ? PC : USER;
			printf("����λ�ñ�ռ\n");
			continue;
		}
		printGameBoard(board, row, col);
		char tmp;
		if ((tmp=checkWin(board, row, col) )!= ' ') {
			printf("���%cӮ\n",tmp);
			return;
		}
	}
}
//���������
int main() {
	while (1) {
		printf("---------------------------\n");
		printf("---------��ѡ��˵�--------\n");
		printf("----------1.����Ϸ---------\n");
		printf("----------2.�˳�-----------\n");
		printf("---------------------------\n");
		printf("�������Ӧ���:");
		int order;
		scanf("%d", &order);
		//�˳���Ϸ
		if (order == 2) return 0;
		//������������
		if (order != 1) {
			printf("��������");
			continue;
		}
		char board[ROW][COL];
		//��ʼ������
		int pro=initGameBoard(board, ROW, COL);
		if (pro == 0) {
			printf("��������");
			continue;
		}
		//�ڳ�����
		printGameBoard(board, ROW, COL);
		//����
		play(board,ROW,COL);
	}
	return 0;
}