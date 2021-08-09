#include <iostream>
#define N 9
using namespace std;
void display(int board[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int board[9][9], int x, int y, int val)
{
    // Check for rows
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == val)
        {
            return false;
        }
    }
    // check for columns
    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == val)
        {
            return false;
        }
    }
    int cornerX, cornerY;
    cornerX = (x / 3) * 3;
    cornerY = (y / 3) * 3;
    // Check for sub matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[cornerX + i][cornerY + j] == val)
            {
                return false;
            }
        }
    }
    return true;
}
void solveSuduko(int board[N][N], int row, int colum)
{
    // base condition
    if (row == 9)
    {
        display(board);
        return;
    }

    int ni = 0, nj = 0;
    if (colum == N - 1)
    {
        ni = row + 1;
        nj = 0;
    }
    else
    {
        ni = row;
        nj = colum + 1;
    }
    if (board[row][colum] != 0)
    {
        solveSuduko(board, ni, nj);
    }
    else
    {
        for (int po = 1; po <= 9; po++)
        {
            if (isSafe(board, row, colum, po) == true)
            {
                board[row][colum] = po;
                solveSuduko(board, ni, nj);
                board[row][colum] = 0;
            }
        }
    }
}
int main()
{
    int board[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 1, 0, 0, 8, 0},
                       {9, 0, 0, 8, 6, 3, 0, 0, 5},
                       {0, 5, 0, 0, 9, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solveSuduko(board, 0, 0);
    return 0;
}