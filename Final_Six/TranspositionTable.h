#ifndef TRANSPOSITIONTABLE_H
#define TRANSPOSITIONTABLE_H

#include<hash_map>
#include<hashtable.h>
#include<defines.h>
#include<vector>
#include<algorithm>
typedef struct HashItem
{
    int64_t check;
    int type;
    int depth;
    int value;
};
class TranspositionTable
{
public:
    TranspositionTable();
    unsigned int m_nHashKey32[2][20][20];
    unsigned long m_uHashKey64[2][20][20];
    HashItem Blackhh[1024*1024];
    HashItem Whitehh[1024*1024];
    unsigned int m_HashKey32;
    long m_HashKey64;

    void CalculateInitHashKey(char board[][GRID_NUM]);
    void Hash_MakeMove(move_t best_move,char ourcolor);
    void Hash_UnMakeMove(move_t best_move,char ourcolor);
    int LookUpHashTable(int alpha,int beta,int depth,int color);
    void EnterHashTable(int type,int eval,int depth,int color);
    void InitializeHashKey();
};
static TranspositionTable TT;
#endif // TRANSPOSITIONTABLE_H
