#include "OpeningBook.h"
#include "defines.h"
#include "Board.h"
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5
#define F 6
#define G 7
#define H 8
#define I 9
#define J 10
#define K 11
#define L 12
#define M 13
#define N 14
#define O 15
#define P 16
#define Q 17
#define R 18
#define S 19

#define _19 1
#define _18 2
#define _17 3
#define _16 4
#define _15 5
#define _14 6
#define _13 7
#define _12 8
#define _11 9
#define _10 10
#define _9 11
#define _8 12
#define _7 13
#define _6 14
#define _5 15
#define _4 16
#define _3 17
#define _2 18
#define _1 19
bool WhiteOpening(char board[][GRID_NUM],move_t *best_move)//ai 白子开局
{
    //山山定石，希望可以赢哈哈哈哈哈
    if(best_move->positions[1].x==10 && best_move->positions[1].y==10)
    {
        best_move->positions[0].x=K;
        best_move->positions[0].y=_10;
        best_move->positions[1].x=J;
        best_move->positions[1].y=_11;
        return true;
    }
    //对方不是中点开局，可能性很小，做完开局库再优化
    return false;
}

bool BlackOpening(char board[][GRID_NUM],move_t *best_move,int steps)//ai黑子开局，自己先走j10，然后根据各种开局搜索后两步
{
    move_t t;
    //j10 h8 i8 k9 l10 田月
    if(board[J][_10]==BLACK
            && board[H][_8]==WHITE && board[I][_8]==WHITE)
    {
        t.positions[0].x=K;
        t.positions[0].y=_9;
        t.positions[1].x=L;
        t.positions[1].y=_10;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    else if(board[J][_10]==BLACK
            && board[H][_12]==WHITE && board[I][_12]==WHITE)
    {
        t.positions[0].x=K;
        t.positions[0].y=_11;
        t.positions[1].x=L;
        t.positions[1].y=_10;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    else if(board[J][_10]==BLACK
            && board[K][_8]==WHITE && board[L][_8]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_9;
        t.positions[1].x=H;
        t.positions[1].y=_10;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    else if(board[J][_10]==BLACK
            && board[K][_12]==WHITE && board[L][_12]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_11;
        t.positions[1].x=H;
        t.positions[1].y=_10;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }

    //水水
    else if(board[J][_10]==BLACK
            && board[I][_11]==WHITE && board[K][_11]==WHITE)
    {
        t.positions[0].x=J;
        t.positions[0].y=_11;
        t.positions[1].x=J;
        t.positions[1].y=_12;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    else if(board[J][_10]==BLACK
            && board[I][_9]==WHITE && board[K][_9]==WHITE)
    {
        t.positions[0].x=J;
        t.positions[0].y=_9;
        t.positions[1].x=J;
        t.positions[1].y=_8;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    else if(board[J][_10]==BLACK
            && board[I][_9]==WHITE && board[I][_11]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_10;
        t.positions[1].x=H;
        t.positions[1].y=_10;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    else if(board[J][_10]==BLACK
            && board[K][_9]==WHITE && board[K][_11]==WHITE)
    {
        t.positions[0].x=K;
        t.positions[0].y=_10;
        t.positions[1].x=L;
        t.positions[1].y=_10;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }

    //山山
    else if(board[J][_10]==BLACK
            && board[J][_11]==WHITE && board[K][_10]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_11;
        t.positions[1].x=I;
        t.positions[1].y=_12;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    else if(board[J][_10]==BLACK
            && board[K][_10]==WHITE && board[J][_9]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_8;
        t.positions[1].x=I;
        t.positions[1].y=_9;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    else if(board[J][_10]==BLACK
            && board[J][_9]==WHITE && board[I][_10]==WHITE)
    {
        t.positions[0].x=H;
        t.positions[0].y=_11;
        t.positions[1].x=I;
        t.positions[1].y=_11;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    else if(board[J][_10]==BLACK
            && board[J][_11]==WHITE && board[I][_10]==WHITE)
    {
        t.positions[0].x=K;
        t.positions[0].y=_11;
        t.positions[1].x=K;
        t.positions[1].y=_12;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }

    //日日
    //h9 i8 k11 j12
    else if(board[J][_10]==BLACK
            && board[H][_9]==WHITE && board[I][_8]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_11;
        t.positions[1].x=I;
        t.positions[1].y=_12;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    //k8 l9 i11 j10
    else if(board[J][_10]==BLACK
            && board[K][_8]==WHITE && board[L][_9]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_11;
        t.positions[1].x=J;
        t.positions[1].y=_10;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    //h11 i12 k9 l10
    else if(board[J][_10]==BLACK
            && board[H][_11]==WHITE && board[I][_12]==WHITE)
    {
        t.positions[0].x=K;
        t.positions[0].y=_9;
        t.positions[1].x=L;
        t.positions[1].y=_10;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    //k12 l11 i9 j8
    else if(board[J][_10]==BLACK
            && board[K][_12]==WHITE && board[L][_11]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_9;
        t.positions[1].x=I;
        t.positions[1].y=_8;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    //贴边开局
    //i10 k10 i9 k11
    else if(board[J][_10]==BLACK
            && board[K][_10]==WHITE && board[I][_10]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_9;
        t.positions[1].x=K;
        t.positions[1].y=_11;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    //j9 j11 i11 k9
    else if(board[J][_10]==BLACK
            && board[J][_9]==WHITE && board[J][_11]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_11;
        t.positions[1].x=K;
        t.positions[1].y=_9;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    //k9k10k11i9
    else if(board[J][_10]==BLACK
            && board[K][_9]==WHITE && board[K][_10]==WHITE)
    {
        t.positions[0].x=K;
        t.positions[0].y=_11;
        t.positions[1].x=I;
        t.positions[1].y=_9;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    //i9i10i11k9
    else if(board[J][_10]==BLACK
            && board[I][_9]==WHITE && board[I][_10]==WHITE)
    {
        t.positions[0].x=I;
        t.positions[0].y=_11;
        t.positions[1].x=K;
        t.positions[1].y=_9;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;
    }
    //远水
    else if(board[J][_10]==BLACK
            && board[I][_11]==WHITE && board[K][_9]==WHITE)
    {
        t.positions[0].x=H;
        t.positions[0].y=_10;
        t.positions[1].x=J;
        t.positions[1].y=_8;
        if(steps==3)
        {
            best_move->positions[0].x=t.positions[0].x;
            best_move->positions[0].y=t.positions[0].y;
            best_move->positions[1].x=t.positions[1].x;
            best_move->positions[1].y=t.positions[1].y;
            return true;
        }
        else  return false;

    }
    else if(board[J][_10]==BLACK
    && board[J][_11]==WHITE && board[K][_8]==WHITE)
    {
    t.positions[0].x=K;
    t.positions[0].y=_11;
    t.positions[1].x=L;
    t.positions[1].y=_12;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    //心日
    else if(board[J][_10]==BLACK
    && board[K][_8]==WHITE && board[K][_10]==WHITE)
    {
    t.positions[0].x=K;
    t.positions[0].y=_11;
    t.positions[1].x=J;
    t.positions[1].y=_12;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    else if(board[J][_10]==BLACK
    && board[I][_10]==WHITE && board[I][_12]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=J;
    t.positions[1].y=_8;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    //远水月
    else if(board[J][_10]==BLACK
    && board[K][_9]==WHITE && board[I][_13]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=K;
    t.positions[1].y=_11;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    //水月
    else if(board[J][_10]==BLACK
    && board[I][_11]==WHITE && board[I][_13]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=L;
    t.positions[1].y=_11;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    else if(board[J][_10]==BLACK
    && board[K][_7]==WHITE && board[K][_9]==WHITE)
    {
    t.positions[0].x=K;
    t.positions[0].y=_11;
    t.positions[1].x=I;
    t.positions[1].y=_9;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    //远水心
    else if(board[J][_10]==BLACK
    && board[I][_11]==WHITE && board[K][_10]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=K;
    t.positions[1].y=_11;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    else if(board[J][_10]==BLACK
    && board[I][_10]==WHITE && board[K][_9]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=K;
    t.positions[1].y=_11;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    //水心反面
    else if(board[J][_10]==BLACK
    && board[I][_10]==WHITE && board[I][_11]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=K;
    t.positions[1].y=_11;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    //远水日
    else if(board[J][_10]==BLACK
    && board[I][_11]==WHITE && board[K][_8]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=K;
    t.positions[1].y=_11;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    else if(board[J][_10]==BLACK
    && board[I][_12]==WHITE && board[K][_9]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=K;
    t.positions[1].y=_11;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    //水日
    else if(board[J][_10]==BLACK
    && board[I][_11]==WHITE && board[I][_12]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=K;
    t.positions[1].y=_11;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    else if(board[J][_10]==BLACK
    && board[K][_9]==WHITE && board[K][_8]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=K;
    t.positions[1].y=_11;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    //山日
    else if(board[J][_10]==BLACK
    && board[J][_9]==WHITE && board[K][_8]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_10;
    t.positions[1].x=K;
    t.positions[1].y=_10;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    else if(board[J][_10]==BLACK
    && board[J][_11]==WHITE && board[I][_12]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_10;
    t.positions[1].x=K;
    t.positions[1].y=_10;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    else if(board[J][_10]==BLACK
    && board[J][_11]==WHITE && board[K][_8]==WHITE)
    {
    t.positions[0].x=K;
    t.positions[0].y=_11;
    t.positions[1].x=L;
    t.positions[1].y=_12;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }
    else if(board[J][_10]==BLACK
    && board[J][_9]==WHITE && board[I][_12]==WHITE)
    {
    t.positions[0].x=I;
    t.positions[0].y=_9;
    t.positions[1].x=H;
    t.positions[1].y=_8;
    if(steps==3)
    {
    best_move->positions[0].x=t.positions[0].x;
    best_move->positions[0].y=t.positions[0].y;
    best_move->positions[1].x=t.positions[1].x;
    best_move->positions[1].y=t.positions[1].y;
    return true;
    }
     else  return false;
    }

    return false;


}
