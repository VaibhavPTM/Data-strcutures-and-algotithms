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

vector<vector<int>> dp;
vector<vector<int>> dp1;
bool isPalindrome(string &s, int i, int j)
{
    if (i >= j)
        return true;
    if (dp1[i][j] != -1)
        return dp1[i][j];
    if (s[i] == s[j])
        return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
    return dp1[i][j] = false;
}

int solve(string s, int l, int r)
{
    if (l >= r)
        return dp[l][r] = 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    if (isPalindrome(s, l, r))
        return dp[l][r] = 0;
    int ans = INT_MAX;
    for (int i = l; i <= r - 1; i++)
    {
        if (isPalindrome(s, l, i))
            ans = min(ans, 1 + solve(s, i + 1, r));
    }
    return dp[l][r] = ans;
}

int minCut(string s)
{
    dp.resize(s.size(), vector<int>(s.size(), -1));
    dp1.resize(s.size(), vector<int>(s.size(), -1));
    return solve(s, 0, s.size() - 1);
}

int main()
{
    string str;
    cin >> str;
    cout << "Answer is : " << minCut(str);
    return 0;
}

// This code is for undeestanding purpos
/*
int dp[502][502];
bool isPalidorm(string s, int i, int j)
{
    if (i == j)
        return true;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int help(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (isPalidorm(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;
        if (dp[i][k] != -1)
            left = dp[i][k];
        else
        {
            left = help(s, i, k);
            dp[i][k] = left;
        }
        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
        {
            right = help(s, k + 1, j);
            dp[k + 1][j] = right;
        }
        int mn = left + right + 1;
        res = min(res, mn);
    }
    return dp[i][j] = res;
}

int palindromicPartition(string str)
{
    memset(dp, -1, sizeof dp);
    return help(str, 0, str.size() - 1);
}
*/