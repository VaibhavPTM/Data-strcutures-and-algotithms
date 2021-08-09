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

string help(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    string dp[n+1][m+1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = "";
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] +  s1[i-1];
            }
            else {
                dp[i][j] = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j]: dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<"LCS : "<<help(s1,s2);
    return 0;
}