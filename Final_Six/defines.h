
#ifndef DEFINES_H
#define DEFINES_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <vector>

#define                 blockSize  30
#define                 chessSize  20
#define                  markSize  10

#define GRID_NUM            21
#define GRID_COUNT          361
#define BLACK               1
#define WHITE               2
#define BORDER              3
#define NOSTONE             0
#define BLOCKSIZE
#define MSG_LENGTH          512

// 估分极值
#define MAXINT              20000
#define MININT              -20000

//搜索深度预设
#define VCFDEPTH            14          //
#define ANTIVCFDEPTH        10          //
#define ANTIVCFN            5           //
//搜索广度预设，可优化
#define NUMOFONE            9           //
#define NUMOFTWO            4           //
typedef  struct moveHistory
{
    int x;
    int y;
    int color;
}move_h;
// 棋盘上的位置
typedef struct _stoneposition
{
    int x;
    int y;
} pos_t;

// 双步
typedef struct _stonemove
{
    pos_t       positions[2];
    double      score;
} move_t;

// 单步
typedef struct chess
{
    int x , y;
    int score;
}move_one_t;

extern int g_board_base_score[GRID_NUM-2][GRID_NUM-2];             //棋盘初值

#endif // DEFINES_H
