#ifndef OPENINGBOOK_H
#define OPENINGBOOK_H
#include "defines.h"
//如果敌人第一步是j，10的话就走日日
bool WhiteOpening(char board[][GRID_NUM],move_t *best_move);
//自己第一步走j10，根据敌人走法直接生成接下来的两步
bool BlackOpening(char board[][GRID_NUM],move_t *best_move,int steps);
#endif // OPEN_H
