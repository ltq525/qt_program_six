
#include "Board.h"

char g_log_file_name[] = "engine.log";

void init_board(char board[][GRID_NUM])
{
    // Board init. [10/28/2011 lang]
    for(int i = 0; i< 21 ; i++)
    {
        board[i][0] = board[0][i] = board[i][GRID_NUM-1] = board[GRID_NUM-1][i] = BORDER;
    }
    for(int i = 1 ; i< GRID_NUM-1 ; i++)
    {
        for(int j = 1 ; j < GRID_NUM-1 ; j++)
        {
            board[i][j] = NOSTONE;
        }
    }
}

void make_move(char board[][GRID_NUM], move_t* move, char color) {
    board[move->positions[0].x][move->positions[0].y] = color;
    board[move->positions[1].x][move->positions[1].y] = color;
}

void unmake_move(char board[][GRID_NUM], move_t* move)
{
    board[move->positions[0].x][move->positions[0].y] = NOSTONE;
    board[move->positions[1].x][move->positions[1].y] = NOSTONE;
}

bool is_win_by_premove(char board[][GRID_NUM], move_t *preMove)
{
    int count = 0,i,j,n,m;

    // The first point.
    n = i = preMove->positions[0].x;
    m = j = preMove->positions[0].y;
    // Horizon direction.
    count = 0;
    if (board[n][m] == BORDER
            || board[n][m] == NOSTONE)
    {
        return false;
    }
    while ( board[i][j] == board[n][m])
    {
        i++;
        count++;
    }
    i = n-1;
    while ( board[i][j] == board[n][m])
    {
        i--;
        count++;
    }
    if (count >= 6)
    {
        return true;
    }

    // Left up direction.
    count = 0;
    i = n;j = m;
    while ( board[i][j] == board[n][m])
    {
        i++;
        j++;
        count++;
    }
    i = n-1;
    j = m-1;
    while ( board[i][j] == board[n][m])
    {
        i--;
        j--;
        count++;
    }
    if (count >= 6)
    {
        return true;
    }

    // Vertical direction.
    count = 0;
    i = n;j = m;
    while ( board[i][j] == board[n][m])
    {
        j++;
        count++;
    }
    j = m-1;
    while (board[i][j] == board[n][m])
    {
        j--;
        count++;
    }
    if (count >= 6)
    {
        return true;
    }

    // Down left direction.
    count = 0;
    i = n;j = m;
    while ( board[i][j] == board[n][m])
    {
        i++;
        j--;
        count++;
    }
    i = n-1;
    j = m+1;
    while ( board[i][j] == board[n][m])
    {
        i--;
        j++;
        count++;
    }
    if (count >= 6)
    {
        return true;
    }

    // The second point.
    n = i = preMove->positions[1].x;
    m = j = preMove->positions[1].y;
    if (board[n][m] == BORDER
            || board[n][m] == NOSTONE)
    {
        return false;
    }
    // Horizon direction.
    count = 0;
    while ( board[i][j] == board[n][m])
    {
        i++;
        count++;
    }
    i = n-1;
    while (board[i][j] == board[n][m])
    {
        i--;
        count++;
    }
    if (count >= 6)
    {
        return true;
    }

    // Up left direction.
    count = 0;
    i = n;j = m;
    while ( board[i][j] == board[n][m])
    {
        i++;
        j++;
        count++;
    }
    i = n-1;
    j = m-1;
    while ( board[i][j] == board[n][m])
    {
        i--;
        j--;
        count++;
    }
    if (count >= 6)
    {
        return true;
    }

    // Vertical direction.
    count = 0;
    i = n;j = m;
    while ( board[i][j] == board[n][m])
    {
        j++;
        count++;
    }
    j = m-1;
    while ( board[i][j] == board[n][m])
    {
        j--;
        count++;
    }
    if (count >= 6)
    {
        return true;
    }

    // Down left direction.
    count = 0;
    i = n;j = m;
    while ( board[i][j] == board[n][m])
    {
        i++;
        j--;
        count++;
    }
    i = n-1;
    j = m+1;
    while ( board[i][j] == board[n][m])
    {
        i--;
        j++;
        count++;
    }
    if (count >= 6)
    {
        return true;
    }

    return false;
}

