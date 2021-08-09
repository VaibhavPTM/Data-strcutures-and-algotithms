// Link : https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1#
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
int dp[201][201][2];
int solve(string s, int i, int j, int isTrue){
    if (i > j){
        return false;
    }
    else if (i == j){
        if (isTrue == 1){
            return s[i] == 'T';
        }
        else{
            return s[i] == 'F';
        }
    }
    if (dp[i][j][isTrue] != -1){
        return dp[i][j][isTrue];
    }
    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2){
        int leftFalse, leftTrue, rightFalse, rightTrue;
        if (dp[i][k - 1][0] != -1){
            leftFalse = dp[i][k - 1][0];
        }
        else{
            leftFalse = solve(s, i, k - 1, 0);
        }
        if (dp[i][k - 1][1] != -1){
            leftTrue = dp[i][k - 1][1];
        }
        else{
            leftTrue = solve(s, i, k - 1, 1);
        }
        if (dp[k + 1][j][1] != -1){
            rightTrue = dp[k + 1][j][1];
        }
        else{
            rightTrue = solve(s, k + 1, j, 1);
        }
        if (dp[k + 1][j][0] != -1){
            rightFalse = dp[k + 1][j][0];
        }
        else{
            rightFalse = solve(s, k + 1, j, 0);
        }

        if (s[k] == '&'){
            if (isTrue == 1){
                ans += leftTrue * rightTrue;
            }
            else{
                ans += (leftFalse * rightFalse) + (leftFalse * rightTrue) + (leftTrue * rightFalse);
            }
        }
        else if (s[k] == '|'){
            if (isTrue == 1){
                ans += (leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftTrue * rightTrue);
            }
            else{
                ans += (leftFalse * rightFalse);
            }
        }
        else{
            if (isTrue == 1){
                ans += (leftTrue * rightFalse) + (leftFalse * rightTrue);
            }
            else{
                ans += (leftFalse * rightFalse) + (leftTrue * rightTrue);
            }
        }
        dp[i][j][isTrue] = ans;
    }
    return ans;
}

int countWays(int N, string s)
{
    memset(dp, -1, sizeof dp);
    return solve(s, 0, N - 1, 1);
}
int main()
{
    string s;
    cin>>s;
    cout<<countWays(s.size(),s);
    return 0;
}