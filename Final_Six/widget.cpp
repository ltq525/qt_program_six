#include "widget.h"
#include "ui_widget.h"
#include "ThreatSearch.h"
#include "Board.h"
#include "defines.h"
#include "OpeningBook.h"


#include <QWidget>
#include <QWidget>
#include <QtMath>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QMouseEvent>
#include <QTextEdit>
#include <QFile>
#include <QDebug>
#include <cstdio>
#include <QTextStream>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(blockSize*25,blockSize*22);
    setMouseTracking(true);
    m_alphabeta_depth = 5; // 1 ~ 5
    m_vcf = true;
    m_vcf_search.init();
    init_game();
}
void Widget::init_game() {//初始化游戏
    init_board(m_board);
    m_vcf_search.init_game();
    aiFlag=false;
    steps=0;
    stepFlag=1;
    m_chess_type=BLACK;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_PvP_clicked()
{
    init_game();
    m_best_move.positions[0].x=0;
    m_best_move.positions[0].y=0;
}

void Widget::on_PvC_clicked()
{
    init_game();
    aiFlag=true;
    m_best_move.positions[0].x=0;
    m_best_move.positions[0].y=0;
    steps=0;
    stepFlag=1;
    m_chess_type=WHITE;
}

void Widget::on_CvP_clicked()
{
    init_game();
    aiFlag=true;
    m_board[10][10]=BLACK;
    m_chess_type=BLACK;
    stepFlag=0;
    PushMoveQue(10,10,BLACK);
}
void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QBrush brush;
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(Qt::black);
    //绘制棋盘
    for(int i=1; i < 20; i++)
    {
        painter.drawLine(blockSize+blockSize*i,blockSize*2,blockSize+blockSize*i,size().height()-blockSize*2);
        painter.drawLine(blockSize+blockSize,blockSize+blockSize*i,size().width()-5*blockSize,blockSize+blockSize*i);
        //画点
        if(i==4 || i==10 || i==16)
        {
            painter.setBrush(Qt::black);
            painter.drawEllipse(blockSize*5-chessSize/8,blockSize+blockSize*i-chessSize/8,chessSize/4,chessSize/4);
            painter.drawEllipse(blockSize*11-chessSize/8,blockSize+blockSize*i-chessSize/8,chessSize/4,chessSize/4);
            painter.drawEllipse(blockSize*17-chessSize/8,blockSize+blockSize*i-chessSize/8,chessSize/4,chessSize/4);
        }
        //画字
        QString str;
        str.setNum(i);
        painter.drawText(blockSize,blockSize+blockSize*(20-i)+chessSize/4,str);
        str = '@'+i;
        painter.drawText(blockSize+blockSize*i,blockSize*21,str);
    }
    //绘制落子
    painter.setBrush(brush);
    for(int i=1;i<=19;i++)
        for(int j=1;j<=19;j++)
        {
            if(m_board[i][j]==BLACK)
            {
                painter.setBrush(Qt::black);
                painter.drawEllipse(blockSize+blockSize*i-chessSize/2,blockSize+blockSize*j-chessSize/2,chessSize,chessSize);
            }
            else if(m_board[i][j]==WHITE)
            {
                painter.setBrush(Qt::white);
                painter.drawEllipse(blockSize+blockSize*i-chessSize/2,blockSize+blockSize*j-chessSize/2,chessSize,chessSize);
            }

        }
    //落子标记
    painter.setBrush(Qt::red);
    painter.drawEllipse(blockSize+blockSize*m_best_move.positions[0].x-chessSize/4,blockSize+blockSize*m_best_move.positions[0].y-chessSize/4,chessSize/2,chessSize/2);
    painter.drawEllipse(blockSize+blockSize*m_best_move.positions[1].x-chessSize/4,blockSize+blockSize*m_best_move.positions[1].y-chessSize/4,chessSize/2,chessSize/2);
    //落子提示
    int chessType;
    aiFlag?chessType=m_chess_type^3:chessType=m_chess_type;
    if(chessType==BLACK)painter.setBrush(Qt::black);
    else if((chessType)==WHITE) painter.setBrush(Qt::white);
    if(ChessNowX<=0 || ChessNowY<=0 || ChessNowX>19 || ChessNowY>19) return;
    painter.drawEllipse(blockSize+blockSize*ChessNowX-markSize/2, blockSize+blockSize*ChessNowY-markSize/2,markSize,markSize);

    update();

}
void Widget::mouseMoveEvent(QMouseEvent *event)
{
        int x = event->x();
        int y = event->y();
        ChessNowX=-1;
        ChessNowY=-1;
        if(x>=1 && x<=size().width()-5*blockSize && y>=0 && y<size().height()-blockSize)
        {
            int row = int(x/blockSize-1);
            int col = int(y/blockSize-1);
            int leftTopPosX = blockSize + blockSize*row;
            int leftTopPosY = blockSize + blockSize*col;
            if(sqrt((x-leftTopPosX)*(x-leftTopPosX) + (y-leftTopPosY)*(y-leftTopPosY))<markSize)
            {
                ChessNowX = row;
                ChessNowY = col;
             }
            else if(sqrt((x-leftTopPosX-blockSize)*(x-leftTopPosX-blockSize) + (y-leftTopPosY)*(y-leftTopPosY))<markSize)
            {
                ChessNowX = row+1;
                 ChessNowY = col;
            }
            else if(sqrt((x-leftTopPosX)*(x-leftTopPosX) + (y-leftTopPosY-blockSize)*(y-leftTopPosY-blockSize))<markSize)
            {
                ChessNowX = row;
                ChessNowY = col+1;
            }
            else if(sqrt((x-leftTopPosX-blockSize)*(x-leftTopPosX-blockSize) + (y-leftTopPosY-blockSize)*(y-leftTopPosY-blockSize))<markSize)
            {
                ChessNowX = row+1;
                ChessNowY = col+1;
            }
        }
        update();
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton && m_board[ChessNowX][ChessNowY]==0 &&
            ChessNowX>=1 && ChessNowX<=19 && ChessNowY>=1 && ChessNowY<=19 && !gameOverFlag)
    {
        putChess(ChessNowX,ChessNowY);
    }
}
void Widget::putChess(int x, int y)
{
    printf("putchess\n");
    if(is_win_by_premove(m_board,&m_best_move))
    {
        printf("GameOver");
        return;
    }
    //人人
    if(!aiFlag)
    {
        m_board[x][y]=m_chess_type;
        m_best_move.positions[stepFlag].x=x;
        m_best_move.positions[stepFlag].y=y;
        PushMoveQue(x,y,m_chess_type);
        stepFlag++;
        if(stepFlag==2)
        {
            stepFlag=0;
            //人人下完，换手
            m_chess_type = m_chess_type^3;
        }
        if(is_win_by_premove(m_board,&m_best_move))
        {
            printf("GameOver");
            return;
        }
    }
    //人机
    else
    {
        m_board[x][y] = m_chess_type^3;
        m_best_move.positions[stepFlag].x=x;
        m_best_move.positions[stepFlag].y=y;
        stepFlag++;
        PushMoveQue(x,y,m_chess_type^3);
        if(is_win_by_premove(m_board,&m_best_move))
        {
            printf("GameOver");
            return;
        }
        if(stepFlag==2)
        {
            stepFlag=0;
            //人下完到人机下
            if(steps==1 && WhiteOpening(m_board,&m_best_move))//ai是白棋，且即将要走2，3步
            {
                make_move(m_board,&m_best_move,m_chess_type);
                PushMoveQue(m_best_move.positions[0].x,m_best_move.positions[0].y,m_chess_type);
                PushMoveQue(m_best_move.positions[1].x,m_best_move.positions[1].y,m_chess_type);
                stepFlag=0;
            }
            else if(BlackOpening(m_board,&m_best_move,steps))
            {
                make_move(m_board,&m_best_move,m_chess_type);
                PushMoveQue(m_best_move.positions[0].x,m_best_move.positions[0].y,m_chess_type);
                PushMoveQue(m_best_move.positions[1].x,m_best_move.positions[1].y,m_chess_type);
                stepFlag=0;
            }
            else if(search_a_move(m_chess_type,&m_best_move))
            {
                make_move(m_board,&m_best_move,m_chess_type);
                PushMoveQue(m_best_move.positions[0].x,m_best_move.positions[0].y,m_chess_type);
                PushMoveQue(m_best_move.positions[1].x,m_best_move.positions[1].y,m_chess_type);
            }      
        }
        if(is_win_by_premove(m_board,&m_best_move))
        {
            printf("GameOver");
            return;
        }
    }

}
void Widget::PushMoveQue(int x, int y, int color)
{
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    int number[20];
    char word[20];
    for(int i=1;i<=19;i++)
        number[i]=20-i;
    for(int i=1;i<=19;i++)
        word[i]='@'+i;
    cout<<"pushMove:"<<word[x]<<number[y]<<endl;
    move_h tem;
    tem.x=x;
    tem.y=y;
    tem.color=color;
//    MoveQue.push(tem);
    stepQueue[steps]=tem;
    steps++;

}
void Widget::printMoveQue(QString win)
{
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    int number[20];
    char word[20];
    for(int i=1;i<=19;i++)
        number[i]=20-i;
    for(int i=1;i<=19;i++)
        word[i]='@'+i;

    move_h tem ;
    QString frist;
    QString second;
    QDateTime current_time = QDateTime::currentDateTime();
    QString current_ymdhm = current_time.toString("yyyy.MM.dd hh:mm");
    frist = ui->first->toPlainText();
    second  = ui->second->toPlainText();
    QString  str;
    str="{[C6]";
    str += '['+frist+" B"+']';
    str += '['+second+ " W"+']';
    str += '['+ win+']';
    str += "[" + current_ymdhm +" 在线][2020 CCGC]";
    for(int i=0;i<steps;i++)
    {
//        if(!MoveQue.empty())
//        {
//            tem = MoveQue.front();
//            if(tem.color==BLACK)
//            {
//                str+=";B";
//            }
//            else {
//                str+=";W";
//            }
//            str+='('+QString(word[tem.x])+','+QString::number(number[tem.y])+')';
//            MoveQue.pop();
//        }
        tem = stepQueue[i];
        if(tem.color==BLACK)
        {
            str+=";B";
        }
        else {
            str += ";W";
        }
        str+='('+QString(word[tem.x])+','+QString::number(number[tem.y])+')';
    }
    str+='}';
    QString fileName = "d:\\C6-"+frist+" vs "+second+'-'+win+".txt";
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << str << endl;

        file.close();
    }
    cout<<"print successfully"<<fileName<<endl;

}
bool Widget::search_a_move(char ourColor,move_t* bestMove)
{
    double score = 0;
    clock_t start,end;

    // 走到第九步后开始高威胁棋形搜索
    if (steps>10)
    {
        bool vcf = false;
        m_vcf_search.BeforeSearch(m_board, m_chess_type);
        vcf = m_vcf_search.vcf_search(0,ourColor,bestMove,bestMove,0,-1);
    // Check if wins.
        start = clock();
        if (vcf)
        {
            printf("Search.\n");
            qsrand(QTime(0,0,0).secsTo((QTime::currentTime())));
            int a;
            a = qrand()%10+10;

            while(true)
            {
                end = clock();
                double b=(double)(end-start)/CLOCKS_PER_SEC;

                if(b > a)
                {
                    printf("Time :\t%.3lf\n",(double)(end - start)/CLOCKS_PER_SEC);
                    return true;
                }

            }
        }
    }


    // AB剪枝
    start = clock();
    m_search_engine.before_search(m_board, m_chess_type, m_alphabeta_depth);
    printf("abSearch\n");
    score = m_search_engine.alpha_beta_search(m_alphabeta_depth,MININT,MAXINT,ourColor,bestMove,bestMove);
    end = clock();
    printf("Time :\t%.3lf\n",(double)(end - start)/CLOCKS_PER_SEC);
    return true;
}



void Widget::on_printChessStep_clicked()
{
    printMoveQue("先手胜");
}

void Widget::on_pushButton_clicked()
{
    printMoveQue("后手胜");
}
