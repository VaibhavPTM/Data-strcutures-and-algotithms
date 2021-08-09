// Link : https://leetcode.com/problems/n-queens/submissions/
#include<iostream>
using namespace std;

bool IsSafe(int board[][10], int i ,int j, int n){
    // check for the colmn
    for (int row = 0; row < i; row++)
    {
        if(board[row][j] == 1){
            return false;
        }
    }
    // ckeck for left diogonal
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0)
    {
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    
    return true;
}
bool solveAQueen(int board[][10],int i, int n){
    // base case
    if(i == n){
        // you have successfully placed all queen in n rows(0.....n-1)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(board[i][j] == 1){
                    cout<<"Q ";
                }
                else{
                    cout<<"_ ";
                }
            }
            cout<<endl;
        }   
        cout<<endl;
        return false; // if you want to all posiible answer then don't write return here   
    }
    // recursive case
    // now we have to place to queen in the currunt row and assume that remainin all rowa will be solved by recusrion
    for (int j = 0; j < n; j++)
    {
        // check that if i and j position are face for place the queen or not
        if(IsSafe(board,i,j,n)){
            // place the queen - assuming that i and j is the right posibtion for the queen
            board[i][j] = 1;

            /* bool nextQueenRakhOaye = solveAQueen(board , i + 1, n);
            if(nextQueenRakhOaye){
                return true;
            }*/
            solveAQueen(board , i + 1, n);
            // if it's come here then i and j is not the face position for the queen
            board[i][j] = 0; // backtrack
        }
    }
    return false; // it means you have tryed all positions for the queen but you did'n placed it
}
int main()
{
    int n;
    cin>>n;

    int board[10][10] = {0};
    
    solveAQueen(board,0,n);
    return 0;
}