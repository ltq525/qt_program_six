//victor of continue four
//一种五子棋的进攻策略，采用连续的冲四，活四进攻
//因为一旦达成后，对手的下一步时可以确定的，所以
//可以在这个基础上可以更容易做出双威胁
#ifndef THREATSEARCH_H_
#define THREATSEARCH_H_

#include <vector>

#include "TypeSearch.h"

#define HASHSIZE 19997

//VCFSearch
typedef struct _node
{
    pos_t p1;
    pos_t p2;
    int pre, next;
}node_t;

typedef struct _listnode
{
    int pos;
    int score;
    int dist;
}ListNode;

typedef struct _hashnode
{
    int dep;
    unsigned long hash;
    int pre;
    move_t move;
    bool res;
    char color;
}HashNode;

class ThreatSearch {
    public:
        ThreatSearch();
       // CVCFSearch(char* ptr_board[GRID_NUM], char* ptr_chess_type);

        // Check if VCFSearch is needed.
        bool ThreatJudge(move_t * preMove);

        int init();

        void init_game();

        void BeforeSearch(char board[][GRID_NUM], char color);

        // VCFSearch implements.执行双VCF搜索
        bool vcf_search(int depth,char ourColor,move_t * bestMove,move_t * preMove, int preNode, int prePos);

        // Anti search for VCF.反vcf
        bool anti_vcf_search(int depth,char ourColor,move_t * bestMove,move_t * preMove, int preNode, int prePos);

    private:
        // 走法列表的产生
        int GetMoveList( char ourColor,char a_d, pos_t * canUse, int n_Pos, move_t * moveList, move_t* pretMove);

        // 如果连成线，检查一下.
        int is_attack(char board[][GRID_NUM],char Color, move_t * Move);

        // 判断move能不能产生四以上的棋形
        int is_dlb_attack(char board[][GRID_NUM],char Color, move_t * Move);
        //由于走两步，两步互换又是一种新的走法，所以要哈希表记录走法以免重复
        int vcf_hash_check(HashNode node);
        unsigned long vcf_hash_board(char board[GRID_NUM][GRID_NUM]);

        int is_three(char position[GRID_NUM][GRID_NUM],char Color, pos_t * Pos);
        void sort(move_t * moveList, int n_moveList, move_t * preMove);
        inline int vcf_abs(int a);
        inline int dist(pos_t p1, pos_t p2, pos_t pt);
        inline int vcf_min(int a, int b);

    public:
        int                 m_vcf_node;

    private:
        DFA                m_dfa;

        char                m_board[GRID_NUM][GRID_NUM];
        char                m_chess_type;
        char                m_has_win;

        char                m_org_board[GRID_NUM][GRID_NUM];
        ListNode            m_list_node[10000];
        move_t              m_tmp_move_list[10000];
        move_t              m_vcf_move_list[VCFDEPTH+1][10000];                         // Generated move list.
        std::vector<int>    m_hash_map[VCFDEPTH+1][HASHSIZE];//哈希表
        HashNode            m_hash_que[1000000];//哈希队列

        node_t              m_vcf_move_table[100000];
        int                 m_vcf_total_node;
        int                 m_vcf_now_pos;
        int                 m_dy[4];//用于循环四个方向
        int                 m_dx[4];//同上                                                    // Directions.
        char                m_vcf_use[GRID_NUM][GRID_NUM][4]; //棋盘上可以走的坐标// Can be used position in the board.
        char                m_vcf_mark[GRID_NUM][GRID_NUM];

};

#endif
