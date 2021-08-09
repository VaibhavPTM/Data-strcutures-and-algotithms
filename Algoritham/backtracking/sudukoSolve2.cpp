#include<iostream>
#define N 9
using namespace std;
void display(int board[9][9]){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool isSafe(int board[9][9],int x, int y, int val){
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
    int cornerX,cornerY;
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
bool solveSuduko(int grid[N][N], int row, int col)
{
   
    if (row == N - 1 && col == N)
        return true;
    if (col == N) {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0)
        return solveSuduko(grid, row, col + 1); 
    for (int num = 1; num <= N; num++) 
    {
         
        if (isSafe(grid, row, col, num)) 
        {
             
            grid[row][col] = num;
           
            if (solveSuduko(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}
int main()
{
    int n, board[9][9];
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
                board[j][k] = 0;
                cin >> board[j][k];
            }
        }
        if(solveSuduko(board,0,0))
        display(board);
    }
    return 0;
}   