// Link : https://leetcode.com/problems/longest-increasing-subsequence/
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
#define mod 1000000007
#define sin(n) scanf("%d",&n)
#define endl "\n"

int solve(vector<lli> a){
    lli n = a.size();
    if(n == 1) return 1;
    vector<lli> dp(n+1,1);
    lli res = 0;
    for (int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i] && dp[i] < dp[j]+1) {
                dp[i] = dp[j] + 1;
            }
        }
        res = max(res,dp[i]);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<lli> v;
    for (int i = 0; i < n; i++){
        lli t;
        cin>>t;
        v.push_back(t);
    }
    cout<<solve(v);
    return 0;
}