// Name : Longest Repeating Subsequence
// Link : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
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
int LongestRepeatingSubsequence(string s){
    int n = s.size();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if (i != j && s[i - 1] == s[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}
int main(){
    string str;
    cin>>str;
    cout<<LongestRepeatingSubsequence(str);

    return 0;
}