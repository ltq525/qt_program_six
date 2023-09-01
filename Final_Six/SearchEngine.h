#include "MoveGenerator.h"
#include "Evaluation.h"
#include "TranspositionTable.h"
/*
 * 可优化，这里没用哈希表
*/
class SearchEngine {
    public:
        SearchEngine();

        void before_search(char board[][GRID_NUM], char color, int m_alphabeta_depth);
        double alpha_beta_search(int depth,double alpha,double beta,char ourColor, move_t* bestMove,move_t* preMove);

    private:

    public:
        int m_total_nodes;

    private:
        char                m_board[GRID_NUM][GRID_NUM];                    // The board in the search engine.
        char                m_chess_type;
        int                 m_alphabeta_depth;
        int  hashKey;
        MoveGenerator      m_move_gernerator;
        Evaluation         m_evaluator;

};
