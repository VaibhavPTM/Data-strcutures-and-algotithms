// Link : https://leetcode.com/problems/ones-and-zeroes/
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
#define mod 1000000007
#define sin(n) scanf("%d", &n)
#define endl "\n"
int findMaxForm(vector<string> &str, int m, int n)
{
    int s = str.size();
    int dp[m + 1][n + 1][s + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= s; k++)
            {
                if (i == 0 && j == 0 || k == 0)
                {
                    dp[i][j][k] = 0;
                    continue;
                }
                string s = str[k - 1];
                int zero = 0, one = 0;
                zero = count(s.begin(), s.end(), '0');
                one = s.size() - zero;
                if (i >= zero && j >= one)
                {
                    dp[i][j][k] = max(1 + dp[i - zero][j - one][k - 1], dp[i][j][k - 1]);
                }
                else
                {
                    dp[i][j][k] = dp[i][j][k - 1];
                }
            }
        }
    }
    return dp[m][n][s];
}
int main()
{
    // vector<string> strs = { "10",
    //                         "0001",
    //                         "111001",
    //                         "1",
    //                         "0" } int m,
    //                n;
    // cin >> m >> n;
    // cout << findMaxForm(strs, m, n);
    if(isdigit('O')){
        cout<<"res";
    }    

    return 0;
}