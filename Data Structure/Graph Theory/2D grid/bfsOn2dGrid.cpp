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
#define si set<int>
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

int N,M;
int cnt[10001][10001];
bool vis[10001][10001];

int corX[4] = {-1,0,1,0};
int cory[4] = {0,1,0,-1};

bool isValid(int x, int y){
    if(vis[x][y] == true || x < 1 || y < 1 || x >N || y > M){
        return false;
    }
    return true;
}

void bfs(int x, int y){
    queue<pair<int,int>> q;
    vis[x][y] = true;
    cnt[x][y] = 0;
    q.push({x,y});

    while (!q.empty())
    {
        int crrX = q.front().f;
        int crrY = q.front().s;
        q.pop();
        for(int i = 0; i < 4; i++){
            if(isValid(crrX + corX[i],crrY + cory[i])){
                int newX = crrX + corX[i];
                int newY = crrY + cory[i];
                vis[newX][newY] = true;
                q.push({newX,newY});
                cnt[newX][newY] = cnt[crrX][crrY] + 1;
            }
        }
    }

    fori(j,N){
        fori(i,M){
            cout<<cnt[j][i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cin>>N>>M;
    bfs(3,2);
    return 0;
}