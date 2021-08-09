// Link  = https://www.hackerrank.com/challenges/sam-and-substrings/problem
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

// int dp[20002][20002];

void make_cob(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << s.substr(i, j) << " ";
        }
    }
}

int main()
{
    string str;
    cin >> str;
    make_cob(str);
    return 0;
}