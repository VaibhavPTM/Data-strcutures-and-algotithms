// Link : https://leetcode.com/problems/coin-change/
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
int coinChange(vector<int> &c, int sum){
    int n = c.size();
    int t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++){
        t[i][0] = 0;
    }
    for (int i = 1; i <= sum; i++){
        t[0][i] = INT_MAX - 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= sum; j++){
            if (c[i - 1] <= j){
                t[i][j] = min(t[i - 1][j], 1 + t[i][j - c[i - 1]]);
            }
            else t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum] == INT_MAX - 1 ? -1 : t[n][sum];
}
int main()
{
    int n, sum; 
    vi v;
    cin>>n>>sum;
    for(int i = 0; i < n; i++){
        int a;
        cin>>a;
        v.pb(a);
    }
    cout<<coinChange(v,sum);
    return 0;
}