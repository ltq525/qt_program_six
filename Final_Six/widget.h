#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QWidget>
#include <QWidget>
#include <QtMath>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QMouseEvent>
#include <stack>
#include <queue>
#include <QTextEdit>
#include "defines.h"
#include "SearchEngine.h"
#include "ThreatSearch.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_PvP_clicked();

    void on_PvC_clicked();

    void on_CvP_clicked();


    void on_printChessStep_clicked();

    void on_pushButton_clicked();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


private:
    std::queue<move_h>       MoveQue;                           //走子序列，用于打谱
    char                m_board[GRID_NUM][GRID_NUM];        //实际棋盘
    move_t              m_best_move;                        //当前的落子，有时也做上一个落子
    int                 m_chess_type;                       //在其它地方是chess colour
    int                 m_alphabeta_depth;
    bool                m_vcf;
    int                 ChessNowX,ChessNowY;                //鼠标坐标
    bool                aiFlag;                             //ai开关
    int                 aiChess;
    int                 steps;
    int                 stepFlag;
    bool                gameOverFlag;
    move_h              stepQueue[500];

    SearchEngine       m_search_engine;
    ThreatSearch          m_vcf_search;
    void init_game();
    void putChess(int x,int y);
    bool search_a_move(char ourColor,move_t* bestMove);
    void PushMoveQue(int x,int y, int color);
    void printMoveQue(QString win);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
