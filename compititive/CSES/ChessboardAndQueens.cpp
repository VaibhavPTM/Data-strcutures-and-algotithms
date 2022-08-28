// Link : https://leetcode.com/problems/n-queens/submissions/
#include<iostream>
using namespace std;
int res = 0;
bool IsSafe(char board[][8], int i ,int j, int n){
    // check for the colmn
    if(board[i][j] == '*') return false;
    for (int row = 0; row < i; row++) {
        if(board[row][j] == 'Q'){
            return false;
        }
    }
    int x = i;
    int y = j;
    while (x >= 0 && y >= 0) {
        if(board[x][y] == 'Q'){
            return false;
        }
        x--;
        y--;
    }

    x = i;
    y = j;
    while (x >= 0 && y < n)
    {
        if(board[x][y] == 'Q'){
            return false;
        }
        x--;
        y++;
    }
    return true;
}
bool solveAQueen(char board[][8],int i, int n){
    // base case
    if(i == n){
        res++;
        return false; 
    }
    for (int j = 0; j < n; j++) {
        if(IsSafe(board,i,j,n)){
            board[i][j] = 'Q';
            solveAQueen(board , i + 1, n);
            board[i][j] = '.'; 
        }
    }
    return false;
}
int main() {
    char board[8][8];
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }
    solveAQueen(board,0,8);
    cout << res << endl;
    return 0;
}