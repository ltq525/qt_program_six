#include "TranspositionTable.h"
#include "time.h"
#include "random"
#include<algorithm>
TranspositionTable::TranspositionTable()
{

}
void TranspositionTable::InitializeHashKey()
{
    srand((unsigned int)time(NULL));

    for(int i=0;i<=1;i++)
    {
        for(int x=1;x<20;i++)
            for(int y=1;y<20;y++)
            {
                m_nHashKey32[i][x][y]= (unsigned int)rand() ^ ((unsigned int)rand() << 15) ^ ((unsigned int)rand() << 30);
                m_uHashKey64[i][x][y]=((unsigned __int64)rand())
                        ^((unsigned __int64)rand() << 15)
                        ^((unsigned __int64)rand() << 30)
                        ^((unsigned __int64)rand() << 45)
                        ^((unsigned __int64)rand() << 60);
            }
    }

}

void TranspositionTable::CalculateInitHashKey(char (*board)[21])
{
    m_HashKey32=0;
    m_HashKey64=0;
    for(int i=1;i<20;i++)
    {
        for(int j=1;j<20;j++)
        {
            if(board[i][j])
            {
                if(board[i][j]==BLACK)
                {
                    m_HashKey32+=m_nHashKey32[0][i][j];
                    m_HashKey64+=m_uHashKey64[0][i][j];
                }
                else {
                    m_HashKey32+=m_nHashKey32[1][i][j];
                    m_HashKey64+=m_uHashKey64[1][i][j];
                }
            }

        }
    }
}
void TranspositionTable::Hash_MakeMove(move_t best_move,char ourcolor)
{
    if(ourcolor==BLACK)
    {
        m_HashKey32+=m_nHashKey32[0][best_move.positions[0].x][best_move.positions[0].y];
        m_HashKey32+=m_nHashKey32[0][best_move.positions[1].x][best_move.positions[1].y];
        m_HashKey64+=m_uHashKey64[0][best_move.positions[0].x][best_move.positions[0].y];
        m_HashKey64+=m_uHashKey64[0][best_move.positions[1].x][best_move.positions[1].y];
    }
    else {
        m_HashKey32+=m_nHashKey32[0][best_move.positions[0].x][best_move.positions[0].y];
        m_HashKey32+=m_nHashKey32[0][best_move.positions[1].x][best_move.positions[1].y];
        m_HashKey64+=m_uHashKey64[0][best_move.positions[0].x][best_move.positions[0].y];
        m_HashKey64+=m_uHashKey64[0][best_move.positions[1].x][best_move.positions[1].y];
    }
}
void TranspositionTable::Hash_UnMakeMove(move_t best_move,char ourcolor)
{
    if(ourcolor==BLACK)
    {
        m_HashKey32-=m_nHashKey32[0][best_move.positions[0].x][best_move.positions[0].y];
        m_HashKey32-=m_nHashKey32[0][best_move.positions[1].x][best_move.positions[1].y];
        m_HashKey64-=m_uHashKey64[0][best_move.positions[0].x][best_move.positions[0].y];
        m_HashKey64-=m_uHashKey64[0][best_move.positions[1].x][best_move.positions[1].y];
    }
    else {
        m_HashKey32-=m_nHashKey32[0][best_move.positions[0].x][best_move.positions[0].y];
        m_HashKey32-=m_nHashKey32[0][best_move.positions[1].x][best_move.positions[1].y];
        m_HashKey64-=m_uHashKey64[0][best_move.positions[0].x][best_move.positions[0].y];
        m_HashKey64-=m_uHashKey64[0][best_move.positions[1].x][best_move.positions[1].y];
    }
}
void TranspositionTable::EnterHashTable(int type, int eval, int depth, int color)
{
    int x=m_HashKey32 & 0xFFFFF;
    HashItem h;
    if(color==BLACK)
    {
        Blackhh[x].type=type;
        Blackhh[x].check=m_HashKey64;
        Blackhh[x].depth=depth;
        Blackhh[x].value=eval;
    }
    else {
        Whitehh[x].type=type;
        Whitehh[x].check=m_HashKey64;
        Whitehh[x].depth=depth;
        Whitehh[x].value=eval;
    }
}

int TranspositionTable::LookUpHashTable(int alpha,int beta,int depth,int color)
{
    if(color==BLACK)
    {
        int x = m_HashKey32;
        int type = Blackhh[x].type;
        if(type==1)
            return Blackhh[x].value;
        else if(type==2)//下边界
        {
            if(Blackhh[x].value >=beta)
                return Blackhh[x].value;
        }
        else {
            if(Blackhh[x].value <alpha)
            {
                return Blackhh[x].value;
            }
        }
    }
    else {
        int x = m_HashKey32;
        int type = Whitehh[x].type;
        if(type==1)
            return Whitehh[x].value;
        else if(type==2)//下边界
        {
            if(Whitehh[x].value >=beta)
                return Whitehh[x].value;
        }
        else {
            if(Whitehh[x].value <alpha)
            {
                return Whitehh[x].value;
            }
        }
    }
    return 0;
}
