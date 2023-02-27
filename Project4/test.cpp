#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//玩游戏的逻辑
void play(char board[ROW][COL], int row, int col) {
	char who = USER;
	while (1) {
		int rowT;
		int colT;
		int ret;
		//玩家下棋
		printf("玩家%c下棋，请输入坐标:",who);
		scanf("%d %d", &rowT, &colT);
		ret=pressChess(board, rowT, colT,who);
		who = who==USER?PC:USER;
		if (ret == 0) {
			who = who == USER ? PC : USER;
			printf("棋子坐标有误\n");
			continue;
		}
		if (ret == 1) {
			who = who == USER ? PC : USER;
			printf("棋子位置被占\n");
			continue;
		}
		printGameBoard(board, row, col);
		char tmp;
		if ((tmp=checkWin(board, row, col) )!= ' ') {
			printf("玩家%c赢\n",tmp);
			return;
		}
	}
}
//主函数入口
int main() {
	while (1) {
		printf("---------------------------\n");
		printf("---------请选择菜单--------\n");
		printf("----------1.玩游戏---------\n");
		printf("----------2.退出-----------\n");
		printf("---------------------------\n");
		printf("请输入对应序号:");
		int order;
		scanf("%d", &order);
		//退出游戏
		if (order == 2) return 0;
		//其他序号则出错
		if (order != 1) {
			printf("输入有误");
			continue;
		}
		char board[ROW][COL];
		//初始化棋盘
		int pro=initGameBoard(board, ROW, COL);
		if (pro == 0) {
			printf("输入有误");
			continue;
		}
		//摆出棋盘
		printGameBoard(board, ROW, COL);
		//下棋
		play(board,ROW,COL);
	}
	return 0;
}