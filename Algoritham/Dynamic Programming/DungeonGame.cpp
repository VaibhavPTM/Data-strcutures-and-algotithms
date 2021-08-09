// Link : https://leetcode.com/problems/dungeon-game/
// Topic : dp (Hard)
#include <bits/stdc++.h>
using namespace std;
static int fastio = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int>>
#define si set<int>
#define maxhp priority_queue<int>
#define minhp priority_queue<int, vector<int>, grater<int>>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define mod 1000000007
#define endl "\n"
int calculateMinimumHP(vector<vector<int>> &dp){
    int n = dp.size();
    int m = dp[0].size();
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if( i == n-1 && j == m - 1) 
                dp[i][j] = min(0, dp[i][j]);
            else if(i == n - 1)
                dp[i][j] = min(0, dp[i][j] + dp[i][j+1]);
            else if(j == m - 1)
                dp[i][j] = min(0, dp[i][j] + dp[i+1][j]);
            else
                dp[i][j] = min(0, dp[i][j] + max(dp[i+1][j], dp[i][j+1]));
        }
    }
    return abs(dp[0][0]) + 1;
}
int main()
{
    vii v = { {-2, -3, 3},
              {-5, -10, 1},
              {10, 30, -5} };
    cout<<calculateMinimumHP(v);

    return 0;
}