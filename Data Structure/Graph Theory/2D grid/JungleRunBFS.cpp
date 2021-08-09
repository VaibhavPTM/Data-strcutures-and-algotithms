#include<iostream>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<algorithm>

#define iil long long int
#define vi vector<int>
#define pb push_back
#define f first
#define s second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define max 1000000001
#define endl "\n"
using namespace std;

char grid[31][31];
bool vis[31][31];
int cnt[31][31];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int n;

bool isValid(int x, int y){
    if(x < 1 || x > n || y < 1 || y > n || vis[x][y] == true || grid[x][y] == 'T'){
        return false;
    }
    return true;
}
void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    vis[x][y] = true;
    cnt[x][y] = 0;
    while(!q.empty()){
        int crrX = q.front().f,crrY = q.front().s;
        q.pop();
        forj(i,4){
            if(isValid(crrX + dx[i] ,crrY + dy[i])){
                int nx = crrX + dx[i], ny = crrY + dy[i];
                vis[nx][ny] = true;
                q.push({nx,ny});
                cnt[nx][ny] = cnt[crrX][crrY] + 1;
                if(grid[nx][ny] == 'E'){
                    cout<<cnt[nx][ny];
                    break;
                }
            }
        }
    }
}

int main()
{
    cin>>n;
    int si,sj;
    fori(i,n){
        fori(j,n){
            cin>>grid[i][j];
            if(grid[i][j] == 'S'){
                si = i,sj = j;
            }
        }
    }
    bfs(1,1);
    
    return 0;
}
