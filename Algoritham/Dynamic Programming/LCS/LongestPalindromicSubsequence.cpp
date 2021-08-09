// Link : https://leetcode.com/problems/longest-palindromic-subsequence/
#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

#define lli long long int
#define vi vector<int>
#define vii vector<vector<int> >
#define si set<int>
#define pb push_back
#define ff first
#define ss second
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fori(i, n) for(int i = 1; i <= n; i++)
#define forj(j, n) for(int j = 0; j < n; j++)
#define fors(j, s, n) for(int j = s; j < n; j++)
#define mx 1000000007
#define endl "\n"

string longestPalindromeSubseq(string str1) {
    string str2 = str1;
    reverse(str2.begin(),str2.end());
    int n = str1.size();
    int m = str2.size();
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string res;
    for (int i = n,j = m; i > 0 && j > 0; ){
        if(str1[i-1] == str2[j-1]){
            res.push_back(str1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else j--;
        }
    }
    return res;
}

int main()
{
    string s;
    cin>>s;
    cout<<longestPalindromeSubseq(s);
    return 0;
}