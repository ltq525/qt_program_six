
#ifndef EVALUATION_H_
#define EVALUATION_H_

#include "defines.h"

// Shape names.
#define huoer           0
#define huosan          1
#define miansan         2
#define huosi           3
#define miansi          4
#define huowu           5
#define mianwu          6
#define liu             7
#define qi              8
#define ba              9
#define jiu             10
#define shi             11
#define shiyi           12
#define sisi            13
#define wuxing          14

#define black_fix 15
#define white_fix 1

// 四个方向
#define DUD             0           // 上下
#define DLR             1           // 左右
#define DRU             2           // 右上
#define DRD             3           // 右下
// Scores for shapes.
#define Threat          300         //威胁
#define CROSSPLUS       300
#define CROSSJIAN       300

// Score index for the shapes. 棋形索引值
#define base_1          0           //2000
#define base_2          1           //1000
#define base_3          2           //0
#define base_4          3           //-1000
#define base_5          4           //-2000
#define base_6          5           //-3000
#define base_7          6           //-4000
#define huoer_big       7           //15
#define huoer_lit       8           //10
#define huosan_big      9           //25
#define huosan_lit      10          //20
#define miansan_big     11          //10
#define miansan_lit     12          //6
#define cross_big       13          //15
#define cross_lit       14          //10

class Evaluation {
    public:
        Evaluation();

        double evaluation( char ourOrder , char nextStep, char board[][GRID_NUM]);

    private:
        void set_situation(char board[][GRID_NUM]);

        //搜索该点在一个方向上时什么棋形
        //x,y:位置
        //countx：
        //county：
        //dir：方向
        //board：棋盘
        void set_situation_for_one_direction(int x, int y ,short countx,short county,int dir,char board[][GRID_NUM]);

    public:
        double      m_time_evalution;

    private:
        //Evaluation
        int         m_w_situation[15];          //白棋棋形统计
        int         m_b_situation[15];          //黑棋棋形统计
        int         m_w_cross;
        int         m_b_cross;
        int         m_w_detail[15][15];         // Detail information for the white in the board.
        int         m_b_detail[15][15];         // Detail information for the black.
        char        m_visited_direction[20][20][4];

        int         m_w_vir_detail[15][15];     // Virtual cross information for white.
        int         m_b_vir_detail[15][15];
        char        m_visited_virtual_direction[20][20][4];

        int         b_mean_point;
        int         w_mean_point;

};

#endif
