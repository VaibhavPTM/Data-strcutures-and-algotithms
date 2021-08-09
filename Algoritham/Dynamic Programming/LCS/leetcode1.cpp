// Name : Wildcard Matching;
// Link : https://leetcode.com/problem
s/wildcard-matching/
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
bool isMatch(string s, string p){
    int n = s.size();
    int m = p.size();
    bool dp[n+1][m+1];
    memset(dp,false,sizeof dp);
    dp[0][0] = true;
    for (int i = 1; i <= m; i++)
    {
        if(p[i-1] == '*') dp[0][i] = dp[0][i-1];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(p[j-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }        
            else if(p[j-1] == '?' || p[j-1] == s[i-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else dp[i][j] = false;
        }
    }
    return dp[n][m];
}
int main()
{
    string s,p;
    cin>>s>>p;
    if(isMatch(s,p)){
        cout<<"YES";
    }
    else cout<<"No";
    return 0;
}