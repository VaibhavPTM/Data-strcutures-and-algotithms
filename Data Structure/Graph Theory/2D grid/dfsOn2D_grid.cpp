// Name : Counting Rooms
// Link : https://cses.fi/problemset/task/1192/
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>

#define iil long long int
#define vi vector<int>
#define si set<int>
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define fors(j, s, n) for (int j = s; j < n; j++)
#define max 1000000001
#define endl "\n"
using namespace std;


int m, n;
int arr[1001][1001];
bool vis[1001][1001];

// for up : x-1 , y
// for right : x , y+1
// for down : x+1,y
// for left : x, y-1
int forx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};
int fory[8] = {0, 1, 0, -1, -1, 1, 1, -1};

bool isValid(int x, int y){
    if(x < 1 || y < 1 || x > m || y > n || vis[x][y] == true || arr[x][y] == 0){ // here the last condition is for count the countind componants
        return false;
    }
    return true;
}
void bfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        if(isValid(x + forx[i], y + fory[i])){
            bfs(x + forx[i], y + fory[i]);
        }
    }
}

int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1 ; j <= n; j++){
            cin>>arr[i][j];
        }
    }
    int cc = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1 ; j <= n; j++){
            if(arr[i][j] == 1 && vis[i][j] == false){
                bfs(i,j);
                cc++;
            }
        }
    }
    cout<<"Conected componants : "<<cc;

    return 0;
}
/*
0 0 1 0 1 1
0 1 1 0 0 1
0 1 0 0 0 0
1 0 1 1 0 0
0 0 0 1 0 0
0 1 1 0 1 1
*/