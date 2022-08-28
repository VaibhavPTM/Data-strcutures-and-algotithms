// Link : https://leetcode.com/problems/making-a-large-island/
// Topic : Making A Large Island
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int>, greater<int>>
#define pb push_back
#define ff first
#define ss second
#define print(x)     
    for (auto it : x) 
        cout << it << " ";
const lli INF = 1e18;
const lli MOD = 1e9 + 7;
#define endl "\n"
int n;
int dfs(int i, int j, vector<vector<int>> &grid, int id)
{
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
        return 0;
    grid[i][j] = id;
    return 1 + dfs(i + 1, j, grid, id) + dfs(i - 1, j, grid, id) + dfs(i, j + 1, grid, id) + dfs(i, j - 1, grid, id);
}

int largestIsland(vector<vector<int>> &grid)
{
    n = grid.size();
    int id = 2;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                int size = dfs(i, j, grid, id);
                mp[id] = size;
                id++;
            }
        }
    }
    int res = mp[2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            set<int> s;
            if (grid[i][j] == 0)
            {
                s.insert(i > 0 ? grid[i - 1][j] : 0);
                s.insert(j > 0 ? grid[i][j - 1] : 0);
                s.insert(i < n - 1 ? grid[i + 1][j] : 0);
                s.insert(j < n - 1 ? grid[i][j + 1] : 0);
                int tres = 1;
                for (auto k : s)
                    tres += mp[k];
                res = max(res, tres);
            }
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Constraints:
    //         n == grid.length
    //         n == grid[i].length
    //         1 <= n <= 500
    //         grid[i][j] is either 0 or 1.

    return 0;
}