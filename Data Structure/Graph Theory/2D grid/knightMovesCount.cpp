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

int cnt[9][9];
bool vis[9][9];
int dx[8] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dy[8] = {-1, 1, 2, 2, -1, 1, -2, -2};
int targetX,targetY;

bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > 8 || y > 8 || vis[x][y] == true)
    {
        return false;
    }
    return true;
}
int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = true;
    cnt[x][y] = 0;
    if(x == targetX && y == targetY) return cnt[x][y];
    while (!q.empty())
    {
        int crrX = q.front().f;
        int crrY = q.front().s;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            if (isValid(crrX + dx[i], crrY + dy[i]))
            {
                x = crrX + dx[i];
                y = crrY + dy[i];
                vis[x][y] = true;
                q.push({x, y});
                cnt[x][y] = cnt[crrX][crrY] + 1;
                if(x == targetX && y == targetY) return cnt[x][y];
            }
        }
    }
}
int getX(char a)
{
	return a - 'a' + 1;
}
int main()
{
    int t,x,y;
    cin >> t;
    while (t--)
    {
        char a,b;
        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++)
                vis[i][j] = false;
        }
        cin>>a>>b;
        x = getX(a);
        y = b - '0';

        cin>>a>>b;
        targetX = getX(a);
        targetY = b - '0';

        cout<<bfs(x,y)<<endl;
    }
    return 0;
}