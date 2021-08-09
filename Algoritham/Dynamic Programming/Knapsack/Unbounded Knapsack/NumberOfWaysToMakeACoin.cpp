// Link 1 : https://www.hackerrank.com/challenges/coin-change/submissions/code/220454137
// Link 2 : https://practice.geeksforgeeks.org/problems/coin-change2448/1
// Link 3 : https://leetcode.com/problems/coin-change-2/
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
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for (int i = 1; i <= n; i++)
#define forj(j, n) for (int j = 0; j < n; j++)
#define fors(j, s, n) for (int j = s; j < n; j++)
#define mx 1000000007
#define endl "\n"
int change(int sum, vector<int> &coins)
{
    int n = coins.size();
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    vector<int> v;
    int n,sum;
    cin>>n>>sum;
    for (int i = 0; i < n; i++)
    {   
        int a;
        cin>>a;
        v.pb(a);    
    }
    cout<<change(sum,v);

    return 0;
}