#include<bits/stdc++.h>
using namespace std;
static int fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

int dp[1001][1001];

int help(string s1, string s2, int i, int j){
    if(i == 0 || j == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    else if(s1[i] == s2[j]) return dp[i][j] = 1 + help(s1,s2,i-1,j-1);
    else return dp[i][j] = max(help(s1,s2,i-1,j), help(s1,s2,i,j-1));
}

int main()
{
    string str1,str2;
    cin>>str1>>str2;
    memset(dp,-1, sizeof dp);
    cout<<help(str1,str2,str1.size(),str2.size());
    return 0;
}