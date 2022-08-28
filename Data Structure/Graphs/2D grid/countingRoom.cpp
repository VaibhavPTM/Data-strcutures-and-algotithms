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

char arr[1001][1001];
bool vis[1001][1001];
int N, M;

int forx[4] = {-1, 0, 1, 0};
int fory[4] = {0, 1, 0, -1};
bool isValid(int x, int y)
{
    if (x < 1 || y < 1 || x > N || y > M || arr[x][y] == '#' || vis[x][y] == true)
    {
        return false;
    }
    return true;
}

void bfs(int x, int y)
{
    vis[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        if (isValid(x + forx[i], y + fory[i]))
        {
            bfs(x + forx[i], y + fory[i]);
        }
    }
}

int main()
{
    cin >> N >> M;
    fori(i, N)
    {
        fori(j, M)
        {
            cin >> arr[i][j];
        }
    }
    int cc = 0;
    fori(i, N)
    {
        fori(j, M)
        {
            if (vis[i][j] == false && arr[i][j] == '.')
            {
                bfs(i, j);
                cc++;
            }
        }
    }
    cout << cc;
    return 0;
}