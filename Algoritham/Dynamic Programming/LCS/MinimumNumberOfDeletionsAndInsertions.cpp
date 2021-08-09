// Link : https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1
// Link : https://leetcode.com/problems/delete-operation-for-two-strings/
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

vector<int> help(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    int insert = s2.size() - dp[n][m];
    int delet = s1.size() - dp[n][m];
    return {insert,delet};    
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<int> v = help(s1,s2);
    cout<<"Maximum Insetion is : "<<v[0]<<"\nMaximum Deletion is : "<<v[1];
    return 0;
}