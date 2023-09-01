#ifndef DEBUGPRINT_H_
#define DEBUGPRINT_H_

#include "defines.h"

// Point (x, y) if in the valid position of the board.
#define IsValidPos(x,y)        ((x>0&&x<GRID_NUM-1 )&&(y>0&&y<GRID_NUM-1))

void init_board(char board[][GRID_NUM]);//初始化棋盘
bool is_win_by_premove(char board[][GRID_NUM], move_t* preMove);

void make_move(char board[][GRID_NUM], move_t* move, char color);
void unmake_move(char board[][GRID_NUM], move_t* move);


#endif
